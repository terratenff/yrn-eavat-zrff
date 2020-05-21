#ifndef SUBJECTCORE_HH
#define SUBJECTCORE_HH

#include "settings.hh"
#include "neuralnetwork.hh"
#include "fitness.hh"
#include "inputoutput.hh"

/*!
 * \class SubjectCore
 * \brief Data implementation of the subjects.
 * \author terratenff
 */
class SubjectCore
{
public:

    /*!
     * \fn setPublicInstance
     * \brief Setter for one of the 5 public instances that are
     * treated as exceptions.
     * \param core Target core of the subject.
     * \param role Integer code for the role. These codes
     * refer to the target types (see "target.hh").
     */
    static void setPublicInstance(SubjectCore *core, int role);

    /*!
     * \brief SubjectCore Constructor.
     */
    SubjectCore();

    /*!
     * \brief ~SubjectCore Destructor.
     */
    virtual ~SubjectCore() = 0;

    /*!
     * \fn update
     * \brief Updates the state of the subject. This function,
     * in particular, updates the core of the subject.
     */
    virtual void update();

    /*!
     * \fn setNeuralNetwork
     * \brief Setter for the neural network that the subject
     * is going to use.
     * \param nn Target neural network.
     */
    void setNeuralNetwork(NeuralNetwork *nn);

    /*!
     * \fn getNeuralNetwork
     * \brief Getter for the neural network that the subject
     * uses.
     * \return Used neural network.
     */
    NeuralNetwork *getNeuralNetwork();

    /*!
     * \fn setCoordinates
     * \brief Moves subject to specified location in 2D space.
     * \param xy Coordinates in 2D space.
     */
    void setCoordinates(XY xy);

    /*!
     * \fn setAxisVelocity
     * \brief Setter for subject's axis-wise velocities.
     * These are separate from velocity.
     * \param xy Axis-wise velocities.
     */
    void setAxisVelocity(XY xy);

    /*!
     * \fn setAxisAcceleration
     * \brief Setter for subject's axis-wise accelerations.
     * These are separate from acceleration.
     * \param xy Axis-wise accelerations.
     */
    void setAxisAcceleration(XY xy);

    /*!
     * \fn setVelocity
     * \brief Setter for the subject's primary velocity.
     * \param var Target velocity.
     */
    void setVelocity(double var);

    /*!
     * \fn setAcceleration
     * \brief Setter for the subject's primary acceleration.
     * \param var Target acceleration.
     */
    void setAcceleration(double var);

    /*!
     * \fn setAngle
     * \brief Points the subject in specified direction.
     * \param var Target angle in degrees. If given angle
     * is outside the range (-360, 360), then the remainder
     * of the angle is taken (for example, 450 results in 90).
     */
    void setAngle(double var);

    /*!
     * \fn setAngularVelocity
     * \brief Sets subject's angular velocity. Once subject movement
     * is to be updated, current angle is increased by current
     * angular velocity.
     * \param var Target angular velocity in degrees.
     */
    void setAngularVelocity(double var);

    /*!
     * \fn getCoordinates
     * \brief Getter for subject's current coordinates.
     * \return Current subject coordinates in 2D space.
     */
    XY getCoordinates();

    /*!
     * \fn getAxisVelocity
     * \brief Getter for subject's axis-wise velocities.
     * These are separate from velocity.
     * \return Subject's axis-wise velocities.
     */
    XY getAxisVelocity();

    /*!
     * \fn getAxisAcceleration
     * \brief Getter for subject's axis-wise accelerations.
     * These are separate from acceleration.
     * \return Subject's axis-wise accelerations.
     */
    XY getAxisAcceleration();

    /*!
     * \fn getVelocity
     * \brief Getter for subject's primary velocity.
     * \return Subject's velocity.
     */
    double getVelocity();

    /*!
     * \fn getAcceleration
     * \brief Getter for subject's primary acceleration.
     * \return Subject's acceleration.
     */
    double getAcceleration();

    /*!
     * \fn getAngle
     * \brief Getter for subject's current angle.
     * \return Subject's current angle in degrees.
     */
    double getAngle();

    /*!
     * \fn getAngularVelocity
     * \brief Getter for subject's current angular velocity.
     * \return Subject's angular velocity in degrees.
     */
    double getAngularVelocity();

    /*!
     * \fn setAxisVelocityFactor
     * \brief Setter for axis-wise velocity factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \param xy Target axis-wise velocity factor.
     */
    void setAxisVelocityFactor(XY xy);

    /*!
     * \fn setAxisAccelerationFactor
     * \brief Setter for axis-wise acceleration factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \param xy Target axis-wise acceleration factor.
     */
    void setAxisAccelerationFactor(XY xy);

    /*!
     * \fn setVelocityFactor
     * \brief Setter for primary velocity factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \param var Target velocity factor.
     */
    void setVelocityFactor(double var);

