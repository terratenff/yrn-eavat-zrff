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
     * \brief TODO
     */
    void test_input_angular_difference();

    /*!
     * \brief TODO
     */
    void test_input_space_scalar_difference();

    /*!
     * \brief TODO
     */
    void test_input_axis_difference();

    /*!
     * \brief TODO
     */
    void test_input_wall_distances();

    /*!
     * \brief TODO
     */
    void test_input_four_way_search();

    /*!
     * \brief TODO
     */
    void test_input_four_corner_search();

    /*!
     * \brief TODO
     */
    void test_output_angular_velocity();

    /*!
     * \brief TODO
     */
    void test_output_direct_angle();

    /*!
     * \brief TODO
     */
    void test_output_angle_velocity();

    /*!
     * \brief TODO
     */
    void test_output_angle_acceleration();

    /*!
     * \brief TODO
     */
    void test_output_axis_velocity();

    /*!
     * \brief TODO
     */
    void test_output_axis_acceleration();

    /*!
     * \brief TODO
     */
    void test_output_small_hops();

    /*!
     * \brief TODO
     */
    void test_output_fixed_movement();
};

#endif // TESTINPUTOUTPUT_HH
