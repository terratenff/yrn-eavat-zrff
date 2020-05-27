#ifndef TESTINPUTOUTPUT_HH
#define TESTINPUTOUTPUT_HH

#include <QtTest>
#include "../shipyard/inputoutput.hh"

/*!
 * \class TestInputOutput
 * \brief Collection of test cases for input and output functions.
 * \author terratenff
 */
class TestInputOutput : public QObject
{
    Q_OBJECT

public:
    TestInputOutput();
    ~TestInputOutput();

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

#endif // TESTINPUTOUTPUT_HH
