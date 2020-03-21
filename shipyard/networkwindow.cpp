#include "networkwindow.hh"
#include "ui_networkwindow.h"

NetworkWindow::NetworkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetworkWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonCancel,
                     SIGNAL(clicked()),
                     this,
                     SLOT(cancel()));
    QObject::connect(ui->buttonDefault,
                     SIGNAL(clicked()),
                     this,
                     SLOT(defaultSettings()));
    QObject::connect(ui->buttonOK,
                     SIGNAL(clicked()),
                     this,
                     SLOT(applyChanges()));

    QObject::connect(ui->sliderInitialWeightMin,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(initialWeightMinChanged(int)));
    QObject::connect(ui->sliderInitialWeightMax,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(initialWeightMaxChanged(int)));
    QObject::connect(ui->sliderPopulationRetentionRate,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(populationRetentionRateChanged(int)));
    QObject::connect(ui->sliderMutationProbability,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(mutationProbabilityChanged(int)));
    QObject::connect(ui->sliderMutationScaleMin,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(mutationScaleMinChanged(int)));
    QObject::connect(ui->sliderMutationScaleMax,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(mutationScaleMaxChanged(int)));

    settings_ = Settings::get_settings();

    ui->sliderInitialWeightMin->setValue(
                static_cast<int>(settings_->get_initial_weight_minimum() * FACTOR_));
    ui->sliderInitialWeightMax->setValue(
                static_cast<int>(settings_->get_initial_weight_maximum() * FACTOR_));

    ui->comboActivationFunctionHidden->addItem("Sigmoid");
    ui->comboActivationFunctionHidden->addItem("(WIP) Hyperbolic Tangent");
    ui->comboActivationFunctionHidden->addItem("(WIP) Sign");
    ui->comboActivationFunctionHidden->addItem("(WIP) Heaviside");
    ui->comboActivationFunctionHidden->addItem("(WIP) ReLU");
    ui->comboActivationFunctionHidden->addItem("(WIP) Leaky ReLU");
    ui->comboActivationFunctionHidden->addItem("(WIP) Gaussian");
    ui->comboActivationFunctionHidden->addItem("(WIP) Softmax (*)");

    ui->comboActivationFunctionOutput->addItem("Sigmoid");
    ui->comboActivationFunctionOutput->addItem("(WIP) Hyperbolic Tangent");
    ui->comboActivationFunctionOutput->addItem("(WIP) Sign");
    ui->comboActivationFunctionOutput->addItem("(WIP) Heaviside");
    ui->comboActivationFunctionOutput->addItem("(WIP) ReLU");
    ui->comboActivationFunctionOutput->addItem("(WIP) Leaky ReLU");
    ui->comboActivationFunctionOutput->addItem("(WIP) Gaussian");
    ui->comboActivationFunctionOutput->addItem("(WIP) Softmax");

    switch(settings_->get_activation_function_hidden()) {
    case SIGMOID:
        ui->comboActivationFunctionHidden->setCurrentIndex(0);
        break;
    case HYPERBOLIC_TANGENT:
        ui->comboActivationFunctionHidden->setCurrentIndex(1);
        break;
    case SIGN:
        ui->comboActivationFunctionHidden->setCurrentIndex(2);
        break;
    case HEAVISIDE:
        ui->comboActivationFunctionHidden->setCurrentIndex(3);
        break;
    case RELU:
        ui->comboActivationFunctionHidden->setCurrentIndex(4);
        break;
    case RELU_LEAKY:
        ui->comboActivationFunctionHidden->setCurrentIndex(5);
        break;
    case GAUSSIAN:
        ui->comboActivationFunctionHidden->setCurrentIndex(6);
        break;
    case SOFTMAX:
        ui->comboActivationFunctionHidden->setCurrentIndex(7);
        break;
    case NO_ACTIVATION:
        ui->comboActivationFunctionHidden->setCurrentIndex(0);
        break;
    }

    switch(settings_->get_activation_function_output()) {
    case SIGMOID:
        ui->comboActivationFunctionOutput->setCurrentIndex(0);
        break;
    case HYPERBOLIC_TANGENT:
        ui->comboActivationFunctionOutput->setCurrentIndex(1);
        break;
    case SIGN:
        ui->comboActivationFunctionOutput->setCurrentIndex(2);
        break;
    case HEAVISIDE:
        ui->comboActivationFunctionOutput->setCurrentIndex(3);
        break;
    case RELU:
        ui->comboActivationFunctionOutput->setCurrentIndex(4);
        break;
    case RELU_LEAKY:
        ui->comboActivationFunctionOutput->setCurrentIndex(5);
        break;
    case GAUSSIAN:
        ui->comboActivationFunctionOutput->setCurrentIndex(6);
        break;
    case SOFTMAX:
        ui->comboActivationFunctionOutput->setCurrentIndex(7);
        break;
    case NO_ACTIVATION:
        ui->comboActivationFunctionOutput->setCurrentIndex(0);
        break;
    }

    ui->comboBreedingMethod->addItem("Copy");
    ui->comboBreedingMethod->addItem("(WIP) Heavily Mutated Copy");
    ui->comboBreedingMethod->addItem("(WIP) Child of Two");
    ui->comboBreedingMethod->addItem("(WIP) Child of Three");

    switch(settings_->get_breeding_method()) {
    case COPY:
        ui->comboBreedingMethod->setCurrentIndex(0);
        break;
    case HEAVILY_MUTATED_COPY:
        ui->comboBreedingMethod->setCurrentIndex(1);
        break;
    case CHILD_OF_TWO:
        ui->comboBreedingMethod->setCurrentIndex(2);
        break;
    case CHILD_OF_THREE:
        ui->comboBreedingMethod->setCurrentIndex(3);
        break;
    case NO_BREEDING:
        ui->comboBreedingMethod->setCurrentIndex(0);
        break;
    }

    ui->sliderPopulationRetentionRate->setValue(
                settings_->get_population_retention_rate());
    ui->sliderMutationProbability->setValue(
                settings_->get_mutation_probability());

    ui->sliderMutationScaleMin->setValue(
                static_cast<int>(settings_->get_mutation_scale_minimum() * FACTOR_));
    ui->sliderMutationScaleMax->setValue(
                static_cast<int>(settings_->get_mutation_scale_maximum() * FACTOR_));

    ui->labelInitialWeightMinValue->setText(
                QString::number(settings_->get_initial_weight_minimum()));
    ui->labelInitialWeightMaxValue->setText(
                QString::number(settings_->get_initial_weight_maximum()));
    ui->labelPopulationRetentionRateValue->setText(
                QString::number(settings_->get_population_retention_rate()) + " %");
    ui->labelMutationProbabilityValue->setText(
                QString::number(settings_->get_mutation_probability()) + " %");
    ui->labelMutationScaleMinValue->setText(
                QString::number(settings_->get_mutation_scale_minimum()));
    ui->labelMutationScaleMaxValue->setText(
                QString::number(settings_->get_mutation_scale_maximum()));
}

