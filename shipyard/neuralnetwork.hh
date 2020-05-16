#ifndef NEURALNETWORK_HH
#define NEURALNETWORK_HH

#include "math.hh"
#include "settings.hh"

using namespace std;

/*!
 * \class NeuralNetwork
 * \brief Contains the implementation of a neural network.
 * \author terratenff
 */
class NeuralNetwork
{
public:

    /*!
     * \brief Basic constructor for a Neural Network.
     * \param settings Application-wide settings.
     * \param rand Random number generator.
     */
    NeuralNetwork(Settings * settings, Random &rand);

    /*!
     * \brief Copy constructor for a Neural Network.
     * Primarily used in crossover function "Copy".
     * \param copy Target Neural Network.
     * \param heavyMutation Flag that determines whether
     * the copied Neural Network should be mutated. This
     * flag is primarily used in the crossover function
     * "Heavily mutated copy".
     */
    NeuralNetwork(const NeuralNetwork &copy,
                  bool heavyMutation = false);

    /*!
     * \brief Copy constructor for a Neural Network.
     * Properties of given Neural Networks are shared
     * with the newly created Neural Network.
     * Primarily used in crossover function "Child of
     * Two".
     * \param nn1 Neural Network 1 (Parent).
     * \param nn2 Neural Network 2 (Parent).
     */
    NeuralNetwork(const NeuralNetwork &nn1,
                  const NeuralNetwork &nn2);

    /*!
     * \brief Copy constructor for a Neural Network.
     * Properties of given Neural Networks are shared
     * with the newly created Neural Network.
     * Primarily used in crossover function "Child
     * of Three".
     * \param nn1 Neural Network 1 (Parent).
     * \param nn2 Neural Network 2 (Parent).
     * \param nn3 Neural Network 3 (Extra).
     */
    NeuralNetwork(const NeuralNetwork &nn1,
                  const NeuralNetwork &nn2,
                  const NeuralNetwork &nn3);

    /*!
     * \fn mutate
     * \brief Mutates the Neural Network by modifying its
     * weights.
     */
    void mutate();

    /*!
     * \fn feedForward
     * \brief Processes given inputs into outputs.
     * \param inputs Target inputs.
     * \return Outputs.
     */
    Row feedForward(Row &inputs);

    /*!
     * \fn getInputCode
     * \brief Getter for the input code, i.e. what kind
     * of input is being used (size, purpose etc.).
     * \return Input type.
     */
    input_type getInputCode();

    /*!
     * \fn getOutputCode
     * \brief Getter for the output code, i.e. what kind
     * of output is to be produced (size, purpose etc.).
     * \return Output type.
     */
    output_type getOutputCode();

    /*!
     * \fn getFitnessCode
     * \brief Getter for the fitness code, i.e. what kind
     * of behaviour is rewarded.
     * \return Fitness type.
     */
    fitness_type getFitnessCode();

    /*!
     * \fn setBias
     * \brief Setter for initial bias.
     * \param var Target bias.
     */
    void setBias(double var);

    /*!
     * \fn getBias
     * \brief Getter for initial bias.
     * \return Bias.
     */
    double getBias();

    /*!
     * \fn addFitness
     * \brief Addition function for fitness.
     * \param var Amount that fitness should be increased by.
     */
    void addFitness(double var);

    /*!
     * \fn setFitness
     * \brief Setter for fitness.
     * \param var Target fitness.
     */
    void setFitness(double var);

    /*!
     * \fn getFitness
     * \brief Getter for fitness.
     * \return Current fitness value.
     */
    double getFitness();

    /*!
     * \fn resetNeurons
     * \brief Resets neurons by setting each of them to zero.
     */
    void resetNeurons();

    /*!
     * \fn compare
     * \brief Comparison function for Neural Networks. Comparison is
     * based on their current fitness values.
     * \param nn1 Neural Network 1.
     * \param nn2 Neural Network 2.
     * \return true/false for which one has greater fitness value.
     */
    static bool compare(NeuralNetwork *nn1, NeuralNetwork *nn2);
private:

    /*!
     * \var fitness_
     * \brief Current fitness value.
     */
    double fitness_;

    /*!
     * \var rand_
     * \brief Random number generator.
     */
    Random &rand_;

    /*!
     * \var layers_
     * \brief Describes the structure of the Neural Network as
     * number of neurons on each layer.
     */
    vector<unsigned int> layers_;

    /*!
     * \var neurons_
     * \brief Contains all of the neurons of the Neural Network.
     */
    Matrix neurons_;

    /*!
     * \var weights_
     * \brief Contains all of the weights between neurons of
     * the Neural Network.
     */
    vector<Matrix> weights_;

    /*!
     * \var bias_
     * \brief Initial bias. This is added on top of other
     * weighted values of neurons.
     */
    double bias_ = 0;

    /*!
     * \var input_code_
     * \brief Input type that is to be used.
     */
    input_type input_code_;

    /*!
     * \var output_code_
     * \brief Output type that is to be used.
     */
    output_type output_code_;

    /*!
     * \var fitness_code_
     * \brief Fitness type that is to be rewarded.
     */
    fitness_type fitness_code_;

    /*!
     * \var initial_weight_min_
     * \brief Minimum value for the initial weight value.
     */
    double initial_weight_min_;

    /*!
     * \var initial_weight_max_
     * \brief Maximum value for the initial weight value.
     */
    double initial_weight_max_;

    /*!
     * \var hidden_activation_
     * \brief Activation function type for the hidden layers.
     */
    activation_type hidden_activation_;

    /*!
     * \var output_activation_
     * \brief Activation function type for the output layer.
     */
    activation_type output_activation_;

    /*!
     * \var mutation_probability_
     * \brief Mutation probability for each weight.
     */
    int mutation_probability_;

    /*!
     * \var mutation_scale_min_
     * \brief Minimum value for the mutation scaling.
     */
    double mutation_scale_min_;

    /*!
     * \var mutation_scale_max_
     * \brief Maximum value for the mutation scaling.
     */
    double mutation_scale_max_;

    /*!
     * \fn initializeNeurons
     * \brief TODO
     */
    void initializeNeurons();

    /*!
     * \fn initializeWeights
     * \brief Initializes the weights by giving them random values
     * between specified min/max values.
     */
    void initializeWeights();

    /*!
     * \fn copyWeights
     * \brief Copies given weights into the Neural Network.
     * \param weights Weights that are to be copied.
     */
    void copyWeights(const vector<Matrix> &weights);

    /*!
     * \fn copyWeights
     * \brief Copies given weights into the Neural Network.
     * The weight sets are selected randomly for each
     * individual weight.
     * \param weights1 Weight set 1.
     * \param weights2 Weight set 2.
     */
    void copyWeights(const vector<Matrix> &weights1,
                     const vector<Matrix> &weights2);

    /*!
     * \fn copyWeights
     * \brief Copies given weights into the Neural Network.
     * The weight sets are selected randomly for each
     * individual weight.
     * \param weights1 Weight set 1.
     * \param weights2 Weight set 2.
     * \param weights3 Weight set 3.
     */
    void copyWeights(const vector<Matrix> &weights1,
                     const vector<Matrix> &weights2,
                     const vector<Matrix> &weights3);

    /*!
     * \fn activation
     * \brief Performs the activation function for the given
     * value. Activation function is selected via specified
     * activation function type.
     * \param value Subject value.
     * \param output Flag that determines whether the value
     * is an output value.
     * \return Activated value.
     */
    double activation(double value, bool output);
};

#endif // NEURALNETWORK_HH
