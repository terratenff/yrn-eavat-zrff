#ifndef MANAGER_HH
#define MANAGER_HH

#include "settings.hh"
#include "subject.hh"
#include <QGraphicsScene>
#include <vector>

/*!
 * \class Manager
 * \brief Conducts a simulation (iterations of the neural networks
 * and the genetic algorithm) behind the scenes.
 * \author terratenff
 */
class Manager
{
public:

    /*!
     * \brief Creates an instance of a Manager that runs simulations.
     * \param settings Pointer to simulation settings.
     * \param scene Pointer to a graphics scene (Manager creates the
     * subjects that are to be seen in the graphics view).
     * \param rand Reference to a random number generating object.
     */
    Manager(Settings *settings,
            QGraphicsScene *scene,
            Random &rand);

    /*!
     * \fn initialize
     * \brief Prepares everything necessary in order to start a
     * simulation.
     * \param p Primary Target.
     * \param s Secondary Target.
     * \param t Tertiary Target.
     * \param m Mouse Point.
     * \param a Adversary.
     * \pre Current simulation should be halted.
     * \post Manager should be initialized for the next simulation.
     */
    void initialize(SubjectCore *p,
                    SubjectCore *s,
                    SubjectCore *t,
                    SubjectCore *m,
                    SubjectCore *a);

    /*!
     * \fn update
     * \brief Updates the state of the simulation by one
     * iteration.
     * \pre Simulation must be initialized.
     * \post One iteration is performed.
     */
    void update();

    /*!
     * \fn get_generation_count
     * \brief Getter for current generation being simulated.
     * \return Current active generation.
     * \pre Simulation should be ongoing.
     * \post Provided integer should represent current generation.
     */
    unsigned int get_generation_count();

    /*!
     * \fn get_iteration_count
     * \brief Getter for current iteration within current generation.
     * \return Current iteration (or current number of iterations
     * performed for current generation).
     * \pre Simulation should be ongoing.
     * \post Provided integer should represent current iteration of
     * currently active generation.
     */
    unsigned int get_iteration_count();

    /*!
     * \fn get_iteration_max
     * \brief Getter for maximum iterations for each generation.
     * \return Maximum iteration count.
     */
    unsigned int get_iteration_max();

    /*!
     * \fn skip_generation
     * \brief Skips current generation. Speeds up the simulation,
     * if used properly.
     * \pre Simulation should be ongoing.
     * \post If called during generation X, generation X + 1 should
     * begin immediately.
     */
    void skip_generation();
private:

    /*!
     * \fn clear_subjects
     * \brief Deletes current list of subjects completely.
     */
    void clear_subjects();

    /*!
     * \fn sort_networks
     * \brief Sorts list of neural networks in terms of their comparison function.
     */
    void sort_networks();

    /*!
     * \fn set_subject_parameters
     * \brief Configures a subject with application settings.
     * \param subject Target subject.
     */
    void set_subject_parameters(Subject *subject);

    /*!
     * \fn get_top_subjects
     * \brief Pseudo-getter for the best subjects, fitness-wise.
     * \param count Number of subjects to be collected.
     * \return Specified number of top performers.
     * \pre Simulation must be currently underway, and list of networks must be sorted.
     * \post Elements in the vector should represent indexes of the
     * container that houses actual subjects/networks.
     */
    std::vector<int> get_top_subjects(unsigned int count);

    /*!
     * \fn get_retention_subjects
     * \brief Decides and collects poorly performing subjects.
     * \param retention_rate The rate at which poor-performers are selected
     * (integer, represents a percentage, 10 = 10%)
     * \param population Population size.
     * \param top_subject_count The first instance from which poor-performers are selected.
     * \return Poorly performing subjects that get to remain in the next generation.
     * \pre Simulation should be currently underway.
     * \post Selected integers that represent indexes of the list of subjects.
     */
    std::vector<int> get_retention_subjects(int retention_rate,
                                            unsigned int population,
                                            unsigned int top_subject_count);

    /*!
     * \fn generate_breeders
     * \brief Creates a list of individuals/groups that are to
     * create children for the next generation.
     * \param method Subject breeding method (crossover function). While the function
     * itself is not used directly, it is used to determine the size of the
     * breeding groups.
     * \param target_count Number of children that are to be created.
     * \param top_subjects Subjects that were selected to breed for
     * being the best of the whole population.
     * \param retention_subjects Poorly performing subjects that were
     * randomly selected to breed.
     * \return List of individuals/groups that are to create
     * new children for the next generation.
     * \pre Simulation should be currently underway, and the next generation
     * should begin within current iteration.
     * \post List should contain the same number of groups as the number
     * of children to be created.
     */
    std::vector<std::vector<int>>
    generate_breeders(breeding_type method,
                      int target_count,
                      std::vector<int> top_subjects,
                      std::vector<int> retention_subjects);

    /*!
     * \var primaryTarget_
     * \brief Core entity of the primary target (Player's ship)
     */
    SubjectCore *primaryTarget_;

    /*!
     * \var secondaryTarget_
     * \brief Core entity of the secondary target (NYI).
     */
    SubjectCore *secondaryTarget_;

    /*!
     * \var tertiaryTarget_
     * \brief Core entity of the tertiary target (NYI).
     */
    SubjectCore *tertiaryTarget_;

    /*!
     * \var mousePoint_
     * \brief Core entity of the mouse point.
     */
    SubjectCore *mousePoint_;

    /*!
     * \var adversary_
     * \brief Core entity of the adversary (NYI).
     */
    SubjectCore *adversary_;

    /*!
     * \var settings_
     * \brief Application-wide settings.
     */
    Settings *settings_;

    /*!
     * \var subjects_
     * \brief List of subjects. Acts as the population of the simulation.
     * \invariant Indexes should match with those of neural networks (networks_).
     */
    std::vector<Subject*> subjects_;

    /*!
     * \var networks_
     * \brief List of subjects' neural networks. Acts as the intelligence of the population.
     * \invariant Indexes should match with those of subjects (subjects_).
     */
    std::vector<NeuralNetwork*> networks_;

    /*!
     * \var scene_
     * \brief Pointer to the graphics scene, situated in the main window.
     */
    QGraphicsScene *scene_;

    /*!
     * \var rand_
     * \brief Object instance for creating random numbers.
     */
    Random &rand_;

    /*!
     * \var generation_count_
     * \brief Keeps track of the current generation.
     */
    unsigned int generation_count_;

    /*!
     * \var iteration_count_
     * \brief Keeps track of the current iteration of the current generation.
     */
    unsigned int iteration_count_;

    /*!
     * \var iteration_max_
     * \brief The maximum number of iterations for each generation.
     */
    unsigned int iteration_max_;

    /*!
     * \var random_point_
     * \brief A point in the graphics scene that serves as a
     * spawn point for a specific spawn point setting.
     */
    XY random_point_;
};

#endif // MANAGER_HH
