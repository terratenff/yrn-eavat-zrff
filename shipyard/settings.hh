#ifndef SETTINGS_HH
#define SETTINGS_HH

/*!
 * \enum input_type
 * \brief Enums that represent various input types.
 * \author terratenff
 */
enum input_type {
    NO_INPUT,
    ANGULAR_DIFFERENCE,
    SPACE_TOTAL_DIFFERENCE,
    SPACE_AXIS_DIFFERENCE,
    WALL_DISTANCES,
    FOUR_WAY_SEARCH,
    FOUR_CORNER_SEARCH
};

/*!
 * \enum output_type
 * \brief Enums that represent various output types.
 * \author terratenff
 */
enum output_type {
    NO_OUTPUT,
    ANGULAR_VELOCITY,
    DIRECT_ANGLE,
    ANGLE_VELOCITY,
    ANGLE_ACCELERATION,
    AXIS_VELOCITY,
    AXIS_ACCELERATION,
    SMALL_HOPS,
    FIXED_MOVEMENT
};

/*!
 * \enum fitness_type
 * \brief Enums that represent various fitness determination methods.
 * \author terratenff
 */
enum fitness_type {
    NO_FITNESS,
    CORRECT_ANGLE,
    CLOSE_PROXIMITY,
    FIXED_DISTANCE,
    NOT_OUT_OF_BOUNDS,
    LOOK_FROM_DISTANCE,
    AVOID_EYE_CONTACT
};

/*!
 * \enum spawn_point
 * \brief Enums that represent various spawn points for the subjects.
 * \author terratenff
 */
enum spawn_point {
    CENTER,
    USER,
    MOUSE,
    RANDOM_POINT,
    SCATTERED,
    NO_SPAWN_POINT
};

/*!
 * \enum activation_type
 * \brief Enums that represent various activation functions.
 * \author terratenff
 */
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

/*!
 * \enum breeding_type
 * \brief Enums that represent various breeding methods (crossover functions).
 * \author terratenff
 */
enum breeding_type {
    COPY,
    HEAVILY_MUTATED_COPY,
    CHILD_OF_TWO,
    CHILD_OF_THREE,
    NO_BREEDING
};

/*!
 * \class Settings
 * \brief Application-wide settings.
 * \author terratenff
 */
class Settings
{
public:

    /*!
     * \fn get_settings
     * \brief Getter for singleton-instance of settings.
     * \return Application-wide settings.
     */
    static Settings *get_settings();

    /*!
     * \fn use_default_settings
     * \brief TODO
     */
    void use_default_settings();

    /*!
     * \fn set_input_type
     * \brief TODO
     * \param type
     */
    void set_input_type(input_type type);

    /*!
     * \fn set_output_type
     * \brief TODO
     * \param type
     */
    void set_output_type(output_type type);

    /*!
     * \fn set_fitness_type
     * \brief TODO
     * \param type
     */
    void set_fitness_type(fitness_type type);

    /*!
     * \fn set_hidden_layer_count
     * \brief TODO
     * \param count
     */
    void set_hidden_layer_count(unsigned int count);

    /*!
     * \fn set_hidden_neuron_count
     * \brief TODO
     * \param count
     */
    void set_hidden_neuron_count(unsigned int count);

    /*!
     * \fn set_initial_bias
     * \brief TODO
     * \param var
     */
    void set_initial_bias(int var);

    /*!
     * \fn set_iteration_count
     * \brief TODO
     * \param count
     */
    void set_iteration_count(unsigned int count);

    /*!
     * \fn set_instance_count
     * \brief TODO
     * \param count
     */
    void set_instance_count(unsigned int count);

    /*!
     * \fn set_offspring_count
     * \brief TODO
     * \param count
     */
    void set_offspring_count(unsigned int count);

    /*!
     * \fn set_time_delta
     * \brief TODO
     * \param time
     */
    void set_time_delta(unsigned int time);

    /*!
     * \fn get_input_type
     * \brief TODO
     * \return
     */
    input_type get_input_type() const;

    /*!
     * \fn get_output_type
     * \brief TODO
     * \return
     */
    output_type get_output_type() const;

