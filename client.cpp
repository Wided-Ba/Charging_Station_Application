#include "client.h"
#include "ui_client.h"
#include "connection.h"
#include "station.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QDate>
#include <QFloat16>
#include "profil.h"
#include <QtSql>
#include<QTextStream>
#include <QtCharts>
#include <QDialog>
#include <QDebug>
#include <QVBoxLayout>
#include <QChartView>
#include <QValueAxis>
#include <QBarSeries>
#include<QPixmap>
#include <QBarSet>
#include <QChart>
#include <QBarCategoryAxis>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QtSql>
#include <QFile>
#include <QTextStream>
#include <QtWidgets>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkInterface>
#include <QtCore/QDebug>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    ui->mainWindow->setObjectName("clientt");
    ui->tableView->setObjectName("tableauclient");

    /*int ret=A.connect_arduino();//lancer la connexion a arduino
         switch(ret)
         {case(0):qDebug()<<"arduino is avaiblble and connected to : "<<A.getarduino_port_name();
             break ;
         case(1):qDebug()<<"arduino is avaible but not conncted to :"<<A.getarduino_port_name().end();
             break;
         case(-1):qDebug()<<"arduino is not avaible";
         }
         level();
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(level()));//permet de lancer
         //le slot de l'update_label suite à la rceception du signal readyRead (reception des  donnés)*/
    player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(":/Notification-25.mp3"));

    QSqlTableModel* model1 = afficherC();
    ui->tableView->setModel(model1);
            ui->tableView->setColumnHidden(4, true);
            ui->tableView->setColumnHidden(6, true);
            ui->tableView->setColumnHidden(8, true);
            ui->tableView->setColumnHidden(9, true);
            ui->tableView->setColumnHidden(10, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->comboBox_id_st->setModel(comboBox_id_st());
    ui->comboBox_id_c->setModel(comboBox_id_c());
    ui->comboBox_client->setModel(comboBox_client());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->comboBox_supp->setModel(comboBox_id());
    ui->comboBox_supp->setModel(comboBox_modif());
    showNotification();
        QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                if (chartPixmapPtr) {
                    ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                    delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
                }

}
/*client::~client()
{
    delete ui;
}*/
client::client (QString CIN_C,QString NOM_C,QString PRENOM_C,QString SEXE_C ,int NBR_RECHARGE_C,int NUM_TEL_C,QString EMAIL_C ,int CON_VISITE_C ,QDate DATE_NAISSANCE_C)
{
    this->CIN_C=CIN_C;
    this->NOM_C=NOM_C;
    this->PRENOM_C=PRENOM_C;
    this->DATE_NAISSANCE_C=DATE_NAISSANCE_C;
    this->SEXE_C=SEXE_C;
    this->NBR_RECHARGE_C=NBR_RECHARGE_C;
    this->NUM_TEL_C=NUM_TEL_C;
    this->EMAIL_C=EMAIL_C;
    this->CON_VISITE_C=CON_VISITE_C;



}
/*client::client(int ID_E,int ID_C,int CON_VISITE_C)
{
    this->ID_C=ID_C;
    this->ID_E=ID_E;
    this->CON_VISITE_C=CON_VISITE_C;
}*/
bool client ::Ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO CLIENTS (CIN_C,NOM_C,PRENOM_C,SEXE_C,NBR_RECHARGE_C,NUM_TEL_C,EMAIL_C,CON_VISITE_C,DATE_NAISSANCE_C)"
                      "VALUES (:CIN_C,:NOM_C,:PRENOM_C,:SEXE_C,:NBR_RECHARGE_C,:NUM_TEL_C,:EMAIL_C,:CON_VISITE_C,:DATE_NAISSANCE_C)");
            NBR_RECHARGE_C = 1;
        query.bindValue(":CIN_C",CIN_C);
           query.bindValue(":NOM_C",NOM_C);
           query.bindValue(":PRENOM_C",PRENOM_C);
           query.bindValue(":SEXE_C",SEXE_C);
           query.bindValue(":NBR_RECHARGE_C",NBR_RECHARGE_C);
           query.bindValue(":NUM_TEL_C", NUM_TEL_C);
           query.bindValue(":EMAIL_C",EMAIL_C);
           query.bindValue(":CON_VISITE_C",CON_VISITE_C);
   query.bindValue(":DATE_NAISSANCE_C", DATE_NAISSANCE_C);


           return query.exec();

}

