#ifndef NEURALNETWORK_HH
#define NEURALNETWORK_HH

#include "math.hh"
#include "settings.hh"

using namespace std;

class NeuralNetwork
{
public:
    NeuralNetwork(input_type inputCode,
                  output_type outputCode,
                  fitness_type fitnessCode,
                  unsigned int hiddenLayers,
                  unsigned int hiddenNeurons,
                  Random &rand);
    NeuralNetwork(const NeuralNetwork &copy);
    void mutate();
    Row feedForward(Row &inputs);

    input_type getInputCode();
    output_type getOutputCode();
    fitness_type getFitnessCode();

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

    input_type input_code_;
    output_type output_code_;
    fitness_type fitness_code_;

    void initializeNeurons();
    void initializeWeights();
    void copyWeights(const vector<Matrix> &weights);
};

#endif // NEURALNETWORK_HH
