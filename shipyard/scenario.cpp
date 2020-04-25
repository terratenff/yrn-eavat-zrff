#include "scenario.hh"
#include <fstream>
#include <string>

Scenario::Scenario()
{}

void Scenario::apply_settings(const Settings *settings)
{
    settings_data_[INPUT_TYPE] = settings->get_input_type();
    settings_data_[OUTPUT_TYPE] = settings->get_output_type();
    settings_data_[FITNESS_TYPE] = settings->get_fitness_type();
    settings_data_[HIDDEN_LAYER_COUNT] =
            static_cast<int>(settings->get_hidden_layer_count());
    settings_data_[HIDDEN_NEURON_COUNT] =
            static_cast<int>(settings->get_hidden_neuron_count());
    settings_data_[INITIAL_BIAS] = settings->get_initial_bias();
    settings_data_[ITERATION_COUNT] =
            static_cast<int>(settings->get_iteration_count());
    settings_data_[INSTANCE_COUNT] =
            static_cast<int>(settings->get_instance_count());
    settings_data_[OFFSPRING_COUNT] =
            static_cast<int>(settings->get_offspring_count());
    settings_data_[TIME_DELTA] =
            static_cast<int>(settings->get_time_delta());
    settings_data_[VELOCITY_INITIAL] =
            static_cast<int>(settings->get_velocity_initial() * FACTOR_);
    settings_data_[VELOCITY_MAX_CHANGE] =
            static_cast<int>(settings->get_velocity_max_change() * FACTOR_);
    settings_data_[ACCELERATION_INITIAL] =
            static_cast<int>(settings->get_acceleration_initial() * FACTOR_);
    settings_data_[ACCELERATION_MAX_CHANGE] =
            static_cast<int>(settings->get_acceleration_max_change() * FACTOR_);
    settings_data_[ANGULAR_VELOCITY_INITIAL] =
            static_cast<int>(settings->get_angular_velocity_initial() * FACTOR_);
    settings_data_[ANGULAR_VELOCITY_MAX_CHANGE] =
            static_cast<int>(settings->get_angular_velocity_max_change() * FACTOR_);
    settings_data_[AXIS_VELOCITY_X_INITIAL] =
            static_cast<int>(settings->get_axis_velocity_x_initial() * FACTOR_);
    settings_data_[AXIS_VELOCITY_X_MAX_CHANGE] =
            static_cast<int>(settings->get_axis_velocity_x_max_change() * FACTOR_);
    settings_data_[AXIS_VELOCITY_Y_INITIAL] =
            static_cast<int>(settings->get_axis_velocity_y_initial() * FACTOR_);
    settings_data_[AXIS_VELOCITY_Y_MAX_CHANGE] =
            static_cast<int>(settings->get_axis_velocity_y_max_change() * FACTOR_);
    settings_data_[AXIS_ACCELERATION_X_INITIAL] =
            static_cast<int>(settings->get_axis_acceleration_x_initial() * FACTOR_);
    settings_data_[AXIS_ACCELERATION_X_MAX_CHANGE] =
            static_cast<int>(settings->get_axis_acceleration_x_max_change() * FACTOR_);
    settings_data_[AXIS_ACCELERATION_Y_INITIAL] =
            static_cast<int>(settings->get_axis_acceleration_y_initial() * FACTOR_);
    settings_data_[AXIS_ACCELERATION_Y_MAX_CHANGE] =
            static_cast<int>(settings->get_axis_acceleration_y_max_change() * FACTOR_);
    settings_data_[SPAWN_LOCATION] = settings->get_spawn_location();
    settings_data_[INITIAL_WEIGHT_MINIMUM] =
            static_cast<int>(settings->get_initial_weight_minimum() * FACTOR_);
    settings_data_[INITIAL_WEIGHT_MAXIMUM] =
            static_cast<int>(settings->get_initial_weight_maximum() * FACTOR_);
    settings_data_[ACTIVATION_FUNCTION_HIDDEN] = settings->get_activation_function_hidden();
    settings_data_[ACTIVATION_FUNCTION_OUTPUT] = settings->get_activation_function_output();
    settings_data_[BREEDING_METHOD] = settings->get_breeding_method();
    settings_data_[POPULATION_RETENTION_RATE] =
            static_cast<int>(settings->get_population_retention_rate());
    settings_data_[MUTATION_PROBABILITY] =
            static_cast<int>(settings->get_mutation_probability());
    settings_data_[MUTATION_SCALE_MINIMUM] =
            static_cast<int>(settings->get_mutation_scale_minimum() * FACTOR_);
    settings_data_[MUTATION_SCALE_MAXIMUM] =
            static_cast<int>(settings->get_mutation_scale_maximum() * FACTOR_);
}

void Scenario::save_scenario(const std::string path)
{
    if (settings_data_.size() == 0) return;
    std::ofstream file;
    file.open(path);
    std::string prefix;
    std::string middle = ":";
    std::string suffix;
    std::string line;
    for (int setting = INPUT_TYPE; setting != SETTING_END; setting++) {
        setting_type type = static_cast<setting_type>(setting);
        prefix = setting_enum_strings[setting];
        suffix = std::to_string(settings_data_[type]);
        line = prefix + middle + suffix;
        file << line << std::endl;
    }
    file.close();
}

void Scenario::load_scenario(const std::string path)
{
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        std::string line;
        std::string prefix;
        std::string middle = ":";
        std::string suffix;
        while (std::getline(file, line)) {
            if (line.size() == 0) continue;
            prefix = line.substr(0, line.find(middle));
            suffix = line.substr(line.find(middle) + 1, line.size());
            setting_type type = get_setting_type(prefix);
            int value = std::stoi(suffix);
            settings_data_[type] = value;
        }
        file.close();
    } else {
        // TODO: Error
    }
}
