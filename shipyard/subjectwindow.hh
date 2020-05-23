#ifndef SUBJECTWINDOW_HH
#define SUBJECTWINDOW_HH

#include <QWidget>
#include "settings.hh"

namespace Ui {
class SubjectWindow;
}

/*!
 * \class SubjectWindow
 * \brief Controller for subject-specific settings.
 * \author terratenff
 */
class SubjectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectWindow(QWidget *parent = nullptr);
    ~SubjectWindow();

private:
    Ui::SubjectWindow *ui;

    /*!
     * \var settings_
     * \brief Application-wide settings. Includes subject-specific
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
};

#endif // SUBJECTWINDOW_HH
