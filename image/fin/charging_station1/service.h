#ifndef SERVICE_H
#define SERVICE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>
#include <QString>
#include<QSqlQueryModel>
#include<QFloat16>


class Services
{
public:
    Services();
    Services(int,int,int,int,int,float,int,int,int,QString,QString,QString);
   /* int getID_SR();
    int getPROFIT_SR();
    int getNBR_CAFE();
    int getNBR_LAVAGE();
    int getNBR_ENTRETIEN();
    int getPRIX_CAFE();
    int getPRIX_LAVAGE();
    int getPRIX_ENTRETIEN();
    int getQUANTITE_SR();
    QString getETAT_SR();
    QString getIMAGE_SR();
    QString getTYPE_SR();
    void setID_SR(int);
    void setPROFIT_SR(int);
    void setNBR_CAFE(int);
    void setNBR_LAVAGE(int);
    void setNBR_ENTRETIEN(int);
    void setPRIX_CAFE(int);
    void setPRIX_LAVAGE(int);
    void setPRIX_ENTRETIEN(int);
    void setQUANTITE_SR(int);
    void setETAT_SR(QString);
    void setIMAGE_SR(QString);
    void setTYPE_SR(QString); */

    bool ajouterServices();
    bool modifier(QString id);
    QSqlQueryModel * tab_recent_sr();
     QSqlQueryModel * tab_recent_cafe();
      QSqlQueryModel * tab_recent_lavage();
       QSqlQueryModel * tab_recent_entretien();


      QSqlQueryModel* ComboBox_id_sr();

private:

    int ID_SR,PROFIT_SR,
    NBR_CAFE,NBR_LAVAGE,NBR_ENTRETIEN,
    PRIX_LAVAGE,PRIX_ENTRETIEN,
    QUANTITE_SR;
    QString ETAT_SR,IMAGE_SR,TYPE_SR;
    float PRIX_CAFE;


};



namespace Ui {
class service;

}

class service : public QDialog
{
    Q_OBJECT

public:
    explicit service(QWidget *parent = nullptr);
    ~service();
   QSqlQueryModel* ComboBox_id_sr();




private slots:
    void on_pb_ajouter_sr_clicked();

    void on_ComboBox_id_sr_currentIndexChanged();
    void on_pushButton_supp_clicked();




    //void on_pushButton_supp_clicked();

private:
    Ui::service *ui;


    Services S;


};







#endif // SERVICE_H
