#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QCloseEvent>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include "settings.hh"
#include "manager.hh"
#include "target.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

public slots:
    void update();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    Settings *settings_;
    QGraphicsScene *scene_;
    QTimer *timer_;
    bool is_running_;

    Random rand_;
    Manager *manager_;

    Target *target_;
    Target *mousePoint_;

private slots:
    void buttonRunClicked();
    void buttonTrainClicked();
    void buttonGenerateClicked();
    void buttonResetClicked();
    void buttonExitClicked();
    void iterationChanged(int change);
    void instanceChanged(int change);
    void offspringChanged(int change);
    void timeChanged(int change);
    void hiddenLayerChanged(int change);
    void hiddenNeuronChanged(int change);
    void inputChanged(int change);
    void outputChanged(int change);
    void fitnessChanged(int change);
};

#endif // MAINWINDOW_HH