NetworkWindow::~NetworkWindow()
{
    delete ui;
}

void NetworkWindow::cancel()
{
    this->close();
}

void NetworkWindow::defaultSettings()
{
    ui->sliderInitialWeightMin->setValue(-500);
    ui->sliderInitialWeightMax->setValue(500);
    ui->comboActivationFunctionHidden->setCurrentIndex(0);
    ui->comboActivationFunctionOutput->setCurrentIndex(0);
    ui->comboBreedingMethod->setCurrentIndex(0);
    ui->sliderPopulationRetentionRate->setValue(10);
    ui->sliderMutationProbability->setValue(10);
    ui->sliderMutationScaleMin->setValue(1000);
    ui->sliderMutationScaleMax->setValue(2000);
}

void NetworkWindow::applyChanges()
{
    settings_->set_initial_weight_minimum(
                ui->sliderInitialWeightMin->value() / FACTOR_);
    settings_->set_initial_weight_maximum(
                ui->sliderInitialWeightMax->value() / FACTOR_);
    settings_->set_population_retention_rate(
                ui->sliderPopulationRetentionRate->value());
    settings_->set_mutation_probability(
                ui->sliderMutationProbability->value());
    settings_->set_mutation_scale_minimum(
                ui->sliderMutationScaleMin->value() / FACTOR_);
    settings_->set_mutation_scale_maximum(
                ui->sliderMutationScaleMax->value() / FACTOR_);

    activation_type activation_function_hidden;
    switch(ui->comboActivationFunctionHidden->currentIndex()) {
    case 0:
        activation_function_hidden = SIGMOID;
        break;
    case 1:
        activation_function_hidden = HYPERBOLIC_TANGENT;
        break;
    case 2:
        activation_function_hidden = SIGN;
        break;
    case 3:
        activation_function_hidden = HEAVISIDE;
        break;
    case 4:
        activation_function_hidden = RELU;
        break;
    case 5:
        activation_function_hidden = RELU_LEAKY;
        break;
    case 6:
        activation_function_hidden = GAUSSIAN;
        break;
    case 7:
        activation_function_hidden = SOFTMAX;
        break;
    default:
        activation_function_hidden = SIGMOID;
        break;
    }
    settings_->set_activation_function_hidden(activation_function_hidden);

    activation_type activation_function_output;
    switch(ui->comboActivationFunctionOutput->currentIndex()) {
    case 0:
        activation_function_output = SIGMOID;
        break;
    case 1:
        activation_function_output = HYPERBOLIC_TANGENT;
        break;
    case 2:
        activation_function_output = SIGN;
        break;
    case 3:
        activation_function_output = HEAVISIDE;
        break;
    case 4:
        activation_function_output = RELU;
        break;
    case 5:
        activation_function_output = RELU_LEAKY;
        break;
    case 6:
        activation_function_output = GAUSSIAN;
        break;
    case 7:
        activation_function_output = SOFTMAX;
        break;
    default:
        activation_function_output = SIGMOID;
        break;
    }
    settings_->set_activation_function_output(activation_function_output);

    breeding_type breeding_action;
    switch(ui->comboBreedingMethod->currentIndex()) {
    case 0:
        breeding_action = COPY;
        break;
    case 1:
        breeding_action = HEAVILY_MUTATED_COPY;
        break;
    case 2:
        breeding_action = CHILD_OF_TWO;
        break;
    case 3:
        breeding_action = CHILD_OF_THREE;
        break;
    default:
        breeding_action = COPY;
        break;
    }
    settings_->set_breeding_method(breeding_action);

    this->close();
}