void client::on_ajoutC_clicked()
{
    QString SEXE_C = ui->comboBox->currentText();
      QDate DATE_NAISSANCE_C = ui->dateEdit->date();
      int NUM_TEL_C=ui->lineEdit_NumTel->text().toInt();
      QString EMAIL_C=ui->lineEdit_Email->text();
      int CON_VISITE_C=ui->lineEdit_Cons->text().toInt();
      QString CIN_C=ui->lineEdit_Cin->text();
      QString NOM_C=ui->lineEdit_Nom->text();
      QString PRENOM_C=ui->lineEdit_Prenom->text();

      // Initialiser NBR_RECHARGE_C à 1
      int NBR_RECHARGE_C = 1;

      // Contrôle de saisie
      if ((NOM_C.isEmpty()) || (CIN_C.isEmpty()) || (PRENOM_C.isEmpty()) ||(SEXE_C.isEmpty()) ||(EMAIL_C.isEmpty())) {
          QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires");
          qDebug() <<"Erreur! Remplir tous les champs" ;
          return;
      }
      if ((NOM_C.length() <= 1) || (PRENOM_C.length() <= 1)){
          QMessageBox::warning(this, "Erreur", "NOM et PRENOM doivent être supérieurs à 1 caractères !");
          qDebug() << "NOM et PRENOM doivent être supérieurs à 1 caractères !";
          return;
      }
      if (CIN_C.length() != 8){
          QMessageBox::warning(this, "Erreur", "CIN doit comporter 8 chiffres !");
          qDebug() << "CIN doit comporter 8 chiffres !";
          return;
      }
      /*if ((NUM_TEL_C == 8 )) {
         QMessageBox::warning(this, "Erreur", "Le numero de tlf doit etre sepriure à 8");
         qDebug() <<"Erreur numero de tlf" ;
          return;
      }*/

      /**************************Email******************/

      QString Email_C = ui->lineEdit_Email->text();
      QRegExp emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
      if (!emailRegex.exactMatch(EMAIL_C)) {
          QMessageBox::warning(this, "Erreur", "Format de Email invalide !");
          qDebug() << "Erreur email";
          return;
      }

      client C(CIN_C, NOM_C, PRENOM_C, SEXE_C, NBR_RECHARGE_C, NUM_TEL_C, EMAIL_C, CON_VISITE_C, DATE_NAISSANCE_C);
      bool test = C.Ajouter();
      if (test)
      {
      QSqlTableModel* model1 = afficherC();
        ui->tableView->setModel(model1);
          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Ajout effectué avec succès.\n"
                                  "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

sendMail();
      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Erreur lors de l'ajout du client !\n"
                                  "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
     /* QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                  if (chartPixmapPtr) {
                      ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                      delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                  }*/
      QSqlTableModel* model1 = afficherC();
 ui->tableView->setModel(model1);
          ui->tableView->resizeColumnsToContents();
              ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
              QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                      if (chartPixmapPtr) {
                          ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                          delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
                      }
                          showNotification();
                          ui->comboBox_id_st->setModel(comboBox_id_st());
                          ui->comboBox_id_c->setModel(comboBox_id_c());
                          ui->comboBox_client->setModel(comboBox_client());
                          ui->comboBox_supp->setModel(comboBox_id());
                          ui->comboBox_supp->setModel(comboBox_modif());

  }
/****image******/
class IconDelegate : public QStyledItemDelegate {
public:
    IconDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        if (index.column() == 5) {
            int value = index.model()->data(index, Qt::DisplayRole).toInt();
            QPixmap pixmap;
            if (value == 1) {
                pixmap = QPixmap(":/ICON/1e.png");
            } else if (value == 2) {
                pixmap = QPixmap(":/ICON/2e.png");
            } else if (value == 3) {
                pixmap = QPixmap(":/ICON/3e.png");
            } else if (value == 4)
            {
                pixmap = QPixmap(":/ICON/4e.png");
            }
            else if (value == 5)
                        {
                            pixmap = QPixmap(":/ICON/5e.png");
                        }
            else if (value == 6)
                        {
                            pixmap = QPixmap(":/ICON/6e.png");
                        }
            painter->drawPixmap(option.rect, pixmap);
        } else {
            QStyledItemDelegate::paint(painter, option, index);
        }
    }
};



QSqlTableModel* client::afficherC()
{
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable("CLIENTS");

    // Spécifier les colonnes à afficher et leurs noms d'en-tête
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN_C"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_C"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM_C"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NBR_RECHARGE_C"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("EMAIL_C"));
            ui->tableView->setColumnHidden(4, true);
            ui->tableView->setColumnHidden(6, true);
            ui->tableView->setColumnHidden(8, true);
            ui->tableView->setColumnHidden(9, true);
            ui->tableView->setColumnHidden(10, true);

    // Activer le tri par défaut sur la colonne ID_ST
    model->setSort(0, Qt::AscendingOrder);

    // Sélectionner les données de la table
    model->select();
    IconDelegate* iconDelegate = new IconDelegate(this);


    // Activer le tri sur le TableView
    ui->tableView->setSortingEnabled(true);
        // Associer l'objet IconDelegate à la colonne NBR_RECHARGE_C
        ui->tableView->setItemDelegateForColumn(5, iconDelegate);
    // Activer le tri sur le TableView
   // ui->tableView->setSortingEnabled(true);

    return model;
}


/*void client::afficherImageSelonMode() {
    QSqlQuery query;
    query.prepare("SELECT NBR_RECHARGE_C(*) FROM CLIENTS");
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count > 0) {
            QPixmap image(":/new/prefix1/ICON/loo.png"); // charger l'image X depuis les ressources de l'application
            ui->label_image->setPixmap(image);
        } else {
            QPixmap image(":/new/prefix1/ICON/loo.png"); // charger l'image Y depuis les ressources de l'application
            ui->label_4->setPixmap(image);
        }
    } else {
        // afficher une erreur si la requête a échoué
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de récupérer les données des stations."));
    }
}*/
//supprimer all


