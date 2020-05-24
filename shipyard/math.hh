#ifndef MATH_HH
#define MATH_HH

#include <vector>
#include <cmath>
#include <random>

using namespace std;
using Matrix = vector<vector<double> >;
using Row = vector<double>;

const double PI = 3.14159265;
const double XY_PRECISION = 0.00001;

bool near_zero(double number,
               double range = 0);
bool near_integer(double number,
                  int target_integer,
                  double range = 0);
bool near_double(double number,
                 double target_double,
                 double range = 0);

struct XY {
    double x;
    double y;
    XY(double xx, double yy) {
        x = xx;
        y = yy;
    }
    XY &operator=(const XY &a) {
        x = a.x;
        y = a.y;
        return *this;
    }
    XY operator+(const XY &a) const
    {
        return XY(x + a.x, y + a.y);
    }
    XY operator-(const XY &a) const
    {
        return XY(x - a.x, y - a.y);
    }
    bool operator==(const XY &a)
    {
        return (near_zero(x - a.x, XY_PRECISION)
                && near_zero(y - a.y, XY_PRECISION));
    }
    bool operator!=(const XY &a)
    {
        return (!near_zero(x - a.x, XY_PRECISION)
                || !near_zero(y - a.y, XY_PRECISION));
    }
    void print();
};

double distance(XY point1, XY point2);
XY unit_vector(XY point1, XY point2);
XY unit_vector(double angle, bool radians = false);

double calculate_angle(XY vector);
double calculate_angle(XY point1, XY point2);
XY calculate_components(double angle, double space, bool radians = false);
double to_degrees(double angle_radians);
double to_radians(double angle_degrees);

Matrix matrix(unsigned int row_count, unsigned int column_count);
void matrix_print(Matrix &matr);
Matrix matrix_transpose(Matrix &matr);
Matrix matrix_add(Matrix &a, Matrix &b);
Matrix matrix_subtract(Matrix &a, Matrix &b);
Matrix matrix_dot(Matrix &a, Matrix &b);
Matrix matrix_dot_scalar(Matrix &a, Matrix &b);
double matrix_dot_element(Matrix &a,
                          Matrix &b,
                          unsigned int i,
                          unsigned int j);

double sigmoid(double &x);
Matrix sigmoid(Matrix &matr);
double sigmoid_curve_gradient(double &x);
Matrix sigmoid_curve_gradient(Matrix &matr);

double hyperbolic_tangent(double &x);
double sign(double &x);
double heaviside(double &x);
double ReLU(double &x);
double ReLU_leaky(double &x);
double gaussian(double &x);
Row softmax(Row &x);

class Random
{
public:
    Random();
    int random_int(int min, int max);
    double random_double(double min, double max);
    XY random_coordinates(int x_min = 0,
                          int x_max = 1920,
                          int y_min = 0,
                          int y_max = 1080);
private:
    std::random_device rd_;
    std::mt19937 rng_;
    std::uniform_int_distribution<int> uni_;

    std::uniform_real_distribution<double> unif_;
    std::default_random_engine re_;
};

#endif // MATH_HH
