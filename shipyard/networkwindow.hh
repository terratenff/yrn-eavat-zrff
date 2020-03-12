#ifndef NETWORKWINDOW_HH
#define NETWORKWINDOW_HH

#include <QWidget>

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
};

#endif // NETWORKWINDOW_HH
