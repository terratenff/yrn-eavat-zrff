#include "test_math.hh"
#include <iostream>

TestMath::TestMath()
{

}

TestMath::~TestMath()
{

}

bool TestMath::compare_rows(Row &row1, Row &row2)
{
    // Check for same number of elements.
    if (row1.size() != row2.size()) return false;

    for (unsigned int i = 0; i < row1.size(); i++) {
        if (!near_double(row1[i], row2[i], 0.0001)) return false;
    }
    return true;
}

void TestMath::print_row_report(std::string title, Row &row1, Row &row2)
{
    std::cout << title << std::endl;
    std::cout << "Expected row:" << std::endl;

    std::string expected = "";
    for (unsigned int i = 0; i < row1.size(); i++) {
        expected += std::to_string(row1[i]) + " ";
    }
    std::cout << expected << std::endl;
    std::cout << "Result row:" << std::endl;

    std::string result = "";
    for (unsigned int i = 0; i < row2.size(); i++) {
        result += std::to_string(row2[i]) + " ";
    }
    std::cout << result << std::endl;
}

bool TestMath::compare_matrices(Matrix &matr1, Matrix &matr2)
{
    // Check for same number of rows.
    if (matr1.size() != matr2.size()) return false;

    for (unsigned int i = 0; i < matr1.size(); i++) {

        // Check for same number of columns (elements on each row).
        if (matr1[i].size() != matr2[i].size()) return false;

        for (unsigned int j = 0; j < matr1[i].size(); j++) {
            if (!near_double(matr1[i][j], matr2[i][j], 0.0001)) {
                return false;
            }
        }
    }
    return true;
}

void TestMath::print_matrix_report(std::string title, Matrix &matr1, Matrix &matr2)
{
    std::cout << title << std::endl;
    std::cout << "Expected matrix:" << std::endl;
    matrix_print(matr1);
    std::cout << "Result matrix:" << std::endl;
    matrix_print(matr2);
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
    Matrix matr1 = matrix(3,3);
    Matrix matr2 = matrix(10,7);
    Matrix matr3 = matrix(0,0);
    Matrix matr4 = matrix(3,0);

    unsigned int sizeRows1 = 3;
    unsigned int sizeColumns1 = 3;
    QVERIFY2(matr1.size() == sizeRows1,
             qPrintable(QString("Expected %1, got %2")
                        .arg(sizeRows1).arg(matr1.size())));
    for (Row row : matr1) {
        QVERIFY2(row.size() == sizeColumns1,
                 qPrintable(QString("Expected %1, got %2")
                            .arg(sizeColumns1).arg(row.size())));
    }

    unsigned int sizeRows2 = 10;
    unsigned int sizeColumns2 = 7;
    QVERIFY2(matr2.size() == sizeRows2,
             qPrintable(QString("Expected %1, got %2")
                        .arg(sizeRows2).arg(matr2.size())));
    for (Row row : matr2) {
        QVERIFY2(row.size() == sizeColumns2,
                 qPrintable(QString("Expected %1, got %2")
                            .arg(sizeColumns2).arg(row.size())));
    }

    unsigned int sizeRows3 = 0;
    unsigned int sizeColumns3 = 0;
    QVERIFY2(matr3.size() == sizeRows3,
             qPrintable(QString("Expected %1, got %2")
                        .arg(sizeRows3).arg(matr3.size())));
    for (Row row : matr3) {
        QVERIFY2(row.size() == sizeColumns3,
                 qPrintable(QString("Expected %1, got %2")
                            .arg(sizeColumns3).arg(row.size())));
    }

    unsigned int sizeRows4 = 0;
    unsigned int sizeColumns4 = 0;
    QVERIFY2(matr4.size() == sizeRows4,
             qPrintable(QString("Expected %1, got %2")
                        .arg(sizeRows4).arg(matr4.size())));
    for (Row row : matr4) {
        QVERIFY2(row.size() == sizeColumns4,
                 qPrintable(QString("Expected %1, got %2")
                            .arg(sizeColumns4).arg(row.size())));
    }
}

