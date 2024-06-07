#ifndef SERVICE_H
#define SERVICE_H
#include <QDialog>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include <QSqlTableModel>
#include <QStandardPaths>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QPieSeries>

//#include "arduino.h"

namespace Ui {
class service;

}

class service : public QDialog
{
    Q_OBJECT

public:
    explicit service(QWidget *parent = nullptr);
    ~service();



   service(int,int,int,int,int,float,int,int,int,QString,QString,QString);
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

   void RFID();

   bool ajouterServices();
   bool modifier(QString id);
  QSqlTableModel * tab_recent_sr();
    QSqlTableModel * tab_recent_cafe();
     QSqlTableModel * tab_recent_lavage();
      QSqlTableModel * tab_recent_entretien();


      QSqlTableModel* tab_recent_sr(QString val);
      QSqlTableModel* tab_recent_cafe(QString val);
      QSqlTableModel* tab_recent_lavage(QString val);
      QSqlTableModel* tab_recent_entretien(QString val);

    QSqlQueryModel* ComboBox_id_cafe();
    QSqlQueryModel* ComboBox_id_lavage();
    QSqlQueryModel* ComboBox_id_entretien();
    QSqlQueryModel* comboBox_id_modif();




private slots:
    void on_pb_ajouter_sr_clicked();

   // void on_ComboBox_id_cafe_currentIndexChanged();
    void on_pushButton_supp_cafe_clicked();

   // void on_ComboBox_id_lavage_currentIndexChanged();
    void on_pushButton_supp_lavage_clicked();

   // void on_ComboBox_id_entretien_currentIndexChanged();
    void on_pushButton_supp_entretien_clicked();


    void on_pb_modifier_sr_clicked();

    void on_tab_recent_cafe_activated(const QModelIndex &index);
    void on_tab_recent_sr_activated(const QModelIndex &index);
    void on_tab_recent_lavage_activated(const QModelIndex &index);
    void on_tab_recent_entretien_activated(const QModelIndex &index);


    void on_pushButton_PDF_cafe_clicked();
    void on_pushButton_PDF_lavage_clicked();
    void on_pushButton_PDF_entrentien_clicked();
    void generatePDF_cafe(QString filename);
    void generatePDF_lavage(QString filename);
    void generatePDF_entretien(QString filename);

    void on_lineEdit_recherche_cafe_textChanged(const QString &arg1);
    void on_lineEdit_recherche_sr_textChanged(const QString &arg1);
    void on_lineEdit_recherche_lavage_textChanged(const QString &arg1);
    void on_lineEdit_recherche_entretien_textChanged(const QString &arg1);

    void changeDesign();
    QPixmap * statistique();

   // void on_pushButton_jour_cafe_clicked();
    //void on_pushButton_jour_lavage_clicked();
    //void on_pushButton_jour_entretien_clicked();

    void afficherImageModeCafe();
    void displayEtatCafe();
    void on_pushButton_Eactiver_cafe_clicked();
    void on_pushButton_Edesact_cafe_clicked();

    void afficherImageModeLavage();
    void displayEtatLavage();
    void on_pushButton_Eactiver_lavage_clicked();
    void on_pushButton_Edesact_lavage_clicked();

    void afficherImageModeEntretien();
    void displayEtatEntretien() ;
    void on_pushButton_Eactiver_entretien_clicked();
    void on_pushButton_Edesact_entretien_clicked();



    void on_comboBox_JF_cafe_currentIndexChanged(const QString &arg1);
    void setComboBoxValueFromDatabase_cafe();
    void compareDayOfWeekWith_cafe();

    void on_comboBox_JF_lavage_currentIndexChanged(const QString &arg1);
    void setComboBoxValueFromDatabase_lavage();
    void compareDayOfWeekWith_lavage();

    void on_comboBox_JF_entretien_currentIndexChanged(const QString &arg1);
    void setComboBoxValueFromDatabase_entretien();
    void compareDayOfWeekWith_entretien();

    void on_ComboBox_type_sr_currentIndexChanged(const QString &arg1);

private:
    Ui::service *ui;


    int ID_SR,PROFIT_SR,
    NBR_CAFE,NBR_LAVAGE,NBR_ENTRETIEN,
    PRIX_LAVAGE,PRIX_ENTRETIEN,
    QUANTITE_SR;
    QString ETAT_SR,IMAGE_SR,TYPE_SR;
    float PRIX;

    QByteArray data; // variable contenant les données reçues

       // arduino A; // objet temporaire

};







#endif // SERVICE_H
