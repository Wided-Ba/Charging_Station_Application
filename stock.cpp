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
#include <QCompleter>
#include <QFileSystemModel>
#include <QPainter>
#include <QPdfWriter>
#include <QtGui>
using namespace QtCharts;
#define STR_EQUAL 0
using namespace std;

stock::stock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stock)
{

    ui->setupUi(this);
    ui->tableView_stock->setObjectName("tableaustoc");
    ui->label->hide();
    QTimer* timer = new QTimer(this);

       timer->start(3000);
       connect(timer, &QTimer::timeout, this, &stock::afficher);
       timer->start(3000); // Appeler toutes les secondes (3000 ms)

    ui->tableView_stock->setModel(afficher());
    ui->tableView_stock->resizeColumnsToContents();
    ui->comboBox_supp->setModel(comboBox_id());
    ui->comboBox_modif->setModel(comboBox_modif());
    ui->dateEdit->setDate(QDate::currentDate());
    auto fileSystemModel = new QFileSystemModel(this);
    ui->lineEdit->setCompleter(new QCompleter(fileSystemModel,this));
    ui->lineEdit_modif->setCompleter(new QCompleter(fileSystemModel,this));
    QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
    if (chartPixmapPtr) {
        ui->label_stat3->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
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
    ui->label_stat3->setAlignment(Qt::AlignCenter);
    ui->label_stat->setAlignment(Qt::AlignCenter);
     ui->label_stat_2->setAlignment(Qt::AlignCenter);
     //alerte
    ui->textBrowser_2 =alerte();
     ui->textBrowser=alerte_3();

     //alerte date périmé
     QTextBrowser* alerteCafeBrowser = checkCafeAlert();
     ui->textBrowser_alertecafe->setHtml(alerteCafeBrowser->toHtml());
     QTextBrowser* alerteCafeBrowser2 = checkCafeAlert();
     ui->textBrowser_alertecafe_2->setHtml(alerteCafeBrowser2->toHtml());
     QSqlQuery query2;
     query2.prepare("Delete from STOCKS where QUANTITE_STK=0");
      query2.exec();

}




stock ::stock(QString NOM_STK,QString REF_STK,int PRIX_A_STK,QDate DFD_STK,QString TYPE_STK,QString MARQUE_STK,int QUANTITE_STK,QByteArray IMAGE_STK)
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
    this->IMAGE_STK=IMAGE_STK;

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
    query.prepare("INSERT INTO stocks ( NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK,MARQUE_STK,QUANTITE_STK,IMAGE_STK) "
                            "VALUES ( :NOM_STK,:REF_STK,:PRIX_A_STK,:DFD_STK,:TYPE_STK,:MARQUE_STK,:QUANTITE_STK,:IMAGE_STK)");
    query.bindValue(":NOM_STK", NOM_STK);
    query.bindValue(":REF_STK",REF_STK);
    query.bindValue(":PRIX_A_STK", PRIX_A_STK_string);
    query.bindValue(":DFD_STK", DFD_STK);
    query.bindValue(":TYPE_STK", TYPE_STK);
    query.bindValue(":MARQUE_STK", MARQUE_STK);
    query.bindValue(":IMAGE_STK", IMAGE_STK);
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
    model->setHeaderData(7, Qt::Horizontal, tr("etat"));
    ui->tableView_stock->setModel(model);
    ui->tableView_stock->hideColumn(7);
    model->setHeaderData(9, Qt::Horizontal, tr("etat"));
    ui->tableView_stock->setModel(model);
    ui->tableView_stock->hideColumn(9);
    model->setHeaderData(10, Qt::Horizontal, tr("etat"));
    ui->tableView_stock->setModel(model);
    ui->tableView_stock->hideColumn(10);
    //trie  ordre croissant et decroissant

    ui->tableView_stock->setSortingEnabled(true);
    ui->tableView_stock->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QSqlQuery query2;
    query2.prepare("Delete from STOCKS where QUANTITE_STK=0");
     query2.exec();
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
        //QString IMAGE_STK=ui->lineEdit->text();
       // QString ETAT_STK=ui->textEdit_etat->toPlainText();
        QDate DFD_STK=ui->dateEdit->date();
         QFile archivo(ui->lineEdit->text());
         if(!archivo.open(QIODevice::ReadOnly))
         {QMessageBox:: critical(this , "error ",archivo.errorString());
             return;
         }
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

    stock s(NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK, MARQUE_STK, QUANTITE_STK,archivo.readAll());
   archivo.close();
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
                          ui->label_stat3->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
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

                      ui->textBrowser_2 =alerte();
                      ui->textBrowser=alerte_3();
                      QTextBrowser* alerteCafeBrowser = checkCafeAlert(); // Appel de la fonction
                      ui->textBrowser_alertecafe->setHtml(alerteCafeBrowser->toHtml());
                      QTextBrowser* alerteCafeBrowser2 = checkCafeAlert();
                      ui->textBrowser_alertecafe_2->setHtml(alerteCafeBrowser2->toHtml());

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
                     auto fileSystemModel = new QFileSystemModel(this);
                     ui->lineEdit->setCompleter(new QCompleter(fileSystemModel,this));
                     ui->lineEdit_modif->setCompleter(new QCompleter(fileSystemModel,this));
                     QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                     if (chartPixmapPtr) {
                         ui->label_stat3->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
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
                     ui->textBrowser_2 =alerte();
                     ui->textBrowser=alerte_3();
                     QTextBrowser* alerteCafeBrowser = checkCafeAlert(); // Appel de la fonction
                     ui->textBrowser_alertecafe->setHtml(alerteCafeBrowser->toHtml());
                     QTextBrowser* alerteCafeBrowser2 = checkCafeAlert();
                     ui->textBrowser_alertecafe_2->setHtml(alerteCafeBrowser2->toHtml());
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
               ui->textBrowser_2=alerte();
               ui->textBrowser=alerte_3();
               QTextBrowser* alerteCafeBrowser = checkCafeAlert(); // Appel de la fonction
               ui->textBrowser_alertecafe->setHtml(alerteCafeBrowser->toHtml());
               QTextBrowser* alerteCafeBrowser2 = checkCafeAlert();
               ui->textBrowser_alertecafe_2->setHtml(alerteCafeBrowser2->toHtml());
               QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
               if (chartPixmapPtr) {
                   ui->label_stat3->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
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

/*
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
             ui->spinBox_quantite_modif->setValue(qry.value(8).toInt());
             QMessageBox::information(nullptr,QObject::tr("Modification !"),QObject::tr("La ligne selectionne peut etre modifier !\n" "Click Cancel to quit"),QMessageBox::Cancel);
            }
        }
        else
        {
         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }

   }
}*/
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
    query.prepare("update STOCKS set NOM_STK=:NOM_STK,REF_STK=:REF_STK,PRIX_A_STK=:PRIX_A_STK,DFD_STK=:DFD_STK,TYPE_STK=:TYPE_STK,MARQUE_STK=:MARQUE_STK,QUANTITE_STK=:QUANTITE_STK,IMAGE_STK=:IMAGE_STK where ID_STK=:ID_STK");
    query.bindValue(":ID_STK",ID_STK_string);
    query.bindValue(":NOM_STK", NOM_STK);
    query.bindValue(":REF_STK",REF_STK);
    query.bindValue(":PRIX_A_STK", PRIX_A_STK_string);
    query.bindValue(":DFD_STK", DFD_STK);
    query.bindValue(":TYPE_STK", TYPE_STK);
    query.bindValue(":MARQUE_STK", MARQUE_STK);
    query.bindValue(":IMAGE_STK", IMAGE_STK);
    query.bindValue(":QUANTITE_STK", QUANTITE_STK_string);
   return query.exec();

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
         ui->spinBox_quantite_modif->setValue(qry.value(8).toInt());

        }
    }
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
    QFile archivo(ui->lineEdit_modif->text());
    if(!archivo.open(QIODevice::ReadOnly))
    {QMessageBox:: critical(this , "error ",archivo.errorString());
        return;
    }
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
           /*         if ((QUANTITE_STK <= 0 )||(PRIX_A_STK <= 0)) {
                  QMessageBox::warning(this, "Erreur", "Les champs Prix et Quantite doivent être supérieur à zéro");
                  qDebug() <<"Error Quantite ou Prix" ;
                   return;
               }
          // Vérifier si la date est valide
            QDate currentDate = QDate::currentDate();//la date actuelle
            QDate maxDate = currentDate.addMonths(5); // ajouter 5 mois à la date actuelle

            if (DFD_STK <= maxDate) {

                QMessageBox::warning(this, "Erreur", "La date doit être supérieure à 5 mois après la date actuelle");
                qDebug() <<"Error date!" ;
                return; // arrêter l'exécution de la fonction
            }*/

    //********************************************************************
    stock s(NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK, MARQUE_STK, QUANTITE_STK,archivo.readAll());
    archivo.close();
       bool test=s.modifier(ID_STK);
       if(test)
       {
           ui->tableView_stock->setModel(afficher());
           ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
           ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
           ui->comboBox_modif->setModel(comboBox_modif());
           ui->textBrowser_2=alerte();
           ui->textBrowser=alerte_3();
           QTextBrowser* alerteCafeBrowser = checkCafeAlert(); // Appel de la fonction
           ui->textBrowser_alertecafe->setHtml(alerteCafeBrowser->toHtml());
           QTextBrowser* alerteCafeBrowser2 = checkCafeAlert();
           ui->textBrowser_alertecafe_2->setHtml(alerteCafeBrowser2->toHtml());
           QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
           if (chartPixmapPtr) {
               ui->label_stat3->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
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
           QSqlQuery query2;
           query2.prepare("Delete from STOCKS where QUANTITE_STK=0");
            query2.exec();
           qDebug() << "Success modification";
            ui->lineEdit->clear();
                 ui->tabWidget->setCurrentIndex(0);
           //QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

       }
       else
         {  QMessageBox::critical(nullptr,QObject::tr("Modification d'un evenement"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
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
        ui->textBrowser_2 =alerte();
          QTextBrowser* alerteCafeBrowser = checkCafeAlert(); // Appel de la fonction
        ui->textBrowser_alertecafe->setHtml(alerteCafeBrowser->toHtml());
        QTextBrowser* alerteCafeBrowser2 = checkCafeAlert();
        ui->textBrowser_alertecafe_2->setHtml(alerteCafeBrowser2->toHtml());
        QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
        if (chartPixmapPtr) {
            ui->label_stat3->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
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
    // Créer un modèle de requête SQL
    QSqlQueryModel *model = new QSqlQueryModel();

    // Exécuter une requête SQL pour obtenir la somme de la consommation totale pour chaque station
      model->setQuery("SELECT ID_STK, SUM(QUANTITE_STK) as total_quantite FROM STOCKS GROUP BY ID_STK");

    // Créer un graphique à barres
    QChart *chart = new QChart();

    // Ajouter des séries de données pour chaque station
    QBarSeries *series = new QBarSeries();

    // Parcourir les résultats de la requête et ajouter chaque ID_ST et total de consommation comme une barre dans la série
    for (int i = 0; i < model->rowCount(); i++) {
        QString id_st = model->index(i, 0).data().toString();
        int total_consommation = model->index(i, 1).data().toInt();
        QBarSet *set = new QBarSet(id_st);
        *set << total_consommation;
        series->append(set);
    }

    // Ajouter les séries au graphique
    chart->addSeries(series);

    // Définir l'axe des x pour afficher les ID_ST des stations
    QStringList categories;
    for (int i = 0; i < model->rowCount(); i++) {
        categories << model->index(i, 0).data().toString();
    }
    chart->createDefaultAxes();

    // Définir l'axe des y pour afficher les valeurs de CONSC_ST
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Consommation totale");
    chart->setAxisY(axisY, series);

    // Définir les titres et les couleurs
    chart->setTitle("Quantite par stocks");
    chart->setTheme(QChart::ChartThemeLight);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(500, 300);
    // Créer un QPixmap à partir de la vue du graphique
    QPixmap *chartPixmap = new QPixmap(chartView->grab());
    return chartPixmap;
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
        int a=qry.value(8).toInt();
 number1+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number2+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    int number3=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number3+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    int number4=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number4+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='ProduitNet' ");
    int number5=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number5+=a;
        }

    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    int number6=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number6+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    int number7=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number7+=a;
        }

    }

    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    int number8=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
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
     QString e = QString("ProduitNet" +QString::number((number5*100)/total,'f',2)+"%" );
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
        int a=qry.value(8).toInt();
 number1+=a;
        }


    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
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

//*************GENERER_PDF********************
void stock::creation_pdf(QString filename)
{
    // Récupérer le chemin du répertoire du bureau de l'utilisateur
      QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

      // Concaténer le chemin du bureau avec le nom de fichier fourni
      QString fullPath = desktopPath + "/" + filename;

      QPrinter printer;
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName(fullPath);

      QPainter painter;
      if(!painter.begin(&printer))
      {
          qDebug() <<"ERREUR";
          return;
      }

      // Ajouter le logo
      painter.drawPixmap(30, 25, QPixmap(":/ICON/loo.png"));
       painter.drawPixmap(-200,-200,QPixmap(":/ICON/llll.png"));
      // Ajouter le titre
          QString title = "LES STOCKS";
          QFont titleFont("Arial", 18, QFont::Bold);
          painter.setFont(titleFont);
          painter.drawText(370,100, title);
          QFont defaultFont;
          painter.setFont(defaultFont);
      // Récupérer les noms des colonnes
          QHeaderView *header = ui->tableView_stock->horizontalHeader();
           QStringList headers;
           int x = 250;
           int y = 20;
           int w = 0;
           int z = 0;
           int a = 40;

      for(int i=0; i<header->count(); i++)
      {
          QString headerText = header->model()->headerData(i, Qt::Horizontal).toString();
          headers << headerText;
          painter.drawText(0+ a, x,headerText);
        a += 140;
      }

      // Afficher les noms de colonnes

      QModelIndex index;
      for(int row=0; row<ui->tableView_stock->model()->rowCount(); row++)
      {
          y = 280; // incrémenter la position verticale pour afficher la prochaine ligne de données
          x = 40;
                 w = y+z;
                 for(int col=0; col<ui->tableView_stock->model()->columnCount(); col++)
                 {
                     index = ui->tableView_stock->model()->index(row, col);
                     QString data = ui->tableView_stock->model()->data(index).toString();
                     painter.drawText(x, w, data);
                     x += 140;
                 }
                 z += 30;
      }
      painter.drawText(310,1350, "Toutes les données ont été générées par l'application Voltify.");
      // Fin du dessin
      painter.end();

      qDebug() << "Fichier PDF enregistré avec succès:" << fullPath;
      QMessageBox::information(this,tr("Voltify"),tr("Votre fichier pdf a ete généré"));
}

void stock::on_pushButton_3_clicked()
{
    QString filename = "stocks.pdf";
      creation_pdf(filename);
}

void stock::on_pushButton_4_clicked()
{
    QString filename = "stocks.pdf";
      creation_pdf(filename);
}
//**************************alerte********************
QTextBrowser* stock::alerte()
{
   // ui->label_alerte->setText("<img src=\"alerte.png\" width=\"100\" height=\"100\"> <font color='red'><b>alerte!</b></font>");
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    int number1=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number1+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number2+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    int number3=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number3+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    int number4=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number4+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='ProduitNet' ");
    int number5=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number5+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    int number6=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number6+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    int number7=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number7+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    int number8=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number8+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
    int number9=0;

    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number9+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    int number10=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number10+=a;
        }
    }

    int total=0;
    total=number1+number2+number3+number4+number5+number6+number7+number8+number9+number10;
     if(total==0)
     {
         QString alerte="Stock est vide!!!!!";
         QTextBrowser* text_browser_alerte_ptr = new QTextBrowser(ui->textBrowser);
         text_browser_alerte_ptr->setText(alerte);
              return text_browser_alerte_ptr;
     }
     else{
        QString alerte ;
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
             alerte += "<b>-ProduitNet\n</b>";
         }
         else  if (number5>3)
         {
             alerte.remove("<b>-ProduitNet\n</b>");
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
         QTextBrowser* text_browser_alerte_ptr = ui->textBrowser_2;

            text_browser_alerte_ptr->setText(alerte);

            return text_browser_alerte_ptr;
     }

}

