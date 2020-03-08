#include "subjectwindow.hh"
#include "ui_subjectwindow.h"

SubjectWindow::SubjectWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectWindow)
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

    settings_ = Settings::get_settings();

    ui->spinVelocityInitial->setValue(settings_->get_velocity_initial());
    ui->spinVelocityChange->setValue(settings_->get_velocity_max_change());
    ui->spinAccelerationInitial->setValue(settings_->get_acceleration_initial());
    ui->spinAccelerationChange->setValue(settings_->get_acceleration_max_change());
    ui->spinAngularInitial->setValue(settings_->get_angular_velocity_initial());
    ui->spinAngularChange->setValue(settings_->get_angular_velocity_max_change());
    ui->spinAxisVelocityInitialX->setValue(settings_->get_axis_velocity_x_initial());
    ui->spinAxisVelocityInitialY->setValue(settings_->get_axis_velocity_y_initial());
    ui->spinAxisVelocityChangeX->setValue(settings_->get_axis_velocity_x_max_change());
    ui->spinAxisVelocityChangeY->setValue(settings_->get_axis_velocity_y_initial());
    ui->spinAxisAccelerationInitialX->setValue(settings_->get_axis_acceleration_x_initial());
    ui->spinAxisAccelerationInitialY->setValue(settings_->get_axis_acceleration_y_initial());
    ui->spinAxisAccelerationChangeX->setValue(settings_->get_axis_acceleration_x_max_change());
    ui->spinAxisAccelerationChangeY->setValue(settings_->get_axis_acceleration_y_max_change());

    switch (settings_->get_spawn_location()) {
    case CENTER:
        ui->radioCenter->setChecked(true);
        break;
    case USER:
        ui->radioUser->setChecked(true);
        break;
    case MOUSE:
        ui->radioMouse->setChecked(true);
        break;
    case RANDOM_POINT:
        ui->radioRandom->setChecked(true);
        break;
    case SCATTERED:
        ui->radioScattered->setChecked(true);
        break;
    case NO_SPAWN_POINT:
        ui->radioCenter->setChecked(true);
        break;
    }
}

SubjectWindow::~SubjectWindow()
{
    delete ui;
}

void SubjectWindow::cancel()
{
    this->close();
}

void SubjectWindow::defaultSettings()
{
    ui->spinVelocityInitial->setValue(20);
    ui->spinVelocityChange->setValue(0);
    ui->spinAccelerationInitial->setValue(0);
    ui->spinAccelerationChange->setValue(0);
    ui->spinAngularInitial->setValue(0);
    ui->spinAngularChange->setValue(0);
    ui->spinAxisVelocityInitialX->setValue(0);
    ui->spinAxisVelocityInitialY->setValue(0);
    ui->spinAxisVelocityChangeX->setValue(0);
    ui->spinAxisVelocityChangeY->setValue(0);
    ui->spinAxisAccelerationInitialX->setValue(0);
    ui->spinAxisAccelerationInitialY->setValue(0);
    ui->spinAxisAccelerationChangeX->setValue(0);
    ui->spinAxisAccelerationChangeY->setValue(0);
    ui->radioCenter->setChecked(true);
}

void SubjectWindow::applyChanges()
{
    settings_->set_velocity_initial(ui->spinVelocityInitial->value());
    settings_->set_velocity_max_change(ui->spinVelocityChange->value());
    settings_->set_acceleration_initial(ui->spinAccelerationInitial->value());
    settings_->set_acceleration_max_change(ui->spinAccelerationChange->value());
    settings_->set_angular_velocity_initial(ui->spinAngularInitial->value());
    settings_->set_angular_velocity_max_change(ui->spinAngularChange->value());
    settings_->set_axis_velocity_x_initial(ui->spinAxisVelocityInitialX->value());
    settings_->set_axis_velocity_y_initial(ui->spinAxisVelocityInitialY->value());
    settings_->set_axis_velocity_x_max_change(ui->spinAxisVelocityChangeX->value());
    settings_->set_axis_velocity_y_initial(ui->spinAxisVelocityChangeY->value());
    settings_->set_axis_acceleration_x_initial(ui->spinAxisAccelerationInitialX->value());
    settings_->set_axis_acceleration_y_initial(ui->spinAxisAccelerationInitialY->value());
    settings_->set_axis_acceleration_x_max_change(ui->spinAxisAccelerationChangeX->value());
    settings_->set_axis_acceleration_y_max_change(ui->spinAxisAccelerationChangeY->value());

    if (ui->radioCenter->isChecked()) {
        settings_->set_spawn_location(CENTER);
    } else if (ui->radioUser->isChecked()) {
        settings_->set_spawn_location(USER);
    } else if (ui->radioMouse->isChecked()) {
        settings_->set_spawn_location(MOUSE);
    } else if (ui->radioRandom->isChecked()) {
        settings_->set_spawn_location(RANDOM_POINT);
    } else if (ui->radioScattered->isChecked()) {
        settings_->set_spawn_location(SCATTERED);
    } else {
        settings_->set_spawn_location(CENTER);
    }

    this->close();
}
