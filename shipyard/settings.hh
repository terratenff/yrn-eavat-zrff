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
 * \brief Enums that represent various breeding methods
 * (crossover functions).
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
     * \brief Applies default application-wide settings.
     */
    void use_default_settings();

    /*!
     * \fn set_input_type
     * \brief Setter for the input type.
     *
     * Input type determines the size of the neural network input layer
     * and what kinds of inputs it takes.
     *
     * \param type Target input type for the subjects / neural networks..
     */
    void set_input_type(input_type type);

    /*!
     * \fn set_output_type
     * \brief Setter for the output type.
     *
     * Output type determines the size of the neural network output layer
     * and what kinds of outputs it generates.
     *
     * \param type Target output type for the subjects / neural networks.
     */
    void set_output_type(output_type type);

    /*!
     * \fn set_fitness_type
     * \brief Setter for the fitness type.
     *
     * Fitness type determines the function that increases the fitness
     * value in a specific manner: different types define different
     * behaviours that are to be encouraged/discouraged.
     *
     * \param type Target fitness type for the subjects.
     */
    void set_fitness_type(fitness_type type);

    /*!
     * \fn set_hidden_layer_count
     * \brief Setter for the hidden layer count.
     *
     * Hidden layers are situated between the input and output layers
     * of a neural network.
     *
     * \param count Target number of hidden layers for the
     * neural networks.
     */
    void set_hidden_layer_count(unsigned int count);

    /*!
     * \fn set_hidden_neuron_count
     * \brief Setter for the hidden neuron count.
     *
     * The number for the hidden neurons are for an individual hidden layer.
     *
     * \param count Target number of neurons in a hidden layer.
     */
    void set_hidden_neuron_count(unsigned int count);

    /*!
     * \fn set_initial_bias
     * \brief Setter for the initial bias.
     *
     * Bias is a value that is added on the neurons (in addition to
     * the usual values computed from previous neurons and weights),
     * transforming the activation function by shifting it to
     * the left/right.
     *
     * \param var Target initial bias.
     */
    void set_initial_bias(int var);

    /*!
     * \fn set_iteration_count
     * \brief Setter for the iteration count.
     *
     * Iteration count determines how many times the subjects are
     * iterated within a generation (networks take inputs and
     * produce outputs).
     *
     * \param count Target iteration count.
     */
    void set_iteration_count(unsigned int count);

    /*!
     * \fn set_instance_count
     * \brief Setter for the instance count.
     *
     * Instance count determines the size of the population, i.e. the
     * number of subjects / neural networks in the area.
     *
     * \param count Target instance count.
     */
    void set_instance_count(unsigned int count);

    /*!
     * \fn set_offspring_count
     * \brief Setter for the offspring count.
     *
     * Offspring count determines the number of subjects that are to be
     * replaced (due to low fitness value) by the offspring of the
     * better-performing subjects. These are created with a selected
     * crossover function.
     *
     * \param count Target offspring count.
     */
    void set_offspring_count(unsigned int count);

    /*!
     * \fn set_time_delta
     * \brief Setter for time delta.
     *
     * "Time delta" stands for the duration of time that the
     * application waits before proceeding to perform the next
     * iteration. The lower this time is, the faster (and smoother)
     * the generations are; however, with large populations and
     * complex neural networks, low deltas may not hold.
     *
     * \param time Target time delta.
     */
    void set_time_delta(unsigned int time);

    /*!
     * \fn get_input_type
     * \brief Getter for the input type.
     *
     * Input type determines the size of the neural network input layer
     * and what kinds of inputs it takes.
     *
     * \return Current input type.
     */
    input_type get_input_type() const;

    /*!
     * \fn get_output_type
     * \brief Getter for the output type.
     *
     * Output type determines the size of the neural network output layer
     * and what kinds of outputs it generates.
     *
     * \return Current output type.
     */
    output_type get_output_type() const;

    /*!
     * \fn get_fitness_type
     * \brief Getter for the fitness type.
     *
     * Fitness type determines the function that increases the fitness
     * value in a specific manner: different types define different
     * behaviours that are to be encouraged/discouraged.
     *
     * \return Current fitness type.
     */
    fitness_type get_fitness_type() const;

    /*!
     * \fn get_hidden_layer_count
     * \brief Getter for the number of hidden layers used in neural networks.
     *
     * Hidden layers are situated between the input and output layers
     * of a neural network.
     *
     * \return Current number of hidden layers used in neural networks.
     */
    unsigned int get_hidden_layer_count() const;

    /*!
     * \fn get_hidden_neuron_count
     * \brief Getter for the number of neurons in each hidden layer.
     *
     * The number for the hidden neurons are for an individual hidden layer.
     *
     * \return Current number of neurons in each hidden layer.
     */
    unsigned int get_hidden_neuron_count() const;

    /*!
     * \fn get_initial_bias
     * \brief Getter for the initial bias.
     *
     * Bias is a value that is added on the neurons (in addition to
     * the usual values computed from previous neurons and weights),
     * transforming the activation function by shifting it to
     * the left/right.
     *
     * \return Current initial bias.
     */
    int get_initial_bias() const;

    /*!
     * \fn get_iteration_count
     * \brief Getter for the iteration count.
     *
     * Iteration count determines how many times the subjects are
     * iterated within a generation (networks take inputs and
     * produce outputs).
     *
     * \return Current iteration count.
     */
    unsigned int get_iteration_count() const;

    /*!
     * \fn get_instance_count
     * \brief Getter for the instance count.
     *
     * Instance count determines the size of the population, i.e. the
     * number of subjects / neural networks in the area.
     *
     * \return Current instance count.
     */
    unsigned int get_instance_count() const;

    /*!
     * \fn get_offspring_count
     * \brief Getter for the offspring count.
     *
     * Offspring count determines the number of subjects that are to be
     * replaced (due to low fitness value) by the offspring of the
     * better-performing subjects. These are created with a selected
     * crossover function.
     *
     * \return Current offspring count.
     */
    unsigned int get_offspring_count() const;

    /*!
     * \fn get_time_delta
     * \brief Getter for the time delta.
     *
     * "Time delta" stands for the duration of time that the
     * application waits before proceeding to perform the next
     * iteration. The lower this time is, the faster (and smoother)
     * the generations are; however, with large populations and
     * complex neural networks, low deltas may not hold.
     *
     * \return Current time delta.
     */
    unsigned int get_time_delta() const;

    /*!
     * \fn set_velocity_initial
     * \brief Setter for initial velocity.
     *
     * Initial velocity is the velocity that the subjects are given
     * at the beginning of a generation.
     *
     * \param var Target initial velocity.
     */
    void set_velocity_initial(double var);

    /*!
     * \fn set_velocity_max_change
     * \brief Setter for maximum change in velocity.
     *
     * Most settings make neural networks yield an output that varies
     * in the range [-1, 1]. Maximum change in velocity represents
     * the highest possible velocity that a subject can get: the
     * velocity a subject gets is neural network output multiplied
     * by the maximum change in velocity.
     *
     * \param var Target maximum change in velocity.
     */
    void set_velocity_max_change(double var);

    /*!
     * \fn set_acceleration_initial
     * \brief Setter for initial acceleration.
     *
     * Initial acceleration is the acceleration that the subjects are
     * given at the beginning of a generation.
     *
     * \param var Target initial acceleration.
     */
    void set_acceleration_initial(double var);

    /*!
     * \fn set_acceleration_max_change
     * \brief Setter for the maximum change in acceleration.
     *
     * Most settings make neural networks yield an output that varies
     * in the range [-1, 1]. Maximum change in acceleration represents
     * the highest possible acceleration that a subject can get: the
     * acceleration a subject gets is neural network output multiplied
     * by the maximum change in acceleration.
     *
     * \param var Target maximum change in acceleration.
     */
    void set_acceleration_max_change(double var);

    /*!
     * \fn set_angular_velocity_initial
     * \brief Setter for initial angular velocity.
     *
     * Initial angular velocity is the angular velocity that the subjects
     * are given at the beginning of a generation.
     *
     * \param var Target initial angular velocity.
     */
    void set_angular_velocity_initial(double var);

    /*!
     * \fn set_angular_velocity_max_change
     * \brief Setter for maximum change in angular velocity.
     *
     * Most settings make neural networks yield an output that varies
     * in the range [-1, 1]. Maximum change in angular velocity
     * represents the highest possible angular velocity that a subject
     * can get: the angular velocity a subject gets is neural network
     * output multiplied by the maximum change in angular velocity.
     *
     * \param var Target maximum change in angular velocity.
     */
    void set_angular_velocity_max_change(double var);

    /*!
     * \fn set_axis_velocity_x_initial
     * \brief Setter for initial velocity on the X-axis.
     *
     * Initial velocity on the X-axis is the velocity on the X-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial velocity.
     *
     * \param var Target initial velocity on the X-axis.
     */
    void set_axis_velocity_x_initial(double var);

    /*!
     * \fn set_axis_velocity_y_initial
     * \brief Setter for initial velocity on the Y-axis.
     *
     * Initial velocity on the Y-axis is the velocity on the Y-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial velocity.
     *
     * \param var Target initial velocity on the Y-axis.
     */
    void set_axis_velocity_y_initial(double var);

    /*!
     * \fn set_axis_velocity_x_max_change
     * \brief Setter for maximum change in velocity on the X-axis.
     *
     * This is the highest possible velocity on the X-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in velocity.
     *
     * \param var Target maximum change in velocity on the X-axis.
     */
    void set_axis_velocity_x_max_change(double var);

    /*!
     * \fn set_axis_velocity_y_max_change
     * \brief Setter for maximum change in velocity on the Y-axis.
     *
     * This is the highest possible velocity on the Y-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in velocity.
     *
     * \param var Target maximum change in velocity on the Y-axis.
     */
    void set_axis_velocity_y_max_change(double var);

    /*!
     * \fn set_axis_acceleration_x_initial
     * \brief Setter for initial acceleration on the X-axis.
     *
     * Initial acceleration on the X-axis is the acceleration on the X-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial acceleration.
     *
     * \param var Target initial acceleration on the X-axis.
     */
    void set_axis_acceleration_x_initial(double var);

    /*!
     * \fn set_axis_acceleration_y_initial
     * \brief Setter for initial acceleration on the Y-axis.
     *
     * Initial acceleration on the Y-axis is the acceleration on the Y-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial acceleration.
     *
     * \param var Target initial acceleration on the Y-axis.
     */
    void set_axis_acceleration_y_initial(double var);

    /*!
     * \fn set_axis_acceleration_x_max_change
     * \brief Setter for maximum change in acceleration on the X-axis.
     *
     * This is the highest possible acceleration on the X-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in acceleration.
     *
     * \param var Target maximum change in acceleration on the X-axis.
     */
    void set_axis_acceleration_x_max_change(double var);

    /*!
     * \fn set_axis_acceleration_y_max_change
     * \brief Setter for maximum change in acceleration on the Y-axis.
     *
     * This is the highest possible acceleration on the Y-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in acceleration.
     *
     * \param var Target maximum change in acceleration on the Y-axis.
     */
    void set_axis_acceleration_y_max_change(double var);

    /*!
     * \fn set_spawn_location
     * \brief Setter for subject spawn location.
     *
     * Once a generation begins, subjects are distributed in the
     * target area for a set number of iterations. A spawn point
     * defines where the subjects will land at the beginning.
     *
     * \param location Target subject spawn location.
     */
    void set_spawn_location(spawn_point location);

    /*!
     * \fn get_velocity_initial
     * \brief Getter for initial velocity.
     *
     * Initial velocity is the velocity that the subjects are given
     * at the beginning of a generation.
     *
     * \return Current initial velocity.
     */
    double get_velocity_initial() const;

    /*!
     * \fn get_velocity_max_change
     * \brief Getter for maximum change in velocity.
     *
     * Most settings make neural networks yield an output that varies
     * in the range [-1, 1]. Maximum change in velocity represents
     * the highest possible velocity that a subject can get: the
     * velocity a subject gets is neural network output multiplied
     * by the maximum change in velocity.
     *
     * \return Current maximum change in velocity.
     */
    double get_velocity_max_change() const;

    /*!
     * \fn get_acceleration_initial
     * \brief Getter for initial acceleration.
     *
     * Initial acceleration is the acceleration that the subjects are
     * given at the beginning of a generation.
     *
     * \return Current initial acceleration.
     */
    double get_acceleration_initial() const;

    /*!
     * \fn get_acceleration_max_change
     * \brief Getter for maximum change in acceleration.
     *
     * Most settings make neural networks yield an output that varies
     * in the range [-1, 1]. Maximum change in acceleration represents
     * the highest possible acceleration that a subject can get: the
     * acceleration a subject gets is neural network output multiplied
     * by the maximum change in acceleration.
     *
     * \return Current maximum change in acceleration.
     */
    double get_acceleration_max_change() const;

    /*!
     * \fn get_angular_velocity_initial
     * \brief Getter for initial angular velocity.
     *
     * Initial angular velocity is the angular velocity that the subjects
     * are given at the beginning of a generation.
     *
     * \return Current initial angular velocity.
     */
    double get_angular_velocity_initial() const;

    /*!
     * \fn get_angular_velocity_max_change
     * \brief Getter for maximum change in angular velocity.
     *
     * Most settings make neural networks yield an output that varies
     * in the range [-1, 1]. Maximum change in angular velocity
     * represents the highest possible angular velocity that a subject
     * can get: the angular velocity a subject gets is neural network
     * output multiplied by the maximum change in angular velocity.
     *
     * \return Current maximum change in angular velocity.
     */
    double get_angular_velocity_max_change() const;

    /*!
     * \fn get_axis_velocity_x_initial
     * \brief Getter for initial velocity on the X-axis.
     *
     * Initial velocity on the X-axis is the velocity on the X-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial velocity.
     *
     * \return Current initial velocity on the X-axis.
     */
    double get_axis_velocity_x_initial() const;

    /*!
     * \fn get_axis_velocity_y_initial
     * \brief Getter for initial velocity on the Y-axis.
     *
     * Initial velocity on the Y-axis is the velocity on the Y-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial velocity.
     *
     * \return Current initial velocity on the Y-axis.
     */
    double get_axis_velocity_y_initial() const;

    /*!
     * \fn get_axis_velocity_x_max_change
     * \brief Getter for maximum change in velocity on the X-axis.
     *
     * This is the highest possible velocity on the X-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in velocity.
     *
     * \return Current maximum change in velocity on the X-axis.
     */
    double get_axis_velocity_x_max_change() const;

    /*!
     * \fn get_axis_velocity_y_max_change
     * \brief Getter for the maximum change in velocity on the Y-axis.
     *
     * This is the highest possible velocity on the Y-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in velocity.
     *
     * \return Current maximum change in velocity on the Y-axis.
     */
    double get_axis_velocity_y_max_change() const;

    /*!
     * \fn get_axis_acceleration_x_initial
     * \brief Getter for initial acceleration on the X-axis.
     *
     * Initial acceleration on the X-axis is the acceleration on the X-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial acceleration.
     *
     * \return Current initial acceleration on the X-axis.
     */
    double get_axis_acceleration_x_initial() const;

    /*!
     * \fn get_axis_acceleration_y_initial
     * \brief Getter for initial acceleration on the Y-axis.
     *
     * Initial acceleration on the Y-axis is the acceleration on the Y-axis
     * that the subjects are given at the beginning of a generation.
     *
     * This is separate from initial acceleration.
     *
     * \return Current initial acceleration on the Y-axis.
     */
    double get_axis_acceleration_y_initial() const;

    /*!
     * \fn get_axis_acceleration_x_max_change
     * \brief Getter for maximum change in acceleration on the X-axis.
     *
     * This is the highest possible acceleration on the X-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in acceleration.
     *
     * \return Current maximum change in acceleration on the X-axis.
     */
    double get_axis_acceleration_x_max_change() const;

    /*!
     * \fn get_axis_acceleration_y_max_change
     * \brief Getter for maximum change in acceleration on the Y-axis.
     *
     * This is the highest possible acceleration on the Y-axis that a subject
     * can achieve with its neural network outputs, barring some
     * exceptions. Subject gets a value from this by multiplying
     * neural network output with the maximum change.
     *
     * This is separate from maximum change in acceleration.
     *
     * \return Current maximum change in acceleration on the Y-axis.
     */
    double get_axis_acceleration_y_max_change() const;

    /*!
     * \fn get_spawn_location
     * \brief Getter for subject spawn location.
     *
     * Once a generation begins, subjects are distributed in the
     * target area for a set number of iterations. A spawn point
     * defines where the subjects will land at the beginning.
     *
     * \return Current subject spawn location.
     */
    spawn_point get_spawn_location() const;

    /*!
     * \fn set_initial_weight_minimum
     * \brief Setter for minimum initial weight.
     *
     * Initial weights for the neural networks are selected upon
     * initialization randomly between a minimum and a maximum.
     *
     * \param var Target minimum initial weight.
     */
    void set_initial_weight_minimum(double var);

    /*!
     * \fn set_initial_weight_maximum
     * \brief Setter for maximum initial weight.
     *
     * Initial weights for the neural networks are selected upon
     * initialization randomly between a minimum and a maximum.
     *
     * \param var Target maximum initial weight.
     */
    void set_initial_weight_maximum(double var);

    /*!
     * \fn set_activation_function_hidden
     * \brief Setter for the activation function on hidden layers.
     *
     * Activation functions take values from the range (-inf, inf)
     * and convert them to a more suitable range, such as (0, 1) or
     * (-1, 1). The graph that comes with activation functions vary.
     *
     * \param type Target activation function for hidden layers.
     */
    void set_activation_function_hidden(activation_type type);

    /*!
     * \fn set_activation_function_output
     * \brief Setter for the activation function on the output layer.
     *
     * Activation functions take values from the range (-inf, inf)
     * and convert them to a more suitable range, such as (0, 1) or
     * (-1, 1). The graph that comes with activation functions vary.
     *
     * \param type Target activation function for the output layer.
     */
    void set_activation_function_output(activation_type type);

    /*!
     * \fn set_breeding_method
     * \brief Setter for the breeding method.
     *
     * The best fit subjects are selected for the next generation,
     * and the worst fit subjects are replaced by the offspring of
     * the best. The breeding method determines how the offspring
     * are created.
     *
     * \param type Target breeding method (crossover function).
     */
    void set_breeding_method(breeding_type type);

    /*!
     * \fn set_population_retention_rate
     * \brief Setter for population retention rate.
     *
     * In order to maintain the uniqueness of the population, some of
     * the worst fit subjects are selected to be in the next generation.
     * Population retention rate describes the probability for each
     * low-fitness subject that they are selected for the next
     * generation.
     *
     * \param var Target population retention rate, as percentages.
     */
    void set_population_retention_rate(int var);

    /*!
     * \fn set_mutation_probability
     * \brief Setter for neural network mutation probability.
     *
     * Upon the creation of an offspring, it is mutated, so as to
     * make it different from its parents. Mutation probability
     * describes the probability for each neural network weight
     * that they are modified in a random means.
     *
     * \param var Target mutation probability, as percentages.
     */
    void set_mutation_probability(int var);

    /*!
     * \fn set_mutation_scale_minimum
     * \brief Setter for minimum mutation scale.
     *
     * During neural network mutation, there is a possibility that
     * a means of mutation is selected where a form of scaling
     * is involved. In these cases, a random number between minimum
     * and maximum mutation scale is selected to scale it.
     *
     * \param var Target minimum mutation scale.
     */
    void set_mutation_scale_minimum(double var);

    /*!
     * \fn set_mutation_scale_maximum
     * \brief Setter for maximum mutation scale.
     *
     * During neural network mutation, there is a possibility that
     * a means of mutation is selected where a form of scaling
     * is involved. In these cases, a random number between minimum
     * and maximum mutation scale is selected to scale it.
     *
     * \param var Target maximum mutation scale.
     */
    void set_mutation_scale_maximum(double var);

    /*!
     * \fn get_initial_weight_minimum
     * \brief Getter for minimum initial weight.
     *
     * Initial weights for the neural networks are selected upon
     * initialization randomly between a minimum and a maximum.
     *
     * \return Current minimum initial weight.
     */
    double get_initial_weight_minimum() const;

    /*!
     * \fn get_initial_weight_maximum
     * \brief Getter for maximum initial weight.
     *
     * Initial weights for the neural networks are selected upon
     * initialization randomly between a minimum and a maximum.
     *
     * \return Current maximum initial weight.
     */
    double get_initial_weight_maximum() const;

    /*!
     * \fn get_activation_function_hidden
     * \brief Getter for the activation function on hidden layers.
     *
     * Activation functions take values from the range (-inf, inf)
     * and convert them to a more suitable range, such as (0, 1) or
     * (-1, 1). The graph that comes with activation functions vary.
     *
     * \return Current activation function for hidden layers.
     */
    activation_type get_activation_function_hidden() const;

    /*!
     * \fn get_activation_function_output
     * \brief Getter for the activation function on the output layer.
     *
     * Activation functions take values from the range (-inf, inf)
     * and convert them to a more suitable range, such as (0, 1) or
     * (-1, 1). The graph that comes with activation functions vary.
     *
     * \return Current activation function for the output layer.
     */
    activation_type get_activation_function_output() const;

    /*!
     * \fn get_breeding_method
     * \brief Getter for the breeding method.
     *
     * The best fit subjects are selected for the next generation,
     * and the worst fit subjects are replaced by the offspring of
     * the best. The breeding method determines how the offspring
     * are created.
     *
     * \return Current breeding method (crossover function).
     */
    breeding_type get_breeding_method() const;

    /*!
     * \fn get_population_retention_rate
     * \brief Getter for population retention rate.
     *
     * In order to maintain the uniqueness of the population, some of
     * the worst fit subjects are selected to be in the next generation.
     * Population retention rate describes the probability for each
     * low-fitness subject that they are selected for the next
     * generation.
     *
     * \return Current population retention rate, as percentages.
     */
    int get_population_retention_rate() const;

    /*!
     * \fn get_mutation_probability
     * \brief Getter for neural network mutation probability.
     *
     * Upon the creation of an offspring, it is mutated, so as to
     * make it different from its parents. Mutation probability
     * describes the probability for each neural network weight
     * that they are modified in a random means.
     *
     * \return Current mutation probability, as percentages.
     */
    int get_mutation_probability() const;

    /*!
     * \fn get_mutation_scale_minimum
     * \brief Getter for minimum mutation scale.
     *
     * During neural network mutation, there is a possibility that
     * a means of mutation is selected where a form of scaling
     * is involved. In these cases, a random number between minimum
     * and maximum mutation scale is selected to scale it.
     *
     * \return Current minimum mutation scale.
     */
    double get_mutation_scale_minimum() const;

    /*!
     * \fn get_mutation_scale_maximum
     * \brief Getter for maximum mutation scale.
     *
     * During neural network mutation, there is a possibility that
     * a means of mutation is selected where a form of scaling
     * is involved. In these cases, a random number between minimum
     * and maximum mutation scale is selected to scale it.
     *
     * \return Current maximum mutation scale.
     */
    double get_mutation_scale_maximum() const;

