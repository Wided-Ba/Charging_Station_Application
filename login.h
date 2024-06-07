#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlQuery>
#include "employee.h"
#include "profil.h"
#include "profilemp.h"
#include <QDebug>
#include "smtp.h"
#include "activatoncodeclass.h"
//#include "arduino.h"
#include <QSqlRecord>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    QSqlQuery request(QString code);
unsigned int getRan() const;
void sendMail();
private slots:
    void on_pushButton_verifier_clicked();
void on_pushButton_oublie_clicked();
    void on_envoyeremail_clicked();
void mailSent(QString status);
   // void update_label();
private:
    Ui::login *ui;
    employee E;
     unsigned int ran;
     Smtp* smtp ;
      QString msg;
      QByteArray data,c;
     // arduino A;
       //activatoncodeclass *act;
};

#endif // LOGIN_H
