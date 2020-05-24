#ifndef TEST_MATH_HH
#define TEST_MATH_HH

#include <QtTest>
#include "../shipyard/math.hh"

/*!
 * \class TestMath
 * \brief Collection of test cases for the custom math module.
 * \author terratenff
 */
class TestMath : public QObject
{
    Q_OBJECT

public:
    TestMath();
    ~TestMath();

private slots:

    /*!
     * \brief Tests the function "near_zero".
     *
     * Testing consists of two valid inputs and
     * multiple invalid inputs of decreasing value
     * (starting at 1.0, then 0.1, 0.01 etc.)
     * sufficiently far enough.
     */
    void test_near_zero();

    /*!
     * \brief Tests the function "near_integer".
     *
     * Testing consists of a few valid inputs and
     * multiple invalid inputs that are similar to
     * the valid inputs, but they are reduced with
     * continuously decreasing values (1.0, 0.1, 0.01 etc.).
     */
    void test_near_integer();

    /*!
     * \brief Tests the function "near_double".
     *
     * Testing consists of a few valid inputs and
     * multiple invalid inputs that are similar to
     * the valid inputs, but they are reduced with
     * continuously decreasing values (1.0, 0.1, 0.01 etc.).
     */
    void test_near_double();

    /*!
     * \brief Tests the function "to_radians".
     *
     * Testing consists of a few inputs in degrees that are
     * transformed into radians. These are then compared to
     * their correct radian values.
     */
    void test_degrees_to_radians();

    /*!
     * \brief Tests the function "to_degrees".
     *
     * Testing consists of a few inputs in radians that are
     * transformed into degrees. These are then compared to
     * their correct degree values.
     */
    void test_radians_to_degrees();

    /*!
     * \brief Tests XY struct instantiation.
     *
     * Testing consists of the creation of a singular XY
     * struct with specified values that are verified again.
     */
    void test_XY_instantiation();

    /*!
     * \brief Tests XY struct addition operations.
     *
     * Testing consists of a variety of addition operations
     * with XY structs that have specified values.
     */
    void test_XY_addition();

    /*!
     * \brief Tests XY struct subtraction operations.
     *
     * Testing consists of a variety of subtraction operations
     * with XY structs that have specified values.
     */
    void test_XY_subtraction();

    /*!
     * \brief Tests XY struct comparison operations.
     *
     * Testing consists of a variety of comparison operations
     * with XY structs that have specified values.
     */
    void test_XY_comparison();

    /*!
     * \brief Tests XY struct assignment operations.
     *
     * Testing consists of different means of XY struct
     * assignments, and checking that said assignments
     * have been performed correctly.
     */
    void test_XY_assignment();

    /*!
     * \brief Tests the function "distance".
     *
     * Testing consists of a few instances: horizontal points,
     * vertical points, equal points and various diagonal points.
     * The distances are known beforehand, and function results
     * are verified using them.
     */
    void test_XY_distance();

    /*!
     * \brief Tests unit vector creation from XY structs (function
     * "unit_vector").
     *
     * Testing consists of a few instances: horizontal vectors,
     * vertical vectors, point vectors and various diagonal vectors.
     * Unit vectors are known beforehand, and function results
     * are verified using them.
     */
    void test_XY_unit_vector_from_points();

    /*!
     * \brief Tests unit vector creation from angles (function
     * "unit_vector").
     *
     * Testing consists of various angles in degrees that are to be
     * converted into unit vectors. These are known beforehand, and
     * function results are verified using them.
     *
     * (radians are skipped because this function converts degrees to
     * radians - using a tested function - if they are specified)
     */
    void test_XY_unit_vector_from_angle();

    /*!
     * \brief Tests angle calculation from a vector
     * (function "calculate_angle").
     *
     * Testing consists of various vectors as XY structs that
     * point in specific directions. These are known beforehand,
     * and function results are verified using them.
     */
    void test_angle_calculation_vector();

