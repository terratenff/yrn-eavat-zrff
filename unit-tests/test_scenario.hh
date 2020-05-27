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
     * \brief TODO
     */
    void test_instantiation();

    /*!
     * \brief TODO
     */
    void test_apply_settings();

    /*!
     * \brief TODO
     */
    void test_set_settings();

    /*!
     * \brief TODO
     */
    void test_save_scenario();

    /*!
     * \brief TODO
     */
    void test_load_scenario();
};

#endif // TESTSCENARIO_HH