private:

    /*!
     * \brief Private constructor. (Singleton pattern)
     */
    Settings();

    /*!
     * \var instance_
     * \brief Static instance of application-wide settings.
     * (Singleton pattern)
     */
    static Settings *instance_;

    /*!
     * \var input_type_
     * \brief Description of the input for a subject and its neural
     * network. Determines neural network input layer size and the
     * nature of the input in general.
     */
    input_type input_type_;

    /*!
     * \var output_type_
     * \brief Description of the output for a subject and its
     * neural network. Determines neural network output layer size
     * and the nature of the output in general.
     */
    output_type output_type_;

    /*!
     * \var fitness_type_
     * \brief Description of the fitness type. Determines the
     * behaviour that is to be encouraged (or discouraged) of
     * the subjects / neural networks.
     */
    fitness_type fitness_type_;

    /*!
     * \var hidden_layer_count_
     * \brief Number of hidden layers within a neural network.
     */
    unsigned int hidden_layer_count_;

    /*!
     * \var hidden_neuron_count_
     * \brief Number of neurons within a hidden layer.
     */
    unsigned int hidden_neuron_count_;

    /*!
     * \var initial_bias_
     * \brief Bias for the neural networks.
     */
    int initial_bias_;

    /*!
     * \var iteration_count_
     * \brief Number of iterations that are to be done before the
     * next generation begins.
     */
    unsigned int iteration_count_;

    /*!
     * \var instance_count_
     * \brief Number of subjects within a simulation, i.e. population
     * size.
     */
    unsigned int instance_count_;

    /*!
     * \var offspring_count_
     * \brief Number of subjects that are to be replaced with the
     * offspring of the best fit subjects.
     */
    unsigned int offspring_count_;

    /*!
     * \var time_delta_
     * \brief Delay between completed iteration and the beginning
     * of the next iteration.
     */
    unsigned int time_delta_;

    /*!
     * \var velocity_initial_
     * \brief Initial velocity of a subject. Initialization occurs
     * at the beginning of each generation.
     */
    double velocity_initial_;

    /*!
     * \var velocity_max_change_
     * \brief Highest possible velocity that a subject can achieve
     * from a neural network output.
     */
    double velocity_max_change_;

    /*!
     * \var acceleration_initial_
     * \brief Initial acceleration of a subject. Initialization occurs
     * at the beginning of each generation.
     */
    double acceleration_initial_;

    /*!
     * \var acceleration_max_change_
     * \brief Highest possible acceleration that a subject can achieve
     * from a neural network output.
     */
    double acceleration_max_change_;

    /*!
     * \var angular_velocity_initial_
     * \brief Initial angular velocity of a subject. Initialization
     * occurs at the beginning of each generation.
     */
    double angular_velocity_initial_;

    /*!
     * \var angular_velocity_max_change_
     * \brief Highest possible angular velocity that a subject can
     * achieve from a neural network output.
     */
    double angular_velocity_max_change_;

    /*!
     * \var axis_velocity_x_initial_
     * \brief Initial, added velocity on the X-axis. Initialization
     * occurs at the beginning of each generation.
     */
    double axis_velocity_x_initial_;

    /*!
     * \var axis_velocity_y_initial_
     * \brief Initial, added velocity on the X-axis. Initialization
     * occurs at the beginning of each generation.
     */
    double axis_velocity_y_initial_;

    /*!
     * \var axis_velocity_x_max_change_
     * \brief Highest possible added velocity on the X-axis that a subject
     * can achieve from a neural network output.
     */
    double axis_velocity_x_max_change_;

    /*!
     * \var axis_velocity_y_max_change_
     * \brief Highest possible added velocity on the Y-axis that a subject
     * can achieve from a neural network output.
     */
    double axis_velocity_y_max_change_;

    /*!
     * \var axis_acceleration_x_initial_
     * \brief Initial, added acceleration on the X-axis. Initialization
     * occurs at the beginning of each generation.
     */
    double axis_acceleration_x_initial_;

    /*!
     * \var axis_acceleration_y_initial_
     * \brief Initial, added acceleration on the Y-axis. Initialization
     * occurs at the beginning of each generation.
     */
    double axis_acceleration_y_initial_;

    /*!
     * \var axis_acceleration_x_max_change_
     * \brief Highest possible added acceleration on the X-axis that
     * a subject can achieve from a neural network output.
     */
    double axis_acceleration_x_max_change_;

    /*!
     * \var axis_acceleration_y_max_change_
     * \brief Highest possible added acceleration on the Y-axis that
     * a subject can achieve from a neural network output.
     */
    double axis_acceleration_y_max_change_;

    /*!
     * \var spawn_location_
     * \brief Spawn point for the subjects.
     */
    spawn_point spawn_location_;

    /*!
     * \var initial_weight_minimum_
     * \brief The lower range value of a random, initial weight.
     */
    double initial_weight_minimum_;

    /*!
     * \var initial_weight_maximum_
     * \brief The higher range value of a random, initial weight.
     */
    double initial_weight_maximum_;

    /*!
     * \var activation_function_hidden_
     * \brief Activation function for hidden layers only.
     */
    activation_type activation_function_hidden_;

    /*!
     * \var activation_function_output_
     * \brief Activation function for the output layer only.
     */
    activation_type activation_function_output_;

    /*!
     * \var breeding_method_
     * \brief Breeding method (crossover function) for the
     * best-fit subjects to use.
     */
    breeding_type breeding_method_;

    /*!
     * \var population_retention_rate_
     * \brief The probability of a low-fitness subject being selected
     * for the next generation.
     */
    int population_retention_rate_;

    /*!
     * \var mutation_probability_
     * \brief The probability of a neural network weight being
     * mutated in a random means.
     */
    int mutation_probability_;

    /*!
     * \var mutation_scale_minimum_
     * \brief The lower range value of a random mutation scale.
     */
    double mutation_scale_minimum_;

    /*!
     * \var mutation_scale_maximum_
     * \brief The higher range value of a random mutation scale.
     */
    double mutation_scale_maximum_;
};

#endif // SETTINGS_HH
