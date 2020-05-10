#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <QWidget>

namespace Ui {
class Instructions;
}

/*!
 * \class Instructions
 * \brief Guides the user to using the application.
 * The instructions themselves are hard-coded into the form that
 * this class takes over.
 * \author terratenff
 */
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
