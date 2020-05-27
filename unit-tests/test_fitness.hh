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
     * \brief test_1
     */
    void test_1();
};

#endif // TESTFITNESS_HH