    /*!
     * \fn get_fitness_type
     * \brief TODO
     * \return
     */
    fitness_type get_fitness_type() const;

    /*!
     * \fn get_hidden_layer_count
     * \brief TODO
     * \return
     */
    unsigned int get_hidden_layer_count() const;

    /*!
     * \fn get_hidden_neuron_count
     * \brief TODO
     * \return
     */
    unsigned int get_hidden_neuron_count() const;

    /*!
     * \fn get_initial_bias
     * \brief TODO
     * \return
     */
    int get_initial_bias() const;

    /*!
     * \fn get_iteration_count
     * \brief TODO
     * \return
     */
    unsigned int get_iteration_count() const;

    /*!
     * \fn get_instance_count
     * \brief TODO
     * \return
     */
    unsigned int get_instance_count() const;

    /*!
     * \fn get_offspring_count
     * \brief TODO
     * \return
     */
    unsigned int get_offspring_count() const;

    /*!
     * \fn get_time_delta
     * \brief TODO
     * \return
     */
    unsigned int get_time_delta() const;

    /*!
     * \fn set_velocity_initial
     * \brief TODO
     * \param var
     */
    void set_velocity_initial(double var);

    /*!
     * \fn set_velocity_max_change
     * \brief TODO
     * \param var
     */
    void set_velocity_max_change(double var);

    /*!
     * \fn set_acceleration_initial
     * \brief TODO
     * \param var
     */
    void set_acceleration_initial(double var);

    /*!
     * \fn set_acceleration_max_change
     * \brief TODO
     * \param var
     */
    void set_acceleration_max_change(double var);

    /*!
     * \fn set_angular_velocity_initial
     * \brief TODO
     * \param var
     */
    void set_angular_velocity_initial(double var);

    /*!
     * \fn set_angular_velocity_max_change
     * \brief TODO
     * \param var
     */
    void set_angular_velocity_max_change(double var);

    /*!
     * \fn set_axis_velocity_x_initial
     * \brief TODO
     * \param var
     */
    void set_axis_velocity_x_initial(double var);

    /*!
     * \fn set_axis_velocity_y_initial
     * \brief TODO
     * \param var
     */
    void set_axis_velocity_y_initial(double var);

    /*!
     * \fn set_axis_velocity_x_max_change
     * \brief TODO
     * \param var
     */
    void set_axis_velocity_x_max_change(double var);

    /*!
     * \fn set_axis_velocity_y_max_change
     * \brief TODO
     * \param var
     */
    void set_axis_velocity_y_max_change(double var);

    /*!
     * \fn set_axis_acceleration_x_initial
     * \brief TODO
     * \param var
     */
    void set_axis_acceleration_x_initial(double var);

    /*!
     * \fn set_axis_acceleration_y_initial
     * \brief TODO
     * \param var
     */
    void set_axis_acceleration_y_initial(double var);

    /*!
     * \fn set_axis_acceleration_x_max_change
     * \brief TODO
     * \param var
     */
    void set_axis_acceleration_x_max_change(double var);

    /*!
     * \fn set_axis_acceleration_y_max_change
     * \brief TODO
     * \param var
     */
    void set_axis_acceleration_y_max_change(double var);

    /*!
     * \fn set_spawn_location
     * \brief TODO
     * \param location
     */
    void set_spawn_location(spawn_point location);

    /*!
     * \fn get_velocity_initial
     * \brief TODO
     * \return
     */
    double get_velocity_initial() const;

    /*!
     * \fn get_velocity_max_change
     * \brief TODO
     * \return
     */
    double get_velocity_max_change() const;

    /*!
     * \fn get_acceleration_initial
     * \brief TODO
     * \return
     */
    double get_acceleration_initial() const;

    /*!
     * \fn get_acceleration_max_change
     * \brief TODO
     * \return
     */
    double get_acceleration_max_change() const;

    /*!
     * \fn get_angular_velocity_initial
     * \brief TODO
     * \return
     */
    double get_angular_velocity_initial() const;

