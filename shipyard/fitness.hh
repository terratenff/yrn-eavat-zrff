#ifndef FITNESS_HH
#define FITNESS_HH

#include "math.hh"

namespace Fitness
{
    double correct_angle(double angle, XY position, XY target);
    double close_proximity(XY position, XY target);
}

#endif // FITNESS_HH