void TestMath::test_matrix_transpose()
{
    Matrix matr1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix matr2 = {
        {10, 11, 12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23, 24, 25}
    };
    Matrix matr3 = {
        {26},
        {27},
        {28},
        {29},
        {30},
        {31}
    };
    Matrix matr4 = {
        {0}
    };

    Matrix matr1t = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    Matrix matr2t = {
        {10, 18},
        {11, 19},
        {12, 20},
        {13, 21},
        {14, 22},
        {15, 23},
        {16, 24},
        {17, 25}
    };
    Matrix matr3t = {
        {26, 27, 28, 29, 30, 31}
    };
    Matrix matr4t = {
        {0}
    };

    Matrix matr1r = matrix_transpose(matr1);
    Matrix matr2r = matrix_transpose(matr2);
    Matrix matr3r = matrix_transpose(matr3);
    Matrix matr4r = matrix_transpose(matr4);

    bool pass1 = compare_matrices(matr1r, matr1t);
    bool pass2 = compare_matrices(matr2r, matr2t);
    bool pass3 = compare_matrices(matr3r, matr3t);
    bool pass4 = compare_matrices(matr4r, matr4t);

    std::string title;
    if (!pass1) {
        title = " -- test_matrix_transpose - Matrix test 1 --";
        print_matrix_report(title, matr1t, matr1r);
    }
    if (!pass2) {
        title = " -- test_matrix_transpose - Matrix test 2 --";
        print_matrix_report(title, matr2t, matr2r);
    }
    if (!pass3) {
        title = " -- test_matrix_transpose - Matrix test 3 --";
        print_matrix_report(title, matr3t, matr3r);
    }
    if (!pass4) {
        title = " -- test_matrix_transpose - Matrix test 4 --";
        print_matrix_report(title, matr4t, matr4r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4) {
        QFAIL(qPrintable(QString("One or more matrix tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestMath::test_matrix_addition()
{
    Matrix matr1 = {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    };
    Matrix matr2 = {
        {2, 2, 2},
        {3, 3, 3},
        {8, 10, 8}
    };
    Matrix matr3 = {
        {-1, -1, 0},
        {0, 6, 20},
        {-15, 10, -25}
    };
    Matrix matr4 = {
        {-8, -1, 12, 18},
        {0, 0, 100, 200}
    };
    Matrix matr5 = {
        {-10, 50, -19, 24},
        {1, 7, -2, -4}
    };

    Matrix matr12 = {
        {7, 7, 7},
        {8, 8, 8},
        {13, 15, 13}
    };
    Matrix matr13 = {
        {4, 4, 5},
        {5, 11, 25},
        {-10, 15, -20}
    };
    Matrix matr22 = {
        {4, 4, 4},
        {6, 6, 6},
        {16, 20, 16}
    };
    Matrix matr45 = {
        {-18, 49, -7, 42},
        {1, 7, 98, 196}
    };

    Matrix matr12r = matrix_add(matr1, matr2);
    Matrix matr13r = matrix_add(matr1, matr3);
    Matrix matr22r = matrix_add(matr2, matr2);
    Matrix matr45r = matrix_add(matr4, matr5);

    bool pass1 = compare_matrices(matr12r, matr12);
    bool pass2 = compare_matrices(matr13r, matr13);
    bool pass3 = compare_matrices(matr22r, matr22);
    bool pass4 = compare_matrices(matr45r, matr45);

    std::string title;
    if (!pass1) {
        title = "-- test_matrix_add - Matrix test 1 --";
        print_matrix_report(title, matr12, matr12r);
    }
    if (!pass2) {
        title = "-- test_matrix_add - Matrix test 2 --";
        print_matrix_report(title, matr13, matr13r);
    }
    if (!pass3) {
        title = "-- test_matrix_add - Matrix test 3 --";
        print_matrix_report(title, matr22, matr22r);
    }
    if (!pass4) {
        title = "-- test_matrix_add - Matrix test 4 --";
        print_matrix_report(title, matr45, matr45r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4) {
        QFAIL(qPrintable(QString("One or more valid matrix tests failed. "
                                 "See below for the comparisons.")));
    }

    QVERIFY_EXCEPTION_THROWN(matrix_add(matr1, matr4), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_add(matr1, matr5), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_add(matr4, matr2), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_add(matr5, matr2), std::out_of_range);
}

void TestMath::test_matrix_subtraction()
{
    Matrix matr1 = {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    };
    Matrix matr2 = {
        {2, 2, 2},
        {3, 3, 3},
        {8, 10, 8}
    };
    Matrix matr3 = {
        {-1, -1, 0},
        {0, 6, 20},
        {-15, 10, -25}
    };
    Matrix matr4 = {
        {-8, -1, 12, 18},
        {0, 0, 100, 200}
    };
    Matrix matr5 = {
        {-10, 50, -19, 24},
        {1, 7, -2, -4}
    };

    Matrix matr12 = {
        {3, 3, 3},
        {2, 2, 2},
        {-3, -5, -3}
    };
    Matrix matr13 = {
        {6, 6, 5},
        {5, -1, -15},
        {20, -5, 30}
    };
    Matrix matr22 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    Matrix matr45 = {
        {2, -51, 31, -6},
        {-1, -7, 102, 204}
    };

    Matrix matr12r = matrix_subtract(matr1, matr2);
    Matrix matr13r = matrix_subtract(matr1, matr3);
    Matrix matr22r = matrix_subtract(matr2, matr2);
    Matrix matr45r = matrix_subtract(matr4, matr5);

    bool pass1 = compare_matrices(matr12r, matr12);
    bool pass2 = compare_matrices(matr13r, matr13);
    bool pass3 = compare_matrices(matr22r, matr22);
    bool pass4 = compare_matrices(matr45r, matr45);

    std::string title;
    if (!pass1) {
        title = "-- test_matrix_subtract - Matrix test 1 --";
        print_matrix_report(title, matr12, matr12r);
    }
    if (!pass2) {
        title = "-- test_matrix_subtract - Matrix test 2 --";
        print_matrix_report(title, matr13, matr13r);
    }
    if (!pass3) {
        title = "-- test_matrix_subtract - Matrix test 3 --";
        print_matrix_report(title, matr22, matr22r);
    }
    if (!pass4) {
        title = "-- test_matrix_subtract - Matrix test 4 --";
        print_matrix_report(title, matr45, matr45r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4) {
        QFAIL(qPrintable(QString("One or more valid matrix tests failed. "
                                 "See below for the comparisons.")));
    }

    QVERIFY_EXCEPTION_THROWN(matrix_subtract(matr1, matr4), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_subtract(matr1, matr5), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_subtract(matr4, matr2), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_subtract(matr5, matr2), std::out_of_range);
}

void TestMath::test_matrix_dot()
{
    Matrix matr1 = {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    };
    Matrix matr2 = {
        {2, 2, 2},
        {3, 3, 3},
        {8, 10, 8}
    };
    Matrix matr3 = {
        {-1, -1, 0},
        {0, 6, 20},
        {-15, 10, -25}
    };
    Matrix matr4 = {
        {-8, -1, 12, 18},
        {0, 0, 100, 200}
    };
    Matrix matr5 = {
        {-10, 50, -19, 24},
        {1, 7, -2, -4}
    };
    Matrix matr6 = {
        {-10, 50},
        {-19, 24},
        {1, 7},
        {-2, -4}
    };

    Matrix matr12 = {
        {65, 75, 65},
        {65, 75, 65},
        {65, 75, 65}
    };
    Matrix matr13 = {
        {-80, 75, -25},
        {-80, 75, -25},
        {-80, 75, -25}
    };
    Matrix matr22 = {
        {26, 30, 26},
        {39, 45, 39},
        {110, 126, 110}
    };
    Matrix matr31 = {
        {-10, -10, -10},
        {130, 130, 130},
        {-150, -150, -150}
    };
    Matrix matr46 = {
        {75, -412},
        {-300, -100}
    };
    Matrix matr64 = {
        {80, 10, 4880, 9820},
        {152, 19, 2172, 4458},
        {-8, -1, 712, 1418},
        {16, 2, -424, -836}
    };

    Matrix matr12r = matrix_dot(matr1, matr2);
    Matrix matr13r = matrix_dot(matr1, matr3);
    Matrix matr22r = matrix_dot(matr2, matr2);
    Matrix matr31r = matrix_dot(matr3, matr1);
    Matrix matr46r = matrix_dot(matr4, matr6);
    Matrix matr64r = matrix_dot(matr6, matr4);

    bool pass1 = compare_matrices(matr12r, matr12);
    bool pass2 = compare_matrices(matr13r, matr13);
    bool pass3 = compare_matrices(matr22r, matr22);
    bool pass4 = compare_matrices(matr31r, matr31);
    bool pass5 = compare_matrices(matr46r, matr46);
    bool pass6 = compare_matrices(matr64r, matr64);

    std::string title;
    if (!pass1) {
        title = "-- test_matrix_dot - Matrix test 1 --";
        print_matrix_report(title, matr12, matr12r);
    }
    if (!pass2) {
        title = "-- test_matrix_dot - Matrix test 2 --";
        print_matrix_report(title, matr13, matr13r);
    }
    if (!pass3) {
        title = "-- test_matrix_dot - Matrix test 3 --";
        print_matrix_report(title, matr22, matr22r);
    }
    if (!pass4) {
        title = "-- test_matrix_dot - Matrix test 4 --";
        print_matrix_report(title, matr31, matr31r);
    }
    if (!pass5) {
        title = "-- test_matrix_dot - Matrix test 5 --";
        print_matrix_report(title, matr46, matr46r);
    }
    if (!pass6) {
        title = "-- test_matrix_dot - Matrix test 6 --";
        print_matrix_report(title, matr64, matr64r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4 || !pass5 || !pass6) {
        QFAIL(qPrintable(QString("One or more valid matrix tests failed. "
                                 "See below for the comparisons.")));
    }

    QVERIFY_EXCEPTION_THROWN(matrix_dot(matr1, matr4), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_dot(matr4, matr1), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_dot(matr4, matr5), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_dot(matr6, matr3), std::out_of_range);
}

void TestMath::test_matrix_dot_scalar()
{
    Matrix matr1 = {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    };
    Matrix matr2 = {
        {2, 2, 2},
        {3, 3, 3},
        {8, 10, 8}
    };
    Matrix matr3 = {
        {-1, -1, 0},
        {0, 6, 20},
        {-15, 10, -25}
    };
    Matrix matr4 = {
        {-8, -1, 12, 18},
        {0, 0, 100, 200}
    };
    Matrix matr5 = {
        {-10, 50, -19, 24},
        {1, 7, -2, -4}
    };

    Matrix matr12 = {
        {10, 10, 10},
        {15, 15, 15},
        {40, 50, 40}
    };
    Matrix matr13 = {
        {-5, -5, 0},
        {0, 30, 100},
        {-75, 50, -125}
    };
    Matrix matr22 = {
        {4, 4, 4},
        {9, 9, 9},
        {64, 100, 64}
    };
    Matrix matr45 = {
        {80, -50, -228, 432},
        {0, 0, -200, -800}
    };

    Matrix matr12r = matrix_dot_scalar(matr1, matr2);
    Matrix matr13r = matrix_dot_scalar(matr1, matr3);
    Matrix matr22r = matrix_dot_scalar(matr2, matr2);
    Matrix matr45r = matrix_dot_scalar(matr4, matr5);

    bool pass1 = compare_matrices(matr12r, matr12);
    bool pass2 = compare_matrices(matr13r, matr13);
    bool pass3 = compare_matrices(matr22r, matr22);
    bool pass4 = compare_matrices(matr45r, matr45);

    std::string title;
    if (!pass1) {
        title = "-- test_matrix_dot_scalar - Matrix test 1 --";
        print_matrix_report(title, matr12, matr12r);
    }
    if (!pass2) {
        title = "-- test_matrix_dot_scalar - Matrix test 2 --";
        print_matrix_report(title, matr13, matr13r);
    }
    if (!pass3) {
        title = "-- test_matrix_dot_scalar - Matrix test 3 --";
        print_matrix_report(title, matr22, matr22r);
    }
    if (!pass4) {
        title = "-- test_matrix_dot_scalar - Matrix test 4 --";
        print_matrix_report(title, matr45, matr45r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4) {
        QFAIL(qPrintable(QString("One or more valid matrix tests failed. "
                                 "See below for the comparisons.")));
    }

    QVERIFY_EXCEPTION_THROWN(matrix_dot_scalar(matr1, matr4), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_dot_scalar(matr1, matr5), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_dot_scalar(matr4, matr2), std::out_of_range);
    QVERIFY_EXCEPTION_THROWN(matrix_dot_scalar(matr5, matr2), std::out_of_range);
}

void TestMath::test_sigmoid()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 0.5000;
    double var2t = 0.7311;
    double var3t = 0.2689;
    double var4t = 0.9820;
    double var5t = 0.0180;

    double var1r = sigmoid(var1);
    double var2r = sigmoid(var2);
    double var3r = sigmoid(var3);
    double var4r = sigmoid(var4);
    double var5r = sigmoid(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_hyperbolic_tangent()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 0.0000;
    double var2t = 0.7616;
    double var3t = -0.7616;
    double var4t = 0.9993;
    double var5t = -0.9993;

    double var1r = hyperbolic_tangent(var1);
    double var2r = hyperbolic_tangent(var2);
    double var3r = hyperbolic_tangent(var3);
    double var4r = hyperbolic_tangent(var4);
    double var5r = hyperbolic_tangent(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_sign()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 0.0000;
    double var2t = 1.0000;
    double var3t = -1.000;
    double var4t = 1.000;
    double var5t = -1.000;

    double var1r = sign(var1);
    double var2r = sign(var2);
    double var3r = sign(var3);
    double var4r = sign(var4);
    double var5r = sign(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_heaviside()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 1.0000;
    double var2t = 1.0000;
    double var3t = 0.0000;
    double var4t = 1.0000;
    double var5t = 0.0000;

    double var1r = heaviside(var1);
    double var2r = heaviside(var2);
    double var3r = heaviside(var3);
    double var4r = heaviside(var4);
    double var5r = heaviside(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_ReLU()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 0.0000;
    double var2t = 1.0000;
    double var3t = 0.0000;
    double var4t = 4.0000;
    double var5t = 0.0000;

    double var1r = ReLU(var1);
    double var2r = ReLU(var2);
    double var3r = ReLU(var3);
    double var4r = ReLU(var4);
    double var5r = ReLU(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_ReLU_leaky()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 0.0000;
    double var2t = 1.0000;
    double var3t = -0.0100;
    double var4t = 4.0000;
    double var5t = -0.0400;

    double var1r = ReLU_leaky(var1);
    double var2r = ReLU_leaky(var2);
    double var3r = ReLU_leaky(var3);
    double var4r = ReLU_leaky(var4);
    double var5r = ReLU_leaky(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_gaussian()
{
    double var1 = 0.00;
    double var2 = 1.00;
    double var3 = -1.00;
    double var4 = 4.00;
    double var5 = -4.00;

    double var1t = 1.0000;
    double var2t = 0.3679;
    double var3t = 0.3679;
    double var4t = 0.0000001;
    double var5t = 0.0000001;

    double var1r = gaussian(var1);
    double var2r = gaussian(var2);
    double var3r = gaussian(var3);
    double var4r = gaussian(var4);
    double var5r = gaussian(var5);

    QVERIFY2(near_double(var1r, var1t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var1t).arg(var1r)));
    QVERIFY2(near_double(var2r, var2t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var2t).arg(var2r)));
    QVERIFY2(near_double(var3r, var3t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var3t).arg(var3r)));
    QVERIFY2(near_double(var4r, var4t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var4t).arg(var4r)));
    QVERIFY2(near_double(var5r, var5t, 0.0001),
             qPrintable(QString("Expected %1, got %2")
                        .arg(var5t).arg(var5r)));
}

void TestMath::test_softmax()
{
    Row row1 =  {0.10, 0.10, 0.10, 0.10, 0.10};
    Row row2 =  {0.10, 0.20, 0.30, 0.40, 0.50};
    Row row3 =  {0.00, 0.00, 0.00, 0.00, 0.00};
    Row row4 =  {1.00, 0.00, 0.00, 0.00, 0.00};
    Row row5 =  {0.00, 0.00, 0.00, 0.00, 1.00};
    Row row6 =  {0.50, 0.40, 0.30, 0.20, 0.10};
    Row row7 =  {-0.10, -0.10, -0.10, -0.10, -0.10};
    Row row8 =  {-0.10, 0.10, -0.10, 0.10, -0.10};
    Row row9 =  {-1.00, 0.00, 0.00, 0.00, 0.00};
    Row row10 = {0.00, 0.00, 0.00, 0.00, -1.00};
    Row row11 = {0.01, 0.10, 1.00, 10.00, -10.00};
    Row row12 = {-0.01, -0.10, -1.00, -10.00, 10.00};
    Row row13 = {1.00};
    Row row14 = {0.00};
    Row row15 = {};

    Row row1t =  {0.2000, 0.2000, 0.2000, 0.2000, 0.2000};
    Row row2t =  {0.1621, 0.1792, 0.1980, 0.2188, 0.2419};
    Row row3t =  {0.2000, 0.2000, 0.2000, 0.2000, 0.2000};
    Row row4t =  {0.4046, 0.1488, 0.1488, 0.1488, 0.1488};
    Row row5t =  {0.1488, 0.1488, 0.1488, 0.1488, 0.4046};
    Row row6t =  {0.2419, 0.2188, 0.1980, 0.1792, 0.1621};
    Row row7t =  {0.2000, 0.2000, 0.2000, 0.2000, 0.2000};
    Row row8t =  {0.1837, 0.2244, 0.1837, 0.2244, 0.1837};
    Row row9t =  {0.0842, 0.2289, 0.2289, 0.2289, 0.2289};
    Row row10t = {0.2289, 0.2289, 0.2289, 0.2289, 0.0842};
    Row row11t = {0.0000, 0.0001, 0.0001, 0.9998, 0.0000};
    Row row12t = {0.0000, 0.0000, 0.0000, 0.0000, 0.9999};
    Row row13t = {1.0000};
    Row row14t = {1.0000};
    Row row15t = {};

    Row row1r =  softmax(row1);
    Row row2r =  softmax(row2);
    Row row3r =  softmax(row3);
    Row row4r =  softmax(row4);
    Row row5r =  softmax(row5);
    Row row6r =  softmax(row6);
    Row row7r =  softmax(row7);
    Row row8r =  softmax(row8);
    Row row9r =  softmax(row9);
    Row row10r = softmax(row10);
    Row row11r = softmax(row11);
    Row row12r = softmax(row12);
    Row row13r = softmax(row13);
    Row row14r = softmax(row14);
    Row row15r = softmax(row15);

    std::vector<bool> passes = {
        compare_rows(row1r, row1t),
        compare_rows(row2r, row2t),
        compare_rows(row3r, row3t),
        compare_rows(row4r, row4t),
        compare_rows(row5r, row5t),
        compare_rows(row6r, row6t),
        compare_rows(row7r, row7t),
        compare_rows(row8r, row8t),
        compare_rows(row9r, row9t),
        compare_rows(row10r, row10t),
        compare_rows(row11r, row11t),
        compare_rows(row12r, row12t),
        compare_rows(row13r, row13t),
        compare_rows(row14r, row14t),
        compare_rows(row15r, row15t),
    };

    bool fail = false;
    for (unsigned int i = 0; i < passes.size(); i++) {
        unsigned int count = i + 1;
        bool pass = passes[i];
        if (!pass) {
            fail = true;
            std::string title = "-- test_softmax - activation test "
                    + std::to_string(count) + " --";
            switch(count) {
            case 1: print_row_report(title, row1t, row1r); break;
            case 2: print_row_report(title, row2t, row2r); break;
            case 3: print_row_report(title, row3t, row3r); break;
            case 4: print_row_report(title, row4t, row4r); break;
            case 5: print_row_report(title, row5t, row5r); break;
            case 6: print_row_report(title, row6t, row6r); break;
            case 7: print_row_report(title, row7t, row7r); break;
            case 8: print_row_report(title, row8t, row8r); break;
            case 9: print_row_report(title, row9t, row9r); break;
            case 10: print_row_report(title, row10t, row10r); break;
            case 11: print_row_report(title, row11t, row11r); break;
            case 12: print_row_report(title, row12t, row12r); break;
            case 13: print_row_report(title, row13t, row13r); break;
            case 14: print_row_report(title, row14t, row14r); break;
            case 15: print_row_report(title, row15t, row15r); break;
            default: break;
            }
        }
    }

    if (fail) {
        QFAIL(qPrintable(QString("One or more valid activation tests "
                                 "failed. See below for the comparisons.")));
    }
}