    /*!
     * \fn get_angular_velocity_max_change
     * \brief TODO
     * \return
     */
    double get_angular_velocity_max_change() const;

    /*!
     * \fn get_axis_velocity_x_initial
     * \brief TODO
     * \return
     */
    double get_axis_velocity_x_initial() const;

    /*!
     * \fn get_axis_velocity_y_initial
     * \brief TODO
     * \return
     */
    double get_axis_velocity_y_initial() const;

    /*!
     * \fn get_axis_velocity_x_max_change
     * \brief TODO
     * \return
     */
    double get_axis_velocity_x_max_change() const;

    /*!
     * \fn get_axis_velocity_y_max_change
     * \brief TODO
     * \return
     */
    double get_axis_velocity_y_max_change() const;

    /*!
     * \fn get_axis_acceleration_x_initial
     * \brief TODO
     * \return
     */
    double get_axis_acceleration_x_initial() const;

    /*!
     * \fn get_axis_acceleration_y_initial
     * \brief TODO
     * \return
     */
    double get_axis_acceleration_y_initial() const;

    /*!
     * \fn get_axis_acceleration_x_max_change
     * \brief TODO
     * \return
     */
    double get_axis_acceleration_x_max_change() const;

    /*!
     * \fn get_axis_acceleration_y_max_change
     * \brief TODO
     * \return
     */
    double get_axis_acceleration_y_max_change() const;

    /*!
     * \fn get_spawn_location
     * \brief TODO
     * \return
     */
    spawn_point get_spawn_location() const;

    /*!
     * \fn set_initial_weight_minimum
     * \brief TODO
     * \param var
     */
    void set_initial_weight_minimum(double var);

    /*!
     * \fn set_initial_weight_maximum
     * \brief TODO
     * \param var
     */
    void set_initial_weight_maximum(double var);

    /*!
     * \fn set_activation_function_hidden
     * \brief TODO
     * \param type
     */
    void set_activation_function_hidden(activation_type type);

    /*!
     * \fn set_activation_function_output
     * \brief TODO
     * \param type
     */
    void set_activation_function_output(activation_type type);

    /*!
     * \fn set_breeding_method
     * \brief TODO
     * \param type
     */
    void set_breeding_method(breeding_type type);

    /*!
     * \fn set_population_retention_rate
     * \brief TODO
     * \param var
     */
    void set_population_retention_rate(int var);

    /*!
     * \fn set_mutation_probability
     * \brief TODO
     * \param var
     */
    void set_mutation_probability(int var);

    /*!
     * \fn set_mutation_scale_minimum
     * \brief TODO
     * \param var
     */
    void set_mutation_scale_minimum(double var);

    /*!
     * \fn set_mutation_scale_maximum
     * \brief TODO
     * \param var
     */
    void set_mutation_scale_maximum(double var);

    /*!
     * \fn get_initial_weight_minimum
     * \brief TODO
     * \return
     */
    double get_initial_weight_minimum() const;

    /*!
     * \fn get_initial_weight_maximum
     * \brief TODO
     * \return
     */
    double get_initial_weight_maximum() const;

    /*!
     * \fn get_activation_function_hidden
     * \brief TODO
     * \return
     */
    activation_type get_activation_function_hidden() const;

    /*!
     * \fn get_activation_function_output
     * \brief TODO
     * \return
     */
    activation_type get_activation_function_output() const;

    /*!
     * \fn get_breeding_method
     * \brief TODO
     * \return
     */
    breeding_type get_breeding_method() const;

    /*!
     * \fn get_population_retention_rate
     * \brief TODO
     * \return
     */
    int get_population_retention_rate() const;

    /*!
     * \fn get_mutation_probability
     * \brief TODO
     * \return
     */
    int get_mutation_probability() const;

    /*!
     * \fn get_mutation_scale_minimum
     * \brief TODO
     * \return
     */
    double get_mutation_scale_minimum() const;

    /*!
     * \fn get_mutation_scale_maximum
     * \brief TODO
     * \return
     */
    double get_mutation_scale_maximum() const;

private:

    /*!
     * \brief Private constructor. (Singleton pattern)
     */
    Settings();

