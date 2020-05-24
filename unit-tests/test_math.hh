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
     * \brief Tests the function near_zero.
     *
     * Testing consists of two valid inputs and
     * multiple invalid inputs of decreasing value
     * (starting at 1.0, then 0.1, 0.01 etc.)
     * sufficiently far enough.
     */
    void test_near_zero();

    /*!
     * \brief Tests the function near_integer.
     *
     * Testing consists of a few valid inputs and
     * multiple invalid inputs that are similar to
     * the valid inputs, but they are reduced with
     * continuously decreasing values (1.0, 0.1, 0.01 etc.).
     */
    void test_near_integer();

    /*!
     * \brief Tests the function near_double.
     *
     * Testing consists of a few valid inputs and
     * multiple invalid inputs that are similar to
     * the valid inputs, but they are reduced with
     * continuously decreasing values (1.0, 0.1, 0.01 etc.).
     */
    void test_near_double();

    /*!
     * \brief Tests the function degrees_to_radians.
     *
     * Testing consists of a few inputs in degrees that are
     * transformed into radians. These are then compared to
     * their correct radian values.
     */
    void test_degrees_to_radians();

    /*!
     * \brief Tests the function radians_to_degrees.
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
     * \brief Tests the function distance.
     *
     * Testing consists of a few instances: horizontal points,
     * vertical points, equal points and various diagonal points.
     * The distances are known beforehand, and function results
     * are verified using them.
     */
    void test_XY_distance();

    /*!
     * \brief Tests unit vector creation from XY structs.
     *
     * Testing consists of a few instances: horizontal vectors,
     * vertical vectors, point vectors and various diagonal vectors.
     * Unit vectors are known beforehand, and function results
     * are verified using them.
     */
    void test_XY_unit_vector_from_points();

    /*!
     * \brief Tests unit vector creation from angles.
     *
     * Testing consists of various angles in degrees that are to be
     * converted into unit vectors. These are known beforehand, and
     * function results are verified using them.
     *
     * (radians are skipped because this function converts degrees to
     * radians - using a tested function - if they are specified)
     *
     */
    void test_XY_unit_vector_from_angle();
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
