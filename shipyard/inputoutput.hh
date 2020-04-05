#ifndef INPUTOUTPUT_HH
#define INPUTOUTPUT_HH

#include "math.hh"

namespace Input
{
    Row angular_difference(double angle,
                           XY position,
                           XY target_position);

    Row space_scalar_difference(XY position,
                                XY target_position);

    Row space_axis_difference(XY position,
                              XY target_position);

    Row wall_distances(XY position);

    Row four_way_search(XY position,
                        XY target_position);
}

namespace Output
{
    Row angular_velocity(const Row &outputs, double factor);

    Row direct_angle(const Row &outputs);

    Row angle_velocity(const Row &outputs,
                       double factor_angular_velocity,
                       double factor_velocity);

    Row angle_acceleration(const Row &outputs,
                           double factor_angular_velocity,
                           double factor_acceleration);

    Row axis_velocity(const Row &outputs, XY factor);

    Row axis_acceleration(const Row &outputs, XY factor);

    Row small_hops(const Row &outputs);

    Row fixed_movement(const Row &outputs);
}

#endif // INPUTOUTPUT_HH
