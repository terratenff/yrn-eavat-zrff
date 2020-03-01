#include "math.hh"
#include <iostream>

bool near_zero(double number,
               double range)
{
    double result = abs(number);
    double threshold = std::numeric_limits<double>::epsilon();
    if (!(range < threshold)) threshold = range;
    if (result < threshold) {
        return true;
    } else return false;
}

bool near_integer(double number,
                  int target_integer,
                  double range)
{
    double result = abs(number - static_cast<double>(target_integer));
    double threshold = std::numeric_limits<double>::epsilon();
    if (!near_zero(range)) threshold = range;
    if (result < threshold) {
        return true;
    } else return false;
}

bool near_double(double number,
                 double target_double,
                 double range)
{
    double result = abs(number - target_double);
    double threshold = std::numeric_limits<double>::epsilon();
    if (!near_zero(range)) threshold = range;
    if (result < threshold) {
        return true;
    } else return false;
}

void XY::print()
{
    std::cout << "(" << this->x << "," << this->y << ")"
              << std::endl;
}

double distance(XY point1, XY point2)
{
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    return abs(sqrt(dx * dx + dy * dy));
}

XY unit_vector(XY point1, XY point2)
{
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    double space = distance(point1, point2);
    if (near_zero(space)) return XY(0,0);
    XY unit_vector(dx / space, dy / space);
    return unit_vector;
}

XY unit_vector(double angle, bool radians)
{
    if (radians) return XY(cos(angle), sin(angle));
    else return XY(cos(to_radians(angle)), sin(to_radians(angle)));
}

double calculate_angle(XY point1, XY point2)
{
    XY difference = point2 - point1;
    if (near_zero(difference.x) && difference.y > 0) {
        return 90;
    } else if (near_zero(difference.x) && difference.y < 0) {
        return 270;
    } else {
        double radians = atan(difference.y / difference.x);
        if (difference.x > 0) return to_degrees(radians);
        else return 180 + to_degrees(radians);
    }
}

XY calculate_components(double angle, double space)
{
    double dx = cos(to_radians(angle)) * space;
    double dy = sin(to_radians(angle)) * space;
    XY components(dx, dy);
    return components;
}

double to_degrees(double angle_radians)
{
    return angle_radians * (360 / (2 * PI));
}

double to_radians(double angle_degrees)
{
    return angle_degrees * ((2 * PI) / 360);
}

Matrix matrix(unsigned int row_count, unsigned int column_count)
{
    Matrix m(row_count, Row(column_count, 0));
    return m;
}

void matrix_print(Matrix &matr)
{
    for (unsigned int i = 0; i < matr.size(); i++) {
        for (unsigned int j = 0; j < matr[i].size(); j++) {
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix matrix_transpose(Matrix &matr)
{
    Matrix result = matrix(
        static_cast<unsigned int>(matr[0].size()),
        static_cast<unsigned int>(matr.size())
    );

    for (unsigned int i = 0; i < matr.size(); i++) {
        for (unsigned int j = 0; j < matr[i].size(); j++) {
            result[j][i] = matr[i][j];
        }
    }
    return result;
}

Matrix matrix_add(Matrix &a, Matrix &b)
{
    Matrix result = matrix(
        static_cast<unsigned int>(a.size()),
        static_cast<unsigned int>(a[0].size())
    );

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

Matrix matrix_subtract(Matrix &a, Matrix &b)
{
    Matrix result = matrix(
        static_cast<unsigned int>(a.size()),
        static_cast<unsigned int>(a[0].size())
    );

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

Matrix matrix_dot(Matrix &a, Matrix &b)
{
    Matrix result = matrix(
        static_cast<unsigned int>(a.size()),
        static_cast<unsigned int>(b[0].size())
    );

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            result[i][j] = matrix_dot_element(a,b,i,j);
        }
    }
    return result;
}

Matrix matrix_dot_scalar(Matrix &a, Matrix &b)
{
    Matrix result = matrix(
        static_cast<unsigned int>(a.size()),
        static_cast<unsigned int>(a[0].size())
    );

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
    return result;
}

double matrix_dot_element(Matrix &a,
                          Matrix &b,
                          unsigned int i,
                          unsigned int j)
{
    double element = 0;
    for (unsigned int k = 0; k < b.size(); k++) {
        element += a[i][k] * b[k][j];
    }
    return element;
}

double sigmoid(double &x)
{
    return 1 / (1 + std::exp(-x));
}

Matrix sigmoid(Matrix &matr)
{
    Matrix result = matrix(
        static_cast<unsigned int>(matr.size()),
        static_cast<unsigned int>(matr[0].size())
    );

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            result[i][j] = sigmoid(matr[i][j]);
        }
    }
    return result;
}

double sigmoid_curve_gradient(double &x)
{
    return x * (1 - x);
}

Matrix sigmoid_curve_gradient(Matrix &matr)
{
    Matrix result = matrix(
        static_cast<unsigned int>(matr.size()),
        static_cast<unsigned int>(matr[0].size())
    );

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result[i].size(); j++) {
            result[i][j] = sigmoid_curve_gradient(matr[i][j]);
        }
    }
    return result;
}

Random::Random():
    rd_(),
    rng_(rd_()),
    uni_(),
    unif_(),
    re_()
{

}

int Random::random_int(int min, int max)
{
    int result = min + (uni_(rng_) % (max - min));
    return result;
}

double Random::random_double(double min, double max)
{
    double result = min + remainder(unif_(re_), (max - min));
    return result;
}

XY Random::random_coordinates(int x_min,
                              int x_max,
                              int y_min,
                              int y_max)
{
    return XY(random_int(x_min, x_max), random_int(y_min, y_max));
}
