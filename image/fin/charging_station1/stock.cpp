#include "stock.h"
#include "ui_stock.h"
#include "connection.h"
#include<QtDebug>
#include <QSqlQuery>
#include <iostream>
#include <QtWidgets>
#include <QSqlTableModel>
#include <QtCharts/QBarSet>
#include <QtCharts>
#include <QChartView>
#include <QPrinter>
using namespace QtCharts;
#define STR_EQUAL 0
using namespace std;


stock::stock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stock)
{
    ui->setupUi(this);
    ui->tableView_stock->setModel(afficher());
    ui->tableView_stock->resizeColumnsToContents();
    ui->comboBox_supp->setModel(comboBox_id());
    ui->comboBox_modif->setModel(comboBox_modif());
    ui->dateEdit->setDate(QDate::currentDate());
    QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
    if (chartPixmapPtr) {
        ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
        delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
    }
    QPixmap* chartPixmapPtr2 = statistique2(); // Appel à votre fonction pour récupérer le QPixmap*
    if (chartPixmapPtr2) {
        ui->label_stat->setPixmap(*chartPixmapPtr2); // Mise à jour de l'image de la QLabel
        delete chartPixmapPtr2; // Libération de la mémoire allouée dynamiquement pour le QPixmap
    }
    QPixmap* chartPixmapPtr3 = statistique3(); // Appel à votre fonction pour récupérer le QPixmap*
    if (chartPixmapPtr3) {
        ui->label_stat_2->setPixmap(*chartPixmapPtr3); // Mise à jour de l'image de la QLabel
        delete chartPixmapPtr3; // Libération de la mémoire allouée dynamiquement pour le QPixmap
    }
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_stat->setAlignment(Qt::AlignCenter);
     ui->label_stat_2->setAlignment(Qt::AlignCenter);
     //alerte
    // ui->label_alerte =alerte();
    // ui->label_alerte_3=alerte_3();

     //alerte date périmé
    ui->label_alerte_2->setText(*checkCafeAlert());
    ui->label_alerte_4->setText(*checkCafeAlert());

     //delete alerteJus; // Libérer la mémoire allouée sur le heap
   //alerte2();
    //ui->label_alerte->setStyleSheet("background-color: red; border: 2px solid black; padding: 5px;");

}

stock ::stock(QString NOM_STK,QString REF_STK,int PRIX_A_STK,QDate DFD_STK,QString TYPE_STK,QString MARQUE_STK,int QUANTITE_STK)
{
    //this->ID_STK=ID_STK;
    this->NOM_STK=NOM_STK;
    this->REF_STK=REF_STK;
    this->PRIX_A_STK=PRIX_A_STK;
    this->TYPE_STK=TYPE_STK;
    this->MARQUE_STK=MARQUE_STK;
   //this->ETAT_PRODUIT_STK=ETAT_PRODUIT_STK;
    this->QUANTITE_STK=QUANTITE_STK;
    this->DFD_STK=DFD_STK;

}

stock::~stock()
{
    delete ui;
}
//**************gettt***********
int stock :: getID_STK()
{return ID_STK;}
int stock:: getPRIX_A_STK()
{return PRIX_A_STK;}
int stock:: getQUANTITE_STK()
{   return QUANTITE_STK;}
QString stock::getNOM_STK()
{    return NOM_STK;}
QString stock::getREF_STK()
{ return REF_STK;}
QString stock::getTYPE_STK()
{ return TYPE_STK;}
QString stock::getMARQUE_STK()
{    return MARQUE_STK;}
/*QString stock::getIMAGE_STK()
{}*/
QString stock::getETAT_PRODUIT_STK()
{   return ETAT_PRODUIT_STK;}
QDate stock::getDFD_STK()
{    return DFD_STK;}
//****************set**********************
void stock :: setID_STK(int ID_STK)
{    this->ID_STK=ID_STK;}
void stock ::setPRIX_A_STK(int PRIX_A_STK)
{    this->PRIX_A_STK=PRIX_A_STK;}
void stock ::setQUANTITE_STK(int QUANTITE_STK)
{    this->QUANTITE_STK=QUANTITE_STK;}
void stock ::setNOM_STK(QString NOM_STK)
{    this->NOM_STK=NOM_STK;}
void stock ::setREF_STK(QString REF_STK)
{    this->REF_STK=REF_STK;}
void stock ::setTYPE_STK(QString TYPE_STK)
{    this->TYPE_STK=TYPE_STK;}
void stock ::setMARQUE_STK(QString MARQUE_STK)
{    this->MARQUE_STK=MARQUE_STK;}
/*void stock ::setIMAGE_STK(QString IMAGE_STK)
{    this->IMAGE_STK=IMAGE_STK;}*/
void stock ::setETAT_PRODUIT_STK(QString ETAT_PRODUIT_STK)
{    this->ETAT_PRODUIT_STK=ETAT_PRODUIT_STK;}
void stock ::setDFD_STK(QDate DFD_STK)
{this->DFD_STK=DFD_STK;}

