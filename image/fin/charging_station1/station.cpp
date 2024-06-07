#include "station.h"
#include "ui_station.h"

station::station(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::station)
{
    ui->setupUi(this);
}

station::~station()
{
    delete ui;
}