    /*!
     * \fn setAccelerationFactor
     * \brief Setter for primary acceleration factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \param var Target acceleration factor.
     */
    void setAccelerationFactor(double var);

    /*!
     * \fn setAngularVelocityFactor
     * \brief Setter for angular velocity factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \param var Target angular velocity factor.
     */
    void setAngularVelocityFactor(double var);

    /*!
     * \fn getAxisVelocityFactor
     * \brief Getter for axis-wise velocity factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \return Axis-wise velocity factor.
     */
    XY getAxisVelocityFactor();

    /*!
     * \fn getAxisAccelerationFactor
     * \brief Getter for axis-wise acceleration factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \return Axis-wise acceleration factor.
     */
    XY getAxisAccelerationFactor();

    /*!
     * \fn getVelocityFactor
     * \brief Getter for primary velocity factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \return Velocity factor.
     */
    double getVelocityFactor();

    /*!
     * \fn getAccelerationFactor
     * \brief Getter for primary acceleration factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \return Acceleration factor.
     */
    double getAccelerationFactor();

    /*!
     * \fn getAngularVelocityFactor
     * \brief Getter for angular velocity factor.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     *
     * \return Angular velocity factor.
     */
    double getAngularVelocityFactor();
private:

    /*!
     * \var primaryTarget_
     * \brief Exception subject 1 of 5. This subject is
     * to be controlled by the user.
     */
    static SubjectCore *primaryTarget_;

    /*!
     * \var secondaryTarget_
     * \brief Exception subject 2 of 5. Currently, this
     * subject has not yet been implemented.
     */
    static SubjectCore *secondaryTarget_;

    /*!
     * \var tertiaryTarget_
     * \brief Exception subject 3 of 5. Currently, this
     * subject has not yet been implemented.
     */
    static SubjectCore *tertiaryTarget_;

    /*!
     * \var mousePoint_
     * \brief Exception subject 4 of 5. This subject
     * acts as a waypoint for some functions, aimed to be
     * created by right-clicking the simulation area.
     */
    static SubjectCore *mousePoint_;

    /*!
     * \var adversary_
     * \brief Exception subject 5 of 5. Currently, this
     * subject has not yet been implmented.
     */
    static SubjectCore *adversary_;

    /*!
     * \var nn_
     * \brief The neural network that the subject is going
     * to use during the simulations.
     */
    NeuralNetwork *nn_;

    /*!
     * \var inputs_
     * \brief Row of inputs that the subject creates for its
     * neural network to process.
     */
    Row inputs_;

    /*!
     * \var outputs_
     * \brief Row of outputs that the subject's neural network creates
     * for the subject to process.
     */
    Row outputs_;

    /*!
     * \var coordinates_
     * \brief Current location of the subject, as coordinates
     * in 2D space.
     */
    XY coordinates_;

    /*!
     * \var axis_velocity_
     * \brief Current axis-wise velocities of the subject in 2D space.
     * These are separate from velocity.
     */
    XY axis_velocity_;

    /*!
     * \var axis_acceleration_
     * \brief Current axis-wise accelerations of the subject in 2D space.
     * These are separate from acceleration.
     */
    XY axis_acceleration_;

    /*!
     * \var axis_velocity_factor_
     * \brief Factor for axis-wise velocities.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     */
    XY axis_velocity_factor_;

    /*!
     * \var axis_acceleration_factor_
     * \brief Factor value for axis-wise accelerations.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     */
    XY axis_acceleration_factor_;

    /*!
     * \var angle_
     * \brief Current angle, in degrees.
     */
    double angle_;

    /*!
     * \var velocity_
     * \brief Current velocity.
     */
    double velocity_;

    /*!
     * \var acceleration_
     * \brief Current acceleration.
     */
    double acceleration_;

    /*!
     * \var angular_velocity_
     * \brief Current angular velocity, in degrees per iteration.
     */
    double angular_velocity_;

    /*!
     * \var velocity_factor_
     * \brief Factor value for velocity.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     */
    double velocity_factor_;

    /*!
     * \var acceleration_factor_
     * \brief Factor value for acceleration.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     */
    double acceleration_factor_;

    /*!
     * \var angular_velocity_factor_
     * \brief Factor value for angular velocity.
     *
     * Variable Factor represents highest possible value that
     * a subject could get from a neural network.
     */
    double angular_velocity_factor_;

    /*!
     * \fn updateMovement
     * \brief Updates subject movement: current angle, velocity
     * and position.
     */
    void updateMovement();

    /*!
     * \fn makeInputs
     * \brief Creates suitable inputs for the subject's neural network
     * to process.
     */
    void makeInputs();

    /*!
     * \fn applyOutputs
     * \brief Modifies the state of the subject, based on the outputs
     * that its neural network has provided.
     */
    void applyOutputs();

    /*!
     * \fn updateFitness
     * \brief Modifies subject's (neural network's) fitness value,
     * based on a fitness function specified for the neural network.
     */
    void updateFitness();
};

#endif // SUBJECTCORE_HH
