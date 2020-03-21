#ifndef NETWORKWINDOW_HH
#define NETWORKWINDOW_HH

#include <QWidget>
#include <settings.hh>

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = nullptr);
    ~NetworkWindow();

private:
    Ui::NetworkWindow *ui;

    Settings *settings_;
    const double FACTOR_ = 1000;
private slots:
    void cancel();
    void defaultSettings();
    void applyChanges();

    void initialWeightMinChanged(int change);
    void initialWeightMaxChanged(int change);
    void populationRetentionRateChanged(int change);
    void mutationProbabilityChanged(int change);
    void mutationScaleMinChanged(int change);
    void mutationScaleMaxChanged(int change);
};

#endif // NETWORKWINDOW_HH
