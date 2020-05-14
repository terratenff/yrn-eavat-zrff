#ifndef MATH_HH
#define MATH_HH

#include <vector>
#include <cmath>
#include <random>

using namespace std;

/*!
 * \file math.hh
 * \brief Collection of math functions for the rest of the application to use.
 * \author terratenff
 */

/*!
 * \def Matrix
 * \brief Convenient abbrievation for a 2D vector.
 */
using Matrix = vector<vector<double> >;

/*!
 * \def Row
 * \brief Convenient abbrievation for a double vector.
 */
using Row = vector<double>;

/*!
 * \var PI
 * \brief 8-digit estimation of pi. Equal to 3.14159265.
 */
const double PI = 3.14159265;

/*!
 * \var XY_PRECISION
 * \brief Precision value for checking equalities with XY-instances,
 * since they use doubles instead of integers. Equal to 0.00001.
 */
const double XY_PRECISION = 0.00001;

/*!
 * \fn near_zero
 * \brief Checks if specified variable is close enough to zero.
 * \param number Subject variable.
 * \param range Acceptable threshold for being close to zero.
 * If not given, std-epsilon is used as the range.
 * \return true, if threshold requirement is met.
 * false otherwise.
 */
bool near_zero(double number,
               double range = 0);

/*!
 * \fn near_integer
 * \brief Checks if specified variable is close enough to
 * specified integer.
 * \param number Subject variable.
 * \param target_integer Target integer.
 * \param range Acceptable threshold for being close to
 * specified integer. If not given, std-epsilon is used
 * as the range.
 * \return true, if threshold requirement is met.
 * false otherwise.
 */
bool near_integer(double number,
                  int target_integer,
                  double range = 0);

/*!
 * \fn near_double
 * \brief Checks if specified variable is close enough to
 * specified double.
 * \param number Subject variable.
 * \param target_double Target double.
 * \param range Acceptable threshold for being close to
 * specified double. If not given, std-epsilon is used
 * as the range.
 * \return  true, if threshold requirement is met.
 * false otherwise.
 */
bool near_double(double number,
                 double target_double,
                 double range = 0);

/*!
 * \struct XY
 * \brief Standard coordinate structure, tailored for the application.
 * \author terratenff
 */
struct XY {

    /*!
     * \var x
     * \brief Value on the X-axis.
     */
    double x;

    /*!
     * \var y
     * \brief Value on the Y-axis.
     */
    double y;

    /*!
     * \brief Simple constructor for an XY struct.
     * \param xx Value for the X-axis.
     * \param yy Value for the Y-axis.
     */
    XY(double xx, double yy) {
        x = xx;
        y = yy;
    }

    /*!
     * \brief Assignment operation for XY structs.
     * \param a Target XY struct for assignment.
     * \return XY struct equal to target struct.
     */
    XY &operator=(const XY &a) {
        x = a.x;
        y = a.y;
        return *this;
    }

    /*!
     * \brief Addition operation for XY structs.
     * \param a Target XY struct for addition.
     * \return Result of two XY structs added together.
     */
    XY operator+(const XY &a) const
    {
        return XY(x + a.x, y + a.y);
    }

    /*!
     * \brief Subtraction operation for XY structs.
     * \param a Target XY struct for subtraction.
     * \return Result of a XY struct from which target XY struct
     * was subtracted.
     */
    XY operator-(const XY &a) const
    {
        return XY(x - a.x, y - a.y);
    }

    /*!
     * \brief Equal comparison operation for XY structs.
     * \param a Target XY struct for comparison.
     * \return true, if both x and y values are
     * equal to those of target XY struct's with
     * pre-defined precision. false otherwise.
     */
    bool operator==(const XY &a)
    {
        return (near_zero(x - a.x, XY_PRECISION)
                && near_zero(y - a.y, XY_PRECISION));
    }

    /*!
     * \brief Inequal comparison operation for XY structs.
     * \param a Target XY struct for comparison.
     * \return true, if x or y values are not equal to
     * those of target XY struct's with pre-defined
     * precision. false otherwise.
     */
    bool operator!=(const XY &a)
    {
        return (!near_zero(x - a.x, XY_PRECISION)
                || !near_zero(y - a.y, XY_PRECISION));
    }

    /*!
     * \fn print
     * \brief Convenience function for printing the state of
     * the XY struct.
     */
    void print();
};

/*!
 * \fn distance
 * \brief Calculates the distance between two points.
 * \param point1 Point A (Source).
 * \param point2 Point B (Target).
 * \return Distance from A to B (0 or greater).
 */
double distance(XY point1, XY point2);