void client::on_pushButton_SC_3_clicked()
{
    QSqlQuery query;
             QMessageBox msgBox;
             msgBox.setText("Voulez-vous supprimer tous le client?");
             msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
             int ret = msgBox.exec();
             switch (ret) {
               case QMessageBox::Ok:
                 query.prepare("Delete from CLIENTS ");
                 query.exec();
                ui->tableView->setModel(afficherC());
                ui->tableView->setColumnHidden(4, true);
                ui->tableView->setColumnHidden(6, true);
                ui->tableView->setColumnHidden(8, true);
                ui->tableView->setColumnHidden(9, true);
                ui->tableView->setColumnHidden(10, true);
                 ui->tableView->resizeColumnsToContents(); //tnadhem l tab

                   break;
               case QMessageBox::Cancel:
                   // Cancel was clicked
                   break;
               default:
                   // should never be reached
                   break;
             }
             QSqlTableModel* model1 = afficherC();
        ui->tableView->setModel(model1);
                 ui->tableView->resizeColumnsToContents();
                     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
                     QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                             if (chartPixmapPtr) {
                                 ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                                 delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
                             }
                                 showNotification();
                                 ui->comboBox_id_st->setModel(comboBox_id_st());
                                 ui->comboBox_id_c->setModel(comboBox_id_c());
                                 ui->comboBox_client->setModel(comboBox_client());
                                 ui->comboBox_supp->setModel(comboBox_id());
                                 ui->comboBox_supp->setModel(comboBox_modif());

             //pour la mise a jour du tableau
}

//***************************delete********************

bool client::supprimer(int ID)
{
    QSqlQuery query;
    QString ID_C_string=QString::number(ID);
    query.prepare("Delete from CLIENTS where ID_C= :ID");
    query.bindValue(":ID",ID_C_string);
    QSqlTableModel* model1 = afficherC();
    ui->tableView->setModel(model1);
        ui->tableView->setColumnHidden(4, true);
        ui->tableView->setColumnHidden(6, true);
        ui->tableView->setColumnHidden(8, true);
        ui->tableView->setColumnHidden(9, true);
        ui->tableView->setColumnHidden(10, true);
        ui->tableView->resizeColumnsToContents();
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
            if (chartPixmapPtr) {
                ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
            }
                showNotification();
                ui->comboBox_id_st->setModel(comboBox_id_st());
                ui->comboBox_id_c->setModel(comboBox_id_c());
                ui->comboBox_client->setModel(comboBox_client());
                ui->comboBox_supp->setModel(comboBox_id());
                ui->comboBox_supp->setModel(comboBox_modif());

    return query.exec();


}


QSqlQueryModel* client::comboBox_id()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query("SELECT ID_C FROM CLIENTS");
    model->setQuery(query);
    return model;

}


