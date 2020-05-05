#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    rand_()
{
    ui->setupUi(this);
    sw = nullptr;
    nw = nullptr;
    in = nullptr;
    ab = nullptr;

    QObject::connect(ui->actionLoad,
                     SIGNAL(triggered()),
                     this,
                     SLOT(fileLoadScenario()));
    QObject::connect(ui->actionSave,
                     SIGNAL(triggered()),
                     this,
                     SLOT(fileSaveScenario()));
    QObject::connect(ui->actionExit,
                     SIGNAL(triggered()),
                     this,
                     SLOT(fileExit()));
    QObject::connect(ui->actionSubjectParams,
                     SIGNAL(triggered()),
                     this,
                     SLOT(editSubjectParameters()));
    QObject::connect(ui->actionNetworkParams,
                     SIGNAL(triggered()),
                     this,
                     SLOT(editNetworkParameters()));
    QObject::connect(ui->actionInstructions,
                     SIGNAL(triggered()),
                     this,
                     SLOT(helpInstructions()));
    QObject::connect(ui->actionAbout,
                     SIGNAL(triggered()),
                     this,
                     SLOT(helpAbout()));

    settings_ = Settings::get_settings();
    scenario_ = new Scenario(settings_);
    scene_ = new QGraphicsScene();
    manager_ = new Manager(settings_, scene_, rand_);

    target_ = new Target(scene_, PRIMARY);
    mousePoint_ = new Target(scene_, MOUSE_POINT);
    SubjectCore::setPublicInstance(target_, 1);
    SubjectCore::setPublicInstance(mousePoint_, 4);

    target_->setDefaultTargetPolygon();
    target_->setCoordinates(XY(350,350));
    target_->update();
    mousePoint_->setDefaultMousePointPolygon();
    mousePoint_->setCoordinates(XY(-100,-100));
    mousePoint_->update();

    ui->graphicsView->setScene(scene_);
    ui->graphicsView->setSceneRect(0,0,1920,1080);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::white));

    QObject::connect(ui->buttonRun,
                     SIGNAL(clicked()),
                     this,
                     SLOT(buttonRunClicked()));
    QObject::connect(ui->buttonReset,
                     SIGNAL(clicked()),
                     this,
                     SLOT(buttonResetClicked()));
    QObject::connect(ui->buttonExit,
                     SIGNAL(clicked()),
                     this,
                     SLOT(buttonExitClicked()));
    QObject::connect(ui->buttonGeneration,
                     SIGNAL(clicked()),
                     this,
                     SLOT(buttonGenerationClicked()));
    QObject::connect(ui->sliderIteration,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(iterationChanged(int)));
    QObject::connect(ui->sliderInstance,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(instanceChanged(int)));
    QObject::connect(ui->sliderOffspring,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(offspringChanged(int)));
    QObject::connect(ui->sliderTime,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(timeChanged(int)));

    ui->buttonGeneration->setDisabled(true);

    ui->comboInput->addItem("Angular Difference [0,1]");
    ui->comboInput->addItem("Space Difference [0,1]");
    ui->comboInput->addItem("Axis-wise Difference [-1,1]");
    ui->comboInput->addItem("Distances to 4 walls [0,1]");
    ui->comboInput->addItem("Search in 4 Directions (0/1)");
    ui->comboInput->addItem("Search in 4 Corners (0/1)");

    ui->comboOutput->addItem("Angular Velocity [0,1]");
    ui->comboOutput->addItem("Direct Angle [0,1]");
    ui->comboOutput->addItem("Angle-Velocity [0,1]");
    ui->comboOutput->addItem("Angle-Acceleration [-1,1]");
    ui->comboOutput->addItem("Axis-wise Velocity [0,1]");
    ui->comboOutput->addItem("Axis-wise Acceleration [-1,1]");
    ui->comboOutput->addItem("Small Hops [-1,1]");
    ui->comboOutput->addItem("Horizontal/Vertical (0/1)");

    ui->comboFitness->addItem("Correct Angle");
    ui->comboFitness->addItem("Close Proximity");
    ui->comboFitness->addItem("Not too far/close");
    ui->comboFitness->addItem("Not Out of Bounds");
    ui->comboFitness->addItem("Look from a Distance");
    ui->comboFitness->addItem("Avoid Eye Contact");

    QObject::connect(ui->comboInput,
                     SIGNAL(currentIndexChanged(int)),
                     this,
                     SLOT(inputChanged(int)));
    QObject::connect(ui->comboOutput,
                     SIGNAL(currentIndexChanged(int)),
                     this,
                     SLOT(outputChanged(int)));
    QObject::connect(ui->comboFitness,
                     SIGNAL(currentIndexChanged(int)),
                     this,
                     SLOT(fitnessChanged(int)));

    QObject::connect(ui->sliderHiddenLayer,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(hiddenLayerChanged(int)));
    QObject::connect(ui->sliderHiddenNeuron,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(hiddenNeuronChanged(int)));
    QObject::connect(ui->sliderBias,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(biasChanged(int)));

    timer_ = new QTimer();
    QObject::connect(timer_, SIGNAL(timeout()), this, SLOT(update()));

    is_running_ = false;
}

