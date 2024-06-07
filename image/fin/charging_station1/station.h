#ifndef STATION_H
#define STATION_H

#include <QDialog>

namespace Ui {
class station;
}

class station : public QDialog
{
    Q_OBJECT

public:
    explicit station(QWidget *parent = nullptr);
    ~station();

private:
    Ui::station *ui;
};

#endif // STATION_H
