#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QCloseEvent>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include "help/instructions.hh"
#include "help/about.hh"
#include "subjectwindow.hh"
#include "networkwindow.hh"
#include "settings.hh"
#include "scenario.hh"
#include "manager.hh"
#include "target.hh"

namespace Ui {
class MainWindow;
}

/*!
 * \class MainWindow
 * \brief Responsible for showing the main window of the application
 * to the user.
 * \author terratenff
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

public slots:

    /*!
     * \fn update
     * \brief Updates the state of the simulation visible
     * in the main window.
     * \pre Simulation must be initialized.
     * \post State of the simulation is updated by one iteration.
     */
    void update();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:

    /*!
     * \fn setControls
     * \brief Applies general settings to the user interface.
     * \pre Pointer to a Settings instance must exist.
     * \post Some of the settings from said instance are
     * set on the user interface.
     */
    void setControls();

    Ui::MainWindow *ui;

    /*!
     * \var sw
     * \brief User interface for subject-specific settings.
     */
    SubjectWindow *sw = nullptr;

    /*!
     * \var nw
     * \brief User interface for settings related to the
     * neural network.
     */
    NetworkWindow *nw = nullptr;

    /*!
     * \var in
     * \brief User interface for a collection of instructions.
     */
    Instructions *in;

    /*!
     * \var ab
     * \brief User interface for general information about
     * the application.
     */
    About *ab;

    /*!
     * \var settings_
     * \brief Collection of settings that modify the flow of
     * the neural network simulations.
     */
    Settings *settings_;

    /*!
     * \var scenario_
     * \brief Saves settings into a text file, or loads them from one.
     */
    Scenario *scenario_;

    /*!
     * \var scene_
     * \brief Graphics Scene for the graphics viewer.
     */
    QGraphicsScene *scene_;

    /*!
     * \var timer_
     * \brief Conducts the timing for the simulations.
     */
    QTimer *timer_;

    /*!
     * \var is_running_
     * \brief Flag for keeping track of whether a simulation
     * is currently underway.
     */
    bool is_running_;

    /*!
     * \var rand_
     * \brief Object instance for creating random numbers.
     */
    Random rand_;

    /*!
     * \var manager_
     * \brief Manages a simulation behind the scenes.
     */
    Manager *manager_;

    /*!
     * \var target_
     * \brief Player's Ship.
     */
    Target *target_;

    /*!
     * \var mousePoint_
     * \brief Mouse Point, created on screen with a right-click.
     */
    Target *mousePoint_;

private slots:

    /*!
     * \fn buttonRunClicked
     * \brief Functionality for when the button for starting the
     * simulation is clicked. Also includes functionality to
     * stopping a simulation.
     */
    void buttonRunClicked();

    /*!
     * \fn buttonResetClicked
     * \brief Functionality for when the button for default settings
     * is clicked. This goes through a confirmation screen to avoid
     * accidental resets.
     */
    void buttonResetClicked();

    /*!
     * \fn buttonExitClicked
     * \brief Functionality for when the button for exiting is
     * clicked.
     */
    void buttonExitClicked();

    /*!
     * \fn buttonGenerationClicked
     * \brief Functionality for when the button for skipping a generation
     * is clicked.
     */
    void buttonGenerationClicked();

    /*!
     * \fn iterationChanged
     * \brief Functionality for when the number of iterations is
     * changed.
     * \param change New number of iterations.
     */
    void iterationChanged(int change);

    /*!
     * \fn instanceChanged
     * \brief Functionality for when the number of subject instances
     * is changed.
     * \param change New number of instances.
     */
    void instanceChanged(int change);

    /*!
     * \fn offspringChanged
     * \brief Functionality for when the number of offsprings is changed.
     * \param change New number of offsprings.
     */
    void offspringChanged(int change);

    /*!
     * \fn timeChanged
     * \brief Functionality for when the delay between iterations is changed.
     * \param change New delay between iterations.
     */
    void timeChanged(int change);

    /*!
     * \fn hiddenLayerChanged
     * \brief Functionality for when the number of hidden layers within a
     * neural network is changed.
     * \param change New number of hidden layers within a neural network.
     */
    void hiddenLayerChanged(int change);

    /*!
     * \fn hiddenNeuronChanged
     * \brief Functionality for when the number of neurons in each
     * hidden layer within a neural network is changed.
     * \param change New number of neurons in each hidden layer within
     * a neural network.
     */
    void hiddenNeuronChanged(int change);

    /*!
     * \fn biasChanged
     * \brief Functionality for when the initial bias is changed.
     * \param change New initial bias.
     */
    void biasChanged(int change);

    /*!
     * \fn inputChanged
     * \brief Functionality for when the input function is changed.
     * \param change Integer code that represents newly selected
     * input function.
     */
    void inputChanged(int change);

    /*!
     * \fn outputChanged
     * \brief Functionality for when the output function is changed.
     * \param change Integer code that represents newly selected
     * output function.
     */
    void outputChanged(int change);

    /*!
     * \fn fitnessChanged
     * \brief Functionality for when the fitness function is changed.
     * \param change Integer code that represents newly selected
     * fitness function.
     */
    void fitnessChanged(int change);

    /*!
     * \fn fileLoadScenario
     * \brief Functionality for when the menu button for loading a
     * scenario is clicked.
     */
    void fileLoadScenario();

    /*!
     * \fn fileSaveScenario
     * \brief Functionality for when the menu button for saving a
     * scenario is clicked.
     */
    void fileSaveScenario();

    /*!
     * \fn fileExit
     * \brief Functionality for when the menu button for exiting
     * is clicked.
     */
    void fileExit();

    /*!
     * \fn editSubjectParameters
     * \brief Functionality for when the menu button for subject
     * parameters is clicked.
     */
    void editSubjectParameters();

    /*!
     * \fn editNetworkParameters
     * \brief Functionality for when the menu button for network
     * parameters is clicked.
     */
    void editNetworkParameters();

    /*!
     * \fn helpInstructions
     * \brief Functionality for when the menu button for
     * instructions is clicked.
     */
    void helpInstructions();

    /*!
     * \fn helpAbout
     * \brief Functionality for when the menu button for general
     * information is clicked.
     */
    void helpAbout();
};

#endif // MAINWINDOW_HH
