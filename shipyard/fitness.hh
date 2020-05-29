#ifndef FITNESS_HH
#define FITNESS_HH

#include "math.hh"

/*!
 * \namespace Fitness
 * \brief Collection of fitness functions that the genetic algorithm
 * can make use of.
 * \author terratenff
 */
namespace Fitness
{
    /*!
     * \fn correct_angle
     * \brief Calculates the fitness value based on provided information.
     * The goal of this fitness function is the locator angle: the closer
     * the angle is pointing at the target, the higher fitness value.
     * \param angle Current directional angle.
     * \param position Current position.
     * \param target Target position.
     * \return Fitness value that varies in the range (0,1). High value
     * is given if current directional angle points towards target,
     * and low value is given if said angle is pointing the other way.
     */
    double correct_angle(double angle, XY position, XY target);

    /*!
     * \fn close_proximity
     * \brief Calculates the fitness value based on provided information.
     * The goal of this fitness function is the proximity between two
     * points. The closer they are, the higher the fitness value.
     * \param position Current position.
     * \param target Target position.
     * \return Fitness value that varies in the range (0,1). High value
     * is given if current position is close to that of target's, and
     * low value is given for faraway positions.
     */
    double close_proximity(XY position, XY target);

    /*!
     * \fn fixed_distance
     * \brief Calculates the fitness value based on provided information.
     * The goal of this fitness function is the proximity between two
     * points. The closer the distance is to a specific value
     * (hard-coded to 500), the higher the fitness value.
     * \param position Current position.
     * \param target Target position.
     * \return Fitness value that varies in the range (0,1). The
     * closer the distance is to 500, the closer the fitness value
     * is to 1. 0 is given if distance is lower than 300 or
     * greater than 700.
     */
    double fixed_distance(XY position, XY target);

    /*!
     * \fn not_out_of_bounds
     * \brief Calculates the fitness value based on provided information.
     * The goal of this fitness function is to keep points in a set area.
     * As long as they remain in said area, their fitness value won't
     * plummet.
     * \param position Current position.
     * \return Fitness value: 1.0 if not out of bounds, -999.0 otherwise.
     */
    double not_out_of_bounds(XY position);

    /*!
     * \fn look_from_distance
     * \brief Calculates the fitness value based on provided information.
     * The goal of this fitness function is to keep distance from the
     * target while maintaining eye contact. As long as distance is
     * maintained as well, fitness increases. Otherwise it decreases.
     * \param angle Current angle.
     * \param position Current position.
     * \param target Target position.
     * \return Fitness value that varies in the range (-1, 1).
     * Fitness value is negative, if distance to target is lower
     * than 500, and positive, if greater than that.
     */
    double look_from_distance(double angle, XY position, XY target);

    /*!
     * \fn avoid_eye_contact
     * \brief Calculates the fitness value based on provided information.
     * The goal of this fitness function is to make sure that the target
     * cannot make eye contact.
     * \param angle Current angle.
     * \param target_angle Target's current angle.
     * \param position Current position.
     * \param target Target position.
     * \return Fitness value that varies in the range (0,1). High value
     * is given if target is looked at while they're looking away, or if
     * target is avoided while they're looking. Low value is given for
     * cases vice versa.
     */
    double avoid_eye_contact(double angle, double target_angle,
                             XY position, XY target);
}

#endif // FITNESS_HH
