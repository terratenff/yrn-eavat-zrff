#ifndef ABOUT_HH
#define ABOUT_HH

#include <QWidget>

namespace Ui {
class About;
}

/*!
 * \class About
 * \brief Responsible for showing general information about the
 * application, letting the user know more about it. The actual
 * text is hard-coded into the form that this class takes over.
 * \author terratenff
 */
class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
};

#endif // ABOUT_HH
