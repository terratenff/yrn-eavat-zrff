#ifndef SCENARIO_HH
#define SCENARIO_HH

#include "settings.hh"
#include <unordered_map>
#include <vector>

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

inline std::string get_setting_string(setting_type type)
{
    return setting_enum_strings[type];
}

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

class Scenario
{
public:
    Scenario(const Settings *settings);
    void apply_settings(const Settings *settings);
    void set_settings(Settings *settings);
    void save_scenario(const std::string path);
    int load_scenario(const std::string path);
private:
    std::unordered_map<setting_type, int> settings_data_;
    const double FACTOR_ = 1000;
};

#endif // SCENARIO_HH
