#include "neuralnetwork.hh"

NeuralNetwork::NeuralNetwork(Settings *settings, Random &rand):
    rand_(rand)
{
    unsigned int hiddenLayers = settings->get_hidden_layer_count();
    unsigned int hiddenNeurons = settings->get_hidden_neuron_count();
    input_code_ = settings->get_input_type();
    output_code_ = settings->get_output_type();
    fitness_code_ = settings->get_fitness_type();

    initial_weight_min_ = settings->get_initial_weight_minimum();
    initial_weight_max_ = settings->get_initial_weight_maximum();
    mutation_scale_min_ = settings->get_mutation_scale_minimum();
    mutation_scale_max_ = settings->get_mutation_scale_maximum();
    mutation_probability_ = settings->get_mutation_probability();
    hidden_activation_ = settings->get_activation_function_hidden();
    output_activation_ = settings->get_activation_function_output();

    switch(input_code_) {
    case ANGULAR_DIFFERENCE:
        layers_.push_back(1);
        break;
    case SPACE_TOTAL_DIFFERENCE:
        layers_.push_back(1);
        break;
    case SPACE_AXIS_DIFFERENCE:
        layers_.push_back(2);
        break;
    case WALL_DISTANCES:
        layers_.push_back(4);
        break;
    case FOUR_WAY_SEARCH:
        layers_.push_back(4);
        break;
    case FOUR_CORNER_SEARCH:
        layers_.push_back(4);
        break;
    case NO_INPUT:
        layers_.push_back(1);
        break;
    }

    for (unsigned int i = 0; i < hiddenLayers; i++) {
        layers_.push_back(hiddenNeurons);
    }

    switch(output_code_) {
    case ANGULAR_VELOCITY:
        layers_.push_back(1);
        break;
    case DIRECT_ANGLE:
        layers_.push_back(1);
        break;
    case ANGLE_VELOCITY:
        layers_.push_back(2);
        break;
    case ANGLE_ACCELERATION:
        layers_.push_back(2);
        break;
    case AXIS_VELOCITY:
        layers_.push_back(2);
        break;
    case AXIS_ACCELERATION:
        layers_.push_back(2);
        break;
    case SMALL_HOPS:
        layers_.push_back(2);
        break;
    case FIXED_MOVEMENT:
        layers_.push_back(4);
        break;
    case NO_OUTPUT:
        layers_.push_back(1);
        break;
    }

    initializeNeurons();
    initializeWeights();

    fitness_ = 0;
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork &copy,
                             bool heavyMutation):
    rand_(copy.rand_)
{
    layers_ = copy.layers_;

    input_code_ = copy.input_code_;
    output_code_ = copy.output_code_;
    fitness_code_ = copy.fitness_code_;

    initial_weight_min_ = copy.initial_weight_min_;
    initial_weight_max_ = copy.initial_weight_max_;
    mutation_scale_min_ = copy.mutation_scale_min_;
    mutation_scale_max_ = copy.mutation_scale_max_;
    mutation_probability_ = copy.mutation_probability_;
    hidden_activation_ = copy.hidden_activation_;
    output_activation_ = copy.output_activation_;

    initializeNeurons();
    initializeWeights();
    copyWeights(copy.weights_);

    fitness_ = 0;

    if (heavyMutation) mutate();
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork &nn1,
                             const NeuralNetwork &nn2):
    rand_(nn1.rand_)
{
    layers_ = nn1.layers_;

    input_code_ = nn1.input_code_;
    output_code_ = nn1.output_code_;
    fitness_code_ = nn1.fitness_code_;

    initial_weight_min_ = nn1.initial_weight_min_;
    initial_weight_max_ = nn1.initial_weight_max_;
    mutation_scale_min_ = nn1.mutation_scale_min_;
    mutation_scale_max_ = nn1.mutation_scale_max_;
    mutation_probability_ = nn1.mutation_probability_;
    hidden_activation_ = nn1.hidden_activation_;
    output_activation_ = nn1.output_activation_;

    initializeNeurons();
    initializeWeights();
    copyWeights(nn1.weights_, nn2.weights_);

    fitness_ = 0;
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork &nn1,
                             const NeuralNetwork &nn2,
                             const NeuralNetwork &nn3):
    rand_(nn1.rand_)
{
    layers_ = nn1.layers_;

    input_code_ = nn1.input_code_;
    output_code_ = nn1.output_code_;
    fitness_code_ = nn1.fitness_code_;

    initial_weight_min_ = nn1.initial_weight_min_;
    initial_weight_max_ = nn1.initial_weight_max_;
    mutation_scale_min_ = nn1.mutation_scale_min_;
    mutation_scale_max_ = nn1.mutation_scale_max_;
    mutation_probability_ = nn1.mutation_probability_;
    hidden_activation_ = nn1.hidden_activation_;
    output_activation_ = nn1.output_activation_;

    initializeNeurons();
    initializeWeights();
    copyWeights(nn1.weights_, nn2.weights_, nn3.weights_);

    fitness_ = 0;
}

void NeuralNetwork::mutate()
{
    for (unsigned int i = 0; i < weights_.size(); i++) {
        for (unsigned int j = 0; j < weights_[i].size(); j++) {
            for (unsigned int k = 0; k < weights_[i][j].size(); k++) {
                double weight = weights_[i][j][k];

                int decisionMaker = rand_.random_int(0, 100);
                if (decisionMaker < mutation_probability_) {
                    switch(rand_.random_int(0,4)) {
                    case 0:
                        weight *= -1;
                        break;
                    case 1:
                        weight = rand_.random_double(
                                    mutation_scale_min_,
                                    mutation_scale_max_);
                        break;
                    case 2:
                        weight *= rand_.random_double(
                                    mutation_scale_min_,
                                    mutation_scale_max_);
                        break;
                    case 3:
                        weight *= rand_.random_double(1.0, 2.0);
                        break;
                    default:
                        weight *= rand_.random_double(0.0, 1.0);
                        break;
                    }
                }
                weights_[i][j][k] = weight;
            }
        }
    }
}

