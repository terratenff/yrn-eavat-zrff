#ifndef MANAGER_HH
#define MANAGER_HH

#include "settings.hh"
#include "subject.hh"
#include <QGraphicsScene>
#include <vector>

class Manager
{
public:
    Manager(Settings *settings,
            QGraphicsScene *scene,
            Random &rand);
    void initialize(SubjectCore *p,
                    SubjectCore *s,
                    SubjectCore *t,
                    SubjectCore *m,
                    SubjectCore *a);
    void update();

    unsigned int get_generation_count();
    unsigned int get_iteration_count();
    unsigned int get_iteration_max();
private:
    void clear_subjects();
    void sort_networks();

    SubjectCore *primaryTarget_;
    SubjectCore *secondaryTarget_;
    SubjectCore *tertiaryTarget_;
    SubjectCore *mousePoint_;
    SubjectCore *adversary_;

    Settings *settings_;
    std::vector<Subject*> subjects_;
    std::vector<NeuralNetwork*> networks_;
    QGraphicsScene *scene_;
    Random &rand_;
    unsigned int generation_count_;
    unsigned int iteration_count_;
    unsigned int iteration_max_;
};

#endif // MANAGER_HH