/*!
 * \fn unit_vector
 * \brief Creates a unit vector from two points.
 * \param point1 Point A (Source).
 * \param point2 Point B (Target).
 * \return Unit vector as an XY struct, pointing from A to B.
 */
XY unit_vector(XY point1, XY point2);

/*!
 * \fn unit_vector
 * \brief Creates a unit vector from an angle.
 * \param angle Target angle.
 * \param radians Flag determining whether degrees or
 * radians are being used. Set to false by default.
 * \return Unit vector as an XY struct, pointing to
 * given angle.
 */
XY unit_vector(double angle, bool radians = false);

/*!
 * \fn calculate_angle
 * \brief Calculates the angle based on given
 * vector in the form of an XY struct.
 * \param vector Target vector.
 * \return Angle as degrees.
 */
double calculate_angle(XY vector);

/*!
 * \fn calculate_angle
 * \brief Calculates the angle based on two
 * given points in space, as XY structs.
 * \param point1 Point A (Source)
 * \param point2 Point B (Target)
 * \return Angle as degrees, from point A to point B.
 */
double calculate_angle(XY point1, XY point2);

/*!
 * \fn calculate_components
 * \brief Constructs an XY struct from given angle
 * and distance.
 * \param angle Target angle.
 * \param space Target distance.
 * \return X and Y components as an XY struct.
 */
XY calculate_components(double angle, double space);

/*!
 * \fn to_degrees
 * \brief Converts radians to degrees.
 * \param angle_radians Angle in radians.
 * \return Degrees.
 */
double to_degrees(double angle_radians);

/*!
 * \fn to_radians
 * \brief Converts degrees to radians.
 * \param angle_degrees Angle in degrees.
 * \return Radians.
 */
double to_radians(double angle_degrees);

/*!
 * \fn matrix
 * \brief Convenient initializer for a matrix variable.
 * \param row_count Number of rows for the matrix.
 * \param column_count Number of columns for the matrix.
 * \return Matrix element with specified number of rows
 * and columns.
 */
Matrix matrix(unsigned int row_count, unsigned int column_count);

/*!
 * \fn matrix_print
 * \brief Convenient function for printing the contents of a
 * matrix.
 * \param matr Target matrix.
 * \pre Given matrix must be an actual matrix.
 */
void matrix_print(Matrix &matr);

/*!
 * \fn matrix_transpose
 * \brief Transposes given matrix.
 * \param matr Target matrix.
 * \return Transposed matrix.
 * \pre Given matrix must be an actual matrix.
 */
Matrix matrix_transpose(Matrix &matr);

/*!
 * \fn matrix_add
 * \brief Addition operation for matrices.
 * \param a Matrix A
 * \param b Matrix B
 * \return A + B.
 * \pre Given matrices must be actual matrices.
 */
Matrix matrix_add(Matrix &a, Matrix &b);

/*!
 * \fn matrix_subtract
 * \brief Subtraction operation for matrices.
 * \param a Matrix A
 * \param b Matrix B
 * \return A - B.
 * \pre Given matrices must be actual matrices.
 */
Matrix matrix_subtract(Matrix &a, Matrix &b);

/*!
 * \fn matrix_dot
 * \brief Multiplication operation for matrices.
 * \param a Matrix A
 * \param b Matrix B
 * \return A * B.
 * \pre Given matrices must be actual matrices.
 */
Matrix matrix_dot(Matrix &a, Matrix &b);

/*!
 * \fn matrix_dot_scalar
 * \brief Element-wise multiplication operation
 * for matrices.
 * \param a Matrix A
 * \param b Matrix B
 * \return A .* B.
 * \pre Given matrices must be actual matrices.
 */
Matrix matrix_dot_scalar(Matrix &a, Matrix &b);

/*!
 * \fn matrix_dot_element
 * \brief Calculates a singular matrix element
 * during matrix multiplication operation.
 * \param a Matrix A
 * \param b Matrix B
 * \param i Target Row
 * \param j Target Column
 * \return Matrix element on target row and column
 * \pre Given matrices must be actual matrices, and this
 * function should only be called during matrix
 * multiplication operation.
 */
double matrix_dot_element(Matrix &a,
                          Matrix &b,
                          unsigned int i,
                          unsigned int j);

/*!
 * \fn sigmoid
 * \brief Calculates the Sigmoid value for given
 * variable.
 * \param x Target variable.
 * \return Sigmoid value of target variable: 1 / (1 + e^(-x)).
 */
double sigmoid(double &x);