QTextBrowser* stock::alerte_3()
{
   // ui->label_alerte->setText("<img src=\"alerte.png\" width=\"100\" height=\"100\"> <font color='red'><b>alerte!</b></font>");
    QSqlQuery qry;
    qry.prepare("select * from STOCKS where TYPE_STK='Sucre' ");
    int number1=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number1+=a;
        }

    }
    qry.prepare("select * from STOCKS where TYPE_STK='Jus' ");
    int number2=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number2+=a;
        }

    }
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    int number3=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number3+=a;
        }


    }

    qry.prepare("select * from STOCKS where TYPE_STK='Cake' ");
    int number4=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number4+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='ProduitNet' ");
    int number5=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number5+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='Eau' ");
    int number6=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number6+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Papier' ");
    int number7=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number7+=a;
        }
    }

    qry.prepare("select * from STOCKS where TYPE_STK='Chocolat' ");
    int number8=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number8+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileSynthetque' ");
    int number9=0;

    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number9+=a;
        }
    }
    qry.prepare("select * from STOCKS where TYPE_STK='HuileMinerale' ");
    int number10=0;
    if(qry.exec())
    {
        while (qry.next())
        {
        int a=qry.value(8).toInt();
        number10+=a;
        }
    }

    int total=0;
    total=number1+number2+number3+number4+number5+number6+number7+number8+number9+number10;
     if(total==0)
     {
         QString alerte="Stock est vide!!!!!";
         QTextBrowser* text_browser_alerte_ptr = new QTextBrowser(ui->textBrowser);
         text_browser_alerte_ptr->setText(alerte);
              return text_browser_alerte_ptr;
     }
     else{
        QString alerte;
         if (number1<=3)
         {
             alerte += "<b>-Sucre</b>";

         }
         else  if (number1>3)
         {

             alerte.replace("<b>-Sucre</b>", "");
         }

         if (number2<=3)
         {
             alerte += "<b>-Jus</b>";
         }
         else  if (number2>3)
         {

             alerte.replace("<b>-Jus</b><br>", "");
         }
         if(number3<=3)
         {
             alerte += "<b>-Cafe</b>";
         }
         else  if (number3>3)
         {

             alerte.replace("<b>-Cafe</b><br>", "");
         }
         if(number4<=3)
         {
             alerte += "<b>-Cake</b>";
         }

         else  if (number4>3)
         {

             alerte.replace("<b>-Cake</b><br>", "");
         }
         if(number5<=3)
         {
             alerte += "<b>-ProduitNet\n</b>";
         }
         else  if (number5>3)
         {

             alerte.replace("<b>-ProduitNet</b><br>", "");
         }
         if(number6<=3)
         {
             alerte += "<b>-Eau</b>";
         }
         else  if (number6>3)
         {

             alerte.replace("<b>-Eau</b><br>", "");
         }
         if(number7<=3)
         {
             alerte += "<b>-Papier</b>";
         }
         else  if (number7>3)
         {
             alerte.replace("<b>-Papier</b><br>", "");
         }
         if(number8<=3)
         {
             alerte += "<b>-Chocolat</b>";
         }
         else  if (number8>3)
         {
             alerte.replace("<b>-Chocolat</b><br>", "");
         }

         if(number9<=3)
         {
             alerte += "<b>-HuileSynthetique</b>";
         }
         else  if (number9>3)
         {
             alerte.replace("<b>-HuileSynthetique</b>", "");

         }
         if(number10<=3)
         {
             alerte += "<b>-HuileMinerale</b>";
         }
         else  if (number10>3)
         {
             alerte.replace("<b>-HuileMinerale</b>", "");

         }

         QTextBrowser* text_browser_alerte_ptr = ui->textBrowser;
            text_browser_alerte_ptr->setText(alerte);
            return text_browser_alerte_ptr;

     }

}

