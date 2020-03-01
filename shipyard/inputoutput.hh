#ifndef INPUTOUTPUT_HH
#define INPUTOUTPUT_HH

#include "math.hh"

namespace Input
{
    Row angular_difference(double angle,
                           XY position,
                           XY target_position);
}

namespace Output
{
    Row angular_velocity(const Row &outputs);
}

#endif // INPUTOUTPUT_HH
