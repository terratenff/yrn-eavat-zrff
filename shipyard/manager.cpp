#include "manager.hh"

Manager::Manager(Settings *settings,
                 QGraphicsScene *scene,
                 Random &rand):
    settings_(settings),
    scene_(scene),
    rand_(rand),
    random_point_(0,0)
{
    primaryTarget_ = nullptr;
    secondaryTarget_ = nullptr;
    tertiaryTarget_ = nullptr;
    mousePoint_ = nullptr;
    adversary_ = nullptr;
}

void Manager::initialize(SubjectCore *p,
                         SubjectCore *s,
                         SubjectCore *t,
                         SubjectCore *m,
                         SubjectCore *a)
{
    clear_subjects();

    random_point_ = rand_.random_coordinates();

    primaryTarget_ = p;
    secondaryTarget_ = s;
    tertiaryTarget_ = t;
    mousePoint_ = m;
    adversary_ = a;

    unsigned int instances = settings_->get_instance_count();

    for (unsigned int i = 0; i < instances; i++) {
        NeuralNetwork *nn = new NeuralNetwork(
                   settings_->get_input_type(),
                   settings_->get_output_type(),
                   settings_->get_fitness_type(),
                   settings_->get_hidden_layer_count(),
                   settings_->get_hidden_neuron_count(),
                   rand_
        );
        nn->mutate();
        networks_.push_back(nn);
    }

    for (unsigned int i = 0; i < instances; i++) {
        Subject *subject = new Subject(scene_);
        subject->setNeuralNetwork(networks_[i]);
        set_subject_parameters(subject);
        subject->update();
        subjects_.push_back(subject);
    }
    generation_count_ = 1;
    iteration_count_ = 0;
    iteration_max_ = settings_->get_iteration_count();
}

void Manager::update()
{
    for (Subject *subject : subjects_) {
        subject->update();
    }

    random_point_ = rand_.random_coordinates();

    ++iteration_count_;
    if (iteration_count_ >= iteration_max_) {
        ++generation_count_;
        iteration_count_ = 0;
        unsigned int population = settings_->get_instance_count();
        unsigned int offspringCount = settings_->get_offspring_count();
        sort_networks();
        unsigned int j = 0;
        for (unsigned int i = population - offspringCount; i < population; i++) {
            networks_[i] = new NeuralNetwork(
                        *networks_[j % (population - offspringCount)]
            );

            networks_[i]->mutate();

            if (j < population - offspringCount) {
                networks_[j]->resetNeurons();
            }
            ++j;
        }

        for (unsigned int i = 0; i < population; i++) {
            Subject *subject = subjects_[i];
            subject->setNeuralNetwork(networks_[i]);
            set_subject_parameters(subject);
            subject->update();
        }
    }
}

unsigned int Manager::get_generation_count()
{
    return generation_count_;
}

unsigned int Manager::get_iteration_count()
{
    return iteration_count_;
}

unsigned int Manager::get_iteration_max()
{
    return iteration_max_;
}

void Manager::clear_subjects()
{
    for (auto subject : subjects_)
    {
        delete subject;
    }
    subjects_.clear();
    networks_.clear();
}

void Manager::sort_networks()
{
    std::sort(networks_.begin(), networks_.end(), NeuralNetwork::compare);
}

void Manager::set_subject_parameters(Subject *subject)
{
    subject->getNeuralNetwork()->setFitness(0);
    subject->getNeuralNetwork()->setBias(static_cast<double>(settings_->get_initial_bias()) / 1000);

    switch (settings_->get_spawn_location()) {
    case CENTER:
        subject->setCoordinates(XY(960,540));
        break;
    case USER:
        subject->setCoordinates(primaryTarget_->getCoordinates());
        break;
    case MOUSE:
        subject->setCoordinates(mousePoint_->getCoordinates());
        break;
    case RANDOM_POINT:
        subject->setCoordinates(random_point_);
        break;
    case SCATTERED:
        subject->setCoordinates(rand_.random_coordinates());
        break;
    case NO_SPAWN_POINT:
        subject->setCoordinates(XY(960,540));
        break;
    }


    subject->setAngle(rand_.random_int(0,360));
    subject->setVelocity(settings_->get_velocity_initial());
    subject->setAcceleration(settings_->get_acceleration_initial());
    subject->setAngularVelocity(settings_->get_angular_velocity_initial());

    subject->setAxisVelocity(
                XY(settings_->get_axis_velocity_x_initial(),
                   settings_->get_axis_velocity_y_initial())
                );
    subject->setAxisAcceleration(
                XY(settings_->get_axis_acceleration_x_initial(),
                   settings_->get_axis_acceleration_y_initial())
                );

    subject->setAxisVelocityFactor(
                XY(settings_->get_axis_velocity_x_max_change(),
                   settings_->get_axis_velocity_y_max_change())
                );
    subject->setAxisAccelerationFactor(
                XY(settings_->get_axis_acceleration_x_max_change(),
                   settings_->get_axis_acceleration_y_max_change())
                );

    subject->setVelocityFactor(settings_->get_velocity_max_change());
    subject->setAccelerationFactor(settings_->get_acceleration_max_change());
    subject->setAngularVelocityFactor(settings_->get_angular_velocity_max_change());
}