void client::on_pushButton_SC_clicked()
{
    int ID = ui->comboBox_supp->currentText().toInt();

    if (!existe(ID))
    { // verification l'existence de l'ID
            QMessageBox::warning(nullptr, QObject::tr("Suppression d'un client"),
                                 QObject::tr("ID introuvable dans le tableau Clients.\n"
                                             "Click Cancel to quit."), QMessageBox::Cancel);
            return; // Quitter la fonction si l'ID n'existe pas
     }

         QMessageBox msgBox;
         msgBox.setText("Voulez-vous supprimer cet client?");
         msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
         int ret = msgBox.exec();
         switch (ret)
         {
               case QMessageBox::Ok:
             {
                 bool test=supprimer(ID);
                 if(test)
                 {
                 QSqlTableModel* model1 = afficherC();
        ui->tableView->setModel(model1);
                     ui->tableView->resizeColumnsToContents();
                         ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

                     ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box

                     QMessageBox::information(nullptr,QObject::tr("Suppression d'un client"),
                                              QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
                 }
                 else
                     QMessageBox::critical(nullptr,QObject::tr("Suppression d'un client"),
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
         QSqlTableModel* model1 = afficherC();
    ui->tableView->setModel(model1);
             ui->tableView->resizeColumnsToContents();
                 ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
                 QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                         if (chartPixmapPtr) {
                             ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                             delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
                         }
                             showNotification();
                             ui->comboBox_id_st->setModel(comboBox_id_st());
                             ui->comboBox_id_c->setModel(comboBox_id_c());
                             ui->comboBox_client->setModel(comboBox_client());
                             ui->comboBox_supp->setModel(comboBox_id());
                             ui->comboBox_supp->setModel(comboBox_modif());

}
//********************chercher*********************
bool client::existe(int ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE ID_C = :ID");
    query.bindValue(":ID", ID);
    if (query.exec())
        return query.next();
    return false;
}
//****************modifier*************


void client::on_tableView_activated(const QModelIndex &index)
{

            QString val=ui->tableView->model()->data(index).toString();

            QSqlQuery qry;
            qry.prepare("select * from CLIENTS where ID_C='"+val+"'");
            if(qry.exec())
            {
                while (qry.next())
                {
                     ui->comboBox_client->setCurrentText(qry.value(0).toString());

                  ui->lineEdit_Cin_3->setText(qry.value(1).toString());
                  ui->lineEdit_Nom_3->setText(qry.value(2).toString());
                   ui->lineEdit_Prenom_3->setText(qry.value(3).toString());
                 ui->comboBox_4->setCurrentText(qry.value(4).toString());
              ui->lineEdit_NbrR_3->setText(qry.value(5).toString());
                 ui->lineEdit_NumTel_3->setText(qry.value(6).toString());
                   ui->lineEdit_Email_3->setText(qry.value(7).toString());
                   ui->lineEdit_Cons_3->setText(qry.value(9).toString());
              ui->dateEdit_2->setDate(qry.value(10).toDate());


               }
                ui->mainWindow->setCurrentIndex(2);
            }
            else
            {
             QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            }
            QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                       if (chartPixmapPtr) {
                           ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                           delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                       }
                           showNotification();
                           ui->comboBox_id_st->setModel(comboBox_id_st());
                           ui->comboBox_id_c->setModel(comboBox_id_c());
                           ui->comboBox_client->setModel(comboBox_client());
                           ui->comboBox_supp->setModel(comboBox_id());
                           ui->comboBox_supp->setModel(comboBox_modif());


}

QSqlQueryModel* client::comboBox_modif()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query("SELECT ID_C FROM CLIENTS");
    model->setQuery(query);
    return model;

}
bool client::modifier(QString ID_C)
{
    QSqlQuery query;

    QString NBR_RECHARGE_C_string=QString::number(NBR_RECHARGE_C);
    QString NUM_TEL_C_string=QString::number(NUM_TEL_C);
     QString CON_VISITE_C_string=QString::number(CON_VISITE_C);
    query.prepare("update CLIENTS set CIN_C=:CIN_C,NOM_C=:NOM_C,PRENOM_C=:PRENOM_C,SEXE_C=:SEXE_C,NBR_RECHARGE_C=:NBR_RECHARGE_C,NUM_TEL_C=:NUM_TEL_C,EMAIL_C=:EMAIL_C ,CON_VISITE_C=:CON_VISITE_C,DATE_NAISSANCE_C=:DATE_NAISSANCE_C  where ID_C=:ID_C");
    query.bindValue(":ID_C",ID_C);
    query.bindValue(":CIN_C", CIN_C);
    query.bindValue(":NOM_C", NOM_C);
    query.bindValue(":PRENOM_C",PRENOM_C);
    query.bindValue(":SEXE_C", SEXE_C);
    query.bindValue(":NBR_RECHARGE_C",NBR_RECHARGE_C_string);
    query.bindValue(":NUM_TEL_C",NUM_TEL_C_string);
    query.bindValue(":EMAIL_C", EMAIL_C);
    query.bindValue(":CON_VISITE_C",CON_VISITE_C_string);
    query.bindValue(":DATE_NAISSANCE_C", DATE_NAISSANCE_C);
   return query.exec();

}




void client::on_pushButton_modifier_clicked()
{
    QString ID_C = ui->comboBox_client->currentText();
    QString CIN_C= ui->lineEdit_Cin_3->text();
    QString NOM_C= ui->lineEdit_Nom_3->text();
    QString PRENOM_C = ui->lineEdit_Prenom_3->text();
    QDate DATE_NAISSANCE_C=ui->dateEdit_2->date();
     QString SEXE_C = ui->comboBox_4->currentText();
    int NBR_RECHARGE_C = ui->lineEdit_NbrR_3->text().toInt();
    int NUM_TEL_C = ui->lineEdit_NumTel_3->text().toInt();
    QString EMAIL_C = ui->lineEdit_Email_3->text();
    int CON_VISITE_C = ui->lineEdit_Cons_3->text().toInt();
    //QString ETAT_Produit_STK=ui->textEdit_etat_2->toPlainText();

 client C(CIN_C,NOM_C,PRENOM_C,SEXE_C,NBR_RECHARGE_C,NUM_TEL_C,EMAIL_C,CON_VISITE_C,DATE_NAISSANCE_C);

 bool test=C.modifier(ID_C);
       if(test)
       {
       QSqlTableModel* model1 = afficherC();
        ui->tableView->setModel(model1);
           ui->tableView->resizeColumnsToContents();
               ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
           ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
         //  ui->spinBox->setModel(comboBox_modif());

                   QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                           if (chartPixmapPtr) {
                               ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                               delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
                           }
                               showNotification();
                               ui->comboBox_id_st->setModel(comboBox_id_st());
                               ui->comboBox_id_c->setModel(comboBox_id_c());
                               ui->comboBox_client->setModel(comboBox_client());
                               ui->comboBox_supp->setModel(comboBox_id());
                               ui->comboBox_supp->setModel(comboBox_modif());

           qDebug() << "Success modification";
           QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Modification d'un evenement"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

}


//RECHERCHE
 QSqlTableModel* client::tableView(QString val)
    {
        QSqlTableModel* model = new QSqlTableModel();
       model->setTable("CLIENTS");

       model->setFilter(QString( "ID_C LIKE '%%1%' OR CIN_C LIKE  '%%1%' OR NOM_C LIKE  '%%1%' OR PRENOM_C LIKE  '%%1%' OR SEXE_C LIKE  '%%1%' OR NBR_RECHARGE_C LIKE  '%%1%' OR NUM_TEL_C LIKE  '%%1%' OR DATE_VISITE_C LIKE  '%%1%' OR CON_VISITE_C LIKE  '%%1%' OR DATE_NAISSANCE_C LIKE'%%1%' OR ID_E LIKE'%%1%'").arg(val));




       model->setHeaderData(0, Qt::Horizontal, tr("ID_C"));
        model->setHeaderData(1, Qt::Horizontal, tr("CIN_C"));
        model->setHeaderData(2, Qt::Horizontal, tr("NOM_C"));
        model->setHeaderData(3, Qt::Horizontal, tr("PRENOM_C"));
        model->setHeaderData(4, Qt::Horizontal, tr("SEXE_C"));
        model->setHeaderData(5, Qt::Horizontal, tr("NBR_RECHARGE_C"));
        model->setHeaderData(6, Qt::Horizontal, tr("NUM_TEL_C"));
        model->setHeaderData(7, Qt::Horizontal, tr("DATE_VISITE_C"));
        model->setHeaderData(8, Qt::Horizontal, tr("CON_VISITE_C"));
        model->setHeaderData(9, Qt::Horizontal, tr("DATE_NAISSANCE"));

            model->select();

            return model;






}



void client::on_lineEditID_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
    ui->tableView->setModel(afficherC());
    } else {
    ui->tableView->setModel(tableView(arg1));
    }
}




// statistique
QPixmap * client::statistique()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from CLIENTS where SEXE_C='FEMME' ");
     int number1=model->rowCount();
     model->setQuery("select * from CLIENTS where SEXE_C='HOMME' ");
     int number2=model->rowCount();


       int total=0;
      total=number1+number2;
     if(total!=0)
    {
     QString a = QString("Femme"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Homme"+QString::number((number2*100)/total,'f',2)+"%" );



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
             chart->setTitle("Pourcentage de clients par sexe");
             chart->legend()->hide();

             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(491,231);

           // chartView->show();
             // Créer un QPixmap à partir de la vue de graphique
             QPixmap* chartPixmap = new QPixmap(chartView->grab());
               return chartPixmap;
     }
     else {
         QChart *chart = new QChart();
        chart->setBackgroundBrush(QBrush(QColor(238, 238, 238)));
         chart->setTheme(QChart::ChartThemeLight);

         // Create chart view
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(491, 231);

         // Create pixmap from chart view
         QPixmap* chartPixmap = new QPixmap(chartView->grab());
         return chartPixmap;
     }
}



//************************historique****************************
void client::on_pushButton_10_clicked()
{


   /// Récupérer le modèle de la requête
    QSqlQueryModel* model = afficherC();
    ui->tableView->resizeColumnsToContents();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Créer un objet QFile pour enregistrer le fichier texte
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier texte"), "", tr("Fichiers texte (*.txt)"));
    QFile file(fileName);

    // Vérifier si le fichier a été correctement ouvert
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Créer un objet QTextStream pour écrire dans le fichier
        QTextStream out(&file);
        out << "\n                                                                                                                                                                           Historique des clients          \n";
       out << "                                                                                                                                                                      Smart Charging Station \n\n\n";
        // Récupérer les noms de colonnes du modèle
        QStringList headers;
        for(int col=0; col<model->columnCount(); col++) {
            if (col == 0) {
                headers << "Id_c       ";
            } else if (col == 1) {
                headers << "    Cin         ";
            } else if (col == 2) {
                headers << "        Nom           ";
            }
            else if (col == 3) {
                            headers << "    Prenom     ";
                        } else if (col == 4) {
                            headers << "       Sexe    ";
                        }
            else if (col == 5) {
                            headers << " Nbr_Rech ";
                        } else if (col == 6) {
                            headers << "  Num_tel  ";
                        }
            else if (col == 7) {
                            headers << "      Email           ";
                        } else if (col == 8) {
                            headers << "          Consmmation    ";


                        } else if (col == 9) {
                            headers << " Date de naissance";
                        }
            else if (col == 10) {
                            headers << "   Id_E         ";
                        }

        }

        // Écrire les noms de colonnes dans le fichier texte

        out << headers.join("\t      ") << "\n";

        // Parcourir chaque ligne et colonne du modèle et écrire les données dans le fichier texte
        for(int row=0; row<model->rowCount(); row++) {
            for(int col=0; col<model->columnCount(); col++) {
                QModelIndex index = model->index(row, col);
                QString data = model->data(index).toString();
                if(col == 10) { // Vérifier si la colonne est la colonne ID_E
                            data = "130"; // Insérer la valeur 130
                        }
        out << data << "       ""             ";
            }
            out << "\n\n\n";
        }
        out << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
               out << "______________________________________________________________________ Historique de 2023 \"Smart Charging Station\" __________________________________________________________";

        // Fermer le fichier
        file.close();

        // Afficher un message de confirmation
        QMessageBox::information(this, "Fichier enregistré", "Le fichier texte a été enregistré avec succès !");
    }
    else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier texte !");
    }
    QSqlTableModel* model1 = afficherC();
     ui->tableView->setModel(model1);
        ui->tableView->resizeColumnsToContents();
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
      //  ui->spinBox->setModel(comboBox_modif());

                QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                        if (chartPixmapPtr) {
                            ui->label_2->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                            delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap*/
                        }
                            showNotification();
                            ui->comboBox_id_st->setModel(comboBox_id_st());
                            ui->comboBox_id_c->setModel(comboBox_id_c());
                            ui->comboBox_client->setModel(comboBox_client());
                            ui->comboBox_supp->setModel(comboBox_id());
                            ui->comboBox_supp->setModel(comboBox_modif());

 }



