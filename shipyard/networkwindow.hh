#ifndef NETWORKWINDOW_HH
#define NETWORKWINDOW_HH

#include <QWidget>
#include <settings.hh>

namespace Ui {
class NetworkWindow;
}

/*!
 * \class NetworkWindow
 * \brief Controller for network-specific settings.
 * \author terratenff
 */
class NetworkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = nullptr);
    ~NetworkWindow();

private:
    Ui::NetworkWindow *ui;

    /*!
     * \var settings_
     * \brief Application-wide settings. Includes network-specific
     * settings.
     */
    Settings *settings_;

    /*!
     * \var FACTOR_
     * \brief Some UI components support integers only, even though
     * numbers higher than 0 but less than 1 are desired. This
     * number is used to convert high integer values to actual,
     * desired values.
     */
    const double FACTOR_ = 1000;
private slots:

    /*!
     * \fn cancel
     * \brief Undoes any changes made on the user interface.
     * Also closes the window.
     */
    void cancel();

    /*!
     * \fn defaultSettings
     * \brief Applies default settings to the UI components.
     */
    void defaultSettings();

    /*!
     * \fn applyChanges
     * \brief Saves settings on the UI to the settings instance,
     * applying them to the rest of the application. Also
     * closes the window.
     */
    void applyChanges();

    /*!
     * \fn initialWeightMinChanged
     * \brief Function response to modifying minimum weight.
     * \param change New minimum weight.
     */
    void initialWeightMinChanged(int change);

    /*!
     * \fn initialWeightMaxChanged
     * \brief Function response to modifying maximum weight.
     * \param change New maximum weight.
     */
    void initialWeightMaxChanged(int change);

    /*!
     * \fn populationRetentionRateChanged
     * \brief Function response to modifying population retention
     * rate.
     * \param change New population retention rate.
     */
    void populationRetentionRateChanged(int change);

    /*!
     * \fn mutationProbabilityChanged
     * \brief Function response to modifying mutation probability.
     * \param change New mutation probability.
     */
    void mutationProbabilityChanged(int change);

    /*!
     * \fn mutationScaleMinChanged
     * \brief Function response to modifying minimum mutation scale.
     * \param change New minimum mutation scale.
     */
    void mutationScaleMinChanged(int change);

    /*!
     * \fn mutationScaleMaxChanged
     * \brief Function response to modifying maximum mutation scale.
     * \param change New maximum mutation scale.
     */
    void mutationScaleMaxChanged(int change);
};

#endif // NETWORKWINDOW_HH
