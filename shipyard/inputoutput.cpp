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

Row Input::space_scalar_difference(XY position,
                                   XY target_position)
{
    Row inputs;

    return inputs;
}

Row Input::space_axis_difference(XY position,
                                 XY target_position)
{
    Row inputs;

    return inputs;
}

Row Input::wall_distances(XY position)
{
    Row inputs;

    return inputs;
}

Row Input::four_way_search(XY position,
                           XY target_position)
{
    Row inputs;

    return inputs;
}

Row Output::angular_velocity(const Row &outputs, double factor)
{
    Row outputValues;
    outputValues.push_back(outputs[0] * factor);
    return outputValues;
}

Row Output::direct_angle(const Row &outputs)
{
    Row outputValues;

    return outputValues;
}

Row Output::angle_velocity_acceleration(const Row &outputs,
                                        double factor_angular_velocity,
                                        double factor_velocity,
                                        double factor_acceleration)
{
    Row outputValues;

    return outputValues;
}

Row Output::axis_velocity(const Row &outputs, XY factor)
{
    Row outputValues;

    return outputValues;
}

Row Output::axis_acceleration(const Row &outputs, XY factor)
{
    Row outputValues;

    return outputValues;
}

Row Output::both_axes(const Row &outputs,
                      XY factor_velocity,
                      XY factor_acceleration)
{
    Row outputValues;

    return outputValues;
}

Row Output::small_hops(const Row &outputs)
{
    Row outputValues;

    return outputValues;
}

Row Output::fixed_movement(const Row &outputs)
{
    Row outputValues;

    return outputValues;
}