/***********************pdf*************/

void client::generatePDF(QString data)
{

    // Récupérer le chemin du répertoire du bureau de l'utilisateur
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    // Concaténer le chemin du bureau avec le nom de fichier fourni
    QString fullPath = desktopPath + "/" + data;

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
    painter.drawPixmap(30,25,QPixmap(":/ICON/loo.png"));
    painter.drawPixmap(-200,-200,QPixmap(":/ICON/llll.png"));

    // Ajouter le titre
        QString title = "les Clients";
        QFont titleFont("Arial", 18, QFont::Bold);
        painter.setFont(titleFont);
        painter.drawText(370,100, title);
        QFont defaultFont;
        painter.setFont(defaultFont);
    // Récupérer les noms des colonnes
    QHeaderView *header = ui->tableView->horizontalHeader();
    QStringList headers;
    int x = 250;
    int y = 20;
    int w = 0;
    int z = 0;
    int a = 30;

    for(int i=0; i<header->count(); i++)
    {
        QString headerText = header->model()->headerData(i, Qt::Horizontal).toString();
        headers << headerText;
        painter.drawText(0+ a, x,headerText);
        a += 95;
    }

    // Afficher les noms de colonnes

    QModelIndex index;
    for(int row=0; row<ui->tableView->model()->rowCount(); row++)
    {
        y = 280; // incrémenter la position verticale pour afficher la prochaine ligne de données
        x = 30;
        w = y+z;//espace mabinethom
        for(int col=0; col<ui->tableView->model()->columnCount(); col++)
                {
                    index = ui->tableView->model()->index(row, col);
                    QString data = ui->tableView->model()->data(index).toString();
                    QRect cell(x, w, 90, 30); // set the width of the cell to 95 pixels
                    QTextOption option;
                    option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere); // enable text wrapping
                    painter.drawText(cell, data, option); // draw the text with options
                    x += 95;
                }
        z += 30;
    }
    painter.drawText(310,1350, "Toutes les données ont été générées par l'application Voltify.");
    // Fin du dessin
    painter.end();

    qDebug() << "Fichier PDF enregistré avec succès:" << fullPath;
    QMessageBox::information(this,tr("Voltify"),tr("Votre fichier pdf a ete généré"));
}


