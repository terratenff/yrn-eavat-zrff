#ifndef SCENARIO_HH
#define SCENARIO_HH

#include "settings.hh"
#include <unordered_map>
#include <vector>

/*!
 * \enum setting_type
 * \brief Collection of settings for the purpose of easy
 * mapping.
 * \author terratenff
 */
enum setting_type {
    INPUT_TYPE, OUTPUT_TYPE, FITNESS_TYPE,
    HIDDEN_LAYER_COUNT, HIDDEN_NEURON_COUNT, INITIAL_BIAS,
    ITERATION_COUNT, INSTANCE_COUNT, OFFSPRING_COUNT, TIME_DELTA,
    VELOCITY_INITIAL, VELOCITY_MAX_CHANGE,
    ACCELERATION_INITIAL, ACCELERATION_MAX_CHANGE,
    ANGULAR_VELOCITY_INITIAL, ANGULAR_VELOCITY_MAX_CHANGE,
    AXIS_VELOCITY_X_INITIAL, AXIS_VELOCITY_X_MAX_CHANGE,
    AXIS_VELOCITY_Y_INITIAL, AXIS_VELOCITY_Y_MAX_CHANGE,
    AXIS_ACCELERATION_X_INITIAL, AXIS_ACCELERATION_X_MAX_CHANGE,
    AXIS_ACCELERATION_Y_INITIAL, AXIS_ACCELERATION_Y_MAX_CHANGE,
    SPAWN_LOCATION,
    INITIAL_WEIGHT_MINIMUM, INITIAL_WEIGHT_MAXIMUM,
    ACTIVATION_FUNCTION_HIDDEN, ACTIVATION_FUNCTION_OUTPUT,
    BREEDING_METHOD, POPULATION_RETENTION_RATE,
    MUTATION_PROBABILITY, MUTATION_SCALE_MINIMUM, MUTATION_SCALE_MAXIMUM,

    SETTING_END
};

/*!
 * \var setting_enum_strings
 * \brief Collection of setting types as strings.
 */
static const char *setting_enum_strings[] = {
    "INPUT_TYPE", "OUTPUT_TYPE", "FITNESS_TYPE",
    "HIDDEN_LAYER_COUNT", "HIDDEN_NEURON_COUNT", "INITIAL_BIAS",
    "ITERATION_COUNT", "INSTANCE_COUNT", "OFFSPRING_COUNT", "TIME_DELTA",
    "VELOCITY_INITIAL", "VELOCITY_MAX_CHANGE",
    "ACCELERATION_INITIAL", "ACCELERATION_MAX_CHANGE",
    "ANGULAR_VELOCITY_INITIAL", "ANGULAR_VELOCITY_MAX_CHANGE",
    "AXIS_VELOCITY_X_INITIAL", "AXIS_VELOCITY_X_MAX_CHANGE",
    "AXIS_VELOCITY_Y_INITIAL", "AXIS_VELOCITY_Y_MAX_CHANGE",
    "AXIS_ACCELERATION_X_INITIAL", "AXIS_ACCELERATION_X_MAX_CHANGE",
    "AXIS_ACCELERATION_Y_INITIAL", "AXIS_ACCELERATION_Y_MAX_CHANGE",
    "SPAWN_LOCATION",
    "INITIAL_WEIGHT_MINIMUM", "INITIAL_WEIGHT_MAXIMUM",
    "ACTIVATION_FUNCTION_HIDDEN", "ACTIVATION_FUNCTION_OUTPUT",
    "BREEDING_METHOD", "POPULATION_RETENTION_RATE",
    "MUTATION_PROBABILITY", "MUTATION_SCALE_MINIMUM", "MUTATION_SCALE_MAXIMUM",
    "SETTING_END"
};

/*!
 * \fn get_setting_string
 * \brief Getter for a setting string.
 * \param type Subject setting type.
 * \return Setting string that matches given setting type.
 */
inline std::string get_setting_string(setting_type type)
{
    return setting_enum_strings[type];
}

/*!
 * \fn get_setting_type
 * \brief Getter for a setting type.
 * \param str Subject setting string.
 * \return Setting type that matches given setting string.
 */
inline setting_type get_setting_type(std::string str)
{
    for (int setting = INPUT_TYPE; setting != SETTING_END; setting++) {
        setting_type type = static_cast<setting_type>(setting);
        if (str == setting_enum_strings[type]) {
            return type;
        }
    }
    return SETTING_END;
}

/*!
 * \class Scenario
 * \brief Tracker of settings as suitable strings.
 * \author terratenff
 */
class Scenario
{
public:

    /*!
     * \brief Constructor for a Scenario.
     * \param settings Application-wide settings.
     */
    Scenario(const Settings *settings);

    /*!
     * \fn apply_settings
     * \brief Collects settings into a map of them for ease of use later.
     * \param settings Application-wide settings.
     */
    void apply_settings(const Settings *settings);

    /*!
     * \fn set_settings
     * \brief Transfers settings from the map to the official settings
     * object.
     * \param settings Application-wide settings.
     */
    void set_settings(Settings *settings);

    /*!
     * \fn save_scenario
     * \brief Saves map of settings into a text file.
     * \param path Path to text file.
     */
    void save_scenario(const std::string path);

    /*!
     * \fn load_scenario
     * \brief Reads a text file, from which settings are collected
     * into the map.
     * \param path Path to text file.
     * \return Outcome as an integer code: 0 = OK, 1 = File could not be opened.
     * 2 = File is incorrectly formatted/does not represent the settings.
     */
    int load_scenario(const std::string path);
private:

    /*!
     * \var settings_data_
     * \brief Map of settings. Acts as gateway between the official
     * settings instance and a text file of settings.
     */
    std::unordered_map<setting_type, int> settings_data_;

    /*!
     * \var FACTOR_
     * \brief Some UI components support integers only, even though
     * numbers higher than 0 but less than 1 are desired. This
     * number is used to convert high integer values to actual,
     * desired values.
     */
    const double FACTOR_ = 1000;
};

#endif // SCENARIO_HH