MainWindow::~MainWindow()
{
    delete settings_;
    delete manager_;
    delete scene_;
    delete timer_;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QString title = "Neural Network Demonstrator";
    QString description;
    QString info;
    if (is_running_) {
        description = "A simulation is currently underway.";
        info = "Exit either way? (Any changes will not be saved automatically)";
    } else {
        description = "Are you sure you want to close the application?";
        info = "Any changes will not be saved automatically.";
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(description);
    msgBox.setInformativeText(info);
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int choice = msgBox.exec();
    if (choice == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::update()
{
    if (is_running_) {
        target_->update();
        mousePoint_->update();
        manager_->update();

        unsigned int generationCount = manager_->get_generation_count();
        unsigned int iterationCount = manager_->get_iteration_count();
        unsigned int iterationMax = manager_->get_iteration_max();

        ui->labelGenerationProgress->setText(
            "Generation "
            + QString::number(generationCount)
            + " Progress"
        );
        ui->progressBarGeneration->setMaximum(static_cast<int>(iterationMax));
        ui->progressBarGeneration->setValue(static_cast<int>(iterationCount));
    } else {
        timer_->stop();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // TODO
    Q_UNUSED(event) //QString key = (event->text());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint remapped = ui->graphicsView->mapFromParent(event->pos());
    remapped.setY(remapped.y() - 22); // Removes MenuBar height.
    if (ui->graphicsView->rect().contains(remapped)) {
        QPointF source = ui->graphicsView->mapToScene(remapped);

        if (event->button() == Qt::MouseButton::RightButton) {
            mousePoint_->setCoordinates(XY(source.x(),source.y()));
            mousePoint_->setAngle(0);
            mousePoint_->update();
        }

        if (event->button() == Qt::MouseButton::LeftButton) {
            target_->setCourse(XY(source.x(), source.y()));
            target_->update();
        }
    }
}

void MainWindow::setControls()
{
    int input = settings_->get_input_type();
    int output = settings_->get_output_type();
    int fitness = settings_->get_fitness_type();

    int iteration = static_cast<int>(settings_->get_iteration_count());
    int instance = static_cast<int>(settings_->get_instance_count());
    int offspring = static_cast<int>(settings_->get_offspring_count());
    int time = static_cast<int>(settings_->get_time_delta());
    int hiddenLayer = static_cast<int>(settings_->get_hidden_layer_count());
    int hiddenNeuron = static_cast<int>(settings_->get_hidden_neuron_count());
    int initialBias = settings_->get_initial_bias();

    ui->comboInput->setCurrentIndex(input - 1);
    ui->comboOutput->setCurrentIndex(output - 1);
    ui->comboFitness->setCurrentIndex(fitness - 1);

    ui->sliderIteration->setValue(iteration);
    ui->sliderInstance->setValue(instance);
    ui->sliderOffspring->setValue(offspring);
    ui->sliderTime->setValue(time);
    ui->sliderHiddenLayer->setValue(hiddenLayer);
    ui->sliderHiddenNeuron->setValue(hiddenNeuron);
    ui->sliderBias->setValue(initialBias);
    ui->labelInstanceCount->setText(QString::number(instance));
    ui->labelOffspringCount->setText(QString::number(offspring));
    ui->sliderOffspring->setMaximum(instance - 1);
    ui->labelDelta->setText(QString::number(time) + " ms");
    ui->labelHiddenLayerCount->setText(QString::number(hiddenLayer));
    ui->labelHiddenNeuronCount->setText(QString::number(hiddenNeuron));
}

void MainWindow::buttonRunClicked()
{
    if (is_running_) {
        is_running_ = false;

        ui->sliderTime->setDisabled(false);
        ui->sliderInstance->setDisabled(false);
        ui->sliderIteration->setDisabled(false);
        ui->sliderOffspring->setDisabled(false);
        ui->sliderHiddenLayer->setDisabled(false);
        ui->sliderHiddenNeuron->setDisabled(false);
        ui->sliderBias->setDisabled(false);
        ui->buttonReset->setDisabled(false);
        ui->buttonGeneration->setDisabled(true);
        ui->comboInput->setDisabled(false);
        ui->comboOutput->setDisabled(false);
        ui->comboFitness->setDisabled(false);
        ui->buttonRun->setText("Run Simulation");
    } else {
        ui->sliderTime->setDisabled(true);
        ui->sliderInstance->setDisabled(true);
        ui->sliderIteration->setDisabled(true);
        ui->sliderOffspring->setDisabled(true);
        ui->sliderHiddenLayer->setDisabled(true);
        ui->sliderHiddenNeuron->setDisabled(true);
        ui->sliderBias->setDisabled(true);
        ui->buttonReset->setDisabled(true);
        ui->buttonGeneration->setDisabled(false);
        ui->comboInput->setDisabled(true);
        ui->comboOutput->setDisabled(true);
        ui->comboFitness->setDisabled(true);
        ui->buttonRun->setText("Stop Simulation");

        manager_->initialize(target_,
                             nullptr,
                             nullptr,
                             mousePoint_,
                             nullptr);

        scene_->update();
        is_running_ = true;
        timer_->start(static_cast<int>(settings_->get_time_delta()));
    }
}

void MainWindow::buttonResetClicked()
{
    QString title = "Neural Networks Demonstrator";
    QString description = "Are you sure you want to reset to default settings?";
    QString info = "Current settings will not be saved automatically.";
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(description);
    msgBox.setInformativeText(info);
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int choice = msgBox.exec();
    if (choice == QMessageBox::Yes) {
        settings_->use_default_settings();
        setControls();
    }
}

void MainWindow::buttonExitClicked()
{
    this->close();
}

void MainWindow::buttonGenerationClicked()
{
    manager_->skip_generation();
}

void MainWindow::iterationChanged(int change)
{
    settings_->set_iteration_count(static_cast<unsigned>(change));
}

void MainWindow::instanceChanged(int change)
{
    settings_->set_instance_count(static_cast<unsigned>(change));
    ui->labelInstanceCount->setText(QString::number(change));

    int instanceCount = change;
    int offspringCount = ui->sliderOffspring->value();

    ui->sliderOffspring->setMaximum(instanceCount - 1);

    if (instanceCount < offspringCount) {
        ui->sliderOffspring->setValue(instanceCount - 1);
        settings_->set_offspring_count(
                    static_cast<unsigned>(instanceCount) - 1
        );
        ui->labelOffspringCount->setText(
                    QString::number(instanceCount - 1)
        );
    }
}

void MainWindow::offspringChanged(int change)
{
    settings_->set_offspring_count(static_cast<unsigned>(change));
    ui->labelOffspringCount->setText(QString::number(change));
}

void MainWindow::timeChanged(int change)
{
    settings_->set_time_delta(static_cast<unsigned>(change));
    ui->labelDelta->setText(QString::number(change) + " ms");
}

void MainWindow::hiddenLayerChanged(int change)
{
    settings_->set_hidden_layer_count(static_cast<unsigned>(change));
    ui->labelHiddenLayerCount->setText(QString::number(change));
}

void MainWindow::hiddenNeuronChanged(int change)
{
    settings_->set_hidden_neuron_count(static_cast<unsigned>(change));
    ui->labelHiddenNeuronCount->setText(QString::number(change));
}

void MainWindow::biasChanged(int change)
{
    settings_->set_initial_bias(change);
}

void MainWindow::inputChanged(int change)
{
    switch(change) {
    case 0:
        settings_->set_input_type(ANGULAR_DIFFERENCE);
        break;
    case 1:
        settings_->set_input_type(SPACE_TOTAL_DIFFERENCE);
        break;
    case 2:
        settings_->set_input_type(SPACE_AXIS_DIFFERENCE);
        break;
    case 3:
        settings_->set_input_type(WALL_DISTANCES);
        break;
    case 4:
        settings_->set_input_type(FOUR_WAY_SEARCH);
        break;
    case 5:
        settings_->set_input_type(FOUR_CORNER_SEARCH);
        break;
    default:
        settings_->set_input_type(NO_INPUT);
        break;
    }
}

void MainWindow::outputChanged(int change)
{
    switch(change) {
    case 0:
        settings_->set_output_type(ANGULAR_VELOCITY);
        break;
    case 1:
        settings_->set_output_type(DIRECT_ANGLE);
        break;
    case 2:
        settings_->set_output_type(ANGLE_VELOCITY);
        break;
    case 3:
        settings_->set_output_type(ANGLE_ACCELERATION);
        break;
    case 4:
        settings_->set_output_type(AXIS_VELOCITY);
        break;
    case 5:
        settings_->set_output_type(AXIS_ACCELERATION);
        break;
    case 6:
        settings_->set_output_type(SMALL_HOPS);
        break;
    case 7:
        settings_->set_output_type(FIXED_MOVEMENT);
        break;
    default:
        settings_->set_output_type(NO_OUTPUT);
        break;
    }
}

void MainWindow::fitnessChanged(int change)
{
    switch(change) {
    case 0:
        settings_->set_fitness_type(CORRECT_ANGLE);
        break;
    case 1:
        settings_->set_fitness_type(CLOSE_PROXIMITY);
        break;
    case 2:
        settings_->set_fitness_type(FIXED_DISTANCE);
        break;
    case 3:
        settings_->set_fitness_type(NOT_OUT_OF_BOUNDS);
        break;
    case 4:
        settings_->set_fitness_type(LOOK_FROM_DISTANCE);
        break;
    case 5:
        settings_->set_fitness_type(AVOID_EYE_CONTACT);
        break;
    default:
        settings_->set_fitness_type(NO_FITNESS);
        break;
    }
}

void MainWindow::fileLoadScenario()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Scenario"),
                QDir::homePath() + "/desktop",
                tr("Scenario-formatted Text Files (*.txt)")
    );
    qDebug() << filename;
    int outcome = scenario_->load_scenario(filename.toStdString());
    if (outcome > 0) {
        QString title = "Neural Networks Demonstrator";
        QString description;
        QString info;
        switch(outcome) {
        case 1:
            description = "Could not open file.";
            info = "Something prevented the opening of selected file.";
            break;
        case 2:
            description = "Error while reading file.";
            info = "The file in question does not heed the format of the application.";
            break;
        default:
            description = "An unknown error has occurred.";
            info = "Something unexpected happened.";
            break;
        }

        QMessageBox msgBox;
        msgBox.setWindowTitle(title);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(description);
        msgBox.setInformativeText(info);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();

        return;
    }

    scenario_->set_settings(settings_);

    if (sw != nullptr) sw->close();
    if (nw != nullptr) nw->close();

    setControls();
}

void MainWindow::fileSaveScenario()
{
    QString filename = QFileDialog::getSaveFileName(
                this,
                tr("Save Scenario"),
                QDir::homePath() + "/desktop",
                tr("Scenario-formatted Text Files (*.txt)")
    );
    qDebug() << filename;
    scenario_->apply_settings(settings_);
    scenario_->save_scenario(filename.toStdString());
}

void MainWindow::fileExit()
{
    this->close();
}

void MainWindow::editSubjectParameters()
{
    bool open = false;

    if (sw != nullptr) {
        if (!sw->isVisible()) {
            open = true;
        }
    } else {
        open = true;
    }

    if (open) {
        sw = new SubjectWindow();
        sw->show();
    }
}

void MainWindow::editNetworkParameters()
{
    bool open = false;

    if (nw != nullptr) {
        if (!nw->isVisible()) {
            open = true;
        }
    } else {
        open = true;
    }

    if (open) {
        nw = new NetworkWindow();
        nw->show();
    }
}

void MainWindow::helpInstructions()
{
    bool open = false;

    if (in != nullptr) {
        if (!in->isVisible()) {
            open = true;
        }
    } else {
        open = true;
    }

    if (open) {
        in = new Instructions();
        in->show();
    }
}

void MainWindow::helpAbout()
{
    bool open = false;

    if (ab != nullptr) {
        if (!ab->isVisible()) {
            open = true;
        }
    } else {
        open = true;
    }

    if (open) {
        ab = new About();
        ab->show();
    }
}
