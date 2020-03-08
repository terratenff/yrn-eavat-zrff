#ifndef SUBJECTWINDOW_HH
#define SUBJECTWINDOW_HH

#include <QWidget>
#include "settings.hh"

namespace Ui {
class SubjectWindow;
}

class SubjectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectWindow(QWidget *parent = nullptr);
    ~SubjectWindow();

private:
    Ui::SubjectWindow *ui;

    Settings *settings_;
private slots:
    void cancel();
    void defaultSettings();
    void applyChanges();
};

#endif // SUBJECTWINDOW_HH