//************************ajouter*************************************
bool stock::ajouter()
{

    QString PRIX_A_STK_string=QString::number(PRIX_A_STK);
    QString QUANTITE_STK_string=QString::number(QUANTITE_STK);
    QSqlQuery query;
    query.prepare("INSERT INTO stocks ( NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK,MARQUE_STK,QUANTITE_STK) "
                            "VALUES ( :NOM_STK,:REF_STK,:PRIX_A_STK,:DFD_STK,:TYPE_STK,:MARQUE_STK,:QUANTITE_STK)");
    query.bindValue(":NOM_STK", NOM_STK);
    query.bindValue(":REF_STK",REF_STK);
    query.bindValue(":PRIX_A_STK", PRIX_A_STK_string);
    query.bindValue(":DFD_STK", DFD_STK);
    query.bindValue(":TYPE_STK", TYPE_STK);
    query.bindValue(":MARQUE_STK", MARQUE_STK);
    //query.bindValue(":ETAT_PRODUIT_STK", ETAT_PRODUIT_STK);
    query.bindValue(":QUANTITE_STK", QUANTITE_STK_string);

return query.exec();

}
//***********************afficher**************************
QSqlTableModel* stock::afficher()
{
    QSqlTableModel* model=new QSqlTableModel(this);
    model->setTable("STOCKS");
   // model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    //trie  ordre croissant et decroissant
    ui->tableView_stock->setSortingEnabled(true);
    ui->tableView_stock->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return model;
}


//***********************ajouter+afficher**********************************************
void stock::on_pushButton_ajouter_clicked()
{
        QString NOM_STK= ui->textEdit_nom->toPlainText();
        QString REF_STK = ui->textEdit_reference->toPlainText();
        int PRIX_A_STK = ui->doubleSpinBox_prix_achat->value();
        QString MARQUE_STK = ui->textEdit_marque->toPlainText();
        QString TYPE_STK = ui->comboBox_type->currentText();
        int QUANTITE_STK = ui->spinBox_quantite->value();
       // QString ETAT_STK=ui->textEdit_etat->toPlainText();
        QDate DFD_STK=ui->dateEdit->date();
         //ne9s image

//***************controle de saisie*********************************
        if ((NOM_STK.isEmpty()) || (REF_STK.isEmpty()) || (MARQUE_STK.isEmpty()) ) {
               QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoire");
                qDebug() <<"Error! Remplir tous les champs" ;
               return;
           }
        if (( REF_STK .length() <= 3)||(MARQUE_STK.length()<=3)|| (NOM_STK.length()<=3) ){

            QMessageBox::warning(this, "Erreur", "Nom/Reference/Marque doivent être supérieur à 3 !");
            qDebug() << "Nom/Reference/Marque doivent être supérieur à 3 !";
            return;
        }
           if ((QUANTITE_STK <= 0 )||(PRIX_A_STK <= 0)) {
              QMessageBox::warning(this, "Erreur", "Les champs Prix et Quantite doivent être supérieur à zéro");
              qDebug() <<"Error Quantite ou Prix" ;
               return;
           }
         /*  // Vérifier si la date est valide
        QDate currentDate = QDate::currentDate();//la date actuelle
        QDate maxDate = currentDate.addMonths(5); // ajouter 5 mois à la date actuelle

        if (DFD_STK <= maxDate) {

            QMessageBox::warning(this, "Erreur", "La date doit être supérieure à 5 mois après la date actuelle");
            qDebug() <<"Error date!" ;
            return; // arrêter l'exécution de la fonction
        }*/

//********************************************************************

    stock s(NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK, MARQUE_STK, QUANTITE_STK);
    bool test=s.ajouter();

         if(test)
         {
                        qDebug() << "Success add";
                        QMessageBox::information(nullptr,QObject::tr("Ajout !"),QObject::tr("Ajout effectue !\n" "Click Cancel to quit"),QMessageBox::Cancel);

                      ui->tableView_stock->setModel(afficher());
                      ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
                      ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
                      ui->comboBox_modif->setModel(comboBox_modif());
                       //************appel du stat************
                      QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                      if (chartPixmapPtr) {
                          ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                          delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                      }
                      QPixmap* chartPixmapPtr2 = statistique2(); // Appel à votre fonction pour récupérer le QPixmap*
                      if (chartPixmapPtr2) {
                          ui->label_stat->setPixmap(*chartPixmapPtr2); // Mise à jour de l'image de la QLabel
                          delete chartPixmapPtr2; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                      }
                      QPixmap* chartPixmapPtr3 = statistique3(); // Appel à votre fonction pour récupérer le QPixmap*
                      if (chartPixmapPtr3) {
                          ui->label_stat_2->setPixmap(*chartPixmapPtr3); // Mise à jour de l'image de la QLabel
                          delete chartPixmapPtr3; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                      }
                      //statistique2();
                      //statistique3();

                      ui->label_alerte =alerte();
                      ui->label_alerte_3=alerte_3();
                      ui->label_alerte_2->setText(*checkCafeAlert());
                      ui->label_alerte_4->setText(*checkCafeAlert());
                      ui->tabWidget->setCurrentIndex(0);
         }
         else
         {
             qDebug() <<"Error add" ;
         }

}


