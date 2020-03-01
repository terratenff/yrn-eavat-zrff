#include "inputoutput.hh"


Row Input::angular_difference(double angle,
                              XY position,
                              XY target_position)
{
    Row inputs;

    double target_angle = calculate_angle(position, target_position);
    double semiInput = abs(angle - target_angle);
    if (semiInput > 180) {
        semiInput = abs(semiInput - 360);
    }
    semiInput = semiInput / 180;

    // Input Size: 1
    // Input range: (0,1)
    inputs.push_back(semiInput);

    return inputs;
}

Row Output::angular_velocity(const Row &outputs)
{
    Row outputValues;
    outputValues.push_back(20 * outputs[0]);
    return outputValues;
}
