#include "test_fitness.hh"

TestFitness::TestFitness()
{

}

TestFitness::~TestFitness()
{

}

void TestFitness::test_fitness_correct_angle()
{
    double angle1 = 0;
    double angle2 = 120;
    double angle3 = 240;

    XY position1(500, 500);
    XY position2(300, 300);
    XY position3(1000, 300);

    XY target(1000, 500);

    double instance11 = Fitness::correct_angle(angle1,
                                               position1,
                                               target);
    double instance21 = Fitness::correct_angle(angle2,
                                               position1,
                                               target);
    double instance31 = Fitness::correct_angle(angle3,
                                               position1,
                                               target);

    QVERIFY2(instance11 > instance21,
             qPrintable(QString("Fitness test 1 failed: %1 > %2")
                        .arg(instance11).arg(instance21)));
    QVERIFY2(instance11 > instance31,
             qPrintable(QString("Fitness test 2 failed: %1 > %2")
                        .arg(instance11).arg(instance31)));
    QVERIFY2(near_double(instance21, instance31, 0.0000001),
             qPrintable(QString("Fitness test 3 failed: %1 == %2")
                        .arg(instance21).arg(instance31)));

    double instance12 = Fitness::correct_angle(angle1,
                                               position2,
                                               target);
    double instance22 = Fitness::correct_angle(angle2,
                                               position2,
                                               target);
    double instance32 = Fitness::correct_angle(angle3,
                                               position2,
                                               target);

    QVERIFY2(instance12 > instance22,
             qPrintable(QString("Fitness test 4 failed: %1 > %2")
                        .arg(instance12).arg(instance22)));
    QVERIFY2(instance12 > instance32,
             qPrintable(QString("Fitness test 5 failed: %1 > %2")
                        .arg(instance12).arg(instance32)));
    QVERIFY2(instance22 > instance32,
             qPrintable(QString("Fitness test 6 failed: %1 > %2")
                        .arg(instance22).arg(instance32)));

    double instance13 = Fitness::correct_angle(angle1,
                                               position3,
                                               target);
    double instance23 = Fitness::correct_angle(angle2,
                                               position3,
                                               target);
    double instance33 = Fitness::correct_angle(angle3,
                                               position3,
                                               target);

    QVERIFY2(instance23 > instance13,
             qPrintable(QString("Fitness test 7 failed: %1 > %2")
                        .arg(instance23).arg(instance13)));
    QVERIFY2(instance23 > instance33,
             qPrintable(QString("Fitness test 8 failed: %1 > %2")
                        .arg(instance23).arg(instance33)));
    QVERIFY2(instance13 > instance33,
             qPrintable(QString("Fitness test 9 failed: %1 > %2")
                        .arg(instance13).arg(instance33)));
}

void TestFitness::test_fitness_close_proximity()
{
    XY position1(500, 500);
    XY position2(300, 300);
    XY position3(1000, 300);

    XY target1(1000, 500);
    XY target2(400, 600);
    XY target3(200, 400);

    double instance11 = Fitness::close_proximity(position1,
                                                  target1);
    double instance21 = Fitness::close_proximity(position2,
                                                 target1);
    double instance31 = Fitness::close_proximity(position3,
                                                 target1);

    QVERIFY2(instance31 > instance11,
             qPrintable(QString("Fitness test 1 failed: %1 > %2")
                        .arg(instance31).arg(instance11)));
    QVERIFY2(instance31 > instance21,
             qPrintable(QString("Fitness test 2 failed: %1 > %2")
                        .arg(instance31).arg(instance21)));
    QVERIFY2(instance11 > instance21,
             qPrintable(QString("Fitness test 3 failed: %1 > %2")
                        .arg(instance11).arg(instance21)));

    double instance12 = Fitness::close_proximity(position1,
                                                 target2);
    double instance22 = Fitness::close_proximity(position2,
                                                 target2);
    double instance32 = Fitness::close_proximity(position3,
                                                 target2);

    QVERIFY2(instance12 > instance22,
             qPrintable(QString("Fitness test 4 failed: %1 > %2")
                        .arg(instance12).arg(instance22)));
    QVERIFY2(instance12 > instance32,
             qPrintable(QString("Fitness test 5 failed: %1 > %2")
                        .arg(instance12).arg(instance32)));
    QVERIFY2(instance22 > instance32,
             qPrintable(QString("Fitness test 6 failed: %1 > %2")
                        .arg(instance22).arg(instance32)));

    double instance13 = Fitness::close_proximity(position1,
                                                 target3);
    double instance23 = Fitness::close_proximity(position2,
                                                 target3);
    double instance33 = Fitness::close_proximity(position3,
                                                 target3);

    QVERIFY2(instance23 > instance13,
             qPrintable(QString("Fitness test 7 failed: %1 > %2")
                        .arg(instance23).arg(instance13)));
    QVERIFY2(instance23 > instance33,
             qPrintable(QString("Fitness test 8 failed: %1 > %2")
                        .arg(instance23).arg(instance33)));
    QVERIFY2(instance13 > instance33,
             qPrintable(QString("Fitness test 9 failed: %1 > %2")
                        .arg(instance13).arg(instance33)));
}

