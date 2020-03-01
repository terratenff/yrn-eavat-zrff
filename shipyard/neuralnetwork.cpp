#include "neuralnetwork.hh"

NeuralNetwork::NeuralNetwork(input_type inputCode,
                             output_type outputCode,
                             fitness_type fitnessCode,
                             unsigned int hiddenLayers,
                             unsigned int hiddenNeurons,
                             Random &rand):
    rand_(rand)
{
    layers_.push_back(1); // TODO
    for (unsigned int i = 0; i < hiddenLayers; i++) {
        layers_.push_back(hiddenNeurons);
    }
    layers_.push_back(1); // TODO

    input_code_ = inputCode;
    output_code_ = outputCode;
    fitness_code_ = fitnessCode;

    initializeNeurons();
    initializeWeights();

    fitness_ = 0;
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork &copy):
    rand_(copy.rand_)
{
    layers_ = copy.layers_;

    input_code_ = copy.input_code_;
    output_code_ = copy.output_code_;
    fitness_code_ = copy.fitness_code_;

    initializeNeurons();
    initializeWeights();
    copyWeights(copy.weights_);

    fitness_ = 0;
}

void NeuralNetwork::mutate()
{
    for (unsigned int i = 0; i < weights_.size(); i++) {
        for (unsigned int j = 0; j < weights_[i].size(); j++) {
            for (unsigned int k = 0; k < weights_[i][j].size(); k++) {
                double weight = weights_[i][j][k];

                int decisionMaker = rand_.random_int(0, 100);
                if (decisionMaker <= 2) {
                    weight *= -1;
                } else if (decisionMaker <= 4) {
                    weight = rand_.random_double(-0.5, 0.5);
                } else if (decisionMaker <= 6) {
                    weight *= rand_.random_double(1.0, 2.0);
                } else if (decisionMaker <= 8) {
                    weight *= rand_.random_double(0.0, 1.0);
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
        for (unsigned int j = 0; j < neurons_[i].size(); j++) {
            double value = 0;
            for (unsigned int k = 0; k < neurons_[i - 1].size(); k++) {
                value += weights_[i - 1][j][k] * neurons_[i - 1][k];
            }
            neurons_[i][j] = sigmoid(value);
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
                neuronWeights.push_back(rand_.random_double(-0.5, 0.5));
            }
            weightSet.push_back(neuronWeights);
        }
        weights_.push_back(weightSet);
    }
}

void NeuralNetwork::copyWeights(const vector<Matrix> &weights)
{
    for (unsigned int i = 0; i < weights.size(); i++) {
        for (unsigned int j = 0; j < weights[i].size(); j++) {
            for (unsigned int k = 0; k < weights[i][j].size(); k++) {
                weights_[i][j][k] = weights[i][j][k];
            }
        }
    }
}