Row NeuralNetwork::feedForward(Row &inputs)
{
    for (unsigned int i = 0; i < inputs.size(); i++) {
        neurons_[0][i] = inputs[i];
    }

    for (unsigned int i = 1; i < layers_.size(); i++) {
        bool outputLayer = i == layers_.size() - 1;
        for (unsigned int j = 0; j < neurons_[i].size(); j++) {
            double value = bias_;
            for (unsigned int k = 0; k < neurons_[i - 1].size(); k++) {
                value += weights_[i - 1][j][k] * neurons_[i - 1][k];
            }

            neurons_[i][j] = activation(value, outputLayer);
        }
        if ((outputLayer && output_activation_ == SOFTMAX)
                || (!outputLayer && hidden_activation_ == SOFTMAX)) {
            neurons_[i] = softmax(neurons_[i]);
        }
    }
    Row outputs = neurons_[neurons_.size() - 1];
    return outputs;
}

input_type NeuralNetwork::getInputCode()
{
    return input_code_;
}

output_type NeuralNetwork::getOutputCode()
{
    return output_code_;
}

fitness_type NeuralNetwork::getFitnessCode()
{
    return fitness_code_;
}

void NeuralNetwork::setBias(double var)
{
    bias_ = var;
}

double NeuralNetwork::getBias()
{
    return bias_;
}

void NeuralNetwork::addFitness(double var)
{
    fitness_ += var;
}

void NeuralNetwork::setFitness(double var)
{
    fitness_ = var;
}

double NeuralNetwork::getFitness()
{
    return fitness_;
}

void NeuralNetwork::resetNeurons()
{
    for (unsigned int i = 0; i < neurons_.size(); i++) {
        for (unsigned int j = 0; j < neurons_[i].size(); j++) {
            neurons_[i][j] = 0;
        }
    }
}

bool NeuralNetwork::compare(NeuralNetwork *nn1, NeuralNetwork *nn2)
{
    return nn1->getFitness() > nn2->getFitness();
}

void NeuralNetwork::initializeNeurons()
{
    for (unsigned int i = 0; i < layers_.size(); i++) {
        Row row;
        for (unsigned int j = 0; j < layers_[i]; j++) {
            row.push_back(0);
        }
        neurons_.push_back(row);
    }
}

void NeuralNetwork::initializeWeights()
{
    for (unsigned int i = 1; i < layers_.size(); i++) {
        Matrix weightSet; // Weights between two layers.
        unsigned int neuronCount = layers_[i - 1];
        for (unsigned int j = 0; j < neurons_[i].size(); j++) {
            Row neuronWeights;
            for (unsigned int k = 0; k < neuronCount; k++) {
                neuronWeights.push_back(rand_.random_double(
                                            initial_weight_min_,
                                            initial_weight_max_));
            }
            weightSet.push_back(neuronWeights);
        }
        weights_.push_back(weightSet);
    }
}

void NeuralNetwork::copyWeights(const vector<Matrix> &weights)
{
    for (unsigned int i = 0; i < weights_.size(); i++) {
        for (unsigned int j = 0; j < weights_[i].size(); j++) {
            for (unsigned int k = 0; k < weights_[i][j].size(); k++) {
                weights_[i][j][k] = weights[i][j][k];
            }
        }
    }
}

void NeuralNetwork::copyWeights(const vector<Matrix> &weights1,
                                const vector<Matrix> &weights2)
{
    for (unsigned int i = 0; i < weights_.size(); i++) {
        for (unsigned int j = 0; j < weights_[i].size(); j++) {
            for (unsigned int k = 0; k < weights_[i][j].size(); k++) {
                int decisionMaker = rand_.random_int(0, 2);
                switch(decisionMaker) {
                case 0:
                    weights_[i][j][k] = weights1[i][j][k];
                    break;
                default:
                    weights_[i][j][k] = weights2[i][j][k];
                    break;
                }
            }
        }
    }
}

void NeuralNetwork::copyWeights(const vector<Matrix> &weights1,
                                const vector<Matrix> &weights2,
                                const vector<Matrix> &weights3)
{
    for (unsigned int i = 0; i < weights_.size(); i++) {
        for (unsigned int j = 0; j < weights_[i].size(); j++) {
            for (unsigned int k = 0; k < weights_[i][j].size(); k++) {
                int decisionMaker = rand_.random_int(0, 3);
                switch(decisionMaker) {
                case 0:
                    weights_[i][j][k] = weights1[i][j][k];
                    break;
                case 1:
                    weights_[i][j][k] = weights2[i][j][k];
                    break;
                default:
                    weights_[i][j][k] = weights3[i][j][k];
                    break;
                }
            }
        }
    }
}

double NeuralNetwork::activation(double value, bool output)
{
    activation_type activation_function;
    if (output) {
        activation_function = output_activation_;
    } else {
        activation_function = hidden_activation_;
    }

    switch(activation_function) {
    case SIGMOID:
        return sigmoid(value);
    case HYPERBOLIC_TANGENT:
        return hyperbolic_tangent(value);
    case SIGN:
        return sign(value);
    case HEAVISIDE:
        return heaviside(value);
    case RELU:
        return ReLU(value);
    case RELU_LEAKY:
        return ReLU_leaky(value);
    case GAUSSIAN:
        return gaussian(value);
    case SOFTMAX:
        return value; // computed somewhere else.
    case NO_ACTIVATION:
        return sigmoid(value);
    }
    return sigmoid(value);
}