QTextBrowser* stock::checkCafeAlert( )
{
    QSqlQuery qry;
    QDate currentDate = QDate::currentDate();//la date actuelle
    QString alerte; // Créer un nouvel objet QString sur le heap pour stocker l'alerte
    qry.prepare("select * from STOCKS where TYPE_STK='Cafe' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                alerte += "<b>-Cafe</b>";
            }
            else
            {
               alerte.replace("<b>-Cafe</b><br>", "");

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
                alerte += "<b>-Cake</b>";
            }
            else
            {
                alerte.replace("<b>-Cake</b><br>", "");

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
                alerte += "<b>-Jus</b>";
            }
            else
            {
                alerte.replace("<b>-Jus</b><br>", "");

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
                alerte += "<b>-Sucre</b>";
            }
            else
            {
                alerte.replace("<b>-Sucre</b><br>", "");

            }
        }
    }


    qry.prepare("select * from STOCKS where TYPE_STK='ProduitNet' ");
    if(qry.exec())
    {
        while (qry.next())
        {
            QDate a=qry.value(4).toDate();
            QDate maxDate2 = a.addMonths(-1); // ajouter 5 mois à la date actuelle

            if (maxDate2 <= currentDate) {
                alerte += "<b>-ProduitNet</b>";
            }
            else
            {
                alerte.replace("<b>-ProduitNet</b><br>", "");

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
                alerte += "<b>-Eau</b>";
            }

            else
            {
                alerte.replace("<b>-Eau</b><br>", "");

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
                alerte += "<b>-Chocolat</b>";
            }
            else
            {
                alerte.replace("<b>-Chocolat</b><br>", "");

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
                alerte += "<b>-HuileSynthetique</b>";
            }
            else
            {
                alerte.replace("<b>-HuileSynthetique</b><br>", "");

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
                alerte += "<b>-Papier</b>";
            }
            else
            {
                alerte.replace("<b>-Papier</b><br>", "");

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
                alerte += "<b>-HuileMinerale</b>";
            }
            else
            {
                alerte.replace("<b>-HuileMinerale</b><br>", "");

            }
        }
    }

    QTextBrowser* alerteBrowser =ui->textBrowser_alertecafe;
        alerteBrowser->setHtml(alerte);
        return alerteBrowser;
}


