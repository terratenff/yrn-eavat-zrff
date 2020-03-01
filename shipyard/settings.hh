#ifndef SETTINGS_HH
#define SETTINGS_HH

enum input_type{
    NO_INPUT,
    ANGULAR_DIFFERENCE,
    SPACE_TOTAL_DIFFERENCE,
    SPACE_AXIS_DIFFERENCE,
    WALL_DISTANCES,
    FOUR_WAY_SEARCH
};
enum output_type{
    NO_OUTPUT,
    ANGULAR_VELOCITY,
    AXIS_VELOCITY,
    AXIS_ACCELERATION,
    SMALL_HOPS,
    FIXED_MOVEMENT
};
enum fitness_type{
    NO_FITNESS,
    CORRECT_ANGLE,
    CLOSE_PROXIMITY,
    FIXED_DISTANCE,
    NOT_OUT_OF_BOUNDS,
    LOOK_FROM_DISTANCE,
    AVOID_EYE_CONTACT
};

class Settings
{
public:
    Settings();
    void use_default_settings();
    void set_input_type(input_type type);
    void set_output_type(output_type type);
    void set_fitness_type(fitness_type type);
    void set_hidden_layer_count(unsigned int count);
    void set_hidden_neuron_count(unsigned int count);

    void set_iteration_count(unsigned int count);
    void set_instance_count(unsigned int count);
    void set_offspring_count(unsigned int count);
    void set_time_delta(unsigned int time);

    input_type get_input_type();
    output_type get_output_type();
    fitness_type get_fitness_type();
    unsigned int get_hidden_layer_count();
    unsigned int get_hidden_neuron_count();

    unsigned int get_iteration_count();
    unsigned int get_instance_count();
    unsigned int get_offspring_count();
    unsigned int get_time_delta();
private:
    input_type input_type_;
    output_type output_type_;
    fitness_type fitness_type_;
    unsigned int hidden_layer_count_;
    unsigned int hidden_neuron_count_;

    unsigned int iteration_count_;
    unsigned int instance_count_;
    unsigned int offspring_count_;
    unsigned int time_delta_;
};

#endif // SETTINGS_HH
