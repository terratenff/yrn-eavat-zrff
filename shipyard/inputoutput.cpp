#include "inputoutput.hh"
#include <algorithm>


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

    inputs.push_back(semiInput);

    return inputs;
}

Row Input::space_scalar_difference(XY position,
                                   XY target_position)
{
    Row inputs;
    double difference = distance(position, target_position);
    double scaled_difference = min(1.0, difference / 500.0);
    double semiInput = scaled_difference;

    inputs.push_back(semiInput);
    return inputs;
}

Row Input::space_axis_difference(XY position,
                                 XY target_position)
{
    Row inputs;
    XY difference = target_position - position;
    XY scaled_difference(difference.x / 1920.0, difference.y / 1080.0);
    if (scaled_difference.x < -1.0) scaled_difference.x = -1.0;
    if (scaled_difference.y < -1.0) scaled_difference.y = -1.0;
    if (scaled_difference.x > 1.0) scaled_difference.x = 1.0;
    if (scaled_difference.y > 1.0) scaled_difference.y = 1.0;

    inputs.push_back(scaled_difference.x);
    inputs.push_back(scaled_difference.y);
    return inputs;
}

Row Input::wall_distances(XY position)
{
    Row inputs;
    double left = (1920.0 - position.x) / 1920.0;
    double right = position.x / 1920.0;
    double up = (1080.0 - position.y) / 1080.0;
    double down = position.y / 1080.0;
    if (left > 1.0) left = 1.0;
    if (right > 1.0) right = 1.0;
    if (up > 1.0) up = 1.0;
    if (down > 1.0) down = 1.0;
    if (left < 0.0) left = 0.0;
    if (right < 0.0) right = 0.0;
    if (up < 0.0) up = 0.0;
    if (down < 0.0) down = 0.0;

    inputs.push_back(left);
    inputs.push_back(right);
    inputs.push_back(up);
    inputs.push_back(down);
    return inputs;
}

Row Input::four_way_search(XY position,
                           XY target_position)
{
    Row inputs;
    bool left = near_double(position.y, target_position.y, 30)
            && position.x >= target_position.x;
    bool right = near_double(position.y, target_position.y, 30)
            && position.x < target_position.x;
    bool up = near_double(position.x, target_position.x, 30)
            && position.y >= target_position.y;
    bool down = near_double(position.x, target_position.x, 30)
            && position.y < target_position.y;

    if (left)  inputs.push_back(1.0);
    else       inputs.push_back(0.0);
    if (right) inputs.push_back(1.0);
    else       inputs.push_back(0.0);
    if (up)    inputs.push_back(1.0);
    else       inputs.push_back(0.0);
    if (down)  inputs.push_back(1.0);
    else       inputs.push_back(0.0);
    return inputs;
}

Row Input::four_corner_search(XY position, XY target_position)
{
    Row inputs;

    XY difference = target_position - position;
    inputs.push_back(0.0);
    inputs.push_back(0.0);
    inputs.push_back(0.0);
    inputs.push_back(0.0);
    bool left = difference.x < 0.0;
    bool right = difference.x > 0.0;
    bool up = difference.y < 0.0;
    bool down = difference.y > 0.0;
    if      (left && up)    inputs[0] = 1.0;
    else if (left && down)  inputs[1] = 1.0;
    else if (right && up)   inputs[2] = 1.0;
    else if (right && down) inputs[3] = 1.0;

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
    outputValues.push_back(outputs[0] * 360);
    return outputValues;
}

Row Output::angle_velocity(const Row &outputs,
                           double factor_angular_velocity,
                           double factor_velocity)
{
    Row outputValues;
    outputValues.push_back(outputs[0] * factor_angular_velocity);
    outputValues.push_back(outputs[1] * factor_velocity);
    return outputValues;
}

Row Output::angle_acceleration(const Row &outputs,
                               double factor_angular_velocity,
                               double factor_acceleration)
{
    Row outputValues;
    outputValues.push_back(outputs[0] * factor_angular_velocity);
    outputValues.push_back(outputs[1] * factor_acceleration);
    return outputValues;
}

Row Output::axis_velocity(const Row &outputs, XY factor)
{
    Row outputValues;
    outputValues.push_back(outputs[0] * factor.x);
    outputValues.push_back(outputs[1] * factor.y);
    return outputValues;
}

Row Output::axis_acceleration(const Row &outputs, XY factor)
{
    Row outputValues;
    outputValues.push_back(outputs[0] * factor.x);
    outputValues.push_back(outputs[1] * factor.y);
    return outputValues;
}

Row Output::small_hops(const Row &outputs)
{
    Row outputValues;
    if (near_zero(outputs[0])) outputValues.push_back(0.0);
    else if (outputs[0] > 0.0) outputValues.push_back(1.0);
    else if (outputs[0] < 0.0) outputValues.push_back(-1.0);
    else outputValues.push_back(0.0);

    if (near_zero(outputs[1])) outputValues.push_back(0.0);
    else if (outputs[1] > 0.0) outputValues.push_back(1.0);
    else if (outputs[1] < 0.0) outputValues.push_back(-1.0);
    else outputValues.push_back(0.0);

    return outputValues;
}

Row Output::fixed_movement(const Row &outputs)
{
    Row outputValues;
    auto iter = std::max_element(outputs.begin(), outputs.end());
    int index = static_cast<int>(std::distance(outputs.begin(), iter));

    for (int i = 0; i < 4; i++) {
        if (i == index) outputValues.push_back(1.0);
        else outputValues.push_back(0.0);
    }

    return outputValues;
}
