#include "instructions.hh"
#include "ui_instructions.h"

Instructions::Instructions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Instructions)
{
    ui->setupUi(this);
}

Instructions::~Instructions()
{
    delete ui;
}