void TestFitness::test_fitness_fixed_distance()
{
    XY position1(500, 500);
    XY position2(300, 300);
    XY position3(1000, 300);

    XY target1(1000, 500);
    XY target2(400, 600);
    XY target3(200, 400);

    double instance11 = Fitness::fixed_distance(position1,
                                                target1);
    double instance21 = Fitness::fixed_distance(position2,
                                                target1);
    double instance31 = Fitness::fixed_distance(position3,
                                                target1);

    QVERIFY2(instance11 > instance21,
             qPrintable(QString("Fitness test 1 failed: %1 > %2")
                        .arg(instance11).arg(instance21)));
    QVERIFY2(instance11 > instance31,
             qPrintable(QString("Fitness test 2 failed: %1 > %2")
                        .arg(instance11).arg(instance31)));
    QVERIFY2(near_double(instance21, instance31),
             qPrintable(QString("Fitness test 3 failed: %1 == %2")
                        .arg(instance21).arg(instance31)));

    double instance12 = Fitness::fixed_distance(position1,
                                                target2);
    double instance22 = Fitness::fixed_distance(position2,
                                                target2);
    double instance32 = Fitness::fixed_distance(position3,
                                                target2);

    QVERIFY2(near_double(instance12, instance22),
             qPrintable(QString("Fitness test 4 failed: %1 == %2")
                        .arg(instance12).arg(instance22)));
    QVERIFY2(near_double(instance12, instance32),
             qPrintable(QString("Fitness test 5 failed: %1 == %2")
                        .arg(instance12).arg(instance32)));
    QVERIFY2(near_double(instance22, instance32),
             qPrintable(QString("Fitness test 6 failed: %1 == %2")
                        .arg(instance22).arg(instance32)));

    double instance13 = Fitness::fixed_distance(position1,
                                                target3);
    double instance23 = Fitness::fixed_distance(position2,
                                                target3);
    double instance33 = Fitness::fixed_distance(position3,
                                                target3);

    QVERIFY2(near_double(instance13, instance23),
             qPrintable(QString("Fitness test 7 failed: %1 == %2")
                        .arg(instance13).arg(instance23)));
    QVERIFY2(near_double(instance13, instance33),
             qPrintable(QString("Fitness test 8 failed: %1 == %2")
                        .arg(instance13).arg(instance33)));
    QVERIFY2(near_double(instance23, instance33),
             qPrintable(QString("Fitness test 9 failed: %1 == %2")
                        .arg(instance23).arg(instance33)));
}

void TestFitness::test_fitness_not_out_of_bounds()
{
    XY position1(500, 500);
    XY position2(1200, 1200);
    XY position3(2000, 1000);
    XY position4(-500, 500);
    XY position5(100, -100);
    XY position6(0, 0);

    double instance1 = Fitness::not_out_of_bounds(position1);
    double instance2 = Fitness::not_out_of_bounds(position2);
    double instance3 = Fitness::not_out_of_bounds(position3);
    double instance4 = Fitness::not_out_of_bounds(position4);
    double instance5 = Fitness::not_out_of_bounds(position5);
    double instance6 = Fitness::not_out_of_bounds(position6);

    QVERIFY2(instance1 > 0,
             qPrintable(
                 QString("Fitness test 1 failed: %1 (should be 1).")
                 .arg(instance1)));
    QVERIFY2(instance2 < 0,
             qPrintable(
                 QString("Fitness test 2 failed: %1 (should be -999).")
                 .arg(instance2)));
    QVERIFY2(instance3 < 0,
             qPrintable(
                 QString("Fitness test 3 failed: %1 (should be -999).")
                 .arg(instance3)));
    QVERIFY2(instance4 < 0,
             qPrintable(
                 QString("Fitness test 4 failed: %1 (should be -999).")
                 .arg(instance4)));
    QVERIFY2(instance5 < 0,
             qPrintable(
                 QString("Fitness test 5 failed: %1 (should be -999).")
                 .arg(instance5)));
    QVERIFY2(instance6 > 0,
             qPrintable(
                 QString("Fitness test 6 failed: %1 (should be 1).")
                 .arg(instance6)));
}

