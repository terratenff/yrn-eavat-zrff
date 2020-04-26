#include "settings.hh"

Settings *Settings::instance_ = nullptr;

Settings::Settings():
    input_type_(ANGULAR_DIFFERENCE),
    output_type_(ANGULAR_VELOCITY),
    fitness_type_(CORRECT_ANGLE),
    hidden_layer_count_(2),
    hidden_neuron_count_(10),
    initial_bias_(0),
    iteration_count_(1000),
    instance_count_(50),
    offspring_count_(25),
    time_delta_(10),
    velocity_initial_(2.5),
    velocity_max_change_(10),
    acceleration_initial_(0.001),
    acceleration_max_change_(10),
    angular_velocity_initial_(0),
    angular_velocity_max_change_(20),
    axis_velocity_x_initial_(0),
    axis_velocity_y_initial_(0),
    axis_velocity_x_max_change_(5),
    axis_velocity_y_max_change_(5),
    axis_acceleration_x_initial_(0),
    axis_acceleration_y_initial_(0),
    axis_acceleration_x_max_change_(5),
    axis_acceleration_y_max_change_(5),
    spawn_location_(CENTER),
    initial_weight_minimum_(-0.5),
    initial_weight_maximum_(0.5),
    activation_function_hidden_(SIGMOID),
    activation_function_output_(SIGMOID),
    breeding_method_(COPY),
    population_retention_rate_(10),
    mutation_probability_(10),
    mutation_scale_minimum_(1.0),
    mutation_scale_maximum_(2.0)
{
}

Settings *Settings::get_settings()
{
    if (instance_ == nullptr) {
        instance_ = new Settings();
    }
    return instance_;
}

void Settings::use_default_settings()
{
    input_type_ = ANGULAR_DIFFERENCE;
    output_type_ = ANGULAR_VELOCITY;
    fitness_type_ = CORRECT_ANGLE;
    hidden_layer_count_ = 2;
    hidden_neuron_count_ = 10;

    iteration_count_ = 1000;
    instance_count_ = 50;
    offspring_count_ = 25;
    time_delta_ = 10;

    /*
    velocity_initial_(2.5),
    velocity_max_change_(10),
    acceleration_initial_(0.001),
    acceleration_max_change_(10),
    angular_velocity_initial_(0),
    angular_velocity_max_change_(20),
    axis_velocity_x_initial_(0),
    axis_velocity_y_initial_(0),
    axis_velocity_x_max_change_(5),
    axis_velocity_y_max_change_(5),
    axis_acceleration_x_initial_(0),
    axis_acceleration_y_initial_(0),
    axis_acceleration_x_max_change_(5),
    axis_acceleration_y_max_change_(5),
    spawn_location_(CENTER),
    initial_weight_minimum_(-0.5),
    initial_weight_maximum_(0.5),
    activation_function_hidden_(SIGMOID),
    activation_function_output_(SIGMOID),
    breeding_method_(COPY),
    population_retention_rate_(10),
    mutation_probability_(10),
    mutation_scale_minimum_(1.0),
    mutation_scale_maximum_(2.0)
    */
}

void Settings::set_input_type(input_type type)
{
    input_type_ = type;
}

void Settings::set_output_type(output_type type)
{
    output_type_ = type;
}

void Settings::set_fitness_type(fitness_type type)
{
    fitness_type_ = type;
}

void Settings::set_hidden_layer_count(unsigned int count)
{
    hidden_layer_count_ = count;
}

void Settings::set_hidden_neuron_count(unsigned int count)
{
    hidden_neuron_count_ = count;
}

void Settings::set_initial_bias(int var)
{
    initial_bias_ = var;
}

void Settings::set_iteration_count(unsigned int count)
{
    iteration_count_ = count;
}

void Settings::set_instance_count(unsigned int count)
{
    instance_count_ = count;
}

void Settings::set_offspring_count(unsigned int count)
{
    offspring_count_ = count;
}

void Settings::set_time_delta(unsigned int time)
{
    time_delta_ = time;
}

input_type Settings::get_input_type() const
{
    return input_type_;
}

output_type Settings::get_output_type() const
{
    return output_type_;
}

fitness_type Settings::get_fitness_type() const
{
    return fitness_type_;
}

unsigned int Settings::get_hidden_layer_count() const
{
    return hidden_layer_count_;
}

unsigned int Settings::get_hidden_neuron_count() const
{
    return hidden_neuron_count_;
}

int Settings::get_initial_bias() const
{
    return initial_bias_;
}

unsigned int Settings::get_iteration_count() const
{
    return iteration_count_;
}

unsigned int Settings::get_instance_count() const
{
    return instance_count_;
}

unsigned int Settings::get_offspring_count() const
{
    return offspring_count_;
}

unsigned int Settings::get_time_delta() const
{
    return time_delta_;
}

