#ifndef EMPLOYE2_H
#define EMPLOYE2_H

#include <QDialog>
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <iostream>
#include <cstdlib>
#include <QDate>
#include <QTableView>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPainter>
#include "DuCrypt.h"
#include "smtp.h"
#include <QSqlTableModel>
namespace Ui {
class employe2;
}

class employe2 : public QDialog
{
    Q_OBJECT
    QString NOM_E,PRENOM_E,SEXE_E,MDP_E,CONF_MDP_E,EMAIL_E,STATUT_E,IMAGE_E;
    int ID_E,CIN_E,NUM_TEL_E,NBR_H_TRAVAILLE_E,SALAIRE_E;
    QDate DDN_E;
public:
    explicit employe2(QWidget *parent = nullptr);
    employe2(int cin,QString nom,QString prenom,QString sexe,QString mdp,QString conf_mdp,QDate ddn,QString email,int num_tel,QString statut,QString image,int salaire);
    ~employe2();

    int getID_E(){return ID_E;}
    int getCIN_E(){return CIN_E;}
    QString getNOM_E(){return NOM_E;}
    QString getPRENOM_E(){return PRENOM_E;}
    QString getSEXE_E(){return SEXE_E;}
    QString getMDP_E(){return MDP_E;}
    QString getCONF_MDP_E(){return CONF_MDP_E;}
    QDate getDDN_E(){return DDN_E;}
    QString getEMAIL_E(){return EMAIL_E;}
    int getNUM_TEL_E(){return NUM_TEL_E;}
    int getNBR_H_TRAVAILLE_E(){return NBR_H_TRAVAILLE_E;}
    QString getStatut_E(){return STATUT_E;}
    QString getIMAGE_E(){return IMAGE_E;}
    int getSALAIRE_E(){return SALAIRE_E;}

    void setID_E(int id){this->ID_E=id;}
    void setCIN_E(int cin){this->CIN_E=cin;}
    void setNOM_E(QString nom){this->NOM_E=nom;}
    void setPRENOM_E(QString prenom){this->PRENOM_E=prenom;}
    void setSEXE_E(QString sexe){this->SEXE_E=sexe;}
    void setMDP_E(QString mdp){this->MDP_E=mdp;}
    void setCONF_MDP_E(QString conf_mdp){this->CONF_MDP_E=conf_mdp;}
    void setDDN_E(QDate ddn){this->DDN_E=ddn;}
    void setEMAIL_E(QString email){this->EMAIL_E=email;}
    void setNUM_TEL_E(int num_tel){this->NUM_TEL_E=num_tel;}
    void setNBR_H_TRAVAILLE_E(int nbr_h){this->NBR_H_TRAVAILLE_E=nbr_h;}
    void setStatut_E(QString statut){this->STATUT_E=statut;}
    void setIMAGE_E(QString image){this->IMAGE_E=image;}
    void setSALAIRE_E(int salaire){this->SALAIRE_E=salaire;}

    QSqlTableModel* afficher();
void recherche(QTableView * table, QString rech);
private slots:
     void on_lineEdit_rechercher_textChanged();
     void on_tableView_clicked(const QModelIndex &index);
private:
    Ui::employe2 *ui;
};

#endif // EMPLOYE2_H