//***************************delete********************
bool stock::supprimer(int ID)
{
    QSqlQuery query;
    QString ID_STK_string=QString::number(ID);
    query.prepare("Delete from STOCKS where ID_STK= :ID");
    query.bindValue(":ID",ID_STK_string);
    return query.exec();

}
QSqlQueryModel* stock::comboBox_id()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query("SELECT ID_STK FROM STOCKS");
    model->setQuery(query);
    return model;

}
void stock::on_pushButton_clicked()
{
    int ID = ui->comboBox_supp->currentText().toInt();

    if (!existe(ID))
    { // verification l'existence de l'ID
            QMessageBox::warning(nullptr, QObject::tr("Suppression d'un stock"),
                                 QObject::tr("Le tableau Stocks est vide !\n"
                                             "Click Cancel to quit."), QMessageBox::Cancel);
            return; // Quitter la fonction si l'ID n'existe pas
     }

         QMessageBox msgBox;
         msgBox.setText("Voulez-vous supprimer cet stock?");
         msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
         int ret = msgBox.exec();
         switch (ret)
         {
               case QMessageBox::Ok:
             {
                 bool test=supprimer(ID);
                 if(test)
                 {
                     ui->tableView_stock->setModel(afficher());
                     ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
                     ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
                     ui->comboBox_modif->setModel(comboBox_modif());
                     QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                     if (chartPixmapPtr) {
                         ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                         delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                     }
                     QPixmap* chartPixmapPtr2 = statistique2(); // Appel à votre fonction pour récupérer le QPixmap*
                     if (chartPixmapPtr2) {
                         ui->label_stat->setPixmap(*chartPixmapPtr2); // Mise à jour de l'image de la QLabel
                         delete chartPixmapPtr2; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                     }
                    QPixmap* chartPixmapPtr3 = statistique3(); // Appel à votre fonction pour récupérer le QPixmap*
                     if (chartPixmapPtr3) {
                         ui->label_stat_2->setPixmap(*chartPixmapPtr3); // Mise à jour de l'image de la QLabel
                       delete chartPixmapPtr3;   // Libération de la mémoire allouée dynamiquement pour le QPixmap
                     }
                     ui->label_alerte =alerte();
                     ui->label_alerte_3=alerte_3();
                     ui->label_alerte_2->setText(*checkCafeAlert());
                     ui->label_alerte_4->setText(*checkCafeAlert());

                     QMessageBox::information(nullptr,QObject::tr("Suppression d'un stock"),
                                              QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
                 }
                 else
                     QMessageBox::critical(nullptr,QObject::tr("Suppression d'un stock"),
                                           QObject::tr("Suppression non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);


             }
                   break;
               case QMessageBox::Cancel:
                   // Cancel was clicked
                   break;
               default:
                   // should never be reached
                   break;
         }
}

//********************chercher pour la supprission*********************
bool stock::existe(int ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM STOCKS WHERE ID_STK = :ID");
    query.bindValue(":ID", ID);
    if (query.exec())
        return query.next();
    return false;
}
//*************************delete_all*******************************
void stock::on_pushButton_del_all_clicked()
{          QSqlQuery query;
           QMessageBox msgBox;
           msgBox.setText("Voulez-vous supprimer tous le stock?");
           msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
           int ret = msgBox.exec();
           switch (ret) {
             case QMessageBox::Ok:
              { query.prepare("Delete from stocks ");
               query.exec();
               ui->tableView_stock->setModel(afficher());
               ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
               ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
               ui->comboBox_modif->setModel(comboBox_modif());
               ui->label_alerte =alerte();
               ui->label_alerte_3=alerte_3();
               ui->label_alerte_2->setText(*checkCafeAlert());
               ui->label_alerte_4->setText(*checkCafeAlert());

               QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
               if (chartPixmapPtr) {
                   ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                   delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
               }
               QPixmap* chartPixmapPtr2 = statistique2(); // Appel à votre fonction pour récupérer le QPixmap*
               if (chartPixmapPtr2) {
                   ui->label_stat->setPixmap(*chartPixmapPtr2); // Mise à jour de l'image de la QLabel
                   delete chartPixmapPtr2; // Libération de la mémoire allouée dynamiquement pour le QPixmap
               }
               QPixmap* chartPixmapPtr3 = statistique3(); // Appel à votre fonction pour récupérer le QPixmap*
               if (chartPixmapPtr3) {
                   ui->label_stat_2->setPixmap(*chartPixmapPtr3); // Mise à jour de l'image de la QLabel
                   delete chartPixmapPtr3; // Libération de la mémoire allouée dynamiquement pour le QPixmap
               }

                 break;
           }
             case QMessageBox::Cancel:
                 // Cancel was clicked
                 break;
             default:
                 // should never be reached
                 break;
           }
               ui->tableView_stock->setModel(afficher());
           //pour la mise a jour du tableau

}




//********************          modifier            ***************************************


void stock::on_tableView_stock_activated(const QModelIndex &index)
{
    {

        QString val=ui->tableView_stock->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from STOCKS where ID_STK='"+val+"'");
        if(qry.exec())
        {
            while (qry.next())
            {
             ui->comboBox_modif->setCurrentText(qry.value(0).toString());
             ui->textEdit_nom_modif->setText(qry.value(1).toString());
             ui->textEdit_reference_modif->setText(qry.value(2).toString());
             ui->doubleSpinBox_prix_achat_modif->setValue(qry.value(3).toInt() );
             ui->dateEdit_modif->setDate(qry.value(4).toDate());
             ui->comboBox_type_modif->setCurrentText(qry.value(5).toString());
             ui->textEdit_marque_modif->setText(qry.value(6).toString());
             ui->spinBox_quantite_modif->setValue(qry.value(9).toInt());
             QMessageBox::information(nullptr,QObject::tr("Modification !"),QObject::tr("La ligne selectionne peut etre modifier !\n" "Click Cancel to quit"),QMessageBox::Cancel);

            }
        }
        else
        {
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }

   }
}
QSqlQueryModel* stock::comboBox_modif()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query("SELECT ID_STK FROM STOCKS");
    model->setQuery(query);
    return model;

}
bool stock::modifier(int ID_STK)
{
    QSqlQuery query;
    QString ID_STK_string=QString::number(ID_STK);
    QString PRIX_A_STK_string=QString::number(PRIX_A_STK);
    QString QUANTITE_STK_string=QString::number(QUANTITE_STK);
    query.prepare("update STOCKS set NOM_STK=:NOM_STK,REF_STK=:REF_STK,PRIX_A_STK=:PRIX_A_STK,DFD_STK=:DFD_STK,TYPE_STK=:TYPE_STK,MARQUE_STK=:MARQUE_STK,QUANTITE_STK=:QUANTITE_STK where ID_STK=:ID_STK");
    query.bindValue(":ID_STK",ID_STK_string);
    query.bindValue(":NOM_STK", NOM_STK);
    query.bindValue(":REF_STK",REF_STK);
    query.bindValue(":PRIX_A_STK", PRIX_A_STK_string);
    query.bindValue(":DFD_STK", DFD_STK);
    query.bindValue(":TYPE_STK", TYPE_STK);
    query.bindValue(":MARQUE_STK", MARQUE_STK);
    query.bindValue(":QUANTITE_STK", QUANTITE_STK_string);
   return query.exec();

}

void stock::on_pushButton_modifier_clicked()
{

    int ID_STK=ui->comboBox_modif->currentText().toInt();
    QString NOM_STK= ui->textEdit_nom_modif->toPlainText();
    QString REF_STK = ui->textEdit_reference_modif->toPlainText();
    int PRIX_A_STK = ui->doubleSpinBox_prix_achat_modif->value();
    QString MARQUE_STK = ui->textEdit_marque_modif->toPlainText();
    QString TYPE_STK = ui->comboBox_type_modif->currentText();
    int QUANTITE_STK = ui->spinBox_quantite_modif->value();
    //QString ETAT_Produit_STK=ui->textEdit_etat_2->toPlainText();
    QDate DFD_STK=ui->dateEdit_modif->date();
    //***************controle de saisie*********************************
            if ((NOM_STK.isEmpty()) || (REF_STK.isEmpty()) || (MARQUE_STK.isEmpty()) ) {
                   QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoire");
                    qDebug() <<"Error! Remplir tous les champs" ;
                   return;
               }
            if (( REF_STK .length() <= 3)||(MARQUE_STK.length()<=3)|| (NOM_STK.length()<=3) ){

                QMessageBox::warning(this, "Erreur", "Nom/Reference/Marque doivent être supérieur à 3 !");
                qDebug() << "Nom/Reference/Marque doivent être supérieur à 3 !";
                return;
            }
               if ((QUANTITE_STK <= 0 )||(PRIX_A_STK <= 0)) {
                  QMessageBox::warning(this, "Erreur", "Les champs Prix et Quantite doivent être supérieur à zéro");
                  qDebug() <<"Error Quantite ou Prix" ;
                   return;
               }
         /*      // Vérifier si la date est valide
            QDate currentDate = QDate::currentDate();//la date actuelle
            QDate maxDate = currentDate.addMonths(5); // ajouter 5 mois à la date actuelle

            if (DFD_STK <= maxDate) {

                QMessageBox::warning(this, "Erreur", "La date doit être supérieure à 5 mois après la date actuelle");
                qDebug() <<"Error date!" ;
                return; // arrêter l'exécution de la fonction
            }*/

    //********************************************************************
    stock s(NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK, MARQUE_STK, QUANTITE_STK);
       bool test=s.modifier(ID_STK);
       if(test)
       {
           ui->tableView_stock->setModel(afficher());
           ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
           ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
           ui->comboBox_modif->setModel(comboBox_modif());
           ui->label_alerte =alerte();
           ui->label_alerte_3=alerte_3();
           ui->label_alerte_2->setText(*checkCafeAlert());
           ui->label_alerte_4->setText(*checkCafeAlert());

           QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
           if (chartPixmapPtr) {
               ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
               delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
           }
           QPixmap* chartPixmapPtr2 = statistique2(); // Appel à votre fonction pour récupérer le QPixmap*
           if (chartPixmapPtr2) {
               ui->label_stat->setPixmap(*chartPixmapPtr2); // Mise à jour de l'image de la QLabel
               delete chartPixmapPtr2; // Libération de la mémoire allouée dynamiquement pour le QPixmap
           }
           QPixmap* chartPixmapPtr3 = statistique3(); // Appel à votre fonction pour récupérer le QPixmap*
           if (chartPixmapPtr3) {
               ui->label_stat_2->setPixmap(*chartPixmapPtr3); // Mise à jour de l'image de la QLabel
               delete chartPixmapPtr3; // Libération de la mémoire allouée dynamiquement pour le QPixmap
           }
           qDebug() << "Success modification";
           QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
            ui->tabWidget->setCurrentIndex(0);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Modification d'un evenement"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);


}

void stock::on_comboBox_modif_currentIndexChanged()
{
     QString val=ui->comboBox_modif->currentText();
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where ID_STK='"+val+"'");
    if(qry.exec())
    {
        while (qry.next())
        {
         ui->comboBox_modif->setCurrentText(qry.value(0).toString());
         ui->textEdit_nom_modif->setText(qry.value(1).toString());
         ui->textEdit_reference_modif->setText(qry.value(2).toString());
         ui->doubleSpinBox_prix_achat_modif->setValue(qry.value(3).toInt() );
         ui->dateEdit_modif->setDate(qry.value(4).toDate());
         ui->comboBox_type_modif->setCurrentText(qry.value(5).toString());
         ui->textEdit_marque_modif->setText(qry.value(6).toString());
         ui->spinBox_quantite_modif->setValue(qry.value(9).toInt());


        }
    }
}

//****************************recherche*****************************
QSqlQueryModel * stock::recherche(QString res)
     {


         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM STOCKS WHERE (ID_STK LIKE '%"+res+"%' OR NOM_STK LIKE '%"+res+"%' OR REF_STK LIKE '%"+res+"%' OR PRIX_A_STK LIKE '%"+res+"%' OR DFD_STK LIKE '%"+res+"%' OR TYPE_STK LIKE '%"+res+"%' OR MARQUE_STK LIKE '%"+res+"%' OR ETAT_PRODUIT_STK LIKE '%"+res+"%' OR QUANTITE_STK LIKE '%"+res+"%' ) ");
         return model;
     }

void stock::on_lineEdit_chercher_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->tableView_stock->setModel(afficher());
        ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
        ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
        ui->comboBox_modif->setModel(comboBox_modif());
        ui->label_alerte =alerte();
        ui->label_alerte_3=alerte_3();
        ui->label_alerte_2->setText(*checkCafeAlert());
        ui->label_alerte_4->setText(*checkCafeAlert());

        QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
        if (chartPixmapPtr) {
            ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
            delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
        }
        QPixmap* chartPixmapPtr2 = statistique2(); // Appel à votre fonction pour récupérer le QPixmap*
        if (chartPixmapPtr2) {
            ui->label_stat->setPixmap(*chartPixmapPtr2); // Mise à jour de l'image de la QLabel
            delete chartPixmapPtr2; // Libération de la mémoire allouée dynamiquement pour le QPixmap
        }
        QPixmap* chartPixmapPtr3 = statistique3(); // Appel à votre fonction pour récupérer le QPixmap*
        if (chartPixmapPtr3) {
            ui->label_stat_2->setPixmap(*chartPixmapPtr3); // Mise à jour de l'image de la QLabel
            delete chartPixmapPtr3; // Libération de la mémoire allouée dynamiquement pour le QPixmap
        }
           return;
    }
    else {
               ui->tableView_stock->setModel(recherche(arg1));
               return;
           }


}
//********************tri par type******************
/*QSqlQueryModel* stock::tri_type()
{

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from STOCKS order by TYPE_STK");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_STK"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_STK"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("REF_STK"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_A_STK"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr(" DFD_STK"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_STK"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("MARQUE_STK"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("ETAT_PRODUIT_STK"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("QUANTITE_STK"));

   return model;

}
QSqlQueryModel* stock::tri_Quantite()
{

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from STOCKS order by QUANTITE_STK");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_STK"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_STK"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("REF_STK"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_A_STK"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr(" DFD_STK"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_STK"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("MARQUE_STK"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("ETAT_PRODUIT_STK"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("QUANTITE_STK"));

   return model;

}
QSqlQueryModel* stock::tri_ID()
{

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from STOCKS order by ID_STK");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_STK"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_STK"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("REF_STK"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_A_STK"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr(" DFD_STK"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_STK"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("MARQUE_STK"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("ETAT_PRODUIT_STK"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("QUANTITE_STK"));

   return model;

}*/
/*
void stock::on_pushButton_tri_clicked()
{
    switch (ui->comboBox_tri->currentIndex()) {
    case 0:
        ui->tableView_stock->setModel(tri_type());
        break;
    case 1:
        ui->tableView_stock->setModel(tri_Quantite());
        break;
    case 2:
          ui->tableView_stock->setModel(tri_ID());
        break;
    }
}*/


//*****************************stat***************************

QPixmap * stock::statistique()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from STOCKS where TYPE_STK='Sucre' ");
     int number1=model->rowCount();
     model->setQuery("select * from STOCKS where TYPE_STK='Jus' ");
     int number2=model->rowCount();
     model->setQuery("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
     int number3=model->rowCount();
     model->setQuery("select * from STOCKS where TYPE_STK='Cafe' ");
     int number4=model->rowCount();
     model->setQuery("select * from STOCKS where TYPE_STK='HuileMinerale' ");
     int number5=model->rowCount();
     model->setQuery("select * from STOCKS where TYPE_STK in ('Eau' ,'Biscuit','Cake','Papier','Chocolat') ");
     int number6=model->rowCount();
       int total=0;
      total=number1+number2+number3+number4+number5+number6;
     if(total!=0)
    {
     QString a = QString("Sucre"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Jus"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("HuileSynthetque"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("Cafe" +QString::number((number4*100)/total,'f',2)+"%" );
     QString e = QString("HuileMinerale" +QString::number((number5*100)/total,'f',2)+"%" );
     QString f = QString("Autre "+QString::number((number6*100)/total,'f',2)+"%" );

    QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
              slice1->setPen(QPen());
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();

              slice2->setPen(QPen());
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
              slice3->setPen(QPen());
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
              slice4->setPen(QPen());
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
              slice5->setPen(QPen());
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage du nombre d'achat de stock par type");
             chart->legend()->hide();

             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(500,300);

           // chartView->show();
             // Créer un QPixmap à partir de la vue de graphique
             QPixmap* chartPixmap = new QPixmap(QPixmap::grabWidget(chartView));
               return chartPixmap;
     }
     else {
         QChart *chart = new QChart();
        chart->setBackgroundBrush(QBrush(QColor(238, 238, 238)));
         chart->setTheme(QChart::ChartThemeLight);

         // Create chart view
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(500, 300);

         // Create pixmap from chart view
         QPixmap* chartPixmap = new QPixmap(QPixmap::grabWidget(chartView));

         return chartPixmap;
     }


}
QPixmap * stock::statistique2()
{
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    int number1=0;

    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
 number1+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number2+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    int number3=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number3+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    int number4=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number4+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Biscuit' ");
    int number5=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number5+=a;
        }

    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    int number6=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number6+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    int number7=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number7+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    int number8=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number8+=a;
        }

    }

    int total=0;
    total=number1+number2+number3+number4+number5+number6+number7+number8;
     if(total!=0)
     {QString a = QString("Sucre"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Jus"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Cafe"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("Cake" +QString::number((number4*100)/total,'f',2)+"%" );
     QString e = QString("Biscuit" +QString::number((number5*100)/total,'f',2)+"%" );
     QString f = QString("Eau "+QString::number((number6*100)/total,'f',2)+"%" );
    QString g = QString("Papier "+QString::number((number7*100)/total,'f',2)+"%" );
    QString h = QString("Chocolat "+QString::number((number8*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     series->append(g,number7);
     series->append(h,number8);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
              slice1->setPen(QPen());
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();

              slice2->setPen(QPen());
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
              slice3->setPen(QPen());
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
              slice4->setPen(QPen());
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
              slice5->setPen(QPen());
     }
     if(number7!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice6 = series->slices().at(6);
              //slice1->setExploded();
              slice6->setLabelVisible();
              slice6->setPen(QPen());
     }
     if(number8!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice7 = series->slices().at(7);
              //slice1->setExploded();
              slice7->setLabelVisible();
              slice7->setPen(QPen());
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par type de stock (Quantite)");
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(500,300);

             // chartView->show();
             // Créer un QPixmap à partir de la vue de graphique
             QPixmap* chartPixmap = new QPixmap(QPixmap::grabWidget(chartView));
             return chartPixmap;
}
     else {
         QChart *chart = new QChart();
         chart->setBackgroundBrush(QBrush(QColor(238, 238, 238)));
         chart->setTheme(QChart::ChartThemeLight);

         // Create chart view
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(500, 300);

         // Create pixmap from chart view
         QPixmap* chartPixmap = new QPixmap(QPixmap::grabWidget(chartView));

         return chartPixmap;
         }

}

QPixmap * stock::statistique3()
{
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
    int number1=0;

    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
 number1+=a;
        }


    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number2+=a;
        }


    }
      int total=0;
     total=number1+number2;
     if(total!=0)
   {
         QString a = QString("HuileSynthetque"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("HuileMinerale"+QString::number((number2*100)/total,'f',2)+"%" );

    QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);

     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
              slice1->setPen(QPen());
     }

             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par type de stock (Quantite)");
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(500,300);
             // Créer un QPixmap à partir de la vue de graphique
             QPixmap* chartPixmap = new QPixmap(QPixmap::grabWidget(chartView));
               return chartPixmap;
     }
     else {
         QChart *chart = new QChart();
      chart->setBackgroundBrush(QBrush(QColor(238, 238, 238)));
         chart->setTheme(QChart::ChartThemeLight);

         // Create chart view
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(500, 300);

         // Create pixmap from chart view
         QPixmap* chartPixmap = new QPixmap(QPixmap::grabWidget(chartView));

         return chartPixmap;
     }

}
//*************************PDF**************************************

