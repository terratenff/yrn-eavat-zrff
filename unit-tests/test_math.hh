#ifndef TEST_MATH_HH
#define TEST_MATH_HH

#include <QtTest>
#include "../shipyard/math.hh"

class TestMath : public QObject
{
    Q_OBJECT

public:
    TestMath();
    ~TestMath();

private slots:

    void test_near_zero();
    void test_near_integer();
    void test_near_double();

    void test_degrees_to_radians();
    void test_radians_to_degrees();

    void test_XY_instantiation();
    void test_XY_addition();
    void test_XY_subtraction();
    void test_XY_comparison();
    void test_XY_assignment();
    void test_XY_distance();
    void test_XY_unit_vector_from_points();
    void test_XY_unit_vector_from_angle();
private:
    const int NEAR_ZERO_PRECISION_ = 15;
    const int NEAR_INTEGER_PRECISION_ = 10;
    const int NEAR_DOUBLE_PRECISION_ = 10;
};

#endif // TEST_MATH_HH
