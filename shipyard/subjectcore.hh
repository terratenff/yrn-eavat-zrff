#ifndef SUBJECTCORE_HH
#define SUBJECTCORE_HH

#include "settings.hh"
#include "neuralnetwork.hh"
#include "fitness.hh"
#include "inputoutput.hh"

class SubjectCore
{
public:
    static void setPublicInstance(SubjectCore *core, int role);
    SubjectCore();
    virtual ~SubjectCore() = 0;
    virtual void update();
    void setNeuralNetwork(NeuralNetwork *nn);
    NeuralNetwork *getNeuralNetwork();

    void setCoordinates(XY xy);
    void setAxisVelocity(XY xy);
    void setAxisAcceleration(XY xy);

    void setVelocity(double var);
    void setAcceleration(double var);
    void setAngle(double var);
    void setAngularVelocity(double var);

    XY getCoordinates();
    XY getAxisVelocity();
    XY getAxisAcceleration();

    double getVelocity();
    double getAcceleration();
    double getAngle();
    double getAngularVelocity();
private:
    static SubjectCore *primaryTarget_;
    static SubjectCore *secondaryTarget_;
    static SubjectCore *tertiaryTarget_;
    static SubjectCore *mousePoint_;
    static SubjectCore *adversary_;

    NeuralNetwork *nn_;
    Row inputs_;
    Row outputs_;

    XY coordinates_;
    XY axis_velocity_;
    XY axis_acceleration_;

    double velocity_;
    double acceleration_;
    double angle_;
    double angular_velocity_;

    void updateMovement();
    void makeInputs();
    void applyOutputs();
    void updateFitness();
};

#endif // SUBJECTCORE_HH
