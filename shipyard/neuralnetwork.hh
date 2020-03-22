#ifndef NEURALNETWORK_HH
#define NEURALNETWORK_HH

#include "math.hh"
#include "settings.hh"

using namespace std;

class NeuralNetwork
{
public:
    NeuralNetwork(Settings * settings, Random &rand);
    NeuralNetwork(const NeuralNetwork &copy,
                  bool heavyMutation = false);
    NeuralNetwork(const NeuralNetwork &nn1,
                  const NeuralNetwork &nn2);
    NeuralNetwork(const NeuralNetwork &nn1,
                  const NeuralNetwork &nn2,
                  const NeuralNetwork &nn3);

    void mutate();
    Row feedForward(Row &inputs);

    input_type getInputCode();
    output_type getOutputCode();
    fitness_type getFitnessCode();

    void setBias(double var);
    double getBias();

    void addFitness(double var);
    void setFitness(double var);
    double getFitness();

    void resetNeurons();

    static bool compare(NeuralNetwork *nn1, NeuralNetwork *nn2);
private:
    double fitness_;
    Random &rand_;
    vector<unsigned int> layers_;
    Matrix neurons_;
    vector<Matrix> weights_;
    double bias_ = 0;

    input_type input_code_;
    output_type output_code_;
    fitness_type fitness_code_;

    double initial_weight_min_;
    double initial_weight_max_;
    activation_type hidden_activation_;
    activation_type output_activation_;
    int mutation_probability_;
    double mutation_scale_min_;
    double mutation_scale_max_;

    void initializeNeurons();
    void initializeWeights();
    void copyWeights(const vector<Matrix> &weights);
    void copyWeights(const vector<Matrix> &weights1,
                     const vector<Matrix> &weights2);
    void copyWeights(const vector<Matrix> &weights1,
                     const vector<Matrix> &weights2,
                     const vector<Matrix> &weights3);

    double activation(double value, bool output);
};

#endif // NEURALNETWORK_HH