void client::on_pushButton_clicked()
{
    QString data = "clients.pdf";
    generatePDF(data);
}


void client::showNotification() {
    // Récupérer l'ID_C du client qui a dépassé le nombre de recharge autorisé
    QString ID_C = "";
    QSqlQuery query;
    query.prepare("SELECT ID_C FROM CLIENTS WHERE NBR_RECHARGE_C > 5");
    query.exec();

    if (query.next()) {
        ID_C = query.value(0).toString();
        // Afficher la notification dans la label
        QString notificationText = "<html><head/><body><p><span style='font-weight:bold; font-size:9pt; color:red;'>Nouvelle fidélité: </span><span style='font-size:9pt;'>Le client " + ID_C + " est un client fidèle.</span></p></body></html>";
        ui->textBrowser_3->setText(notificationText);
        if (player->state() == QMediaPlayer::StoppedState) {
              player->play();
          }
    } else {
        ui->textBrowser_3->clear();
        return; // Aucun client n'a dépassé le nombre de recharge autorisé
    }


}
/********************mailling*****************/

/*void client::sendMail()
{
   Smtp* smtp = new Smtp("applicationvoltifyy@gmail.com", "gtvcymonmuyzdkal", "smtp.gmail.com", 465);
   connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString))); // Uncomment this line

   smtp->sendMail("applicationvoltifyy@gmail.com", ui->lineEdit_Email->text(),"Bienvenu","Bienvenue !\nNous sommes ravis de vous accueillir dans notre entreprise.\nNous espérons que vous vous sentirez rapidement à l'aise et que vous vous épanouirez dans votre nouveau poste.\nNous sommes convaincus que vous apporterez une contribution précieuse à notre équipe, et nous sommes impatients de travailler avec vous.\nN'hésitez pas à nous contacter si vous avez des questions ou des préoccupations.\nBienvenue dans notre équipe !Cordialement\nVOLTIFY.");
  // QMessageBox::information(nullptr,QObject::tr("Mailing"),QObject::tr("Mail Sent\n" "Click Cancel to quit"),QMessageBox::Cancel);
}
void client::mailSent(QString status)
{
   qDebug() << "Status of email:" << status; // Add this line
   if(status == "Message sent")
       QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
*/

/******************Double clicked*************/
void client::on_tableView_doubleClicked(const QModelIndex &index)
{

    // Vérifier si l'utilisateur a cliqué sur la colonne "NOM_C"
    if (index.column() == 2) {
        // Récupérer le nom du client à partir de la cellule sélectionnée
        QString nomClient = index.data().toString();

        // Rechercher le client dans la base de données
        QSqlQuery query;
        query.prepare("SELECT * FROM CLIENTS WHERE NOM_C = :nomClient");
        query.bindValue(":nomClient", nomClient);
        if (query.exec() && query.first()) {
            // Créer une fenêtre pour afficher les propriétés du client
            QDialog *dialog = new QDialog(this);
            dialog->setWindowTitle(QString("Détails du client \"%1\"").arg(nomClient));
            QVBoxLayout *layout = new QVBoxLayout(dialog);

            // Ajouter les propriétés du client à la fenêtre
            QLabel *idLabel = new QLabel(QString("ID: %1").arg(query.value("ID_C").toString()));
            QLabel *cinLabel = new QLabel(QString("CIN: %1").arg(query.value("CIN_C").toString()));
            QLabel *nomLabel = new QLabel(QString("Nom: %1").arg(query.value("NOM_C").toString()));
            QLabel *prenomLabel = new QLabel(QString("Prénom: %1").arg(query.value("PRENOM_C").toString()));
            QLabel *sexeLabel = new QLabel(QString("Sexe: %1").arg(query.value("SEXE_C").toString()));
            QLabel *rechargeLabel = new QLabel(QString("Nombre de recharges: %1").arg(query.value("NBR_RECHARGE_C").toString()));
            QLabel *telLabel = new QLabel(QString("Numéro de téléphone: %1").arg(query.value("NUM_TEL_C").toString()));
            QLabel *emailLabel = new QLabel(QString("Adresse email: %1").arg(query.value("EMAIL_C").toString()));
            QLabel *datevisiteLabel = new QLabel(QString("Date de visite: %1").arg(query.value("DATE_VISITE_C").toString()));
            QLabel *conVisiteLabel = new QLabel(QString("consommation visite: %1").arg(query.value("CON_VISITE_C").toString()));
            QLabel *dateNaissanceLabel = new QLabel(QString("Date de naissance: %1").arg(query.value("DATE_NAISSANCE_C").toString()));
            QLabel *idELabel = new QLabel(QString("ID de l'employe: 12").arg(query.value("ID_E").toString()));

            layout->addWidget(idLabel);
            layout->addWidget(cinLabel);
            layout->addWidget(nomLabel);
            layout->addWidget(prenomLabel);
            layout->addWidget(sexeLabel);
            layout->addWidget(rechargeLabel);
            layout->addWidget(telLabel);
            layout->addWidget(emailLabel);
            layout->addWidget(datevisiteLabel);
            layout->addWidget(conVisiteLabel);
            layout->addWidget(dateNaissanceLabel);
            layout->addWidget(idELabel);

            dialog->exec();
        }
    }
}


