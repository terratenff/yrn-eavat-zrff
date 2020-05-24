#include "test_math.hh"

TestMath::TestMath()
{

}

TestMath::~TestMath()
{

}

void TestMath::test_near_zero()
{
    QCOMPARE(near_zero(0.0000000000), true);
    QCOMPARE(near_zero(0), true);
    double positive = 1.0;
    double negative = -1.0;

    for (int i = 0; i < NEAR_ZERO_PRECISION_; i++) {
        QCOMPARE(near_zero(positive), false);
        QCOMPARE(near_zero(negative), false);
        positive /= 10;
        negative /= 10;
    }
}

void TestMath::test_near_integer()
{
    QCOMPARE(near_integer(1.000, 1), true);
    int target_int1 = 1;
    int target_int2 = -65;
    int target_int3 = 659223;
    double subject1 = static_cast<double>(target_int1);
    double subject2 = static_cast<double>(target_int2);
    double subject3 = static_cast<double>(target_int3);
    QCOMPARE(near_integer(subject1, target_int1), true);
    QCOMPARE(near_integer(subject2, target_int2), true);
    QCOMPARE(near_integer(subject3, target_int3), true);

    double reduction = 1;

    for (int i = 0; i < NEAR_INTEGER_PRECISION_; i++) {
        QCOMPARE(near_integer(subject1 - reduction, target_int1), false);
        QCOMPARE(near_integer(subject2 - reduction, target_int2), false);
        QCOMPARE(near_integer(subject3 - reduction, target_int3), false);
        reduction /= 10;
    }
}

void TestMath::test_near_double()
{
    QCOMPARE(near_double(1.000, 1.000), true);
    double target1 = 0.6751253;
    double target2 = sqrt(2);
    double target3 = -2775.100992;
    double subject1 = target1;
    double subject2 = target2;
    double subject3 = target3;
    QCOMPARE(near_double(subject1, target1), true);
    QCOMPARE(near_double(subject2, target2), true);
    QCOMPARE(near_double(subject3, target3), true);

    double reduction = 1;

    for (int i = 0; i < NEAR_INTEGER_PRECISION_; i++) {
        QCOMPARE(near_double(subject1 - reduction, target1), false);
        QCOMPARE(near_double(subject2 - reduction, target2), false);
        QCOMPARE(near_double(subject3 - reduction, target3), false);
        reduction /= 10;
    }
}

void TestMath::test_degrees_to_radians()
{
    double degrees1 = 180;
    double degrees2 = 90;
    double degrees3 = 45;
    double degrees4 = 20;

    QVERIFY(near_double(to_radians(degrees1), PI));
    QVERIFY(near_double(to_radians(degrees2), PI / 2));
    QVERIFY(near_double(to_radians(degrees3), PI / 4));
    QVERIFY(near_double(to_radians(degrees4), PI / 9));
}

void TestMath::test_radians_to_degrees()
{
    double radians1 = 2 * PI;
    double radians2 = (3 * PI) / 2;
    double radians3 = PI / 6;
    double radians4 = (7 * PI) / 8;

    QVERIFY(near_double(to_degrees(radians1), 360));
    QVERIFY(near_double(to_degrees(radians2), 270));
    QVERIFY(near_double(to_degrees(radians3), 30));
    QVERIFY(near_double(to_degrees(radians4), 157.5));
}

void TestMath::test_XY_instantiation()
{
    XY xy(1,4);
    double x = xy.x;
    double y = xy.y;
    QVERIFY(near_integer(x, 1));
    QVERIFY(near_integer(y, 4));
}

void TestMath::test_XY_addition()
{
    XY xy1(5,2);
    XY xy2(10, -15);
    XY xy3(-7, 0);

    XY xy4 = xy1 + xy2;
    XY xy5 = xy1 + xy3;
    XY xy6 = xy2 + xy3;
    XY xy7 = xy1 + xy2 + xy3;
    XY xy8 = xy4 + xy5 + xy6;
    XY xy9 = xy7 + xy8;

    QVERIFY(near_integer(xy4.x, 15));
    QVERIFY(near_integer(xy4.y, -13));
    QVERIFY(near_integer(xy5.x, -2));
    QVERIFY(near_integer(xy5.y, 2));
    QVERIFY(near_integer(xy6.x, 3));
    QVERIFY(near_integer(xy6.y, -15));
    QVERIFY(near_integer(xy7.x, 8));
    QVERIFY(near_integer(xy7.y, -13));
    QVERIFY(near_integer(xy8.x, 16));
    QVERIFY(near_integer(xy8.y, -26));
    QVERIFY(near_integer(xy9.x, 24));
    QVERIFY(near_integer(xy9.y, -39));
}

