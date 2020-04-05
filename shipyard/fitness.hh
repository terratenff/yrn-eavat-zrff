#ifndef FITNESS_HH
#define FITNESS_HH

#include "math.hh"

namespace Fitness
{
    double correct_angle(double angle, XY position, XY target);

    double close_proximity(XY position, XY target);

    double fixed_distance(XY position, XY target);

    double not_out_of_bounds(XY position);

    double look_from_distance(double angle, XY position, XY target);

    double avoid_eye_contact(double angle, double target_angle,
                             XY position, XY target);
}

#endif // FITNESS_HH
