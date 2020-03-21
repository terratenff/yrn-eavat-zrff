#ifndef SETTINGS_HH
#define SETTINGS_HH

enum input_type {
    NO_INPUT,
    ANGULAR_DIFFERENCE,
    SPACE_TOTAL_DIFFERENCE,
    SPACE_AXIS_DIFFERENCE,
    WALL_DISTANCES,
    FOUR_WAY_SEARCH
};
enum output_type {
    NO_OUTPUT,
    ANGULAR_VELOCITY,
    AXIS_VELOCITY,
    AXIS_ACCELERATION,
    SMALL_HOPS,
    FIXED_MOVEMENT
};
enum fitness_type {
    NO_FITNESS,
    CORRECT_ANGLE,
    CLOSE_PROXIMITY,
    FIXED_DISTANCE,
    NOT_OUT_OF_BOUNDS,
    LOOK_FROM_DISTANCE,
    AVOID_EYE_CONTACT
};
enum spawn_point {
    CENTER,
    USER,
    MOUSE,
    RANDOM_POINT,
    SCATTERED,
    NO_SPAWN_POINT
};
enum activation_type {
    SIGMOID,
    HYPERBOLIC_TANGENT,
    SIGN,
    HEAVISIDE,
    RELU,
    RELU_LEAKY,
    GAUSSIAN,
    SOFTMAX,
    NO_ACTIVATION
};
enum breeding_type {
    COPY,
    HEAVILY_MUTATED_COPY,
    CHILD_OF_TWO,
    CHILD_OF_THREE,
    NO_BREEDING
};

class Settings
{
public:
    static Settings *get_settings();

    void use_default_settings();

    // General Settings (MainWindow)

    void set_input_type(input_type type);
    void set_output_type(output_type type);
    void set_fitness_type(fitness_type type);
    void set_hidden_layer_count(unsigned int count);
    void set_hidden_neuron_count(unsigned int count);
    void set_initial_bias(int var);

    void set_iteration_count(unsigned int count);
    void set_instance_count(unsigned int count);
    void set_offspring_count(unsigned int count);
    void set_time_delta(unsigned int time);

    input_type get_input_type();
    output_type get_output_type();
    fitness_type get_fitness_type();
    unsigned int get_hidden_layer_count();
    unsigned int get_hidden_neuron_count();
    int get_initial_bias();

    unsigned int get_iteration_count();
    unsigned int get_instance_count();
    unsigned int get_offspring_count();
    unsigned int get_time_delta();

    // Subject Settings (SubjectWindow)

    void set_velocity_initial(double var);
    void set_velocity_max_change(double var);
    void set_acceleration_initial(double var);
    void set_acceleration_max_change(double var);
    void set_angular_velocity_initial(double var);
    void set_angular_velocity_max_change(double var);
    void set_axis_velocity_x_initial(double var);
    void set_axis_velocity_y_initial(double var);
    void set_axis_velocity_x_max_change(double var);
    void set_axis_velocity_y_max_change(double var);
    void set_axis_acceleration_x_initial(double var);
    void set_axis_acceleration_y_initial(double var);
    void set_axis_acceleration_x_max_change(double var);
    void set_axis_acceleration_y_max_change(double var);
    void set_spawn_location(spawn_point location);

    double get_velocity_initial();
    double get_velocity_max_change();
    double get_acceleration_initial();
    double get_acceleration_max_change();
    double get_angular_velocity_initial();
    double get_angular_velocity_max_change();
    double get_axis_velocity_x_initial();
    double get_axis_velocity_y_initial();
    double get_axis_velocity_x_max_change();
    double get_axis_velocity_y_max_change();
    double get_axis_acceleration_x_initial();
    double get_axis_acceleration_y_initial();
    double get_axis_acceleration_x_max_change();
    double get_axis_acceleration_y_max_change();
    spawn_point get_spawn_location();

    // Network Settings (NetworkWindow)

    void set_initial_weight_minimum(double var);
    void set_initial_weight_maximum(double var);
    void set_activation_function_hidden(activation_type type);
    void set_activation_function_output(activation_type type);

    void set_breeding_method(breeding_type type);
    void set_population_retention_rate(int var);
    void set_mutation_probability(int var);
    void set_mutation_scale_minimum(double var);
    void set_mutation_scale_maximum(double var);

    double get_initial_weight_minimum();
    double get_initial_weight_maximum();
    activation_type get_activation_function_hidden();
    activation_type get_activation_function_output();

    breeding_type get_breeding_method();
    int get_population_retention_rate();
    int get_mutation_probability();
    double get_mutation_scale_minimum();
    double get_mutation_scale_maximum();

private:
    Settings();
    static Settings *instance_;

    // General Parameters.

    input_type input_type_;
    output_type output_type_;
    fitness_type fitness_type_;
    unsigned int hidden_layer_count_;
    unsigned int hidden_neuron_count_;
    int initial_bias_;

    unsigned int iteration_count_;
    unsigned int instance_count_;
    unsigned int offspring_count_;
    unsigned int time_delta_;

    // Subject Parameters.

    double velocity_initial_;
    double velocity_max_change_;
    double acceleration_initial_;
    double acceleration_max_change_;
    double angular_velocity_initial_;
    double angular_velocity_max_change_;
    double axis_velocity_x_initial_;
    double axis_velocity_y_initial_;
    double axis_velocity_x_max_change_;
    double axis_velocity_y_max_change_;
    double axis_acceleration_x_initial_;
    double axis_acceleration_y_initial_;
    double axis_acceleration_x_max_change_;
    double axis_acceleration_y_max_change_;
    spawn_point spawn_location_;

    // Network Parameters.

    double initial_weight_minimum_;
    double initial_weight_maximum_;
    activation_type activation_function_hidden_;
    activation_type activation_function_output_;

    breeding_type breeding_method_;
    int population_retention_rate_;
    int mutation_probability_;
    double mutation_scale_minimum_;
    double mutation_scale_maximum_;
};

#endif // SETTINGS_HH
