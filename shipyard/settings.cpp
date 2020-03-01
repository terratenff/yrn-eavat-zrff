#include "settings.hh"

Settings::Settings():
    input_type_(ANGULAR_DIFFERENCE),
    output_type_(ANGULAR_VELOCITY),
    fitness_type_(CLOSE_PROXIMITY),
    hidden_layer_count_(2),
    hidden_neuron_count_(10),
    iteration_count_(1000),
    instance_count_(50),
    offspring_count_(25),
    time_delta_(10)
{
}

void Settings::use_default_settings()
{
    input_type_ = ANGULAR_DIFFERENCE;
    output_type_ = ANGULAR_VELOCITY;
    fitness_type_ = CLOSE_PROXIMITY;
    hidden_layer_count_ = 2;
    hidden_neuron_count_ = 10;

    iteration_count_ = 1000;
    instance_count_ = 50;
    offspring_count_ = 25;
    time_delta_ = 10;
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

input_type Settings::get_input_type()
{
    return input_type_;
}

output_type Settings::get_output_type()
{
    return output_type_;
}

fitness_type Settings::get_fitness_type()
{
    return fitness_type_;
}

unsigned int Settings::get_hidden_layer_count()
{
    return hidden_layer_count_;
}

unsigned int Settings::get_hidden_neuron_count()
{
    return hidden_neuron_count_;
}

unsigned int Settings::get_iteration_count()
{
    return iteration_count_;
}

unsigned int Settings::get_instance_count()
{
    return instance_count_;
}

unsigned int Settings::get_offspring_count()
{
    return offspring_count_;
}

unsigned int Settings::get_time_delta()
{
    return time_delta_;
}