void Settings::set_velocity_initial(double var)
{
    velocity_initial_ = var;
}

void Settings::set_velocity_max_change(double var)
{
    velocity_max_change_ = var;
}

void Settings::set_acceleration_initial(double var)
{
    acceleration_initial_ = var;
}

void Settings::set_acceleration_max_change(double var)
{
    acceleration_max_change_ = var;
}

void Settings::set_angular_velocity_initial(double var)
{
    angular_velocity_initial_ = var;
}

void Settings::set_angular_velocity_max_change(double var)
{
    angular_velocity_max_change_ = var;
}

void Settings::set_axis_velocity_x_initial(double var)
{
    axis_velocity_x_initial_ = var;
}

void Settings::set_axis_velocity_y_initial(double var)
{
    axis_velocity_y_initial_ = var;
}

void Settings::set_axis_velocity_x_max_change(double var)
{
    axis_velocity_x_max_change_ = var;
}

void Settings::set_axis_velocity_y_max_change(double var)
{
    axis_velocity_y_max_change_ = var;
}

void Settings::set_axis_acceleration_x_initial(double var)
{
    axis_acceleration_x_initial_ = var;
}

void Settings::set_axis_acceleration_y_initial(double var)
{
    axis_acceleration_y_initial_ = var;
}

void Settings::set_axis_acceleration_x_max_change(double var)
{
    axis_acceleration_x_max_change_ = var;
}

void Settings::set_axis_acceleration_y_max_change(double var)
{
    axis_acceleration_y_max_change_ = var;
}

void Settings::set_spawn_location(spawn_point location)
{
    spawn_location_ = location;
}

double Settings::get_velocity_initial() const
{
    return velocity_initial_;
}

double Settings::get_velocity_max_change() const
{
    return velocity_max_change_;
}

double Settings::get_acceleration_initial() const
{
    return acceleration_initial_;
}

double Settings::get_acceleration_max_change() const
{
    return acceleration_max_change_;
}

double Settings::get_angular_velocity_initial() const
{
    return angular_velocity_initial_;
}

double Settings::get_angular_velocity_max_change() const
{
    return angular_velocity_max_change_;
}

double Settings::get_axis_velocity_x_initial() const
{
    return axis_velocity_x_initial_;
}

double Settings::get_axis_velocity_y_initial() const
{
    return axis_velocity_y_initial_;
}

double Settings::get_axis_velocity_x_max_change() const
{
    return axis_velocity_x_max_change_;
}

double Settings::get_axis_velocity_y_max_change() const
{
    return axis_velocity_y_max_change_;
}

double Settings::get_axis_acceleration_x_initial() const
{
    return axis_acceleration_x_initial_;
}

double Settings::get_axis_acceleration_y_initial() const
{
    return axis_acceleration_y_initial_;
}

double Settings::get_axis_acceleration_x_max_change() const
{
    return axis_acceleration_x_max_change_;
}

double Settings::get_axis_acceleration_y_max_change() const
{
    return axis_acceleration_y_max_change_;
}

spawn_point Settings::get_spawn_location() const
{
    return spawn_location_;
}

void Settings::set_initial_weight_minimum(double var)
{
    initial_weight_minimum_ = var;
}

void Settings::set_initial_weight_maximum(double var)
{
    initial_weight_maximum_ = var;
}

void Settings::set_activation_function_hidden(activation_type type)
{
    activation_function_hidden_ = type;
}

void Settings::set_activation_function_output(activation_type type)
{
    activation_function_output_ = type;
}

void Settings::set_breeding_method(breeding_type type)
{
    breeding_method_ = type;
}

void Settings::set_population_retention_rate(int var)
{
    population_retention_rate_ = var;
}

void Settings::set_mutation_probability(int var)
{
    mutation_probability_ = var;
}

void Settings::set_mutation_scale_minimum(double var)
{
    mutation_scale_minimum_ = var;
}

void Settings::set_mutation_scale_maximum(double var)
{
    mutation_scale_maximum_ = var;
}

double Settings::get_initial_weight_minimum() const
{
    return initial_weight_minimum_;
}

double Settings::get_initial_weight_maximum() const
{
    return initial_weight_maximum_;
}

activation_type Settings::get_activation_function_hidden() const
{
    return activation_function_hidden_;
}

activation_type Settings::get_activation_function_output() const
{
    return activation_function_output_;
}

breeding_type Settings::get_breeding_method() const
{
    return breeding_method_;
}

int Settings::get_population_retention_rate() const
{
    return population_retention_rate_;
}

int Settings::get_mutation_probability() const
{
    return mutation_probability_;
}

double Settings::get_mutation_scale_minimum() const
{
    return mutation_scale_minimum_;
}

double Settings::get_mutation_scale_maximum() const
{
    return mutation_scale_maximum_;
}