    /*!
     * \var instance_
     * \brief Static instance of application-wide settings. (Singleton pattern)
     */
    static Settings *instance_;

    /*!
     * \var input_type_
     * \brief TODO
     */
    input_type input_type_;

    /*!
     * \var output_type_
     * \brief TODO
     */
    output_type output_type_;

    /*!
     * \var fitness_type_
     * \brief TODO
     */
    fitness_type fitness_type_;

    /*!
     * \var hidden_layer_count_
     * \brief TODO
     */
    unsigned int hidden_layer_count_;

    /*!
     * \var hidden_neuron_count_
     * \brief TODO
     */
    unsigned int hidden_neuron_count_;

    /*!
     * \var initial_bias_
     * \brief TODO
     */
    int initial_bias_;

    /*!
     * \var iteration_count_
     * \brief TODO
     */
    unsigned int iteration_count_;

    /*!
     * \var instance_count_
     * \brief TODO
     */
    unsigned int instance_count_;

    /*!
     * \var offspring_count_
     * \brief TODO
     */
    unsigned int offspring_count_;

    /*!
     * \var time_delta_
     * \brief TODO
     */
    unsigned int time_delta_;

    /*!
     * \var velocity_initial_
     * \brief TODO
     */
    double velocity_initial_;

    /*!
     * \var velocity_max_change_
     * \brief TODO
     */
    double velocity_max_change_;

    /*!
     * \var acceleration_initial_
     * \brief TODO
     */
    double acceleration_initial_;

    /*!
     * \var acceleration_max_change_
     * \brief TODO
     */
    double acceleration_max_change_;

    /*!
     * \var angular_velocity_initial_
     * \brief TODO
     */
    double angular_velocity_initial_;

    /*!
     * \var angular_velocity_max_change_
     * \brief TODO
     */
    double angular_velocity_max_change_;

    /*!
     * \var axis_velocity_x_initial_
     * \brief TODO
     */
    double axis_velocity_x_initial_;

    /*!
     * \var axis_velocity_y_initial_
     * \brief TODO
     */
    double axis_velocity_y_initial_;

    /*!
     * \var axis_velocity_x_max_change_
     * \brief TODO
     */
    double axis_velocity_x_max_change_;

    /*!
     * \var axis_velocity_y_max_change_
     * \brief TODO
     */
    double axis_velocity_y_max_change_;

    /*!
     * \var axis_acceleration_x_initial_
     * \brief TODO
     */
    double axis_acceleration_x_initial_;

    /*!
     * \var axis_acceleration_y_initial_
     * \brief TODO
     */
    double axis_acceleration_y_initial_;

    /*!
     * \var axis_acceleration_x_max_change_
     * \brief TODO
     */
    double axis_acceleration_x_max_change_;

    /*!
     * \var axis_acceleration_y_max_change_
     * \brief TODO
     */
    double axis_acceleration_y_max_change_;

    /*!
     * \var spawn_location_
     * \brief TODO
     */
    spawn_point spawn_location_;

    /*!
     * \var initial_weight_minimum_
     * \brief TODO
     */
    double initial_weight_minimum_;

    /*!
     * \var initial_weight_maximum_
     * \brief TODO
     */
    double initial_weight_maximum_;

    /*!
     * \var activation_function_hidden_
     * \brief TODO
     */
    activation_type activation_function_hidden_;

    /*!
     * \var activation_function_output_
     * \brief TODO
     */
    activation_type activation_function_output_;

    /*!
     * \var breeding_method_
     * \brief TODO
     */
    breeding_type breeding_method_;

    /*!
     * \var population_retention_rate_
     * \brief TODO
     */
    int population_retention_rate_;

    /*!
     * \var mutation_probability_
     * \brief TODO
     */
    int mutation_probability_;

    /*!
     * \var mutation_scale_minimum_
     * \brief TODO
     */
    double mutation_scale_minimum_;

    /*!
     * \var mutation_scale_maximum_
     * \brief TODO
     */
    double mutation_scale_maximum_;
};

#endif // SETTINGS_HH
