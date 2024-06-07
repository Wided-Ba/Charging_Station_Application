#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <iostream>
#include <cstdlib>
#include <QDialog>
#include <QDate>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QTextBrowser>
namespace Ui {
class stock;
}

class stock : public QDialog
{
    Q_OBJECT

public:
    explicit stock(QWidget *parent = nullptr);
    //~stock();
    //stock();
   stock(QString NOM_STK,QString REF_STK,int PRIX_A_STK,QDate DFD_STK,QString TYPE_STK,QString MARQUE_STK,int QUANTITE_STK,QByteArray IMAGE_STK);
   //*************get************
   int getID_STK();
    int getPRIX_A_STK();
    int getQUANTITE_STK();
    QString getNOM_STK();
    QString getREF_STK();
   QString getTYPE_STK();
   QString getMARQUE_STK();
   QString getIMAGE_STK();
   QString getETAT_PRODUIT_STK();
   QDate getDFD_STK();
//*************set**************
    void setID_STK(int);
    void setPRIX_A_STK(int);
    void setQUANTITE_STK(int);
    void setNOM_STK(QString);
    void setREF_STK(QString);
    void setTYPE_STK(QString);
    void setMARQUE_STK(QString);
    void setIMAGE_STK(QString);
    void setETAT_PRODUIT_STK(QString);
    void setDFD_STK(QDate);

//******************* fonction prinicipaux*******************************************************************
    bool ajouter();
    QSqlTableModel* afficher();
    bool supprimer(int);
    bool existe(int ID);
    void ajouterBoutons(QSqlQueryModel* model);
    void setButtonInTableView();
    bool modifier(int );
    QSqlQueryModel* comboBox_id();
    QSqlQueryModel* comboBox_modif();

    QSqlQueryModel * recherche(QString res);
    void on_Search_objet_cursorPositionChanged(const QString &arg1);
    QSqlQueryModel* tri_type();
    QSqlQueryModel* tri_Quantite();
    QSqlQueryModel* tri_ID();

    QPixmap * statistique();
    QPixmap * statistique2();
    QPixmap * statistique3();
    void creation_pdf(QString filename);
    QTextBrowser* alerte();
    QTextBrowser* alerte_3();
    void alerte2();

QTextBrowser* checkCafeAlert( );

private slots:
//    void on_toolButton_clicked();



    void on_pushButton_ajouter_clicked();

    void on_pushButton_del_all_clicked();

    void on_pushButton_clicked();

    void on_tableView_stock_activated(const QModelIndex &index);

    void on_pushButton_modifier_clicked();


    void on_comboBox_modif_currentIndexChanged();

    void on_lineEdit_chercher_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_clicked();



    void on_toolButton_modif_clicked();


private:
    Ui::stock *ui;

public :
    QString NOM_STK;
    QString REF_STK;
    QString TYPE_STK;
    QString MARQUE_STK;
    //QString IMAGE_STK;
    QString ETAT_PRODUIT_STK;
    QDate DFD_STK;
    int ID_STK;
    int PRIX_A_STK;
    int QUANTITE_STK;
    QByteArray IMAGE_STK;

};

#endif // STOCK_H
