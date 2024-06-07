#ifndef CLIENT_H
#define CLIENT_H


#include <QDialog>
#include<QString>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include <QDate>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include <QtMultimedia/QMediaPlayer>
#include <arduino.h>
#include <QByteArray>
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPainter>
namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    //~client();
    client (QString,QString,QString ,QString ,int ,int,QString ,int,QDate);
    client (int ,int,int);
    client (int );
       bool Ajouter();
       bool AjouterCon(int ,int, int);
       bool Modifier(int);
       QSqlQueryModel* comboBox_modif();
       QSqlTableModel* tableView(QString val);
       void on_lineEdit_textChanged(const QString &arg1);
       bool modifier(QString ID_C);
      // bool Modifier2(QString id, int consj_st);
       bool Modifier(QString id, int consj_st);
       bool Verif(QString id, int CONSJ, int& reste, QString& eco);
       void sendMail();
       void mailSent(QString status);
       QSqlQuery give(QString mail);

private:
    Ui::client *ui;
    QString NOM_C,PRENOM_C,CIN_C,SEXE_C,EMAIL_C;
    int NBR_RECHARGE_C,NUM_TEL_C,CON_VISITE_C,ID_E;
    QDate DATE_NAISSANCE_C;
    QMediaPlayer *player;
    int CONSJ_ST;
    QString  ID_ST;

private slots:
void  aff_debut();
    void on_ajoutC_clicked();
    QSqlTableModel* afficherC();
    QSqlQueryModel* comboBox_id_st();
 QSqlQueryModel* comboBox_id_c();
    void on_pushButton_SC_3_clicked();
    //void level();
    bool existe(int ID);
    bool supprimer(int ID);
    QSqlQueryModel* comboBox_id();
    void on_pushButton_SC_clicked();
    void on_tableView_activated(const QModelIndex &index);
    //void sendMail();
    // void mailSent(QString status);
    void on_pushButton_modifier_clicked();
    void showNotification();
    void on_ajoutConsommation_clicked();
    void generatePDF(QString filename);
    void on_pushButton_10_clicked();
    QPixmap * statistique();
    void on_lineEditID_textChanged(const QString &arg1);
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_pushButton_clicked();
    QSqlQueryModel* comboBox_client();
    void on_comboBox_client_currentIndexChanged();


private:
QByteArray data;
//Arduino A;

};

#endif // CLIENT_H