void TestMath::test_XY_subtraction()
{
    XY xy1(5,2);
    XY xy2(10, -15);
    XY xy3(-7, 0);

    XY xy4 = xy1 - xy2;
    XY xy5 = xy1 - xy3;
    XY xy6 = xy2 - xy3;
    XY xy7 = xy1 - xy2 - xy3;
    XY xy8 = xy4 - xy5 - xy6;
    XY xy9 = xy7 - xy8;

    QVERIFY(near_integer(xy4.x, -5));
    QVERIFY(near_integer(xy4.y, 17));
    QVERIFY(near_integer(xy5.x, 12));
    QVERIFY(near_integer(xy5.y, 2));
    QVERIFY(near_integer(xy6.x, 17));
    QVERIFY(near_integer(xy6.y, -15));
    QVERIFY(near_integer(xy7.x, 2));
    QVERIFY(near_integer(xy7.y, 17));
    QVERIFY(near_integer(xy8.x, -34));
    QVERIFY(near_integer(xy8.y, 30));
    QVERIFY(near_integer(xy9.x, 36));
    QVERIFY(near_integer(xy9.y, -13));
}

void TestMath::test_XY_comparison()
{
    XY xy1(5,2);
    XY xy2(10, -15);
    XY xy3(5, 2);
    XY xy4(5.001, 2.000);
    XY xy5(5.000, 1.999);
    XY xy6(0, 0);
    XY xy7(0.000, 0.000);
    XY xy8(0.0000000000001, 0);
    XY xy9(0, 0.0000000000001);

    QVERIFY2(xy1 != xy2, "XY Elements are not the same");
    QVERIFY2(xy1 == xy3, "XY Elements are the same");
    QVERIFY2(xy1 != xy2, "XY Elements are not the same");
    QVERIFY2(xy1 != xy4, "XY Elements are not the same");
    QVERIFY2(xy1 != xy5, "XY Elements are not the same");
    QVERIFY2(xy4 != xy5, "XY Elements are not the same");
    QVERIFY2(xy6 == xy7, "XY Elements are (considered) the same");
    QVERIFY2(xy6 == xy8, "XY Elements are (considered) the same");
    QVERIFY2(xy6 == xy9, "XY Elements are (considered) the same");
    QVERIFY2(xy8 == xy9, "XY Elements are (considered) the same");
}

void TestMath::test_XY_assignment()
{
    XY xy1(5,2);
    XY xy2(10, -15);
    XY xy3 = xy1;
    XY xy4 = xy2;
    XY xy5 = XY(0,0);

    QVERIFY2(xy1 == xy3, "XY Elements are the same");
    QVERIFY2(xy2 == xy4, "XY Elements are the same");
    QVERIFY2(xy5 == XY(0, 0), "XY Elements are the same");
    QVERIFY2(xy1 != xy2, "XY Elements are not the same");
    QVERIFY2(xy3 != xy4, "XY Elements are not the same");

    XY xy6(10,10);
    XY xy7 = xy6;
    QVERIFY2(xy6 == xy7, "XY Elements are the same");
    xy7.x = 5;
    QVERIFY2(xy6 != xy7, "XY Elements are not the same");
}

void TestMath::test_XY_distance()
{
    XY horizontal1(0,5);
    XY horizontal2(15,5);
    XY vertical1(3,3);
    XY vertical2(3,8);
    XY point1(-5,-5);
    XY point2 = point1;
    XY diagonal1(10,10);
    XY diagonal2(15,15);
    XY diagonal3(8,8);
    XY diagonal4(11,9);

    QVERIFY2(near_double(distance(horizontal1, horizontal2), 15),
             qPrintable(QString("Expected 15, got %1")
                        .arg(distance(horizontal1, horizontal2))));
    QVERIFY2(near_double(distance(vertical1, vertical2), 5),
             qPrintable(QString("Expected 5, got %1")
                        .arg(distance(vertical1, vertical2))));
    QVERIFY2(near_double(distance(point1, point2), 0),
             qPrintable(QString("Expected 0, got %1")
                        .arg(distance(point1, point2))));
    QVERIFY2(near_double(distance(diagonal1, diagonal2), 5 * sqrt(2)),
             qPrintable(QString("Expected 7.0710678..., got %1")
                        .arg(distance(diagonal1, diagonal2))));
    QVERIFY2(near_double(distance(diagonal3, diagonal4), sqrt(10)),
             qPrintable(QString("Expected 3.1622776..., got %1")
                        .arg(distance(diagonal3, diagonal4))));
}

