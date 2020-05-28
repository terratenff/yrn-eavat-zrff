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
     * \fn compare_rows
     * \brief Convenient function for comparing two rows to see
     * if they are equal, i.e. have the same elements and size.
     * \param row1 Row 1.
     * \param row2 Row 2.
     * \return true, if given rows are equal. false otherwise.
     */
    bool compare_rows(Row &row1, Row &row2);

    /*!
     * \fn print_row_report
     * \brief Convenient function for printing a report of comparison
     * between two rows.
     * \param title Description of the unit test.
     * \param row1 Row 1 (Expected row).
     * \param row2 Row 2 (Result row).
     */
    void print_row_report(std::string title, Row &row1, Row &row2);
private slots:

    /*!
     * \brief Tests input function "angular_difference".
     *
     * Testing consists of a few instances where a subject and
     * a target are placed in 2D space. Current angle of the
     * subject is known. Using provided information, the results
     * from the input function are compared with expected values.
     */
    void test_input_angular_difference();

    /*!
     * \brief Tests input function "space_scalar_difference".
     *
     * Testing consists of a few instances where a subject and
     * a target are placed in 2D space. Using provided information,
     * the results from the input function are compared with
     * expected values.
     */
    void test_input_space_scalar_difference();

    /*!
     * \brief Tests input function "space_axis_difference".
     *
     * Testing consists of a few instances where a subject and
     * a target are placed in 2D space. Using provided information,
     * the results from the input function are compared with
     * expected values.
     */
    void test_input_axis_difference();

    /*!
     * \brief Tests input function "wall_distances".
     *
     * Testing consists of a few instances where a subject and
     * a target are placed in 2D space. Using provided information,
     * the results from the input function are compared with
     * expected values.
     */
    void test_input_wall_distances();

    /*!
     * \brief Tests input function "four_way_search".
     *
     * Testing consists of a few instances where a subject and
     * a target are placed in 2D space. Using provided information,
     * the results from the input function are compared with
     * expected values.
     */
    void test_input_four_way_search();

    /*!
     * \brief Tests input function "four_corner_search".
     *
     * Testing consists of a few instances where a subject and
     * a target are placed in 2D space. Using provided information,
     * the results from the input function are compared with
     * expected values.
     */
    void test_input_four_corner_search();

    /*!
     * \brief Tests output function "angular_velocity".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_angular_velocity();

    /*!
     * \brief Tests output function "direct_angle".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_direct_angle();

    /*!
     * \brief Tests output function "angle_velocity".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_angle_velocity();

    /*!
     * \brief Tests output function "angle_acceleration".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_angle_acceleration();

    /*!
     * \brief Tests output function "axis_velocity".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_axis_velocity();

    /*!
     * \brief Tests output function "axis_acceleration".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_axis_acceleration();

    /*!
     * \brief Tests output function "small_hops".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_small_hops();

    /*!
     * \brief Tests output function "fixed_movement".
     *
     * Testing consists of a single output size verification.
     */
    void test_output_fixed_movement();
};

#endif // TESTINPUTOUTPUT_HH