void TestFitness::test_fitness_look_from_distance()
{
    double angle1 = 0;
    double angle2 = 120;
    double angle3 = 240;

    XY position1(500, 500);
    XY position2(300, 300);
    XY position3(1000, 300);

    XY target(1000, 500);

    double instance11 = Fitness::look_from_distance(angle1,
                                                    position1,
                                                    target);
    double instance21 = Fitness::look_from_distance(angle2,
                                                    position1,
                                                    target);
    double instance31 = Fitness::look_from_distance(angle3,
                                                    position1,
                                                    target);

    QVERIFY2(instance11 > instance21,
             qPrintable(QString("Fitness test 1 failed: %1 > %2")
                        .arg(instance11).arg(instance21)));
    QVERIFY2(instance11 > instance31,
             qPrintable(QString("Fitness test 2 failed: %1 > %2")
                        .arg(instance11).arg(instance31)));
    QVERIFY2(near_double(instance21, instance31, 0.0000001),
             qPrintable(QString("Fitness test 3 failed: %1 == %2")
                        .arg(instance21).arg(instance31)));

    double instance12 = Fitness::look_from_distance(angle1,
                                                    position2,
                                                    target);
    double instance22 = Fitness::look_from_distance(angle2,
                                                    position2,
                                                    target);
    double instance32 = Fitness::look_from_distance(angle3,
                                                    position2,
                                                    target);

    QVERIFY2(instance12 > instance22,
             qPrintable(QString("Fitness test 4 failed: %1 > %2")
                        .arg(instance12).arg(instance22)));
    QVERIFY2(instance12 > instance32,
             qPrintable(QString("Fitness test 5 failed: %1 > %2")
                        .arg(instance12).arg(instance32)));
    QVERIFY2(instance22 > instance32,
             qPrintable(QString("Fitness test 6 failed: %1 > %2")
                        .arg(instance22).arg(instance32)));

    double instance13 = Fitness::look_from_distance(angle1,
                                                    position3,
                                                    target);
    double instance23 = Fitness::look_from_distance(angle2,
                                                    position3,
                                                     target);
    double instance33 = Fitness::look_from_distance(angle3,
                                                    position3,
                                                    target);

    QVERIFY2(instance13 > instance23,
             qPrintable(QString("Fitness test 7 failed: %1 > %2")
                        .arg(instance13).arg(instance23)));
    QVERIFY2(instance33 > instance23,
             qPrintable(QString("Fitness test 8 failed: %1 > %2")
                        .arg(instance33).arg(instance23)));
    QVERIFY2(instance33 > instance13,
             qPrintable(QString("Fitness test 9 failed: %1 > %2")
                        .arg(instance33).arg(instance13)));
}

void TestFitness::test_fitness_avoid_eye_contact()
{
    XY position(300, 300);
    XY target(500, 300);

    double angle1 = 0;
    double angle2 = 90;
    double angle3 = 180;

    double instance11 = Fitness::avoid_eye_contact(angle1,
                                                   angle1,
                                                   position,
                                                   target);
    double instance21 = Fitness::avoid_eye_contact(angle2,
                                                   angle1,
                                                   position,
                                                   target);
    double instance31 = Fitness::avoid_eye_contact(angle3,
                                                   angle1,
                                                   position,
                                                   target);

    QVERIFY2(instance11 > instance21,
             qPrintable(QString("Fitness test 1 failed: %1 > %2")
                        .arg(instance11).arg(instance21)));
    QVERIFY2(instance11 > instance31,
             qPrintable(QString("Fitness test 2 failed: %1 > %2")
                        .arg(instance11).arg(instance31)));
    QVERIFY2(instance21 > instance31,
             qPrintable(QString("Fitness test 3 failed: %1 > %2")
                        .arg(instance21).arg(instance31)));

    double instance12 = Fitness::avoid_eye_contact(angle1,
                                                   angle2,
                                                   position,
                                                   target);
    double instance22 = Fitness::avoid_eye_contact(angle2,
                                                   angle2,
                                                   position,
                                                   target);
    double instance32 = Fitness::avoid_eye_contact(angle3,
                                                   angle2,
                                                   position,
                                                   target);

    QVERIFY2(instance12 > instance22,
             qPrintable(QString("Fitness test 4 failed: %1 > %2")
                        .arg(instance12).arg(instance22)));
    QVERIFY2(instance12 > instance32,
             qPrintable(QString("Fitness test 5 failed: %1 > %2")
                        .arg(instance12).arg(instance32)));
    QVERIFY2(instance22 > instance32,
             qPrintable(QString("Fitness test 6 failed: %1 > %2")
                        .arg(instance22).arg(instance32)));

    double instance13 = Fitness::avoid_eye_contact(angle1,
                                                   angle3,
                                                   position,
                                                   target);
    double instance23 = Fitness::avoid_eye_contact(angle2,
                                                   angle3,
                                                   position,
                                                   target);
    double instance33 = Fitness::avoid_eye_contact(angle3,
                                                   angle3,
                                                   position,
                                                   target);

    QVERIFY2(instance33 > instance13,
             qPrintable(QString("Fitness test 7 failed: %1 > %2")
                        .arg(instance33).arg(instance13)));
    QVERIFY2(instance33 > instance23,
             qPrintable(QString("Fitness test 8 failed: %1 > %2")
                        .arg(instance33).arg(instance23)));
    QVERIFY2(instance23 > instance13,
             qPrintable(QString("Fitness test 9 failed: %1 > %2")
                        .arg(instance23).arg(instance13)));
}
