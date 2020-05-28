#ifndef TESTFITNESS_HH
#define TESTFITNESS_HH

#include <QtTest>
#include "../shipyard/fitness.hh"

/*!
 * \class TestFitness
 * \brief Collection of test cases for fitness functions.
 * \author terratenff
 */
class TestFitness : public QObject
{
    Q_OBJECT

public:
    TestFitness();
    ~TestFitness();

private slots:

    /*!
     * \brief Tests fitness function "correct_angle".
     *
     * Testing consists of comparing instances to one another:
     * instance A should be of greater fitness than instance B,
     * based on the behaviour that the fitness function describes.
     */
    void test_fitness_correct_angle();

    /*!
     * \brief Tests fitness function "close_proximity".
     *
     * Testing consists of comparing instances to one another:
     * instance A should be of greater fitness than instance B,
     * based on the behaviour that the fitness function describes.
     */
    void test_fitness_close_proximity();

    /*!
     * \brief Tests fitness function "fixed_distance".
     *
     * Testing consists of comparing instances to one another:
     * instance A should be of greater fitness than instance B,
     * based on the behaviour that the fitness function describes.
     */
    void test_fitness_fixed_distance();

    /*!
     * \brief Tests fitness function "not_out_of_bounds".
     *
     * Testing consists of comparing instances to one another:
     * instance A should be of greater fitness than instance B,
     * based on the behaviour that the fitness function describes.
     */
    void test_fitness_not_out_of_bounds();

    /*!
     * \brief Tests fitness function "look_from_distance".
     *
     * Testing consists of comparing instances to one another:
     * instance A should be of greater fitness than instance B,
     * based on the behaviour that the fitness function describes.
     */
    void test_fitness_look_from_distance();

    /*!
     * \brief Tests fitness function "avoid_eye_contact".
     *
     * Testing consists of comparing instances to one another:
     * instance A should be of greater fitness than instance B,
     * based on the behaviour that the fitness function describes.
     */
    void test_fitness_avoid_eye_contact();
};

#endif // TESTFITNESS_HH