//********************************insertion image***************************************************
void stock::on_toolButton_clicked()
{
   auto nombreArchivo= QFileDialog::getOpenFileName(this,"abrir imagen",QDir::rootPath(),
    "Imagenes(*.png *.jpg *.jpeg);;Cualquier archivo (*.*)");
   ui->lineEdit->setText(nombreArchivo);
  QString TYPE_STK = ui->comboBox_type->currentText();
   if(nombreArchivo.contains(TYPE_STK))
   {
      qDebug() << "L'image choisie est compatible ";

   }

   else
   {
       QMessageBox::critical(nullptr,QObject::tr("Image non compatible"),QObject::tr("La ligne selectionne peut etre modifier !\n" "Click Cancel to quit"),QMessageBox::Cancel);
       ui->lineEdit->clear();
       //ui->tabWidget->setCurrentIndex(0);
       return ;
   }
}

void stock::on_toolButton_modif_clicked()
{
    auto nombreArchivo= QFileDialog::getOpenFileName(this,"abrir imagen",QDir::rootPath(),
     "Imagenes(*.png *.jpg *.jpeg);;Cualquier archivo (*.*)");
    ui->lineEdit_modif->setText(nombreArchivo);
   QString TYPE_STK = ui->comboBox_type_modif->currentText();
    if(nombreArchivo.contains(TYPE_STK))
    {
       qDebug() << "L'image choisie est compatible ";

    }

    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Image non compatible"),QObject::tr("La ligne selectionne peut etre modifier !\n" "Click Cancel to quit"),QMessageBox::Cancel);
        ui->lineEdit_modif->clear();
        //ui->tabWidget->setCurrentIndex(0);
        return ;
    }
}