/*!
 * \fn sigmoid
 * \brief Calculates the Sigmoid value for every
 * element of given matrix.
 * \param matr Target matrix.
 * \return Sigmoid values of every matrix element.
 */
Matrix sigmoid(Matrix &matr);

/*!
 * \fn sigmoid_curve_gradient
 * \brief Calculates the Sigmoid Curve Gradient for
 * given variable.
 * \param x Target variable.
 * \return Sigmoid Curve Gradient of target variable:
 * x * (1 - x).
 */
double sigmoid_curve_gradient(double &x);

/*!
 * \fn sigmoid_curve_gradient
 * \brief Calculates the Sigmoid Curve Gradient for every
 * element of given matrix.
 * \param matr Target matrix.
 * \return Sigmoid Curve Gradients of every matrix
 * element.
 */
Matrix sigmoid_curve_gradient(Matrix &matr);

/*!
 * \fn hyperbolic_tangent
 * \brief Calculates the Hyperbolic Tangent for
 * given variable.
 * \param x Target variable.
 * \return Hyperbolic Tangent of target variable:
 * (2 / (1 + e^(-2x))) - 1.
 */
double hyperbolic_tangent(double &x);

/*!
 * \fn sign
 * \brief Calculates the Sign value for given variable.
 * \param x Target variable.
 * \return Sign value of target variable:
 * 1 if x > 0, 0 if x = 0, -1 if x < 0.
 */
double sign(double &x);

/*!
 * \fn heaviside
 * \brief Calculates the Heavisde value for given variable.
 * \param x Target variable.
 * \return Heaviside value of target variable:
 * 1 if x >= 0, 0 if x < 0.
 */
double heaviside(double &x);

/*!
 * \fn ReLU
 * \brief Calculates the Rectified Linear Unit (ReLU) for given variable.
 * \param x Target variable.
 * \return Rectified Linear Unit of target variable:
 * 0 if x < 0, x if x >= 0.
 */
double ReLU(double &x);

/*!
 * \fn ReLU_leaky
 * \brief Calculates the Leaky Rectified Linear Unit (Leaky ReLU) for
 * given variable.
 * \param x Target variable.
 * \return Leaky Rectified Linear Unit of target variable:
 * 0.01x if x < 0, x if x >= 0.
 */
double ReLU_leaky(double &x);

/*!
 * \fn gaussian
 * \brief Calculates the Gaussian value for given variable.
 * \param x Target variable.
 * \return Gaussian value of target variable: e^(-x^2).
 */
double gaussian(double &x);

/*!
 * \fn softmax
 * \brief Calculates the Softmax values for a given row
 * of elements.
 * \param x Target row.
 * \return Softmax values of target row.
 */
Row softmax(Row &x);

/*!
 * \class Random
 * \brief Custom-implemented random number generator.
 * \author terratenff
 */
class Random
{
public:

    /*!
     * \brief Random number generator constructor.
     */
    Random();

    /*!
     * \fn random_int
     * \brief Generates a random integer within given
     * range.
     * \param min Minimum integer, inclusive.
     * \param max Maximum integer, exclusive.
     * \return Random integer within range [min, max).
     */
    int random_int(int min, int max);

    /*!
     * \fn random_double
     * \brief Generates a random double within given
     * range.
     * \param min Minimum double, inclusive.
     * \param max Maximum double, exclusive.
     * \return Random double within range [min, max).
     */
    double random_double(double min, double max);

    /*!
     * \fn random_coordinates
     * \brief Generates random coordinates within given
     * range.
     * \param x_min Minimum X. Default value is 0.
     * \param x_max Maximum X. Default value is 1920.
     * \param y_min Minimum Y. Default value is 0.
     * \param y_max Maximum Y. Default value is 1080.
     * \return Random coordinates, constrained by given
     * ranges.
     */
    XY random_coordinates(int x_min = 0,
                          int x_max = 1920,
                          int y_min = 0,
                          int y_max = 1080);
private:

    /*!
     * \var rd_
     * \brief Uniformly distributed integer random number
     * generator. Non-deterministic.
     */
    std::random_device rd_;

    /*!
     * \var rng_
     * \brief Mersenne Twister pseudo-random generator.
     */
    std::mt19937 rng_;

    /*!
     * \var uni_
     * \brief Uniform distribution of random integers.
     */
    std::uniform_int_distribution<int> uni_;

    /*!
     * \var unif_
     * \brief Uniform distribution of random doubles.
     */
    std::uniform_real_distribution<double> unif_;

    /*!
     * \var re_
     * \brief Pseudo-random number engine.
     */
    std::default_random_engine re_;
};

#endif // MATH_HH