void TestMath::test_XY_unit_vector_from_points()
{
    XY horizontal1(0,5);
    XY horizontal2(15,5);
    XY vertical1(3,3);
    XY vertical2(3,8);
    XY point1(-5,-5);
    XY point2 = point1;
    XY diagonal1(10,10);
    XY diagonal2(15,15);
    XY diagonal3(8,8);
    XY diagonal4(11,9);

    XY horizontalVector(1,0);
    XY verticalVector(0,1);
    XY pointVector(0,0);
    XY diagonalVector1(1 / sqrt(2), 1 / sqrt(2));
    XY diagonalVector2(3 / sqrt(10), 1 / sqrt(10));

    QVERIFY2(unit_vector(horizontal1, horizontal2) == horizontalVector,
             qPrintable(QString("Expected (1,0), got (%1,%2)")
                        .arg(unit_vector(horizontal1, horizontal2).x)
                        .arg(unit_vector(horizontal1, horizontal2).y)));
    QVERIFY2(unit_vector(vertical1, vertical2) == verticalVector,
             qPrintable(QString("Expected (0,1), got (%1,%2)")
                        .arg(unit_vector(vertical1, vertical2).x)
                        .arg(unit_vector(vertical1, vertical2).y)));
    QVERIFY2(unit_vector(point1, point2) == pointVector,
             qPrintable(QString("Expected (0,0), got (%1,%2)")
                        .arg(unit_vector(point1, point2).x)
                        .arg(unit_vector(point1, point2).y)));
    QVERIFY2(unit_vector(diagonal1, diagonal2) == diagonalVector1,
             qPrintable(QString("Expected (0.707106,0.707106), got (%1,%2)")
                        .arg(unit_vector(diagonal1, diagonal2).x)
                        .arg(unit_vector(diagonal1, diagonal2).y)));
    QVERIFY2(unit_vector(diagonal3, diagonal4) == diagonalVector2,
             qPrintable(QString("Expected (0.948683,0.316227), got (%1,%2)")
                        .arg(unit_vector(diagonal3, diagonal4).x)
                        .arg(unit_vector(diagonal3, diagonal4).y)));
}

void TestMath::test_XY_unit_vector_from_angle()
{
    double angle1 = 0;
    double angle2 = 360;
    double angle3 = 180;
    double angle4 = 45;
    double angle5 = -135;

    XY vector1(1,0);
    XY vector2(1,0);
    XY vector3(-1,0);
    XY vector4(1 / sqrt(2), 1 / sqrt(2));
    XY vector5(-1 / sqrt(2), -1 / sqrt(2));

    QVERIFY2(unit_vector(angle1) == vector1,
             qPrintable(QString("Expected (1,0), got (%1,%2)")
                        .arg(unit_vector(angle1).x)
                        .arg(unit_vector(angle1).y)));
    QVERIFY2(unit_vector(angle2) == vector2,
             qPrintable(QString("Expected (1,0), got (%1,%2)")
                        .arg(unit_vector(angle2).x)
                        .arg(unit_vector(angle2).y)));
    QVERIFY2(unit_vector(angle3) == vector3,
             qPrintable(QString("Expected (-1,0), got (%1,%2)")
                        .arg(unit_vector(angle3).x)
                        .arg(unit_vector(angle3).y)));
    QVERIFY2(unit_vector(angle4) == vector4,
             qPrintable(QString("Expected (0.707106,0.707106), got (%1,%2)")
                        .arg(unit_vector(angle4).x)
                        .arg(unit_vector(angle4).y)));
    QVERIFY2(unit_vector(angle5) == vector5,
             qPrintable(QString("Expected (-0.707106,-0.707106), got (%1,%2)")
                        .arg(unit_vector(angle5).x)
                        .arg(unit_vector(angle5).y)));
}

void TestMath::test_angle_calculation_vector()
{
    XY vector1(1,1);
    XY vector2(-2,4);
    XY vector3(7,-10);
    XY vector4(0,-3);
    XY vector5(0,0);

    double angle1 = 45;
    double angle2 = 116.5651;
    double angle3 = -55.0080;
    double angle4 = 270;
    double angle5 = 0;

    QVERIFY2(near_double(calculate_angle(vector1), angle1, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle1)
                        .arg(calculate_angle(vector1))));
    QVERIFY2(near_double(calculate_angle(vector2), angle2, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle2)
                        .arg(calculate_angle(vector2))));
    QVERIFY2(near_double(calculate_angle(vector3), angle3, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle3)
                        .arg(calculate_angle(vector3))));
    QVERIFY2(near_double(calculate_angle(vector4), angle4, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle4)
                        .arg(calculate_angle(vector4))));
    QVERIFY2(near_double(calculate_angle(vector5), angle5, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle5)
                        .arg(calculate_angle(vector5))));
}

