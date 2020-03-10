#include "subjectcore.hh"

SubjectCore *SubjectCore::primaryTarget_ = nullptr;
SubjectCore *SubjectCore::secondaryTarget_ = nullptr;
SubjectCore *SubjectCore::tertiaryTarget_ = nullptr;
SubjectCore *SubjectCore::mousePoint_ = nullptr;
SubjectCore *SubjectCore::adversary_ = nullptr;

void SubjectCore::setPublicInstance(SubjectCore *core, int role)
{
    switch(role) {
    case 0: break;
    case 1: primaryTarget_ = core; break;
    case 2: secondaryTarget_ = core; break;
    case 3: tertiaryTarget_ = core; break;
    case 4: mousePoint_ = core; break;
    case 5: adversary_ = core; break;
    default: break;
    }
}

SubjectCore::SubjectCore():
    nn_(nullptr),
    inputs_(Row()),
    outputs_(Row()),
    coordinates_(XY(0,0)),
    axis_velocity_(XY(0,0)),
    axis_acceleration_(XY(0,0)),
    axis_velocity_factor_(XY(0,0)),
    axis_acceleration_factor_(XY(0,0)),
    angle_(0),
    velocity_(0),
    acceleration_(0),
    angular_velocity_(0),
    velocity_factor_(0),
    acceleration_factor_(0),
    angular_velocity_factor_(0)
{
    // TODO
}

SubjectCore::~SubjectCore()
{
    if (nn_ != nullptr) delete nn_;
}

void SubjectCore::update()
{
    if (nn_ == nullptr) return;

    updateMovement();
    makeInputs();

    outputs_ = nn_->feedForward(inputs_);

    applyOutputs();
    updateFitness();
}

void SubjectCore::setNeuralNetwork(NeuralNetwork *nn)
{
    nn_ = nn;
}

NeuralNetwork *SubjectCore::getNeuralNetwork()
{
    return nn_;
}

void SubjectCore::setCoordinates(XY xy)
{
    coordinates_ = xy;
}

void SubjectCore::setAxisVelocity(XY xy)
{
    axis_velocity_ = xy;
}

void SubjectCore::setAxisAcceleration(XY xy)
{
    axis_acceleration_ = xy;
}

void SubjectCore::setVelocity(double var)
{
    velocity_ = var;
}

void SubjectCore::setAcceleration(double var)
{
    acceleration_ = var;
}

void SubjectCore::setAngle(double var)
{
    angle_ = var;
}

void SubjectCore::setAngularVelocity(double var)
{
    angular_velocity_ = var;
}

XY SubjectCore::getCoordinates()
{
    return coordinates_;
}

XY SubjectCore::getAxisVelocity()
{
    return axis_velocity_;
}

XY SubjectCore::getAxisAcceleration()
{
    return axis_acceleration_;
}

double SubjectCore::getVelocity()
{
    return velocity_;
}

double SubjectCore::getAcceleration()
{
    return acceleration_;
}

double SubjectCore::getAngle()
{
    return angle_;
}

double SubjectCore::getAngularVelocity()
{
    return angular_velocity_;
}

void SubjectCore::setAxisVelocityFactor(XY xy)
{
    axis_velocity_factor_ = xy;
}

void SubjectCore::setAxisAccelerationFactor(XY xy)
{
    axis_acceleration_factor_ = xy;
}

void SubjectCore::setVelocityFactor(double var)
{
    velocity_factor_ = var;
}

void SubjectCore::setAccelerationFactor(double var)
{
    acceleration_factor_ = var;
}

void SubjectCore::setAngularVelocityFactor(double var)
{
    angular_velocity_factor_ = var;
}

XY SubjectCore::getAxisVelocityFactor()
{
    return axis_velocity_factor_;
}

XY SubjectCore::getAxisAccelerationFactor()
{
    return axis_acceleration_factor_;
}

double SubjectCore::getVelocityFactor()
{
    return velocity_factor_;
}

double SubjectCore::getAccelerationFactor()
{
    return acceleration_factor_;
}

double SubjectCore::getAngularVelocityFactor()
{
    return angular_velocity_factor_;
}

void SubjectCore::updateMovement()
{
    angle_ += angular_velocity_;
    angle_ = std::remainder(angle_, 360);
    velocity_ += acceleration_;
    XY velocity_components = calculate_components(angle_, abs(velocity_));
    coordinates_ = coordinates_ + velocity_components;

    axis_velocity_ = axis_velocity_ + axis_acceleration_;
    coordinates_ = coordinates_ + axis_velocity_;
}

void SubjectCore::makeInputs()
{
    inputs_.clear();
    if (primaryTarget_ == nullptr) return;
    switch(nn_->getInputCode()) {
    case ANGULAR_DIFFERENCE:
        inputs_ = Input::angular_difference(getAngle(),
                                            getCoordinates(),
                                            primaryTarget_->getCoordinates());
        break;
    case SPACE_TOTAL_DIFFERENCE:
        break;
    case SPACE_AXIS_DIFFERENCE:
        break;
    case WALL_DISTANCES:
        break;
    case FOUR_WAY_SEARCH:
        break;
    case NO_INPUT:
        break;
    }
}

void SubjectCore::applyOutputs()
{
    Row outputValues;

    switch(nn_->getOutputCode()) {
    case ANGULAR_VELOCITY:
        if (outputs_.size() != 1) return;
        outputValues = Output::angular_velocity(outputs_);
        if (outputValues.size() != 1) return;
        setAngularVelocity(outputValues[0] * angular_velocity_factor_);
        break;
    case AXIS_VELOCITY:
        break;
    case AXIS_ACCELERATION:
        break;
    case SMALL_HOPS:
        break;
    case FIXED_MOVEMENT:
        break;
    case NO_OUTPUT:
        break;
    }
}

void SubjectCore::updateFitness()
{
    double fitnessValue = 0;

    switch(nn_->getFitnessCode()) {
    case CORRECT_ANGLE:
        //if (inputs_.size() != 1) return;
        //fitnessValue = 1 - inputs_[0];
        fitnessValue = Fitness::correct_angle(
            getAngle(),
            getCoordinates(),
            primaryTarget_->getCoordinates()
        );
        break;
    case CLOSE_PROXIMITY:
        fitnessValue = Fitness::close_proximity(
            getCoordinates(),
            primaryTarget_->getCoordinates()
        );
        break;
    case FIXED_DISTANCE:
        break;
    case NOT_OUT_OF_BOUNDS:
        break;
    case LOOK_FROM_DISTANCE:
        break;
    case AVOID_EYE_CONTACT:
        break;
    case NO_FITNESS:
        break;
    }

    nn_->addFitness(fitnessValue);
}
