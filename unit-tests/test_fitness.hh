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

private:

    /*!
     * \fn help
     * \brief TODO
     */
    void help();
private slots:

    /*!
     * \brief TODO
     */
    void test_fitness_correct_angle();

    /*!
     * \brief TODO
     */
    void test_fitness_close_proximity();

    /*!
     * \brief TODO
     */
    void test_fitness_fixed_distance();

    /*!
     * \brief TODO
     */
    void test_fitness_not_out_of_bounds();

    /*!
     * \brief TODO
     */
    void test_fitness_look_from_distance();

    /*!
     * \brief TODO
     */
    void test_fitness_avoid_eye_contact();
};

#endif // TESTFITNESS_HH
