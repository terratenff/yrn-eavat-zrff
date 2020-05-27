#ifndef TESTSCENARIO_HH
#define TESTSCENARIO_HH

#include <QtTest>
#include "../shipyard/scenario.hh"
#include "../shipyard/settings.hh"

/*!
 * \class TestScenario
 * \brief Collection of test cases for scenario management.
 * \author terratenff
 */
class TestScenario : public QObject
{
    Q_OBJECT

public:
    TestScenario();
    ~TestScenario();

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

#endif // TESTSCENARIO_HH
