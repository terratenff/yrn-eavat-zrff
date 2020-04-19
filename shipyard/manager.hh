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

    void skip_generation();
private:
    void clear_subjects();
    void sort_networks();
    void set_subject_parameters(Subject *subject);

    std::vector<int> get_top_subjects(unsigned int count);
    std::vector<int> get_retention_subjects(int retention_rate,
                                            unsigned int population,
                                            unsigned int top_subject_count);
    std::vector<std::vector<int>>
    generate_breeders(breeding_type method,
                      int target_count,
                      std::vector<int> top_subjects,
                      std::vector<int> retention_subjects);

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

    XY random_point_;
};

#endif // MANAGER_HH
