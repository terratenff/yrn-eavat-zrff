#include "test_inputoutput.hh"
#include <iostream>

TestInputOutput::TestInputOutput()
{

}

TestInputOutput::~TestInputOutput()
{

}

bool TestInputOutput::compare_rows(Row &row1, Row &row2)
{
    // Check for same number of elements.
    if (row1.size() != row2.size()) return false;

    for (unsigned int i = 0; i < row1.size(); i++) {
        if (!near_double(row1[i], row2[i], 0.0001)) return false;
    }
    return true;
}

void TestInputOutput::print_row_report(std::string title,
                                       Row &row1,
                                       Row &row2)
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

void TestInputOutput::test_input_angular_difference()
{
    double angle1 = 125;
    XY position1(200, 100);
    XY target_position1(400,400);
    double angle2 = 90;
    XY position2(1000, 500);
    XY target_position2(1000,800);
    double angle3 = 300;
    XY position3(960, 540);
    XY target_position3(100,100);

    Row row1t = {0.3816};
    Row row2t = {0.0000};
    Row row3t = {0.5161};

    Row row1r = Input::angular_difference(angle1, position1, target_position1);
    Row row2r = Input::angular_difference(angle2, position2, target_position2);
    Row row3r = Input::angular_difference(angle3, position3, target_position3);

    bool pass1 = compare_rows(row1t, row1r);
    bool pass2 = compare_rows(row2t, row2r);
    bool pass3 = compare_rows(row3t, row3r);

    std::string title;
    if (!pass1) {
        title = "-- test_input_angular_difference - Input test 1 --";
        print_row_report(title, row1t, row1r);
    }
    if (!pass2) {
        title = "-- test_input_angular_difference - Input test 2 --";
        print_row_report(title, row2t, row2r);
    }
    if (!pass3) {
        title = "-- test_input_angular_difference - Input test 3 --";
        print_row_report(title, row3t, row3r);
    }

    if (!pass1 || !pass2 || !pass3) {
        QFAIL(qPrintable(QString("One or more input tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestInputOutput::test_input_space_scalar_difference()
{
    XY position1(200, 100);
    XY target_position1(400,400);
    XY position2(1000, 500);
    XY target_position2(1000,800);
    XY position3(960, 540);
    XY target_position3(100,100);

    Row row1t = {0.1802};
    Row row2t = {0.1500};
    Row row3t = {0.4830};

    Row row1r = Input::space_scalar_difference(position1, target_position1);
    Row row2r = Input::space_scalar_difference(position2, target_position2);
    Row row3r = Input::space_scalar_difference(position3, target_position3);

    bool pass1 = compare_rows(row1t, row1r);
    bool pass2 = compare_rows(row2t, row2r);
    bool pass3 = compare_rows(row3t, row3r);

    std::string title;
    if (!pass1) {
        title = "-- test_input_space_scalar_difference - Input test 1 --";
        print_row_report(title, row1t, row1r);
    }
    if (!pass2) {
        title = "-- test_input_space_scalar_difference - Input test 2 --";
        print_row_report(title, row2t, row2r);
    }
    if (!pass3) {
        title = "-- test_input_space_scalar_difference - Input test 3 --";
        print_row_report(title, row3t, row3r);
    }

    if (!pass1 || !pass2 || !pass3) {
        QFAIL(qPrintable(QString("One or more input tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestInputOutput::test_input_axis_difference()
{
    XY position1(200, 100);
    XY target_position1(400,400);
    XY position2(1000, 500);
    XY target_position2(1000,800);
    XY position3(960, 540);
    XY target_position3(100,100);

    Row row1t = {0.1042, 0.2778};
    Row row2t = {0.0000, 0.2778};
    Row row3t = {-0.4479, -0.4074};

    Row row1r = Input::space_axis_difference(position1, target_position1);
    Row row2r = Input::space_axis_difference(position2, target_position2);
    Row row3r = Input::space_axis_difference(position3, target_position3);

    bool pass1 = compare_rows(row1t, row1r);
    bool pass2 = compare_rows(row2t, row2r);
    bool pass3 = compare_rows(row3t, row3r);

    std::string title;
    if (!pass1) {
        title = "-- test_input_space_axis_difference - Input test 1 --";
        print_row_report(title, row1t, row1r);
    }
    if (!pass2) {
        title = "-- test_input_space_axis_difference - Input test 2 --";
        print_row_report(title, row2t, row2r);
    }
    if (!pass3) {
        title = "-- test_input_space_axis_difference - Input test 3 --";
        print_row_report(title, row3t, row3r);
    }

    if (!pass1 || !pass2 || !pass3) {
        QFAIL(qPrintable(QString("One or more input tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestInputOutput::test_input_wall_distances()
{
    XY position1(200, 100);
    XY position2(1000, 500);
    XY position3(2000, 1500);

    Row row1t = {0.8958, 0.1042, 0.9074, 0.0926};
    Row row2t = {0.4792, 0.5208, 0.5370, 0.4630};
    Row row3t = {0.0000, 1.0000, 0.0000, 1.0000};

    Row row1r = Input::wall_distances(position1);
    Row row2r = Input::wall_distances(position2);
    Row row3r = Input::wall_distances(position3);

    bool pass1 = compare_rows(row1t, row1r);
    bool pass2 = compare_rows(row2t, row2r);
    bool pass3 = compare_rows(row3t, row3r);

    std::string title;
    if (!pass1) {
        title = "-- test_input_wall_distances - Input test 1 --";
        print_row_report(title, row1t, row1r);
    }
    if (!pass2) {
        title = "-- test_input_wall_distances - Input test 2 --";
        print_row_report(title, row2t, row2r);
    }
    if (!pass3) {
        title = "-- test_input_wall_distances - Input test 3 --";
        print_row_report(title, row3t, row3r);
    }

    if (!pass1 || !pass2 || !pass3) {
        QFAIL(qPrintable(QString("One or more input tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestInputOutput::test_input_four_way_search()
{
    XY position1(500, 500);
    XY target_position1(520,1000);
    XY position2(500, 500);
    XY target_position2(480,250);
    XY position3(500, 500);
    XY target_position3(1000,520);
    XY position4(500, 500);
    XY target_position4(250,480);
    XY position5(500, 500);
    XY target_position5(471,529);
    XY position6(500, 500);
    XY target_position6(602,608);
    XY position7(500, 500);
    XY target_position7(399,390);

    Row row1t = {0.0000, 0.0000, 0.0000, 0.2502};
    Row row2t = {0.0000, 0.0000, 0.1253, 0.0000};
    Row row3t = {0.0000, 0.2502, 0.0000, 0.0000};
    Row row4t = {0.1253, 0.0000, 0.0000, 0.0000};
    Row row5t = {0.0205, 0.0000, 0.0000, 0.0205};
    Row row6t = {0.0000, 0.0000, 0.0000, 0.0000};
    Row row7t = {0.0000, 0.0000, 0.0000, 0.0000};

    Row row1r = Input::four_way_search(position1, target_position1);
    Row row2r = Input::four_way_search(position2, target_position2);
    Row row3r = Input::four_way_search(position3, target_position3);
    Row row4r = Input::four_way_search(position4, target_position4);
    Row row5r = Input::four_way_search(position5, target_position5);
    Row row6r = Input::four_way_search(position6, target_position6);
    Row row7r = Input::four_way_search(position7, target_position7);

    bool pass1 = compare_rows(row1t, row1r);
    bool pass2 = compare_rows(row2t, row2r);
    bool pass3 = compare_rows(row3t, row3r);
    bool pass4 = compare_rows(row4t, row4r);
    bool pass5 = compare_rows(row5t, row5r);
    bool pass6 = compare_rows(row6t, row6r);
    bool pass7 = compare_rows(row7t, row7r);

    std::string title;
    if (!pass1) {
        title = "-- test_input_four_way_search - Input test 1 --";
        print_row_report(title, row1t, row1r);
    }
    if (!pass2) {
        title = "-- test_input_four_way_search - Input test 2 --";
        print_row_report(title, row2t, row2r);
    }
    if (!pass3) {
        title = "-- test_input_four_way_search - Input test 3 --";
        print_row_report(title, row3t, row3r);
    }
    if (!pass4) {
        title = "-- test_input_four_way_search - Input test 4 --";
        print_row_report(title, row4t, row4r);
    }
    if (!pass5) {
        title = "-- test_input_four_way_search - Input test 5 --";
        print_row_report(title, row5t, row5r);
    }
    if (!pass6) {
        title = "-- test_input_four_way_search - Input test 6 --";
        print_row_report(title, row6t, row6r);
    }
    if (!pass7) {
        title = "-- test_input_four_way_search - Input test 7 --";
        print_row_report(title, row7t, row7r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4 || !pass5 || !pass6 || !pass7) {
        QFAIL(qPrintable(QString("One or more input tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestInputOutput::test_input_four_corner_search()
{
    XY position1(500, 500);
    XY target_position1(600,1000);
    XY position2(500, 500);
    XY target_position2(400,250);
    XY position3(500, 500);
    XY target_position3(-500,520);
    XY position4(500, 500);
    XY target_position4(550,480);

    Row row1t = {0.0000, 0.0000, 0.0000, 0.2549};
    Row row2t = {0.1346, 0.0000, 0.0000, 0.0000};
    Row row3t = {0.0000, 0.5001, 0.0000, 0.0000};
    Row row4t = {0.0000, 0.0000, 0.0269, 0.0000};

    Row row1r = Input::four_corner_search(position1, target_position1);
    Row row2r = Input::four_corner_search(position2, target_position2);
    Row row3r = Input::four_corner_search(position3, target_position3);
    Row row4r = Input::four_corner_search(position4, target_position4);

    bool pass1 = compare_rows(row1t, row1r);
    bool pass2 = compare_rows(row2t, row2r);
    bool pass3 = compare_rows(row3t, row3r);
    bool pass4 = compare_rows(row4t, row4r);

    std::string title;
    if (!pass1) {
        title = "-- test_input_four_corner_search - Input test 1 --";
        print_row_report(title, row1t, row1r);
    }
    if (!pass2) {
        title = "-- test_input_four_corner_search - Input test 2 --";
        print_row_report(title, row2t, row2r);
    }
    if (!pass3) {
        title = "-- test_input_four_corner_search - Input test 3 --";
        print_row_report(title, row3t, row3r);
    }
    if (!pass4) {
        title = "-- test_input_four_corner_search - Input test 4 --";
        print_row_report(title, row4t, row4r);
    }

    if (!pass1 || !pass2 || !pass3 || !pass4) {
        QFAIL(qPrintable(QString("One or more input tests failed. "
                                 "See below for the comparisons.")));
    }
}

void TestInputOutput::test_output_angular_velocity()
{
    Row output = {0.5};
    double factor = 5000;
    Row result = Output::angular_velocity(output, factor);
    QVERIFY2(result.size() == 1, "Invalid output size.");
}

void TestInputOutput::test_output_direct_angle()
{
    Row output = {0.5};
    Row result = Output::direct_angle(output);
    QVERIFY2(result.size() == 1, "Invalid output size.");
}

void TestInputOutput::test_output_angle_velocity()
{
    Row output = {0.5, 0.5};
    double factor = 5000;
    Row result = Output::angle_velocity(output, factor, factor);
    QVERIFY2(result.size() == 2, "Invalid output size.");
}

void TestInputOutput::test_output_angle_acceleration()
{
    Row output = {0.5, 0.5};
    double factor = 5000;
    Row result = Output::angle_acceleration(output, factor, factor);
    QVERIFY2(result.size() == 2, "Invalid output size.");
}

void TestInputOutput::test_output_axis_velocity()
{
    Row output = {0.5, 0.5};
    XY factor(5000, 5000);
    Row result = Output::axis_velocity(output, factor);
    QVERIFY2(result.size() == 2, "Invalid output size.");
}

void TestInputOutput::test_output_axis_acceleration()
{
    Row output = {0.5, 0.5};
    XY factor(5000, 5000);
    Row result = Output::axis_acceleration(output, factor);
    QVERIFY2(result.size() == 2, "Invalid output size.");
}

void TestInputOutput::test_output_small_hops()
{
    Row output = {0.5, 0.5};
    XY factor(5000, 5000);
    Row result = Output::small_hops(output);
    QVERIFY2(result.size() == 2, "Invalid output size.");
}

void TestInputOutput::test_output_fixed_movement()
{
    Row output = {0.5, 0.5, 0.5, 0.5};
    XY factor(5000, 5000);
    Row result = Output::fixed_movement(output);
    QVERIFY2(result.size() == 4, "Invalid output size.");
}
