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

    void setAxisVelocityFactor(XY xy);
    void setAxisAccelerationFactor(XY xy);

    void setVelocityFactor(double var);
    void setAccelerationFactor(double var);
    void setAngularVelocityFactor(double var);

    XY getAxisVelocityFactor();
    XY getAxisAccelerationFactor();

    double getVelocityFactor();
    double getAccelerationFactor();
    double getAngularVelocityFactor();
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

    XY axis_velocity_factor_;
    XY axis_acceleration_factor_;

    double angle_;
    double velocity_;
    double acceleration_;
    double angular_velocity_;

    double velocity_factor_;
    double acceleration_factor_;
    double angular_velocity_factor_;

    void updateMovement();
    void makeInputs();
    void applyOutputs();
    void updateFitness();
};

#endif // SUBJECTCORE_HH