    /*!
     * \brief Tests angle calculation from a set of two points
     * (function "calculate_angle").
     *
     * Testing consists of a collection of points (XY structs)
     * distributed in the 2D space. Angles from the combinations
     * are known beforehand, and function results are verified using them.
     */
    void test_angle_calculation_points();

    /*!
     * \brief Tests function "calculate_components" where X and Y
     * components are determined using a given angle and distance.
     *
     * Testing consists of a small set of angles and distances that
     * are combined for component calculations. The components for
     * each combination are known beforehand, and function results
     * are verified using them.
     */
    void test_component_calculation();

    /*!
     * \brief Tests matrix instantiation (function "matrix").
     *
     * Testing consists of a few simple instantiations of the
     * matrix type variables, which are actually two-dimensional
     * vectors of doubles.
     */
    void test_matrix_instantiation();

    /*!
     * \brief Tests matrix transposing (function "matrix_transpose").
     *
     * Testing consists of a few matrices, the transpositions of which
     * are known beforehand. Function results are then verified using
     * known information.
     */
    void test_matrix_transpose();

    /*!
     * \brief Tests matrix addition operations. (function "matrix_add").
     *
     * Testing consists of a collection of matrices being added
     * together. Incompatible matrices are also tested. Valid
     * operations are verified with expected results.
     */
    void test_matrix_addition();

    /*!
     * \brief Tests matrix subtraction operations (function
     * "matrix_subtract").
     *
     * Testing consists of a collection of matrices being subtracted
     * by one another. Incompatible matrices are also tested. Valid
     * operations are verified with expected results.
     */
    void test_matrix_subtraction();

    /*!
     * \brief Tests matrix multiplication (function "matrix_dot").
     *
     * Testing consists of a collection of matrices being multiplied
     * by one another. Incompatible matrices are also tested. Valid
     * operations are verified with expected results.
     */
    void test_matrix_multiplication();

    /*!
     * \brief Tests scalar-wise matrix multiplication
     * (function "matrix_dot_scalar").
     *
     * Testing consists of a collection of matrices being multiplied
     * by one another. Incompatible matrices are also tested. Valid
     * operations are verified with expected results.
     */
    void test_matrix_scalar_multiplication();

    /*!
     * \brief Tests activation function "sigmoid".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_sigmoid();

    /*!
     * \brief Tests activation function "hyperbolic_tangent".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_hyperbolic_tangent();

    /*!
     * \brief Tests activation function "sign".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_sign();

    /*!
     * \brief Tests activation function "heaviside".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_heaviside();

    /*!
     * \brief Tests activation function "ReLU".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_ReLU();

    /*!
     * \brief Tests activation function "leaky_ReLU".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_leaky_ReLU();

    /*!
     * \brief Tests activation function "gaussian".
     *
     * Testing consists of five different values that are used with
     * other activation functions during testing. The results are
     * compared with the expected results.
     */
    void test_gaussian();

    /*!
     * \brief Tests activation function "softmax".
     *
     * Testing consista of a collection of Rows (vectors)
     * that are to be activated. The results are compared with
     * the expected results.
     */
    void test_softmax();
private:

    /*!
     * \brief Level of accuracy demonstrated for unit tests
     * related to the use of near_zero. Modifying this value
     * (default value is 15) could lead to associated unit tests
     * failing.
     */
    const int NEAR_ZERO_PRECISION_ = 15;

    /*!
     * \brief Level of accuracy demonstrated for unit tests
     * related to the use of near_integer. Modifying this value
     * (default value is 10) could lead to associated unit tests
     * failing.
     */
    const int NEAR_INTEGER_PRECISION_ = 10;

    /*!
     * \brief Level of accuracy demonstrated for unit tests
     * related to the use of near_double. Modifying this value
     * (default value is 10) could lead to associated unit tests
     * failing.
     */
    const int NEAR_DOUBLE_PRECISION_ = 10;
};

#endif // TEST_MATH_HH
