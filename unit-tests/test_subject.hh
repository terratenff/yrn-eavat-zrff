#ifndef TEST_SUBJECT_HH
#define TEST_SUBJECT_HH

#include <QtTest>
#include "../shipyard/subjectcore.hh"

class TestSubject : public QObject
{
    Q_OBJECT

public:
    TestSubject();
    ~TestSubject();

private slots:
    void test_instantiation();

    void test_movement_velocity();
    void test_movement_acceleration();
    void test_movement_angular_velocity();

    void test_axis_movement_velocity();
    void test_axis_movement_acceleration();

    void test_combined_movement();
};

#endif // TEST_SUBJECT_HH