/*************************************************arduino *******************/
/*void client::level()
{
    int value = 0;
    data = A.read_from_arduino();
    QSqlQuery query;
    query.prepare("SELECT CON_VISITE_C FROM CLIENTS WHERE ID_C=63");
    if (query.exec() && query.first()) {
        // Récupération de la valeur de la colonne CON_VISITE_C
        value = query.value(0).toInt();
         qDebug() << "Error executing query: " << value;
    } else {
        qDebug() << "Error executing query: " << query.lastError().text();
    }

    // Comparer la valeur récupérée de la base de données avec la valeur lue depuis l'Arduino
  if (data.toInt()== 1) {
        // Envoyer 1 à l'Arduino
        A.write_to_arduino("1");
    } else {
        // Envoyer 0 à l'Arduino
        A.write_to_arduino("0");
    }
}
*/

//*************code ghassen************************************
QSqlQueryModel* client::comboBox_id_st()
{
    QSqlQueryModel* model3=new QSqlQueryModel();
    QSqlQuery query3("SELECT ID_ST FROM STATIONS");
    model3->setQuery(query3);
    return model3;
}
QSqlQueryModel* client::comboBox_id_c()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_C FROM CLIENTS");
    model4->setQuery(query4);
    return model4;
}

client::client(int consj_st)
{
    this->CONSJ_ST=consj_st;
}



 bool client::Modifier(QString id, int consj_st)
{
    QSqlQuery query0;
    query0.prepare("SELECT * FROM stations WHERE ID_ST = :id");
    query0.bindValue(":id", id);
    if (!query0.exec()) {
        qDebug() << "Erreur lors de la sélection de la station : " << query0.lastError().text();
        return false;
    }
    if (query0.next()) {
        int aconsj = query0.value("CONSJ_ST").toInt();
        int consc_st = query0.value("CONSC_ST").toInt();
        float profit = query0.value("PROFIT_ST").toFloat();
        float prix = query0.value("PRIX_KW_ST").toFloat();
        int consm_st = query0.value("CONSM_ST").toInt();
        QString etat = query0.value("ETAT_ST").toString();
        QString eco = query0.value("MODE_ST").toString();
        int NBR = query0.value("NBR_CHARGE_ST").toInt();
        qDebug() << "CONSJ_ST avant modification :" << aconsj;
        int total = aconsj + consj_st;
        int total2 = consc_st + consj_st;
        float pro = total * prix;
        int pro2 = pro + profit;
        int consm = consm_st + consj_st;
        NBR = NBR + 1;
        if (eco == "Economique")
        {
        if (total >= 300)
        {
            etat = "En repos";
        }
        }
        QSqlQuery query;
        query.prepare("UPDATE STATIONS SET PROFIT_ST = :pro2, NBR_CHARGE_ST = :NBR ,CONSJ_ST = :total, ETAT_ST = :etat, CONSC_ST= :total2, CONSM_ST= :consm WHERE ID_ST = '"+id+"'");
        query.bindValue(":pro2",pro2);
        query.bindValue(":total",total);
        query.bindValue(":etat",etat);
        query.bindValue(":total2",total2);
        query.bindValue(":NBR",NBR);
        query.bindValue(":consm",consm);
        if (query.exec()) {
            qDebug() << "Modification effectuée avec succès.";
            return true;
        } else {
            qDebug() << "Erreur lors de la modification : " << query.lastError().text();
            return false;
        }
    } else {
        qDebug() << "La station avec l'ID " << id << " n'existe pas.";
        return false;
    }
}

bool client::Verif(QString id, int CONSJ, int& reste, QString& eco)
{
    // Vérifier si la station est en mode économique
    QSqlQuery query;
    query.prepare("SELECT * FROM stations WHERE ID_ST = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la sélection de la station : " << query.lastError().text();
        return false;
    }
    if (query.next()) {
         eco = query.value("MODE_ST").toString();
        reste = 0;
        if (eco == "Economique") {
            // Vérifier si la consommation après modification ne dépasse pas 300
            int aconsj = query.value("CONSJ_ST").toInt();
            int total = aconsj + CONSJ;
            reste = 300 - total;
            if (total > 300) {
                int reste1 = 300 - aconsj;
                QMessageBox::warning(nullptr, QObject::tr("Attention"),
                QObject::tr("Impossible d'ajouter la consommation, la station est en mode économique et la consommation journalière totale dépasse 300 kWh.\nIl vous reste que %1 kWh pour aujourd'hui.").arg(reste1), QMessageBox::Ok);
                return false;
            }
        }
    }
    return true;
}