void stock::on_tableView_stock_activated(const QModelIndex &index)
{
    {

        QString val=ui->tableView_stock->model()->data(index).toString();
         QString val1=ui->tableView_stock->model()->data(index).toString();
        QSqlQuery qry;
        QSqlQuery qry1;
        qry.prepare("select IMAGE_STK from STOCKS where ID_STK='"+val+"'");
         qry1.prepare("select ID_STK,NOM_STK from STOCKS where ID_STK='"+val+"'");
        if(qry.exec())
        {
            while (qry.next())
            { qry1.exec();
                qry1.next();
                QPixmap pixmap;
                pixmap.loadFromData(qry.value(0).toByteArray());
                QPixmap pixmap_resized = pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio);

                QDialog *newWindow = new QDialog(this);
                newWindow->setWindowTitle("Image Viewer");

                QLabel *imageLabel = new QLabel(newWindow);
                imageLabel->setPixmap(pixmap_resized);
                imageLabel->setAlignment(Qt::AlignCenter);

               QLabel *infoLabel = new QLabel(newWindow);
                QString infoText = "<b>Id :</b> " + qry1.value(0).toString() + "<br>" +
                                   "<b>Nom :</b> " + qry1.value(1).toString();
                infoLabel->setText(infoText);

                QGridLayout *layout = new QGridLayout(newWindow);
                layout->addWidget(infoLabel, 0, 0);  // première ligne, première colonne
                layout->addWidget(imageLabel, 1, 0);  // deuxième ligne, première colonne
                newWindow->setLayout(layout);

                newWindow->show();
                ui->label->hide();
            }
        }
   }
}
/*stock::~stock()
{
    delete ui;
}*/





