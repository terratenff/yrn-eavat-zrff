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
    return min(1.0, abs(1.0 - (space / 2000.0)));
}

double Fitness::fixed_distance(XY position, XY target)
{
    double space = distance(position, target);
    if (space > 300.0 || space < 700.0) {
        double difference = abs(space - 500.0);
        return 1 - (difference / 200.0);
    } else return 0.0;
}

double Fitness::not_out_of_bounds(XY position)
{
    if (position.x < 0.0 || position.x > 1920.0) return -999.0;
    else if (position.y < 0.0 || position.y > 1080.0) return -999.0;
    else return 1.0;
}

double Fitness::look_from_distance(double angle, XY position, XY target)
{
    double angle_fitness = correct_angle(angle, position, target);
    double space = distance(position, target);
    if (space < 500.0) {
        angle_fitness *= -1;
    }
    return angle_fitness;
}

double Fitness::avoid_eye_contact(double angle, double target_angle,
                                  XY position, XY target)
{
    double angle_to_target = calculate_angle(position, target);
    double angle_from_target = calculate_angle(target, position);
    double difference = abs(angle - angle_to_target);
    if (difference > 180) {
        difference = abs(difference - 360);
    }
    difference = difference / 180;
    double difference_target = abs(target_angle - angle_from_target);
    if (difference_target > 180) {
        difference_target = abs(difference_target - 360);
    }

    if (near_zero(difference_target, 20)) {
        return difference;
    } else {
        return 1 - difference;
    }
}