void client::on_ajoutConsommation_clicked()
{
    // Récupérer les données du formulaire
    station S;
    int reste;
    QString eco;
    QString ID_ST = ui->comboBox_id_st->currentText();
    QString ID_C = ui->comboBox_id_c->currentText();
     int CON_VISITE_C = ui->spinBox_2->value();

 QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE ID_C=:ID_C");
    query.bindValue(":ID_C", ID_C);
    query.exec();

    if (!query.next()) {
        QMessageBox::warning(this, "Erreur", "ID_C n'existe pas !");
        return;
    }

    // Ajouter une nouvelle consommation pour le client
    query.prepare("UPDATE CLIENTS SET CON_VISITE_C=CON_VISITE_C+:CON_VISITE_C, NBR_RECHARGE_C = CASE WHEN NBR_RECHARGE_C > 5 THEN 1 ELSE NBR_RECHARGE_C+1 END WHERE ID_C=:ID_C");
    query.bindValue(":ID_C", ID_C);
    query.bindValue(":CON_VISITE_C", CON_VISITE_C);


    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'ajout de la consommation !");
        return;
    }
        query.prepare("SELECT COUNT(*) FROM CLIENTS WHERE NBR_RECHARGE_C > 5");
        query.exec();

        if (query.next()) {
            int count = query.value(0).toInt();
            if (count > 0) {
                showNotification();
            }
        }
        qDebug() << "reste:" << ID_C;
        qDebug() << "reste:" << CON_VISITE_C;
        //***************************code_station**************************************************
            bool test2 = Verif(ID_ST,CON_VISITE_C,reste,eco);
            if (test2) {
                client C(CON_VISITE_C);
                bool test=C.Modifier(ID_ST,CON_VISITE_C);
                if(test)
               {
                     if (eco == "Economique"){
                   QMessageBox::information(nullptr,QObject::tr("Base de données"),
                   QObject::tr("Modification effectuée.\nIl vous reste que %1 kWh pour aujourd'hui.").arg(reste),QMessageBox::Yes);
                     }else {
                     QMessageBox::information(nullptr,QObject::tr("Base de données"),
                     QObject::tr("Modification effectuée."),QMessageBox::Yes);}
               }
                else
                   QMessageBox::critical(nullptr,QObject::tr("Base de données"),
                   QObject::tr("Modification non effectuée\n"),QMessageBox::Yes);
                    }
        //******************************************************************************************
        // Actualiser le modèle de table
                          S.appelfonc();
        QSqlTableModel *model = new QSqlTableModel(this);
        model->setTable("CLIENTS");
        model->select();
      QSqlTableModel* model1 = afficherC();
        ui->tableView->setModel(model1);
          ui->tableView->resizeColumnsToContents();
              ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void client::aff_debut()
{
    QSqlQuery query;
            query.prepare("SELECT COUNT(*) FROM CLIENTS WHERE NBR_RECHARGE_C > 5");
            query.exec();

            if (query.next()) {
                int count = query.value(0).toInt();
                if (count > 0) {
                    showNotification();
                }
            }
}
/**********************email****************/

void client::sendMail()
{
    QSqlQuery query;
    QString mail=ui->lineEdit_Email->text();
    query =give(mail);
    if(query.exec())
        {

           if(query.next())
            {
    QString userid = query.value(0).toString();
    Smtp* smtp = new Smtp("applicationvoltifyy@gmail.com", "gtvcymonmuyzdkal", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString))); // Uncomment this line

    smtp->sendMail("applicationvoltifyy@gmail.com", ui->lineEdit_Email->text(),"Bienvenu","Bienvenue !\nNous sommes ravis de vous accueillir dans notre entreprise.\nNous sommes impatients de travailler avec vous.\nN'hésitez pas à nous contacter si vous avez des questions ou des préoccupations.\n Votre IDENTIFIANT EST :"+userid+" !Cordialement\nVOLTIFY.");
   // QMessageBox::information(nullptr,QObject::tr("Mailing"),QObject::tr("Mail Sent\n" "Click Cancel to quit"),QMessageBox::Cancel);

           }
    }


}
void client::mailSent(QString status)
{
   qDebug() << "Status of email:" << status; // Add this line
   if(status == "Message sent")
       QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}



QSqlQuery client::give(QString mail)
{

    QSqlQuery query;

    query.prepare("select * from CLIENTS where EMAIL_C= '"+mail+"' ");
    query.exec();
    return query;
}

QSqlQueryModel* client::comboBox_client()
{
    QSqlQueryModel* model3=new QSqlQueryModel();
    QSqlQuery query3("SELECT ID_C FROM CLIENTS");
    model3->setQuery(query3);
    return model3;
}

void client::on_comboBox_client_currentIndexChanged()
{
    QString ID_C=ui->comboBox_client->currentText();
    QSqlQuery qry;
    qry.prepare("select * from CLIENTS WHERE ID_C='"+ID_C+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_Cin_3->setText(qry.value(1).toString());
            ui->lineEdit_Nom_3->setText(qry.value(2).toString());
             ui->lineEdit_Prenom_3->setText(qry.value(3).toString());
           ui->comboBox_4->setCurrentText(qry.value(4).toString());
        ui->lineEdit_NbrR_3->setText(qry.value(5).toString());
           ui->lineEdit_NumTel_3->setText(qry.value(6).toString());
             ui->lineEdit_Email_3->setText(qry.value(7).toString());
             ui->lineEdit_Cons_3->setText(qry.value(9).toString());
        ui->dateEdit_2->setDate(qry.value(10).toDate());

        }
    }
}
