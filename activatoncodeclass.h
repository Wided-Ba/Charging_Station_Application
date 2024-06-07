#ifndef ACTIVATONCODECLASS_H
#define ACTIVATONCODECLASS_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QToolTip>
#include <QSettings>
#include <QTimer>
#include <QDebug>
#include <QVariant>
#include "employee.h"
class login;
namespace Ui {
class activatoncodeclass;
}

class activatoncodeclass : public QDialog
{
    Q_OBJECT

public:
    explicit activatoncodeclass(QWidget *parent = nullptr);
    ~activatoncodeclass();
    int getCode() const;
    void setCode(int value);
    QString getPass() const;
    void setPass( QString value);
//bool modify();
bool modify(employee& e);
    QString getUname() const;
    void setUname( QString value);

    QString getEmail() const;
    void setEmail(const QString &value);
QSqlQuery give(QString mail);
  public  slots:
    void checkCode();
    void update();
    void checkPassword(const QString &password);
private slots:
    //void on_verififercode_3_clicked();

    void on_modifier_clicked();

private:
    Ui::activatoncodeclass *ui;
    int code;
    QString uname;
    QString pass;
    QString email;
    QDateTime current,expire;
    QTimer *timer;
    employee E;

};

#endif // ACTIVATONCODECLASS_H
