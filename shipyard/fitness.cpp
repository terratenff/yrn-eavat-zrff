#include "fitness.hh"


double Fitness::correct_angle(double angle, XY position, XY target)
{
    double target_angle = calculate_angle(position, target);
    double difference = abs(angle - target_angle);
    if (difference > 180) {
        difference = abs(difference - 360);
    }
    difference = difference / 180;

    return 1 - difference;
}

double Fitness::close_proximity(XY position, XY target)
{
    double space = distance(position, target);
    return 1 - sigmoid(space);
}
