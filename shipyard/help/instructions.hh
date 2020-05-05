#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <QWidget>

namespace Ui {
class Instructions;
}

class Instructions : public QWidget
{
    Q_OBJECT

public:
    explicit Instructions(QWidget *parent = nullptr);
    ~Instructions();

private:
    Ui::Instructions *ui;
};

#endif // INSTRUCTIONS_HH