void stock::creation_pdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
      if (QFileInfo(fileName).suffix().isEmpty())
          { fileName.append(".pdf"); }
      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setPaperSize(QPrinter::A4);
      printer.setOutputFileName(fileName);

      QTextDocument doc;
      QSqlQuery q;
      q.prepare("SELECT * FROM STOCKS");
      q.exec();
      QString pdf="<br> <h1  style='color:blue'>LISTE DES STOCKS  <br></h1>\n <br> <table>  <tr>  <th>NUM_AVION  </th> <th>VITESSE  </th> <th>NB_REPARATION  </th><th>NB_P_CHANGER  </th><th>MARQUE  </th><th>CONSOMATION </th><th>PRIX_ACHAT </th><th>ETAT </th> </tr>" ;
  //br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //

      while ( q.next())
          {

          pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +"  <td>"  +q.value(6).toString() +" <td>" +q.value(7).toString() +" <td>" +q.value(8).toString() +"  "" " "</td> </td>" ;
      }
      doc.setHtml(pdf);
      doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
      doc.print(&printer);
}

void stock::on_pushButton_3_clicked()
{
    QString strStream;
               strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                   if (QFileInfo(strStream).suffix().isEmpty())
                       { strStream.append(".pdf"); }

                   QPrinter printer(QPrinter::PrinterResolution);
                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(strStream);

                         QTextStream out(&strStream);

                         const int rowCount = ui->tableView_stock->model()->rowCount();
                         const int columnCount = ui->tableView_stock->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString();
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - STOCKS<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                                 "<img src=\"logo.png\" width=\"100\" height=\"100\">" //path
                                "<h2 style=\"text-align: center;\"><strong> "+TT+"</strong></h2>"

                             "<h1 style=\"text-align: center;\"><strong> *****LISTE DES STOCKS ***** </strong></h1>"

                             "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableView_stock->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableView_stock->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++)
                           {
                                 if (!ui->tableView_stock->isColumnHidden(column)) {
                                     QString data =ui->tableView_stock->model()->data(ui->tableView_stock->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument document;
                         document.setHtml(strStream);
                         document.print(&printer);
                         QMessageBox::information(nullptr,QObject::tr("PDF"),
                                                  QObject::tr("PDF effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

}



void stock::on_pushButton_4_clicked()
{
    QString strStream;
               strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                   if (QFileInfo(strStream).suffix().isEmpty())
                       { strStream.append(".pdf"); }

                   QPrinter printer(QPrinter::PrinterResolution);
                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(strStream);

                         QTextStream out(&strStream);

                         const int rowCount = ui->tableView_stock->model()->rowCount();
                         const int columnCount = ui->tableView_stock->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString();
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - STOCKS<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                               +"<img src=C:\\Users\benai\\Documents\\charging_station1\\ICON />" //path
                             "<h1 style=\"text-align: center;\"><strong> *****LISTE DES STOCKS ***** </strong></h1>"

                             "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableView_stock->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableView_stock->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++)
                           {
                                 if (!ui->tableView_stock->isColumnHidden(column)) {
                                     QString data =ui->tableView_stock->model()->data(ui->tableView_stock->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument document;
                         document.setHtml(strStream);
                         document.print(&printer);
}
//**************************alerte********************
QLabel* stock::alerte()
{
   // ui->label_alerte->setText("<img src=\"alerte.png\" width=\"100\" height=\"100\"> <font color='red'><b>alerte!</b></font>");
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    int number1=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number1+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number2+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    int number3=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number3+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    int number4=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number4+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Biscuit' ");
    int number5=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number5+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    int number6=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number6+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    int number7=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number7+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    int number8=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number8+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
    int number9=0;

    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number9+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    int number10=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number10+=a;
        }
    }

    int total=0;
    total=number1+number2+number3+number4+number5+number6+number7+number8+number9+number10;
     if(total==0)
     {      QString alerte="Stock est vide!!!!!";
          QLabel*  label_alerte_ptr = ui->label_alerte;
           label_alerte_ptr->setText(alerte);
              return label_alerte_ptr;
     }
     else{
        QString alerte = "\n\n <h4><font color=\"red\">Presque épuisé:</font></h4>\n";
         if (number1<=3)
         {
             alerte += "<b>-Sucre</b>";
         }
         else  if (number1>3)
         {
             alerte.remove("<b>-Sucre</b>");
         }

         if (number2<=3)
         {
             alerte += "<b>-Jus</b>";
         }
         else  if (number2>3)
         {
             alerte.remove("<b>-Jus</b>");
         }
         if(number3<=3)
         {
             alerte += "<b>-Cafe</b>";
         }
         else  if (number3>3)
         {
             alerte.remove("<b>-Cafe</b>");
         }
         if(number4<=3)
         {
             alerte += "<b>-Cake</b>";
         }

         else  if (number4>3)
         {
             alerte.remove("<b>-Cake</b>");
         }
         if(number5<=3)
         {
             alerte += "<b>-Biscuit \n</b>";
         }
         else  if (number5>3)
         {
             alerte.remove("<b>-Biscuit \n</b>");
         }
         if(number6<=3)
         {
             alerte += "<b>-Eau</b>";
         }
         else  if (number6>3)
         {
             alerte.remove("<b>-Eau</b>");
         }
         if(number7<=3)
         {
             alerte += "<b>-Papier</b>";
         }
         else  if (number7>3)
         {
             alerte.remove("<b>-Papier</b>");
         }
         if(number8<=3)
         {
             alerte += "<b>-Chocolat</b>";
         }
         else  if (number8>3)
         {
             alerte.remove("<b>-Chocolat</b>");
         }

         if(number9<=3)
         {
             alerte += "<b>-HuileSynthetique</b>";
         }
         else  if (number9>3)
         {
             alerte.remove("<b>-HuileSynthetique</b>");

         }
         if(number10<=3)
         {
             alerte += "<b>-HuileMinerale</b>";
         }
         else  if (number10>3)
         {
             alerte.remove("<b>-HuileMinerale</b>");

         }
         //ui->label_alerte->setText(alerte);
        QLabel* label_alerte_ptr = ui->label_alerte;
            label_alerte_ptr->setText(alerte);

             return label_alerte_ptr;
      //   ui->label_alerte->setText(alerte);
    //  ui->label_alerte_3->setText(alerte);
     }

}

QLabel* stock::alerte_3()
{
   // ui->label_alerte->setText("<img src=\"alerte.png\" width=\"100\" height=\"100\"> <font color='red'><b>alerte!</b></font>");
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    int number1=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
 number1+=a;
        }

        qDebug() <<number1;
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number2+=a;
        }



    }
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    int number3=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number3+=a;
        }


    }

    qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    int number4=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number4+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Biscuit' ");
    int number5=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number5+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    int number6=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number6+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    int number7=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number7+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    int number8=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number8+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
    int number9=0;

    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number9+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    int number10=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(9).toInt();
        number10+=a;
        }
    }

    int total=0;
    total=number1+number2+number3+number4+number5+number6+number7+number8+number9+number10;
     if(total==0)
     {
         QString alerte="Stock est vide!!!!!";
                  QLabel* label_alerte_ptr = ui->label_alerte;
                      label_alerte_ptr->setText(alerte);
                      return label_alerte_ptr;
     }
     else{
        QString alerte = "\n\n <h4><font color=\"red\">Presque épuisé:</font></h4>\n";
         if (number1<=3)
         {
             alerte += "<b>-Sucre</b>";
         }
         else  if (number1>3)
         {
             alerte.remove("<b>-Sucre</b>");
         }

         if (number2<=3)
         {
             alerte += "<b>-Jus</b>";
         }
         else  if (number2>3)
         {
             alerte.remove("<b>-Jus</b>");
         }
         if(number3<=3)
         {
             alerte += "<b>-Cafe</b>";
         }
         else  if (number3>3)
         {
             alerte.remove("<b>-Cafe</b>");
         }
         if(number4<=3)
         {
             alerte += "<b>-Cake</b>";
         }

         else  if (number4>3)
         {
             alerte.remove("<b>-Cake</b>");
         }
         if(number5<=3)
         {
             alerte += "<b>-Biscuit \n</b>";
         }
         else  if (number5>3)
         {
             alerte.remove("<b>-Biscuit \n</b>");
         }
         if(number6<=3)
         {
             alerte += "<b>-Eau</b>";
         }
         else  if (number6>3)
         {
             alerte.remove("<b>-Eau</b>");
         }
         if(number7<=3)
         {
             alerte += "<b>-Papier</b>";
         }
         else  if (number7>3)
         {
             alerte.remove("<b>-Papier</b>");
         }
         if(number8<=3)
         {
             alerte += "<b>-Chocolat</b>";
         }
         else  if (number8>3)
         {
             alerte.remove("<b>-Chocolat</b>");
         }

         if(number9<=3)
         {
             alerte += "<b>-HuileSynthetique</b>";
         }
         else  if (number9>3)
         {
             alerte.remove("<b>-HuileSynthetique</b>");

         }
         if(number10<=3)
         {
             alerte += "<b>-HuileMinerale</b>";
         }
         else  if (number10>3)
         {
             alerte.remove("<b>-HuileMinerale</b>");

         }
         //ui->label_alerte->setText(alerte);
        QLabel* label_alerte_ptr = ui->label_alerte_3;
            label_alerte_ptr->setText(alerte);

             return label_alerte_ptr;
      //   ui->label_alerte->setText(alerte);
    //  ui->label_alerte_3->setText(alerte);
     }

}
/*
void stock::alerte2()
{
    // ui->label_alerte->setText("<img src=\"alerte.png\" width=\"100\" height=\"100\"> <font color='red'><b>alerte!</b></font>");
     QSqlQuery qry;
      QDate currentDate = QDate::currentDate();//la date actuelle
      QString alerte = "\n\n <h4><font color=\"red\">Presque périmés:</font></h4>\n";
     qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate1 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate1<= currentDate) {
            alerte += "<b>-Sucre</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }


     }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate2<= currentDate) {
            alerte += "<b>-Jus</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }


     }
     qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate3 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate3<= currentDate) {
            alerte += "<b>-Cafe</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }

     }

     qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate4 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate4<= currentDate) {
            alerte += "<b>-Cake</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }
     }

     qry.prepare("select * from STOCKS where TYPE_STK='Biscuit' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate5 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate5<= currentDate) {
            alerte += "<b>-Biscuit</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }
     }
     qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate6 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate6<= currentDate) {
            alerte += "<b>-Eau</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }

     }

     qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate7 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate7<= currentDate) {
            alerte += "<b>-Papier</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }

     }

     qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate8 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate8<= currentDate) {
            alerte += "<b>-Chocolat</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }


     }
     qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");

     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate9 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate9<= currentDate) {
            alerte += "<b>-HuileSynthetique</b>";
            ui->label_alerte_2->setText(alerte);
             ui->label_alerte_4->setText(alerte);
         }
         }
     }
     qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");

     if(qry.exec())
     {
         while (qry.next())
         {
         QDate a=qry.value(4).toDate();
         QDate maxDate10 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

         if (maxDate10<= currentDate) {
            alerte += "<b>-HuileMinerale</b>";
            ui->label_alerte_2->setText(alerte);
            ui->label_alerte_4->setText(alerte);
         }
         }
     }

}

QString* stock::checkJusAlert( )
{
    QSqlQuery qry;
    QDate currentDate = QDate::currentDate();//la date actuelle
    QString* alerte = new QString(); // Créer un nouvel objet QString sur le heap pour stocker l'alerte
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Jus</b>";
            }
        }
    }

    return alerte; // Retourner un pointeur vers l'objet QString
}
QString* stock::checkSucreAlert( )
{
    QSqlQuery qry;
    QDate currentDate = QDate::currentDate();//la date actuelle
    QString* alerte = new QString(); // Créer un nouvel objet QString sur le heap pour stocker l'alerte
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Sucre</b>";
            }
        }
    }

    return alerte; // Retourner un pointeur vers l'objet QString
}*/
QString* stock::checkCafeAlert( )
{
    QSqlQuery qry;
    QDate currentDate = QDate::currentDate();//la date actuelle
    QString* alerte = new QString(); // Créer un nouvel objet QString sur le heap pour stocker l'alerte
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Cafe</b>";
            }
        }
    }

   qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Cake</b>";
            }
            else
            {
                alerte->remove("<b>-Cake</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Jus</b>";
            }
            else
            {
                alerte->remove("<b>-Jus</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Sucre</b>";
            }
            else
            {
                alerte->remove("<b>-Sucre</b>");

            }
        }
    }


    qry.prepare("select * from STOCKS where TYPE_STK='Biscuit' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Biscuit</b>";
            }
            else
            {
                alerte->remove("<b>-Biscuit</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Eau</b>";
            }

            else
            {
                alerte->remove("<b>-Eau</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Chocolat</b>";
            }
            else
            {
                alerte->remove("<b>-Chocolat</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-HuileSynthetique</b>";
            }
            else
            {
                alerte->remove("<b>-HuileSynthetique</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-Papier</b>";
            }
            else
            {
                alerte->remove("<b>-Papier</b>");

            }
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                *alerte += "<b>-HuileMinerale</b>";
            }
            else
            {
                alerte->remove("<b>-HuileMinerale</b>");

            }
        }
    }

    return alerte; // Retourner un pointeur vers l'objet QString
}