void TestMath::test_angle_calculation_points()
{
    XY point1(0,0);
    XY point2(-4,-2);
    XY point3(2,11);
    XY point4(6,0);

    double angle1 = 206.5651;
    double angle2 = -70.0169;
    double angle3 = 79.6952;
    double angle4 = 11.3099;
    double angle5 = 0;
    double angle6 = 180;
    double angle7 = 0;

    QVERIFY2(near_double(calculate_angle(point1, point2), angle1, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle1)
                        .arg(calculate_angle(point1, point2))));
    QVERIFY2(near_double(calculate_angle(point3, point4), angle2, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle2)
                        .arg(calculate_angle(point3, point4))));
    QVERIFY2(near_double(calculate_angle(point1, point3), angle3, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle3)
                        .arg(calculate_angle(point1, point3))));
    QVERIFY2(near_double(calculate_angle(point2, point4), angle4, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle4)
                        .arg(calculate_angle(point2, point4))));
    QVERIFY2(near_double(calculate_angle(point1, point4), angle5, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle5)
                        .arg(calculate_angle(point1, point4))));
    QVERIFY2(near_double(calculate_angle(point4, point1), angle6, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle6)
                        .arg(calculate_angle(point4, point1))));
    QVERIFY2(near_double(calculate_angle(point3, point3), angle7, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(angle7)
                        .arg(calculate_angle(point3, point3))));
}

void TestMath::test_component_calculation()
{
    double angle1 = 45;
    double angle2 = -130;
    double angle3 = 380;
    double dist1 = 10;
    double dist2 = -20;
    double dist3 = 0;

    XY comp1(7.07107, 7.07107);
    XY comp2(12.85575, 15.32089);
    XY comp3(-14.14214, -14.14214);
    XY comp4(-6.42787, -7.66044);
    XY comp5(0,0);

    XY res1 = calculate_components(angle1, dist1);
    XY res2 = calculate_components(angle2, dist2);
    XY res3 = calculate_components(angle1, dist2);
    XY res4 = calculate_components(angle2, dist1);
    XY res5 = calculate_components(angle3, dist3);

    QVERIFY2(res1 == comp1,
             qPrintable(QString("Expected (%1,%2), got (%3,%4)")
                        .arg(comp1.x).arg(comp1.y)
                        .arg(res1.x).arg(res1.y)));
    QVERIFY2(res2 == comp2,
             qPrintable(QString("Expected (%1,%2), got (%3,%4)")
                        .arg(comp2.x).arg(comp2.y)
                        .arg(res2.x).arg(res2.y)));
    QVERIFY2(res3 == comp3,
             qPrintable(QString("Expected (%1,%2), got (%3,%4)")
                        .arg(comp3.x).arg(comp3.y)
                        .arg(res3.x).arg(res3.y)));
    QVERIFY2(res4 == comp4,
             qPrintable(QString("Expected (%1,%2), got (%3,%4)")
                        .arg(comp4.x).arg(comp4.y)
                        .arg(res4.x).arg(res4.y)));
    QVERIFY2(res5 == comp5,
             qPrintable(QString("Expected (%1,%2), got (%3,%4)")
                        .arg(comp5.x).arg(comp5.y)
                        .arg(res5.x).arg(res5.y)));
}

void TestMath::test_matrix_instantiation()
{
    QFAIL("TODO");
}

void TestMath::test_matrix_transpose()
{
    QFAIL("TODO");
}

void TestMath::test_matrix_addition()
{
    QFAIL("TODO");
}

void TestMath::test_matrix_subtraction()
{
    QFAIL("TODO");
}

void TestMath::test_matrix_multiplication()
{
    QFAIL("TODO");
}

void TestMath::test_matrix_scalar_multiplication()
{
    QFAIL("TODO");
}

void TestMath::test_sigmoid()
{
    QFAIL("TODO");
}

void TestMath::test_hyperbolic_tangent()
{
    QFAIL("TODO");
}

void TestMath::test_sign()
{
    QFAIL("TODO");
}

void TestMath::test_heaviside()
{
    QFAIL("TODO");
}

void TestMath::test_ReLU()
{
    QFAIL("TODO");
}

void TestMath::test_leaky_ReLU()
{
    QFAIL("TODO");
}

void TestMath::test_gaussian()
{
    QFAIL("TODO");
}

void TestMath::test_softmax()
{
    QFAIL("TODO");
}