void NetworkWindow::initialWeightMinChanged(int change)
{
    ui->labelInitialWeightMinValue->setText(
                QString::number(
                    static_cast<double>(change / FACTOR_)));
    if (ui->sliderInitialWeightMax->value()
            < ui->sliderInitialWeightMin->value()) {
        ui->sliderInitialWeightMax->setValue(
                    ui->sliderInitialWeightMin->value());
    }
}

void NetworkWindow::initialWeightMaxChanged(int change)
{
    ui->labelInitialWeightMaxValue->setText(
                QString::number(
                    static_cast<double>(change / FACTOR_)));
    if (ui->sliderInitialWeightMin->value()
            > ui->sliderInitialWeightMax->value()) {
        ui->sliderInitialWeightMin->setValue(
                    ui->sliderInitialWeightMax->value());
    }
}

void NetworkWindow::populationRetentionRateChanged(int change)
{
    ui->labelPopulationRetentionRateValue->setText(
                QString::number(change) + " %");
}

void NetworkWindow::mutationProbabilityChanged(int change)
{
    ui->labelMutationProbabilityValue->setText(
                QString::number(change) + " %");
}

void NetworkWindow::mutationScaleMinChanged(int change)
{
    ui->labelMutationScaleMinValue->setText(
                QString::number(
                    static_cast<double>(change / FACTOR_)));
    if (ui->sliderMutationScaleMax->value()
            < ui->sliderMutationScaleMin->value()) {
        ui->sliderMutationScaleMax->setValue(
                    ui->sliderMutationScaleMin->value());
    }
}

void NetworkWindow::mutationScaleMaxChanged(int change)
{
    ui->labelMutationScaleMaxValue->setText(
                QString::number(
                    static_cast<double>(change / FACTOR_)));
    if (ui->sliderMutationScaleMin->value()
            > ui->sliderMutationScaleMax->value()) {
        ui->sliderMutationScaleMin->setValue(
                    ui->sliderMutationScaleMax->value());
    }
}
