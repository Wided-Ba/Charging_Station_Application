#ifndef PROFILEMP_H
#define PROFILEMP_H

#include <QMainWindow>
#include <client.h>
#include <service.h>
#include <station.h>
#include <stock.h>
#include <reglage.h>
#include "employe2.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class profilemp; }
QT_END_NAMESPACE

class profilemp : public QMainWindow
{
    Q_OBJECT

public:
    profilemp(QWidget *parent = nullptr);
    ~profilemp();

private slots:
    void on_pushButton_profil_clicked();

    void on_pushButton_client_clicked();

    void on_pushButton_station_clicked();

    void on_pushButton_service_clicked();

    void on_pushButton_stock_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_reglage_clicked();

    void on_pushButton_employee_clicked();

private:
    Ui::profilemp *ui;
    client C;
    service S;
    station ST;
    stock SCK;
    reglage R;
    employe2 E2;
};
#endif // PROFILEMP_H
