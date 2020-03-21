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

    ui->spinVelocityInitial->setValue(
                static_cast<int>(settings_->get_velocity_initial() * FACTOR_));
    ui->spinVelocityChange->setValue(
                static_cast<int>(settings_->get_velocity_max_change() * FACTOR_));
    ui->spinAccelerationInitial->setValue(
                static_cast<int>(settings_->get_acceleration_initial() * FACTOR_));
    ui->spinAccelerationChange->setValue(
                static_cast<int>(settings_->get_acceleration_max_change() * FACTOR_));
    ui->spinAngularInitial->setValue(
                static_cast<int>(settings_->get_angular_velocity_initial() * FACTOR_));
    ui->spinAngularChange->setValue(
                static_cast<int>(settings_->get_angular_velocity_max_change() * FACTOR_));
    ui->spinAxisVelocityInitialX->setValue(
                static_cast<int>(settings_->get_axis_velocity_x_initial() * FACTOR_));
    ui->spinAxisVelocityInitialY->setValue(
                static_cast<int>(settings_->get_axis_velocity_y_initial() * FACTOR_));
    ui->spinAxisVelocityChangeX->setValue(
                static_cast<int>(settings_->get_axis_velocity_x_max_change() * FACTOR_));
    ui->spinAxisVelocityChangeY->setValue(
                static_cast<int>(settings_->get_axis_velocity_y_max_change() * FACTOR_));
    ui->spinAxisAccelerationInitialX->setValue(
                static_cast<int>(settings_->get_axis_acceleration_x_initial() * FACTOR_));
    ui->spinAxisAccelerationInitialY->setValue(
                static_cast<int>(settings_->get_axis_acceleration_y_initial() * FACTOR_));
    ui->spinAxisAccelerationChangeX->setValue(
                static_cast<int>(settings_->get_axis_acceleration_x_max_change() * FACTOR_));
    ui->spinAxisAccelerationChangeY->setValue(
                static_cast<int>(settings_->get_axis_acceleration_y_max_change() * FACTOR_));

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
    ui->spinVelocityInitial->setValue(5000);
    ui->spinVelocityChange->setValue(1000);
    ui->spinAccelerationInitial->setValue(0);
    ui->spinAccelerationChange->setValue(1000);
    ui->spinAngularInitial->setValue(0);
    ui->spinAngularChange->setValue(1000);
    ui->spinAxisVelocityInitialX->setValue(0);
    ui->spinAxisVelocityInitialY->setValue(0);
    ui->spinAxisVelocityChangeX->setValue(1000);
    ui->spinAxisVelocityChangeY->setValue(1000);
    ui->spinAxisAccelerationInitialX->setValue(0);
    ui->spinAxisAccelerationInitialY->setValue(0);
    ui->spinAxisAccelerationChangeX->setValue(1000);
    ui->spinAxisAccelerationChangeY->setValue(1000);
    ui->radioCenter->setChecked(true);
}

void SubjectWindow::applyChanges()
{
    settings_->set_velocity_initial(
                ui->spinVelocityInitial->value() / FACTOR_);
    settings_->set_velocity_max_change(
                ui->spinVelocityChange->value() / FACTOR_);
    settings_->set_acceleration_initial(
                ui->spinAccelerationInitial->value() / FACTOR_);
    settings_->set_acceleration_max_change(
                ui->spinAccelerationChange->value() / FACTOR_);
    settings_->set_angular_velocity_initial(
                ui->spinAngularInitial->value() / FACTOR_);
    settings_->set_angular_velocity_max_change(
                ui->spinAngularChange->value() / FACTOR_);
    settings_->set_axis_velocity_x_initial(
                ui->spinAxisVelocityInitialX->value() / FACTOR_);
    settings_->set_axis_velocity_y_initial(
                ui->spinAxisVelocityInitialY->value() / FACTOR_);
    settings_->set_axis_velocity_x_max_change(
                ui->spinAxisVelocityChangeX->value() / FACTOR_);
    settings_->set_axis_velocity_y_max_change(
                ui->spinAxisVelocityChangeY->value() / FACTOR_);
    settings_->set_axis_acceleration_x_initial(
                ui->spinAxisAccelerationInitialX->value() / FACTOR_);
    settings_->set_axis_acceleration_y_initial(
                ui->spinAxisAccelerationInitialY->value() / FACTOR_);
    settings_->set_axis_acceleration_x_max_change(
                ui->spinAxisAccelerationChangeX->value() / FACTOR_);
    settings_->set_axis_acceleration_y_max_change(
                ui->spinAxisAccelerationChangeY->value() / FACTOR_);

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
