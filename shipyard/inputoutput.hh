#ifndef INPUTOUTPUT_HH
#define INPUTOUTPUT_HH

#include "math.hh"

/*!
 * \namespace Input
 * \brief Collection of input functions for the subjects to use.
 * \author terratenff
 */
namespace Input
{
    /*!
     * \fn angular_difference
     * \brief Creates input layer for the neural network. The input
     * consists of one value, that being the angular difference
     * between subject angle and angle towards the target.
     * \param angle Current angle.
     * \param position Current position.
     * \param target_position Target position.
     * \return Angular difference, reduced to range (0,1). 0 implies
     * equal angles, and 1 implies opposite angles.
     * \post Input vector size should be 1.
     */
    Row angular_difference(double angle,
                           XY position,
                           XY target_position);

    /*!
     * \fn space_scalar_difference
     * \brief Creates input layer for the neural network. The input
     * consists of one value, that being the scalar spatial difference
     * between the subject and the target.
     * \param position Current position.
     * \param target_position Target position.
     * \return Scalar spatial difference, reduced to range (0,1]. 0
     * implies zero distance, and 1 implies a distance of 2000
     * or greater.
     * \post Input vector size should be 1.
     */
    Row space_scalar_difference(XY position,
                                XY target_position);

    /*!
     * \fn space_axis_difference
     * \brief Creates input layer for the neural network. The input
     * consists of two values, those being 2D spatial differences
     * between the subject and the target. The first value is for x-axis,
     * and the second for the y-axis.
     * \param position Current position.
     * \param target_position Target position.
     * \return 2D spatial difference, reduced to range [-1, 1]. -1
     * implies that the target is of distance 1920+ to the left (x),
     * or of distance 1080+ upwards (y). 1 implies that the target is
     * of distance 1920+ to the right (x), or of distance 1080+
     * downwards (y).
     * \post Input vector size should be 2.
     */
    Row space_axis_difference(XY position,
                              XY target_position);

    /*!
     * \fn wall_distances
     * \brief Creates input layer for the neural network. The input
     * consists of four values, those being distances to the four
     * walls that confine the subjects.
     * \param position Current position
     * \return Subject distances to four walls, reduced to range [0,1].
     * 0 implies not being past a wall, but rather, being past some other
     * wall. 1 implies being past a wall (resulting in a 0 on some other
     * value). Reduced distances by order: left, right, up, down.
     * \post Input vector size should be 4.
     */
    Row wall_distances(XY position);

    /*!
     * \fn four_way_search
     * \brief Creates input layer for the neural network. The input
     * consists of four values, those being detections to the target
     * in horizontal + vertical directions.
     * \param position Current position.
     * \param target_position Target position.
     * \return Detection values to the target, as two different possible
     * values: 0 implies no detection, and any number greater than 0
     * implies a detection. Magnitude of the number determines
     * how close the detection is.
     * Directions by order: left, right, up, down.
     * \post Input vector size should be 4.
     */
    Row four_way_search(XY position,
                        XY target_position);

    /*!
     * \fn four_corner_search
     * \brief Creates input layer for the neural network. The input
     * consists of four values, those being detections to the target
     * in the subject's four corners.
     * \param position Current position.
     * \param target_position Target position.
     * \return Detection values to the target, as two different possible
     * values: 0 implies no detection, and any number greater than 0
     * implies a detection. Magnitude of the number determines how
     * close the detection is.
     * Corners by order: top-left, bottom-left, top-right, bottom-right.
     * \post Input vector size should be 4.
     */
    Row four_corner_search(XY position,
                           XY target_position);
}

/*!
 * \namespace Output
 * \brief Collection of output functions for the subject to use.
 * \author terratenff
 */
namespace Output
{
    /*!
     * \fn angular_velocity
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of one value, that being angular velocity.
     * \param outputs Output values from the neural network.
     * \param factor Scale for angular velocity (Maximum Change).
     * \return Angular velocity, scaled by provided factor.
     * \pre Output vector size should be 1.
     * \post Returned vector size should be 1.
     */
    Row angular_velocity(const Row &outputs, double factor);

    /*!
     * \fn direct_angle
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of one value, that being a specific angle.
     * \param outputs Output values from the neural network.
     * \return An angle in degrees, varying in range [0,360].
     * \pre Output vector size should be 1.
     * \post Returned vector size should be 1.
     */
    Row direct_angle(const Row &outputs);

    /*!
     * \fn angle_velocity
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of two values, those being angular velocity
     * and velocity.
     * \param outputs Output values from the neural network.
     * \param factor_angular_velocity Scale for angular velocity
     * (Maximum Change).
     * \param factor_velocity Scale for velocity (Maximum Change).
     * \return Angular velocity and velocity, scaled by provided factors.
     * \pre Output vector size should be 2.
     * \post Returned vector size should be 2.
     */
    Row angle_velocity(const Row &outputs,
                       double factor_angular_velocity,
                       double factor_velocity);

    /*!
     * \fn angle_acceleration
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of two values, those being angular velocity
     * and acceleration.
     * \param outputs Output values from the neural network.
     * \param factor_angular_velocity Scale for angular velocity
     * (Maximum Change).
     * \param factor_acceleration Scale for acceleration
     * (Maximum Change).
     * \return Angular velocity and acceleration, scaled by provided factors.
     * \pre Output vector size should be 2.
     * \post Returned vector size should be 2.
     */
    Row angle_acceleration(const Row &outputs,
                           double factor_angular_velocity,
                           double factor_acceleration);

    /*!
     * \fn axis_velocity
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of two values, those being velocities for
     * axes x and y, respectively.
     * \param outputs Output values from the neural network.
     * \param factor Scale for axis-wise velocities (Maximum Change).
     * \return Axis-wise velocities, scaled by provided factor.
     * \pre Output vector size should be 2.
     * \post Returned vector size should be 2.
     */
    Row axis_velocity(const Row &outputs, XY factor);

    /*!
     * \fn axis_acceleration
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of two values, those being accelerations for
     * axes x and y, respectively.
     * \param outputs Output values from the neural network.
     * \param factor Scale for axis-wise accelerations (Maximum Change).
     * \return Axis-wise accelerations, scaled by provided factor.
     * \pre Output vector size should be 2.
     * \post Returned vector size should be 2.
     */
    Row axis_acceleration(const Row &outputs, XY factor);

    /*!
     * \fn small_hops
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of two values, those being small steps for
     * axes x and y, respectively.
     * \param outputs Output values from the neural network.
     * \return Small hops, unaffected by any factors.
     * \pre Output vector size should be 2.
     * \post Returned vector size should be 2.
     */
    Row small_hops(const Row &outputs);

    /*!
     * \fn fixed_movement
     * \brief Creates outputs from the neural network, for the subject.
     * The output consists of four values, those being both horizontal
     * and vertical directions that the subject is allowed to move in.
     * \param outputs Output values from the neural network.
     * \return Direction, where the subject is allowed to go. The
     * highest-valued output element is selected.
     * \pre Output vector size should be 4.
     * \post Returned vector size should be 4.
     */
    Row fixed_movement(const Row &outputs);
}

#endif // INPUTOUTPUT_HH
