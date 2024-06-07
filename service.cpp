#include "service.h"
#include "reglage.h"
#include "ui_service.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QDate>
#include <QFloat16>
#include <QSqlTableModel>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QStandardPaths>
#include <QtCharts/QBarSet>
#include <QtCharts>
#include <QChartView>
#include <QSqlRecord>

service::service(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::service)
{
    ui->setupUi(this);


      /* int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
//        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(RFID())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données). */


         //RFID();

        // QTimer* timer = new QTimer(this);
             //    connect(timer, &QTimer::timeout, this, &service::RFID);
              //   timer->start(2000); // Appeler toutes les secondes (3000 ms)

//***********affichage tab_recent_sr*****************
       // Appel de la fonction dans votre code
       QSqlTableModel* model1 = tab_recent_sr();
       ui->tab_recent_sr->setModel(model1);
       ui->tab_recent_sr->resizeColumnsToContents();
       ui->tab_recent_sr->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_sr->setColumnHidden(1, true);
       ui->tab_recent_sr->setColumnHidden(2, true);
       ui->tab_recent_sr->setColumnHidden(3, true);
       ui->tab_recent_sr->setColumnHidden(5, true);
       ui->tab_recent_sr->setColumnHidden(6, true);
       ui->tab_recent_sr->setColumnHidden(7, true);
       ui->tab_recent_sr->setColumnHidden(9, true);
       ui->tab_recent_sr->setColumnHidden(10, true);
       ui->tab_recent_sr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//************affichage tab_recent_cafe****************
       QSqlTableModel* model2 = tab_recent_cafe();
       ui->tab_recent_cafe->setModel(model2);
       ui->tab_recent_cafe->resizeColumnsToContents();
       ui->tab_recent_cafe->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_cafe->setColumnHidden(1, true);
       ui->tab_recent_cafe->setColumnHidden(2, true);
       ui->tab_recent_cafe->setColumnHidden(3, true);
       ui->tab_recent_cafe->setColumnHidden(5, true);
       ui->tab_recent_cafe->setColumnHidden(6, true);
       ui->tab_recent_cafe->setColumnHidden(7, true);
       ui->tab_recent_cafe->setColumnHidden(9, true);
       ui->tab_recent_cafe->setColumnHidden(10, true);
       ui->tab_recent_cafe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//************affichage tab_recent_lavage*************
       QSqlTableModel* model3 = tab_recent_lavage();
       ui->tab_recent_lavage->setModel(model3);
       ui->tab_recent_lavage->resizeColumnsToContents();
       ui->tab_recent_lavage->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_lavage->setColumnHidden(1, true);
       ui->tab_recent_lavage->setColumnHidden(2, true);
       ui->tab_recent_lavage->setColumnHidden(3, true);
       ui->tab_recent_lavage->setColumnHidden(5, true);
       ui->tab_recent_lavage->setColumnHidden(6, true);
       ui->tab_recent_lavage->setColumnHidden(7, true);
       ui->tab_recent_lavage->setColumnHidden(9, true);
       ui->tab_recent_lavage->setColumnHidden(10, true);
       ui->tab_recent_lavage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//************affichage tab_recent_entretien***********
       QSqlTableModel* model4 = tab_recent_entretien();
       ui->tab_recent_entretien->setModel(model4);
       ui->tab_recent_entretien->resizeColumnsToContents();
       ui->tab_recent_entretien->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_entretien->setColumnHidden(1, true);
       ui->tab_recent_entretien->setColumnHidden(2, true);
       ui->tab_recent_entretien->setColumnHidden(3, true);
       ui->tab_recent_entretien->setColumnHidden(5, true);
       ui->tab_recent_entretien->setColumnHidden(6, true);
       ui->tab_recent_entretien->setColumnHidden(7, true);
       ui->tab_recent_entretien->setColumnHidden(9, true);
       ui->tab_recent_entretien->setColumnHidden(10, true);
       ui->tab_recent_entretien->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->ComboBox_id_cafe->setModel(ComboBox_id_cafe());
    ui->ComboBox_id_lavage->setModel(ComboBox_id_lavage());
    ui->ComboBox_id_entretien->setModel(ComboBox_id_entretien());
    ui->comboBox_id_modif->setModel(comboBox_id_modif());
    QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
        if (chartPixmapPtr) {
            ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
            delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
        }


        // call the changeDesign() function here
           changeDesign();

        // etat service

           afficherImageModeCafe();
           afficherImageModeLavage();
           afficherImageModeEntretien();
           displayEtatCafe();
           displayEtatLavage();
           displayEtatEntretien();

           setComboBoxValueFromDatabase_cafe();
           setComboBoxValueFromDatabase_lavage();
           setComboBoxValueFromDatabase_entretien();



/***********************************  controle de saisie  ***************************************************************/
        ui->le_quantite_sr->setValidator(new QIntValidator(0,99,this));

/***********************************  controle de saisie  ***************************************************************/
        ui->tab_recent_sr->setObjectName("tableauser1");
        ui->tab_recent_cafe->setObjectName("tableauser2");
        ui->tab_recent_lavage->setObjectName("tableauser3");
        ui->tab_recent_entretien->setObjectName("tableauser4");

}


service::~service()
{
    delete ui;

}

/*************************************************************    AFFICHAGE     **************************************************************************************/
QSqlTableModel * service::tab_recent_sr()
{
    QSqlTableModel* model1 = new QSqlTableModel(this);
        model1->setTable("SERVICES");
        model1->setEditStrategy(QSqlTableModel::OnFieldChange);

       // Spécifier les colonnes à afficher et leurs noms d'en-tête
        model1->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model1->setHeaderData(4, Qt::Horizontal, tr("TYPE"));
        model1->setHeaderData(8, Qt::Horizontal, tr("PRIX"));
        model1->setHeaderData(11, Qt::Horizontal, tr("QUANTITE"));


        // Activer le tri par défaut sur la colonne ID_SR
        model1->setSort(0, Qt::AscendingOrder);

        // Sélectionner les données de la table
        model1->select();

        // Activer le tri sur le TableView
        ui->tab_recent_sr->setSortingEnabled(true);

        return model1;

}


QSqlTableModel * service::tab_recent_cafe()
{
    QSqlTableModel* model1 = new QSqlTableModel(this);
        model1->setTable("SERVICES");
        model1->setEditStrategy(QSqlTableModel::OnFieldChange);

       // Spécifier les colonnes à afficher et leurs noms d'en-tête
        model1->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model1->setHeaderData(4, Qt::Horizontal, tr("TYPE"));
        model1->setHeaderData(8, Qt::Horizontal, tr("PRIX"));
        model1->setHeaderData(11, Qt::Horizontal, tr("QUANTITE"));

        // Sélectionner seulement les lignes où le TYPE_SR est "Cafe"
            model1->setFilter("TYPE_SR = 'Cafe'");

        // Activer le tri par défaut sur la colonne ID_SR
        model1->setSort(0, Qt::AscendingOrder);

        // Sélectionner les données de la table
        model1->select();

        // Activer le tri sur le TableView
        ui->tab_recent_cafe->setSortingEnabled(true);

        return model1;

}


QSqlTableModel * service::tab_recent_lavage()
{
    QSqlTableModel* model1 = new QSqlTableModel(this);
        model1->setTable("SERVICES");
        model1->setEditStrategy(QSqlTableModel::OnFieldChange);

       // Spécifier les colonnes à afficher et leurs noms d'en-tête
        model1->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model1->setHeaderData(4, Qt::Horizontal, tr("TYPE"));
        model1->setHeaderData(8, Qt::Horizontal, tr("PRIX"));
        model1->setHeaderData(11, Qt::Horizontal, tr("QUANTITE"));

        // Sélectionner seulement les lignes où le TYPE_SR est "Lavage"
            model1->setFilter("TYPE_SR = 'Lavage'");

        // Activer le tri par défaut sur la colonne ID_SR
        model1->setSort(0, Qt::AscendingOrder);

        // Sélectionner les données de la table
        model1->select();

        // Activer le tri sur le TableView
        ui->tab_recent_lavage->setSortingEnabled(true);

        return model1;

}


QSqlTableModel * service::tab_recent_entretien()
{
    QSqlTableModel* model1 = new QSqlTableModel(this);
        model1->setTable("SERVICES");
        model1->setEditStrategy(QSqlTableModel::OnFieldChange);

       // Spécifier les colonnes à afficher et leurs noms d'en-tête
        model1->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model1->setHeaderData(4, Qt::Horizontal, tr("TYPE"));
        model1->setHeaderData(8, Qt::Horizontal, tr("PRIX"));
        model1->setHeaderData(11, Qt::Horizontal, tr("QUANTITE"));

        // Sélectionner seulement les lignes où le TYPE_SR est "Entretien"
            model1->setFilter("TYPE_SR = 'Entretien'");
        // Activer le tri par défaut sur la colonne ID_SR
        model1->setSort(0, Qt::AscendingOrder);

        // Sélectionner les données de la table
        model1->select();

        // Activer le tri sur le TableView
        ui->tab_recent_entretien->setSortingEnabled(true);

        return model1;

}

QSqlQueryModel* service::comboBox_id_modif()
{
    QSqlQueryModel* model3=new QSqlQueryModel();
      QSqlQuery query3("SELECT ID_SR FROM SERVICES");
      model3->setQuery(query3);
      return model3;
}

void service::on_tab_recent_sr_activated(const QModelIndex &index)
{
    QString val=ui->tab_recent_sr->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from SERVICES where ID_SR='"+val+"'");
        if(query.exec())
        {
            while(query.next())
            {
                ui->comboBox_id_modif->setCurrentText(query.value(0).toString());
                ui->ComboBox_type_sr_modif->setCurrentText(query.value(4).toString());
                ui->le_quantite_sr_modif->setText(query.value(11).toString());
                QString str = query.value(8).toString();
                double prix = str.toDouble();
                ui->db_prix_sr_modif->setValue(prix);
                ui->tabWidget->setCurrentIndex(5);
            }
        }
        else {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
}

void service::on_tab_recent_lavage_activated(const QModelIndex &index)
{
    QString val=ui->tab_recent_lavage->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from SERVICES where ID_SR='"+val+"'");
        if(query.exec())
        {
            while(query.next())
            {
                ui->comboBox_id_modif->setCurrentText(query.value(0).toString());
                ui->ComboBox_type_sr_modif->setCurrentText(query.value(4).toString());
                ui->le_quantite_sr_modif->setText(query.value(11).toString());
                QString str = query.value(8).toString();
                double prix = str.toDouble();
                ui->db_prix_sr_modif->setValue(prix);
                ui->tabWidget->setCurrentIndex(5);
            }
        }
        else {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
}

void service::on_tab_recent_entretien_activated(const QModelIndex &index)
{
    QString val=ui->tab_recent_entretien->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from SERVICES where ID_SR='"+val+"'");
        if(query.exec())
        {
            while(query.next())
            {
                ui->comboBox_id_modif->setCurrentText(query.value(0).toString());
                ui->ComboBox_type_sr_modif->setCurrentText(query.value(4).toString());
                ui->le_quantite_sr_modif->setText(query.value(11).toString());
                QString str = query.value(8).toString();
                double prix = str.toDouble();
                ui->db_prix_sr_modif->setValue(prix);
                ui->tabWidget->setCurrentIndex(5);
            }
        }
        else {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
}


/********************************************************************  end of affichage   ********************************************************************************************/




service::service(int ID_SR,int PROFIT_SR,
                 int NBR_CAFE,int NBR_LAVAGE,int NBR_ENTRETIEN,
                 float PRIX,int PRIX_LAVAGE,int PRIX_ENTRETIEN,
                 int QUANTITE_SR,
                 QString ETAT_SR,QString IMAGE_SR,QString TYPE_SR)
{
    this->ID_SR=ID_SR; this->PROFIT_SR=PROFIT_SR;
    this->NBR_CAFE=NBR_CAFE; this->NBR_LAVAGE=NBR_LAVAGE; this->NBR_ENTRETIEN=NBR_ENTRETIEN;
    this->PRIX=PRIX; this->PRIX_LAVAGE=PRIX_LAVAGE; this->PRIX_ENTRETIEN=PRIX_ENTRETIEN;
    this->QUANTITE_SR=QUANTITE_SR;
    this->ETAT_SR=ETAT_SR; this->IMAGE_SR=IMAGE_SR; this->TYPE_SR=TYPE_SR;
}
/*
int Services::getID_SR(){return ID_SR;}
int Services::getPROFIT_SR(){return PROFIT_SR;}
int Services::getNBR_CAFE(){return NBR_CAFE;}
int Services::getNBR_LAVAGE(){return NBR_LAVAGE;}
int Services::getNBR_ENTRETIEN(){return NBR_ENTRETIEN;}
int Services::getPRIX_CAFE(){return PRIX_CAFE;}
int Services::getPRIX_LAVAGE(){return PRIX_LAVAGE;}
int Services::getPRIX_ENTRETIEN(){return PRIX_ENTRETIEN;}
int Services::getQUANTITE_SR(){return QUANTITE_SR;}
QString Services::getETAT_SR(){return ETAT_SR;}
QString Services::getIMAGE_SR(){return IMAGE_SR;}
QString Services::getTYPE_SR(){return TYPE_SR;}
void Services::setID_SR(int ID_SR){this->ID_SR=ID_SR;}
void Services::setPROFIT_SR(int PROFIT_SR){this->PROFIT_SR=PROFIT_SR;}
void Services::setNBR_CAFE(int NBR_CAFE){this->NBR_CAFE=NBR_CAFE;}
void Services::setNBR_LAVAGE(int NBR_LAVAGE){this->NBR_LAVAGE=NBR_LAVAGE;}
void Services::setNBR_ENTRETIEN(int NBR_ENTRETIEN){this->NBR_ENTRETIEN=NBR_ENTRETIEN;}
void Services::setPRIX_CAFE(int PRIX_CAFE){this->PRIX_CAFE=PRIX_CAFE;}
void Services::setPRIX_LAVAGE(int PRIX_LAVAGE){this->PRIX_LAVAGE=PRIX_LAVAGE;}
void Services::setPRIX_ENTRETIEN(int PRIX_ENTRETIEN){this->PRIX_ENTRETIEN=PRIX_ENTRETIEN;}
void Services::setQUANTITE_SR(int QUANTITE_SR){this->QUANTITE_SR=QUANTITE_SR;}
void Services::setETAT_SR(QString ETAT_SR){this->ETAT_SR=ETAT_SR;}
void Services::setIMAGE_SR(QString IMAGE_SR){this->IMAGE_SR=IMAGE_SR;}
void Services::setTYPE_SR(QString TYPE_SR){this->TYPE_SR=TYPE_SR;} */


/********************************************************  AJOUTER  ********************************************************/
bool service::ajouterServices()
{

    QSqlQuery query;


          query.prepare("INSERT INTO SERVICES (TYPE_SR, QUANTITE_SR, PRIX) "
                        "VALUES (:TYPE_SR, :QUANTITE_SR, :PRIX)");
          query.bindValue(":TYPE_SR", TYPE_SR);
          query.bindValue(":QUANTITE_SR", QUANTITE_SR);
          query.bindValue(":PRIX", static_cast<double>(PRIX));

          return  query.exec();



}

void service::on_pb_ajouter_sr_clicked()
{
            QString TYPE_SR=ui->ComboBox_type_sr->currentText();
            int QUANTITE_SR=ui->le_quantite_sr->text().toInt();
            qfloat16 PRIX=ui->db_prix_sr->value();

            service SR( 0, 0, 0, 0, 0, PRIX,0, 0, QUANTITE_SR, "", "", TYPE_SR);


            QSqlQuery query;
            query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = :type");
            query.bindValue(":type", TYPE_SR);

            if (query.exec() && query.next()) {
                QString etatSR = query.value(0).toString(); // retrieve the value of ETAT_SR
                if(etatSR != "En service") {
                       // ETAT_SR is not En service, display message
                       QMessageBox::warning(this, "Hors service", "Selected service is not currently in service.");

            } else
                {
                    QString NOM_STK=ui->ComboBox_produit->currentText();
                    QSqlQuery query1;
                    query1.prepare("SELECT QUANTITE_STK FROM STOCKS WHERE NOM_STK = :nomproduit");
                    query1.bindValue(":nomproduit", NOM_STK);
                    qDebug() << "NOM_STK before: " << NOM_STK;
                    if (query1.exec() && query1.next()){
                        int QUANTITE_STK = query1.value(0).toInt();
                        qDebug() << "QUANTITE_STK before: " << QUANTITE_STK;

                        if (QUANTITE_STK >= QUANTITE_SR) {
                           int QUANTITE_STK1 = QUANTITE_STK;

                            QUANTITE_STK1 = (QUANTITE_STK1 - QUANTITE_SR);
                            qDebug() << "QUANTITE_STK After: " << QUANTITE_STK1;

                            QSqlQuery query2;

                            query2.prepare("UPDATE STOCKS SET QUANTITE_STK = :QUANTITE_STK1 WHERE NOM_STK = :nomproduit");
                            query2.bindValue(":QUANTITE_STK1", QUANTITE_STK1);
                            query2.bindValue(":nomproduit", NOM_STK);
                            qDebug() << "NOM_STK after: " << NOM_STK;
                           query2.exec();

                                bool test= SR.ajouterServices();
                                qDebug() << "Ajouter: " << test;


                                if (test)
                                    {
                                    QMessageBox::information(nullptr,QObject::tr("Base de données"),
                                           QObject::tr("Ajout effectuée\n"),QMessageBox::Yes);
                                    QSqlTableModel* model1 = tab_recent_sr();
                                    ui->tab_recent_sr->setModel(model1);
                                    ui->tab_recent_sr->resizeColumnsToContents();
                                    ui->tab_recent_sr->setEditTriggers(QAbstractItemView::NoEditTriggers);
                                    ui->tab_recent_sr->setColumnHidden(1, true);
                                    ui->tab_recent_sr->setColumnHidden(2, true);
                                    ui->tab_recent_sr->setColumnHidden(3, true);
                                    ui->tab_recent_sr->setColumnHidden(5, true);
                                    ui->tab_recent_sr->setColumnHidden(6, true);
                                    ui->tab_recent_sr->setColumnHidden(7, true);
                                    ui->tab_recent_sr->setColumnHidden(9, true);
                                    ui->tab_recent_sr->setColumnHidden(10, true);
                                    ui->tab_recent_sr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                                    QSqlTableModel* model2 = tab_recent_cafe();
                                    ui->tab_recent_cafe->setModel(model2);
                                    ui->tab_recent_cafe->resizeColumnsToContents();
                                    ui->tab_recent_cafe->setEditTriggers(QAbstractItemView::NoEditTriggers);
                                    ui->tab_recent_cafe->setColumnHidden(1, true);
                                    ui->tab_recent_cafe->setColumnHidden(2, true);
                                    ui->tab_recent_cafe->setColumnHidden(3, true);
                                    ui->tab_recent_cafe->setColumnHidden(5, true);
                                    ui->tab_recent_cafe->setColumnHidden(6, true);
                                    ui->tab_recent_cafe->setColumnHidden(7, true);
                                    ui->tab_recent_cafe->setColumnHidden(9, true);
                                    ui->tab_recent_cafe->setColumnHidden(10, true);
                                    ui->tab_recent_cafe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                                    QSqlTableModel* model3 = tab_recent_lavage();
                                    ui->tab_recent_lavage->setModel(model3);
                                    ui->tab_recent_lavage->resizeColumnsToContents();
                                    ui->tab_recent_lavage->setEditTriggers(QAbstractItemView::NoEditTriggers);
                                    ui->tab_recent_lavage->setColumnHidden(1, true);
                                    ui->tab_recent_lavage->setColumnHidden(2, true);
                                    ui->tab_recent_lavage->setColumnHidden(3, true);
                                    ui->tab_recent_lavage->setColumnHidden(5, true);
                                    ui->tab_recent_lavage->setColumnHidden(6, true);
                                    ui->tab_recent_lavage->setColumnHidden(7, true);
                                    ui->tab_recent_lavage->setColumnHidden(9, true);
                                    ui->tab_recent_lavage->setColumnHidden(10, true);
                                    ui->tab_recent_lavage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                                    QSqlTableModel* model4 = tab_recent_entretien();
                                    ui->tab_recent_entretien->setModel(model4);
                                    ui->tab_recent_entretien->resizeColumnsToContents();
                                    ui->tab_recent_entretien->setEditTriggers(QAbstractItemView::NoEditTriggers);
                                    ui->tab_recent_entretien->setColumnHidden(1, true);
                                    ui->tab_recent_entretien->setColumnHidden(2, true);
                                    ui->tab_recent_entretien->setColumnHidden(3, true);
                                    ui->tab_recent_entretien->setColumnHidden(5, true);
                                    ui->tab_recent_entretien->setColumnHidden(6, true);
                                    ui->tab_recent_entretien->setColumnHidden(7, true);
                                    ui->tab_recent_entretien->setColumnHidden(9, true);
                                    ui->tab_recent_entretien->setColumnHidden(10, true);
                                    ui->tab_recent_entretien->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                                 ui->ComboBox_id_cafe->setModel(ComboBox_id_cafe());
                                 ui->ComboBox_id_lavage->setModel(ComboBox_id_lavage());
                                 ui->ComboBox_id_entretien->setModel(ComboBox_id_entretien());
                                 QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                                     if (chartPixmapPtr) {
                                         ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                                         delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                                     }


                            }else
                                {
                                QMessageBox::critical(nullptr,QObject::tr("Base de données"),
                                       QObject::tr("Ajout non effectuée\n"),QMessageBox::Yes);
                            }



                    }    else {

                            QMessageBox::critical(nullptr,QObject::tr("Base de données"),
                                   QObject::tr("Produit hors stock \n"),QMessageBox::Yes);

                        }




                        }


                    // call the changeDesign() function here
                       changeDesign();



                }
            }


}

/************************************************************* end of ajouter  *****************************************************/




/*************************************************************  SUPPRIMER     ************************************************/
//CAFE
QSqlQueryModel* service::ComboBox_id_cafe()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_SR FROM SERVICES WHERE TYPE_SR = 'Cafe'");
    model4->setQuery(query4);
    return model4;
}

void service::on_pushButton_supp_cafe_clicked()
{
    QString id;
    id=ui->ComboBox_id_cafe->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICES WHERE ID_SR='"+id+"'");

    QMessageBox::StandardButton reply = QMessageBox::warning(this,"Base de données", "Etes vous sur de le supprimer?", QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes)
           {
               if(query.exec()){
                   QMessageBox::critical(this,tr("Base de données"),tr("Suppression effectuée"));
                   QSqlTableModel* model1 = tab_recent_sr();
                   ui->tab_recent_sr->setModel(model1);
                   ui->tab_recent_sr->resizeColumnsToContents();
                   ui->tab_recent_sr->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_sr->setColumnHidden(1, true);
                   ui->tab_recent_sr->setColumnHidden(2, true);
                   ui->tab_recent_sr->setColumnHidden(3, true);
                   ui->tab_recent_sr->setColumnHidden(5, true);
                   ui->tab_recent_sr->setColumnHidden(6, true);
                   ui->tab_recent_sr->setColumnHidden(7, true);
                   ui->tab_recent_sr->setColumnHidden(9, true);
                   ui->tab_recent_sr->setColumnHidden(10, true);
                   ui->tab_recent_sr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model2 = tab_recent_cafe();
                   ui->tab_recent_cafe->setModel(model2);
                   ui->tab_recent_cafe->resizeColumnsToContents();
                   ui->tab_recent_cafe->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_cafe->setColumnHidden(1, true);
                   ui->tab_recent_cafe->setColumnHidden(2, true);
                   ui->tab_recent_cafe->setColumnHidden(3, true);
                   ui->tab_recent_cafe->setColumnHidden(5, true);
                   ui->tab_recent_cafe->setColumnHidden(6, true);
                   ui->tab_recent_cafe->setColumnHidden(7, true);
                   ui->tab_recent_cafe->setColumnHidden(9, true);
                   ui->tab_recent_cafe->setColumnHidden(10, true);
                   ui->tab_recent_cafe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model3 = tab_recent_lavage();
                   ui->tab_recent_lavage->setModel(model3);
                   ui->tab_recent_lavage->resizeColumnsToContents();
                   ui->tab_recent_lavage->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_lavage->setColumnHidden(1, true);
                   ui->tab_recent_lavage->setColumnHidden(2, true);
                   ui->tab_recent_lavage->setColumnHidden(3, true);
                   ui->tab_recent_lavage->setColumnHidden(5, true);
                   ui->tab_recent_lavage->setColumnHidden(6, true);
                   ui->tab_recent_lavage->setColumnHidden(7, true);
                   ui->tab_recent_lavage->setColumnHidden(9, true);
                   ui->tab_recent_lavage->setColumnHidden(10, true);
                   ui->tab_recent_lavage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model4 = tab_recent_entretien();
                   ui->tab_recent_entretien->setModel(model4);
                   ui->tab_recent_entretien->resizeColumnsToContents();
                   ui->tab_recent_entretien->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_entretien->setColumnHidden(1, true);
                   ui->tab_recent_entretien->setColumnHidden(2, true);
                   ui->tab_recent_entretien->setColumnHidden(3, true);
                   ui->tab_recent_entretien->setColumnHidden(5, true);
                   ui->tab_recent_entretien->setColumnHidden(6, true);
                   ui->tab_recent_entretien->setColumnHidden(7, true);
                   ui->tab_recent_entretien->setColumnHidden(9, true);
                   ui->tab_recent_entretien->setColumnHidden(10, true);
                   ui->tab_recent_entretien->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                ui->ComboBox_id_cafe->setModel(ComboBox_id_cafe());
                ui->ComboBox_id_lavage->setModel(ComboBox_id_lavage());
                ui->ComboBox_id_entretien->setModel(ComboBox_id_entretien());
                QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                    if (chartPixmapPtr) {
                        ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                        delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                    }


                    // call the changeDesign() function here
                       changeDesign();
           }
               else {QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
          }
}
           else
               QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
}

//lavage
QSqlQueryModel* service::ComboBox_id_lavage()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_SR FROM SERVICES WHERE TYPE_SR = 'Lavage'");
    model4->setQuery(query4);
    return model4;
}

void service::on_pushButton_supp_lavage_clicked()
{
    QString id;
    id=ui->ComboBox_id_lavage->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICES WHERE ID_SR='"+id+"'");

    QMessageBox::StandardButton reply = QMessageBox::warning(this,"Base de données", "Etes vous sur de le supprimer?", QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes) {
               if(query.exec()){
                   QMessageBox::critical(this,tr("Base de données"),tr("Suppression effectuée"));
                   QSqlTableModel* model1 = tab_recent_sr();
                   ui->tab_recent_sr->setModel(model1);
                   ui->tab_recent_sr->resizeColumnsToContents();
                   ui->tab_recent_sr->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_sr->setColumnHidden(1, true);
                   ui->tab_recent_sr->setColumnHidden(2, true);
                   ui->tab_recent_sr->setColumnHidden(3, true);
                   ui->tab_recent_sr->setColumnHidden(5, true);
                   ui->tab_recent_sr->setColumnHidden(6, true);
                   ui->tab_recent_sr->setColumnHidden(7, true);
                   ui->tab_recent_sr->setColumnHidden(9, true);
                   ui->tab_recent_sr->setColumnHidden(10, true);
                   ui->tab_recent_sr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model2 = tab_recent_cafe();
                   ui->tab_recent_cafe->setModel(model2);
                   ui->tab_recent_cafe->resizeColumnsToContents();
                   ui->tab_recent_cafe->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_cafe->setColumnHidden(1, true);
                   ui->tab_recent_cafe->setColumnHidden(2, true);
                   ui->tab_recent_cafe->setColumnHidden(3, true);
                   ui->tab_recent_cafe->setColumnHidden(5, true);
                   ui->tab_recent_cafe->setColumnHidden(6, true);
                   ui->tab_recent_cafe->setColumnHidden(7, true);
                   ui->tab_recent_cafe->setColumnHidden(9, true);
                   ui->tab_recent_cafe->setColumnHidden(10, true);
                   ui->tab_recent_cafe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model3 = tab_recent_lavage();
                   ui->tab_recent_lavage->setModel(model3);
                   ui->tab_recent_lavage->resizeColumnsToContents();
                   ui->tab_recent_lavage->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_lavage->setColumnHidden(1, true);
                   ui->tab_recent_lavage->setColumnHidden(2, true);
                   ui->tab_recent_lavage->setColumnHidden(3, true);
                   ui->tab_recent_lavage->setColumnHidden(5, true);
                   ui->tab_recent_lavage->setColumnHidden(6, true);
                   ui->tab_recent_lavage->setColumnHidden(7, true);
                   ui->tab_recent_lavage->setColumnHidden(9, true);
                   ui->tab_recent_lavage->setColumnHidden(10, true);
                   ui->tab_recent_lavage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model4 = tab_recent_entretien();
                   ui->tab_recent_entretien->setModel(model4);
                   ui->tab_recent_entretien->resizeColumnsToContents();
                   ui->tab_recent_entretien->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_entretien->setColumnHidden(1, true);
                   ui->tab_recent_entretien->setColumnHidden(2, true);
                   ui->tab_recent_entretien->setColumnHidden(3, true);
                   ui->tab_recent_entretien->setColumnHidden(5, true);
                   ui->tab_recent_entretien->setColumnHidden(6, true);
                   ui->tab_recent_entretien->setColumnHidden(7, true);
                   ui->tab_recent_entretien->setColumnHidden(9, true);
                   ui->tab_recent_entretien->setColumnHidden(10, true);
                   ui->tab_recent_entretien->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                ui->ComboBox_id_cafe->setModel(ComboBox_id_cafe());
                ui->ComboBox_id_lavage->setModel(ComboBox_id_lavage());
                ui->ComboBox_id_entretien->setModel(ComboBox_id_entretien());
                QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                    if (chartPixmapPtr) {
                        ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                        delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                    }

                    // call the changeDesign() function here
                       changeDesign();
           } else {QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
          }
}else
               QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
}
// entretien
QSqlQueryModel* service::ComboBox_id_entretien()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_SR FROM SERVICES WHERE TYPE_SR = 'Entretien'");
    model4->setQuery(query4);
    return model4;
}

void service::on_pushButton_supp_entretien_clicked()
{
    QString id;
    id=ui->ComboBox_id_entretien->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICES WHERE ID_SR='"+id+"'");

    QMessageBox::StandardButton reply = QMessageBox::warning(this,"Base de données", "Etes vous sur de le supprimer?", QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes) {
               if(query.exec()){
                   QMessageBox::critical(this,tr("Base de données"),tr("Suppression effectuée"));

                   QSqlTableModel* model1 = tab_recent_sr();
                   ui->tab_recent_sr->setModel(model1);
                   ui->tab_recent_sr->resizeColumnsToContents();
                   ui->tab_recent_sr->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_sr->setColumnHidden(1, true);
                   ui->tab_recent_sr->setColumnHidden(2, true);
                   ui->tab_recent_sr->setColumnHidden(3, true);
                   ui->tab_recent_sr->setColumnHidden(5, true);
                   ui->tab_recent_sr->setColumnHidden(6, true);
                   ui->tab_recent_sr->setColumnHidden(7, true);
                   ui->tab_recent_sr->setColumnHidden(9, true);
                   ui->tab_recent_sr->setColumnHidden(10, true);
                   ui->tab_recent_sr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model2 = tab_recent_cafe();
                   ui->tab_recent_cafe->setModel(model2);
                   ui->tab_recent_cafe->resizeColumnsToContents();
                   ui->tab_recent_cafe->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_cafe->setColumnHidden(1, true);
                   ui->tab_recent_cafe->setColumnHidden(2, true);
                   ui->tab_recent_cafe->setColumnHidden(3, true);
                   ui->tab_recent_cafe->setColumnHidden(5, true);
                   ui->tab_recent_cafe->setColumnHidden(6, true);
                   ui->tab_recent_cafe->setColumnHidden(7, true);
                   ui->tab_recent_cafe->setColumnHidden(9, true);
                   ui->tab_recent_cafe->setColumnHidden(10, true);
                   ui->tab_recent_cafe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model3 = tab_recent_lavage();
                   ui->tab_recent_lavage->setModel(model3);
                   ui->tab_recent_lavage->resizeColumnsToContents();
                   ui->tab_recent_lavage->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_lavage->setColumnHidden(1, true);
                   ui->tab_recent_lavage->setColumnHidden(2, true);
                   ui->tab_recent_lavage->setColumnHidden(3, true);
                   ui->tab_recent_lavage->setColumnHidden(5, true);
                   ui->tab_recent_lavage->setColumnHidden(6, true);
                   ui->tab_recent_lavage->setColumnHidden(7, true);
                   ui->tab_recent_lavage->setColumnHidden(9, true);
                   ui->tab_recent_lavage->setColumnHidden(10, true);
                   ui->tab_recent_lavage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                   QSqlTableModel* model4 = tab_recent_entretien();
                   ui->tab_recent_entretien->setModel(model4);
                   ui->tab_recent_entretien->resizeColumnsToContents();
                   ui->tab_recent_entretien->setEditTriggers(QAbstractItemView::NoEditTriggers);
                   ui->tab_recent_entretien->setColumnHidden(1, true);
                   ui->tab_recent_entretien->setColumnHidden(2, true);
                   ui->tab_recent_entretien->setColumnHidden(3, true);
                   ui->tab_recent_entretien->setColumnHidden(5, true);
                   ui->tab_recent_entretien->setColumnHidden(6, true);
                   ui->tab_recent_entretien->setColumnHidden(7, true);
                   ui->tab_recent_entretien->setColumnHidden(9, true);
                   ui->tab_recent_entretien->setColumnHidden(10, true);
                   ui->tab_recent_entretien->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


                ui->ComboBox_id_cafe->setModel(ComboBox_id_cafe());
                ui->ComboBox_id_lavage->setModel(ComboBox_id_lavage());
                ui->ComboBox_id_entretien->setModel(ComboBox_id_entretien());
                QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
                    if (chartPixmapPtr) {
                        ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                        delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
                    }


                    // call the changeDesign() function here
                       changeDesign();


           } else {QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
          }
}else
               QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
}


/************************************************************* end of supp *********************************************************************/


/********************          modifier            ***************************************/
//MODIFIER
bool service::modifier(QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE SERVICES SET TYPE_SR = :type, PRIX = :prix, QUANTITE_SR = :quantite WHERE ID_SR = '"+id+"'");
    query.bindValue(":id",ID_SR);
    query.bindValue(":type",TYPE_SR);
    query.bindValue(":quantite",QUANTITE_SR);
    query.bindValue(":prix",static_cast<double>(PRIX));
    return query.exec();
}


void service::on_tab_recent_cafe_activated(const QModelIndex &index)
{
    QString val=ui->tab_recent_cafe->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from SERVICES where ID_SR='"+val+"'");
        if(query.exec())
        {
            while(query.next())
            {
                ui->comboBox_id_modif->setCurrentText(query.value(0).toString());
                ui->ComboBox_type_sr_modif->setCurrentText(query.value(4).toString());
                ui->le_quantite_sr_modif->setText(query.value(11).toString());
                QString str = query.value(8).toString();
                double prix = str.toDouble();
                ui->db_prix_sr_modif->setValue(prix);
                ui->tabWidget->setCurrentIndex(5);
            }
        }
        else {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
    }


void service::on_pb_modifier_sr_clicked()
{
    QString ID_SR = ui->comboBox_id_modif->currentText();
    QString TYPE_SR = ui->ComboBox_type_sr_modif->currentText();
    int QUANTITE_SR =ui->le_quantite_sr_modif->text().toInt();
    qfloat16 PRIX= ui->db_prix_sr_modif->value();


    service SR( 0, 0, 0, 0, 0,  PRIX, 0, 0, QUANTITE_SR, "", "", TYPE_SR);



    bool test=SR.modifier(ID_SR);
    if(test)
   {
       QMessageBox::information(nullptr,QObject::tr("Base de données"),
       QObject::tr("Modification effectuée\n"),QMessageBox::Yes);
       QSqlTableModel* model1 = tab_recent_sr();
       ui->tab_recent_sr->setModel(model1);
       ui->tab_recent_sr->resizeColumnsToContents();
       ui->tab_recent_sr->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_sr->setColumnHidden(1, true);
       ui->tab_recent_sr->setColumnHidden(2, true);
       ui->tab_recent_sr->setColumnHidden(3, true);
       ui->tab_recent_sr->setColumnHidden(5, true);
       ui->tab_recent_sr->setColumnHidden(6, true);
       ui->tab_recent_sr->setColumnHidden(7, true);
       ui->tab_recent_sr->setColumnHidden(9, true);
       ui->tab_recent_sr->setColumnHidden(10, true);
       ui->tab_recent_sr->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


       QSqlTableModel* model2 = tab_recent_cafe();
       ui->tab_recent_cafe->setModel(model2);
       ui->tab_recent_cafe->resizeColumnsToContents();
       ui->tab_recent_cafe->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_cafe->setColumnHidden(1, true);
       ui->tab_recent_cafe->setColumnHidden(2, true);
       ui->tab_recent_cafe->setColumnHidden(3, true);
       ui->tab_recent_cafe->setColumnHidden(5, true);
       ui->tab_recent_cafe->setColumnHidden(6, true);
       ui->tab_recent_cafe->setColumnHidden(7, true);
       ui->tab_recent_cafe->setColumnHidden(9, true);
       ui->tab_recent_cafe->setColumnHidden(10, true);
       ui->tab_recent_cafe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


       QSqlTableModel* model3 = tab_recent_lavage();
       ui->tab_recent_lavage->setModel(model3);
       ui->tab_recent_lavage->resizeColumnsToContents();
       ui->tab_recent_lavage->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_lavage->setColumnHidden(1, true);
       ui->tab_recent_lavage->setColumnHidden(2, true);
       ui->tab_recent_lavage->setColumnHidden(3, true);
       ui->tab_recent_lavage->setColumnHidden(5, true);
       ui->tab_recent_lavage->setColumnHidden(6, true);
       ui->tab_recent_lavage->setColumnHidden(7, true);
       ui->tab_recent_lavage->setColumnHidden(9, true);
       ui->tab_recent_lavage->setColumnHidden(10, true);
       ui->tab_recent_lavage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


       QSqlTableModel* model4 = tab_recent_entretien();
       ui->tab_recent_entretien->setModel(model4);
       ui->tab_recent_entretien->resizeColumnsToContents();
       ui->tab_recent_entretien->setEditTriggers(QAbstractItemView::NoEditTriggers);
       ui->tab_recent_entretien->setColumnHidden(1, true);
       ui->tab_recent_entretien->setColumnHidden(2, true);
       ui->tab_recent_entretien->setColumnHidden(3, true);
       ui->tab_recent_entretien->setColumnHidden(5, true);
       ui->tab_recent_entretien->setColumnHidden(6, true);
       ui->tab_recent_entretien->setColumnHidden(7, true);
       ui->tab_recent_entretien->setColumnHidden(9, true);
       ui->tab_recent_entretien->setColumnHidden(10, true);
       ui->tab_recent_entretien->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    ui->ComboBox_id_cafe->setModel(ComboBox_id_cafe());
    ui->ComboBox_id_lavage->setModel(ComboBox_id_lavage());
    ui->ComboBox_id_entretien->setModel(ComboBox_id_entretien());
        QPixmap* chartPixmapPtr = statistique(); // Appel à votre fonction pour récupérer le QPixmap*
            if (chartPixmapPtr) {
                ui->label->setPixmap(*chartPixmapPtr); // Mise à jour de l'image de la QLabel
                delete chartPixmapPtr; // Libération de la mémoire allouée dynamiquement pour le QPixmap
            }

            // call the changeDesign() function here
               changeDesign();
   }
    else
       QMessageBox::critical(nullptr,QObject::tr("Base de données"),
       QObject::tr("Modification non effectuée\n"),QMessageBox::Yes);
}





//*************GENERER_PDF********************//
//******PDF_CAFE*********
void service::generatePDF_cafe(QString filename)
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
    painter.drawPixmap(30,25,QPixmap(":/ICON/loo.png"));
    painter.drawPixmap(-200,-200,QPixmap(":/ICON/llll.png"));

    // Ajouter le titre
        QString title = "SERVICE CAFE";
        QFont titleFont("Arial", 18, QFont::Bold);
        painter.setFont(titleFont);
        painter.drawText(370,100, title);
        QFont defaultFont;
        painter.setFont(defaultFont);



    // Récupérer les noms des colonnes
    QHeaderView *header = ui->tab_recent_cafe->horizontalHeader();
    QStringList headersToPrint = {"ID", "TYPE", "PRIX", "QUANTITE"};
    int x = 250;
    int y = 20;
    int w = 0;
    int z = 0;
    int a = 30;

    for(const QString &headerText : headersToPrint)
    {
        int headerIndex = header->visualIndex(header->logicalIndex(header->count() - 1)) + 1;
        for(int i = 0; i < header->count(); i++)
        {
            if(header->model()->headerData(i, Qt::Horizontal).toString() == headerText)
            {
                headerIndex = header->visualIndex(i);
                break;
            }
        }
        if(headerIndex >= header->count())
        {
            continue;
        }
        painter.drawText(0 + a, x, headerText);
        a += 95;
    }
    // Afficher les noms de colonnes

    QModelIndex index;
    for(int row=0; row<ui->tab_recent_cafe->model()->rowCount(); row++)
    {
        y = 280; // incrémenter la position verticale pour afficher la prochaine ligne de données
        x = 30;
        w = y+z;
        for(const QString &headerText : headersToPrint)
        {
            int headerIndex = header->visualIndex(header->logicalIndex(header->count() - 1)) + 1;
            for(int i = 0; i < header->count(); i++)
            {
                if(header->model()->headerData(i, Qt::Horizontal).toString() == headerText)
                {
                    headerIndex = header->visualIndex(i);
                    break;
                }
            }
            if(headerIndex >= header->count())
            {
                continue;
            }
            index = ui->tab_recent_cafe->model()->index(row, headerIndex);
            QString data = ui->tab_recent_cafe->model()->data(index).toString();
            painter.drawText(x, w, data);
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

void service::on_pushButton_PDF_cafe_clicked()
{
    QString filename = "SERVICE_CAFE.pdf";
    generatePDF_cafe(filename);
}
//*********PDF_lavage*************

void service::generatePDF_lavage(QString filename)
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
    painter.drawPixmap(30,25,QPixmap(":/ICON/loo.png"));
    painter.drawPixmap(-200,-200,QPixmap(":/ICON/llll.png"));

    // Ajouter le titre
        QString title = "SERVICE LAVAGE";
        QFont titleFont("Arial", 18, QFont::Bold);
        painter.setFont(titleFont);
        painter.drawText(370,100, title);
        QFont defaultFont;
        painter.setFont(defaultFont);


        // Récupérer les noms des colonnes
        QHeaderView *header = ui->tab_recent_lavage->horizontalHeader();
        QStringList headersToPrint = {"ID", "TYPE", "PRIX", "QUANTITE"};
        int x = 250;
        int y = 20;
        int w = 0;
        int z = 0;
        int a = 30;

        for(const QString &headerText : headersToPrint)
        {
            int headerIndex = header->visualIndex(header->logicalIndex(header->count() - 1)) + 1;
            for(int i = 0; i < header->count(); i++)
            {
                if(header->model()->headerData(i, Qt::Horizontal).toString() == headerText)
                {
                    headerIndex = header->visualIndex(i);
                    break;
                }
            }
            if(headerIndex >= header->count())
            {
                continue;
            }
            painter.drawText(0 + a, x, headerText);
            a += 95;
        }
        // Afficher les noms de colonnes

        QModelIndex index;
        for(int row=0; row<ui->tab_recent_lavage->model()->rowCount(); row++)
        {
            y = 280; // incrémenter la position verticale pour afficher la prochaine ligne de données
            x = 30;
            w = y+z;
            for(const QString &headerText : headersToPrint)
            {
                int headerIndex = header->visualIndex(header->logicalIndex(header->count() - 1)) + 1;
                for(int i = 0; i < header->count(); i++)
                {
                    if(header->model()->headerData(i, Qt::Horizontal).toString() == headerText)
                    {
                        headerIndex = header->visualIndex(i);
                        break;
                    }
                }
                if(headerIndex >= header->count())
                {
                    continue;
                }
                index = ui->tab_recent_lavage->model()->index(row, headerIndex);
                QString data = ui->tab_recent_lavage->model()->data(index).toString();
                painter.drawText(x, w, data);
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
void service::on_pushButton_PDF_lavage_clicked()
{
    QString filename = "SERVICE_LAVAGE.pdf";
    generatePDF_lavage(filename);
}
//***************PDF_entretien********
void service::generatePDF_entretien(QString filename)
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
    painter.drawPixmap(30,25,QPixmap(":/ICON/loo.png"));
    painter.drawPixmap(-200,-200,QPixmap(":/ICON/llll.png"));

    // Ajouter le titre
        QString title = "SERVICE ENTRETIEN";
        QFont titleFont("Arial", 18, QFont::Bold);
        painter.setFont(titleFont);
        painter.drawText(370,100, title);
        QFont defaultFont;
        painter.setFont(defaultFont);


        // Récupérer les noms des colonnes
        QHeaderView *header = ui->tab_recent_entretien->horizontalHeader();
        QStringList headersToPrint = {"ID", "TYPE", "PRIX", "QUANTITE"};
        int x = 250;
        int y = 20;
        int w = 0;
        int z = 0;
        int a = 30;

        for(const QString &headerText : headersToPrint)
        {
            int headerIndex = header->visualIndex(header->logicalIndex(header->count() - 1)) + 1;
            for(int i = 0; i < header->count(); i++)
            {
                if(header->model()->headerData(i, Qt::Horizontal).toString() == headerText)
                {
                    headerIndex = header->visualIndex(i);
                    break;
                }
            }
            if(headerIndex >= header->count())
            {
                continue;
            }
            painter.drawText(0 + a, x, headerText);
            a += 95;
        }
        // Afficher les noms de colonnes

        QModelIndex index;
        for(int row=0; row<ui->tab_recent_entretien->model()->rowCount(); row++)
        {
            y = 280; // incrémenter la position verticale pour afficher la prochaine ligne de données
            x = 30;
            w = y+z;
            for(const QString &headerText : headersToPrint)
            {
                int headerIndex = header->visualIndex(header->logicalIndex(header->count() - 1)) + 1;
                for(int i = 0; i < header->count(); i++)
                {
                    if(header->model()->headerData(i, Qt::Horizontal).toString() == headerText)
                    {
                        headerIndex = header->visualIndex(i);
                        break;
                    }
                }
                if(headerIndex >= header->count())
                {
                    continue;
                }
                index = ui->tab_recent_entretien->model()->index(row, headerIndex);
                QString data = ui->tab_recent_entretien->model()->data(index).toString();
                painter.drawText(x, w, data);
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
void service::on_pushButton_PDF_entrentien_clicked()
{
    QString filename = "SERVICE_ENTRE.pdf";
    generatePDF_entretien(filename);
}

//********************Recherchee***********
//***********Services
QSqlTableModel* service::tab_recent_sr(QString val)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("SERVICES");
    model->setFilter(QString("ID_SR LIKE '%%1%' OR QUANTITE_SR LIKE '%%1%' OR PRIX LIKE '%%1%' OR TYPE_SR LIKE '%%1%' ").arg(val));
    model->setHeaderData(0, Qt::Horizontal, tr("ID_SR"));
    model->setHeaderData(4, Qt::Horizontal, tr("TYPE_SR"));
    model->setHeaderData(8, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(11, Qt::Horizontal, tr("QUANTITE_SR"));

    // Masquer les colonnes non souhaitées
    ui->tab_recent_sr->setColumnHidden(1, true);
    ui->tab_recent_sr->setColumnHidden(2, true);
    ui->tab_recent_sr->setColumnHidden(3, true);
    ui->tab_recent_sr->setColumnHidden(5, true);
    ui->tab_recent_sr->setColumnHidden(6, true);
    ui->tab_recent_sr->setColumnHidden(7, true);
    ui->tab_recent_sr->setColumnHidden(9, true);
    ui->tab_recent_sr->setColumnHidden(10, true);
    model->select();
    return model;
}
void service::on_lineEdit_recherche_sr_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
    ui->tab_recent_sr->setModel(tab_recent_sr());
    } else {
    ui->tab_recent_sr->setModel(tab_recent_sr(arg1));
    }
}


// **********cafe
QSqlTableModel* service::tab_recent_cafe(QString val)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("SERVICES");
    model->setFilter(QString("(ID_SR LIKE '%%1%' OR QUANTITE_SR LIKE '%%1%' OR PRIX LIKE '%%1%') AND TYPE_SR='Cafe'").arg(val));
    model->setHeaderData(0, Qt::Horizontal, tr("ID_SR"));
    model->setHeaderData(4, Qt::Horizontal, tr("TYPE_SR"));
    model->setHeaderData(8, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(11, Qt::Horizontal, tr("QUANTITE_SR"));

    // Masquer les colonnes non souhaitées
    ui->tab_recent_cafe->setColumnHidden(1, true);
    ui->tab_recent_cafe->setColumnHidden(2, true);
    ui->tab_recent_cafe->setColumnHidden(3, true);
    ui->tab_recent_cafe->setColumnHidden(5, true);
    ui->tab_recent_cafe->setColumnHidden(6, true);
    ui->tab_recent_cafe->setColumnHidden(7, true);
    ui->tab_recent_cafe->setColumnHidden(9, true);
    ui->tab_recent_cafe->setColumnHidden(10, true);
    model->select();
    return model;
}

void service::on_lineEdit_recherche_cafe_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
    ui->tab_recent_cafe->setModel(tab_recent_cafe());
    } else {
    ui->tab_recent_cafe->setModel(tab_recent_cafe(arg1));
    }

}

//************lavage
QSqlTableModel* service::tab_recent_lavage(QString val)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("SERVICES");
    model->setFilter(QString("(ID_SR LIKE '%%1%' OR QUANTITE_SR LIKE '%%1%' OR PRIX LIKE '%%1%') AND TYPE_SR='Lavage'").arg(val));
    model->setHeaderData(0, Qt::Horizontal, tr("ID_SR"));
    model->setHeaderData(4, Qt::Horizontal, tr("TYPE_SR"));
    model->setHeaderData(8, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(11, Qt::Horizontal, tr("QUANTITE_SR"));

    // Masquer les colonnes non souhaitées
    ui->tab_recent_lavage->setColumnHidden(1, true);
    ui->tab_recent_lavage->setColumnHidden(2, true);
    ui->tab_recent_lavage->setColumnHidden(3, true);
    ui->tab_recent_lavage->setColumnHidden(5, true);
    ui->tab_recent_lavage->setColumnHidden(6, true);
    ui->tab_recent_lavage->setColumnHidden(7, true);
    ui->tab_recent_lavage->setColumnHidden(9, true);
    ui->tab_recent_lavage->setColumnHidden(10, true);
    model->select();
    return model;
}

void service::on_lineEdit_recherche_lavage_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
    ui->tab_recent_lavage->setModel(tab_recent_lavage());
    } else {
    ui->tab_recent_lavage->setModel(tab_recent_lavage(arg1));
    }
}


//*************** Entretien
QSqlTableModel* service::tab_recent_entretien(QString val)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("SERVICES");
    model->setFilter(QString("(ID_SR LIKE '%%1%' OR QUANTITE_SR LIKE '%%1%' OR PRIX LIKE '%%1%') AND TYPE_SR='Entretien'").arg(val));
    model->setHeaderData(0, Qt::Horizontal, tr("ID_SR"));
    model->setHeaderData(4, Qt::Horizontal, tr("TYPE_SR"));
    model->setHeaderData(8, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(11, Qt::Horizontal, tr("QUANTITE_SR"));

    // Masquer les colonnes non souhaitées
    ui->tab_recent_entretien->setColumnHidden(1, true);
    ui->tab_recent_entretien->setColumnHidden(2, true);
    ui->tab_recent_entretien->setColumnHidden(3, true);
    ui->tab_recent_entretien->setColumnHidden(5, true);
    ui->tab_recent_entretien->setColumnHidden(6, true);
    ui->tab_recent_entretien->setColumnHidden(7, true);
    ui->tab_recent_entretien->setColumnHidden(9, true);
    ui->tab_recent_entretien->setColumnHidden(10, true);
    model->select();
    return model;
}

void service::on_lineEdit_recherche_entretien_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
    ui->tab_recent_entretien->setModel(tab_recent_entretien());
    } else {
    ui->tab_recent_entretien->setModel(tab_recent_entretien(arg1));
    }
}

//*******************STATESTIQUE******************

QPixmap * service::statistique()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from SERVICES where TYPE_SR='Cafe' ");
     int number1=model->rowCount();
     model->setQuery("select * from SERVICES where TYPE_SR='Lavage' ");
     int number2=model->rowCount();
     model->setQuery("select * from SERVICES where TYPE_SR='Entretien' ");
     int number3=model->rowCount();

       int total=0;
      total=number1+number2+number3;
     if(total!=0)
    {
     QString a = QString("Cafe"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Lavage"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Entretien"+QString::number((number3*100)/total,'f',2)+"%" );



    QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);

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

             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Profite Service");
             chart->legend()->hide();

             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(490,241);

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
         chartView->resize(490, 241);

         // Create pixmap from chart view
         QPixmap* chartPixmap = new QPixmap(chartView->grab());
         return chartPixmap;
     }


}



//*************************************** Design *****************************************************

void service::changeDesign()
{
    // Find the service with the highest profit
       QSqlQuery query;
       query.prepare("SELECT TYPE_SR FROM SERVICES WHERE PRIX * QUANTITE_SR = (SELECT MAX(PRIX * QUANTITE_SR) FROM SERVICES)");
       query.exec();
       query.next();
       QString type = query.value(0).toString();



        // Set the background color based on the service type
        QString backgroundColor;
        if (type == "Cafe") {
            ui->groupBox->setTitle("Le service le plus profitable est Cafe");
                    ui->groupBox->setStyleSheet("QGroupBox {"
                                                "    border: 2px solid #a17a47;"
                                                "    border-radius: 5px;"
                                                "    font-size: 16px;"
                                                "    font-family: Arial;"
                                                "    color: #333333;"
                                                "    background-color: #f5f5f5;"
                                                "}"
                                                "QGroupBox::title {"
                                                "    subcontrol-origin: margin;"
                                                "    subcontrol-position: top center;"
                                                "    padding: 0 10px;"
                                                "    font-weight: bold;"
                                                "    background-color: #a17a47;"
                                                "    color: #ffffff;"
                                                "    border-top-left-radius: 5px;"
                                                "    border-top-right-radius: 5px;"
                                                "    image: url(:/new/prefix1/ICON/coffee-icon.jfif);"
                                                "    image-position: left center;"
                                                "    padding-left: 30px;"
                                                "}"
                                                "QGroupBox::indicator {"
                                                "    width: 20px;"
                                                "    height: 20px;"
                                                "}"
                                                "QGroupBox::indicator:checked {"
                                                "    image: url(\":/checked-icon.png\");"
                                                "}"
                                                "QGroupBox::indicator:unchecked {"
                                                "    image: url(\":/unchecked-icon.png\");"
                                                "}");

                    // Set the stylesheet for the stacked widget with a scaled background image

                    ui->label_27->setStyleSheet(
                        "QLabel {"
                        "    background-image: url(:/ICON/photocafe.png);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "}"
                    );
                    ui->label_27->setScaledContents(true);


        } else if (type == "Lavage") {
            ui->groupBox->setTitle("Le service le plus profitable est Lavage");
                    ui->groupBox->setStyleSheet("QGroupBox {"
                                                "    border: 2px solid #007aff;"
                                                "    border-radius: 5px;"
                                                "    font-size: 16px;"
                                                "    font-family: Arial;"
                                                "    color: #333333;"
                                                "    background-color: #f5f5f5;"
                                                "}"
                                                "QGroupBox::title {"
                                                "    subcontrol-origin: margin;"
                                                "    subcontrol-position: top center;"
                                                "    padding: 0 10px;"
                                                "    font-weight: bold;"
                                                "    background-color: #007aff;"
                                                "    color: #ffffff;"
                                                "    border-top-left-radius: 5px;"
                                                "    border-top-right-radius: 5px;"
                                                "}"
                                                "QGroupBox::indicator {"
                                                "    width: 20px;"
                                                "    height: 20px;"
                                                "}"
                                                "QGroupBox::indicator:checked {"
                                                "    image: url(\":/checked-icon.png\");"
                                                "}"
                                                "QGroupBox::indicator:unchecked {"
                                                "    image: url(\":/unchecked-icon.png\");"
                                                "}"
                                                "QGroupBox QLabel {"
                                                "    font-size: 14px;"
                                                "    font-weight: bold;"
                                                "}"
                                                "QGroupBox QPushButton {"
                                                "    font-size: 14px;"
                                                "    font-weight: bold;"
                                                "    padding: 5px;"
                                                "    border: none;"
                                                "    background-color: #007aff;"
                                                "    color: #ffffff;"
                                                "}"
                                                "QGroupBox QPushButton:hover {"
                                                "    background-color: #0056b3;"
                                                "}");

                    // Set the stylesheet for the stacked widget with a scaled background image
                    ui->label_27->setStyleSheet(
                        "QLabel {"
                        "    background-image: url(:/ICON/photolavage.png);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "}"
                    );
                    ui->label_27->setScaledContents(true);
        } else if (type == "Entretien") {
            ui->groupBox->setTitle("Le service le plus profitable est Entretien");
                    ui->groupBox->setStyleSheet("QGroupBox {"
                                                "    border: 2px solid #333333;"
                                                "    border-radius: 5px;"
                                                "    font-size: 16px;"
                                                "    font-family: Arial;"
                                                "    color: #333333;"
                                                "    background-color: #ffffff;"
                                                "}"
                                                "QGroupBox::title {"
                                                "    subcontrol-origin: margin;"
                                                "    subcontrol-position: top center;"
                                                "    padding: 0 10px;"
                                                "    font-weight: bold;"
                                                "    background-color: #333333;"
                                                "    color: #ffffff;"
                                                "    border-top-left-radius: 5px;"
                                                "    border-top-right-radius: 5px;"
                                                "}"
                                                "QGroupBox::indicator {"
                                                "    width: 20px;"
                                                "    height: 20px;"
                                                "}"
                                                "QGroupBox::indicator:checked {"
                                                "    image: url(\":/checked-icon.png\");"
                                                "}"
                                                "QGroupBox::indicator:unchecked {"
                                                "    image: url(\":/unchecked-icon.png\");"
                                                "}"
                                                "QGroupBox QLabel {"
                                                "    font-size: 14px;"
                                                "    font-weight: bold;"
                                                "}"
                                                "QGroupBox QPushButton {"
                                                "    font-size: 14px;"
                                                "    font-weight: bold;"
                                                "    padding: 5px;"
                                                "    border: none;"
                                                "    background-color: #333333;"
                                                "    color: #ffffff;"
                                                "}"
                                                "QGroupBox QPushButton:hover {"
                                                "    background-color: #4d4d4d;"
                                                "}");
                    // Set the stylesheet for the stacked widget with a scaled background image
                    ui->label_27->setStyleSheet(
                        "QLabel {"
                        "    background-image: url(:/ICON/photoentretien.png);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "}"
                    );
                    ui->label_27->setScaledContents(true);
        }

}






//************************************************** Activer/desactiver of service *******************










void service::afficherImageModeCafe() {
    QSqlQuery query;
    query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Cafe'");
    if (query.exec() && query.next()) {
        QString etat = query.value(0).toString();
        if (etat == "En service") {
            QPixmap image(":/ICON/open.png"); // charger l'image X depuis les ressources de l'application
            ui->label_etat_cafe->setPixmap(image);
        } else {
            QPixmap image(":/ICON/close.png"); // charger l'image Y depuis les ressources de l'application
            ui->label_etat_cafe->setPixmap(image);
        }
    } else {
        // afficher une erreur si la requête a échoué
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de récupérer les données des stations."));
    }
}

void service::displayEtatCafe()
{
    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to select the ETAT_SR column where TYPE_SR is 'Cafe'
    QString selectStatement = "SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Cafe'";
    query.prepare(selectStatement);

    // Execute the select statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error selecting ETAT_SR:" << query.lastError().text();
        return;
    }

    // Fetch the first row from the query result
    if (query.first()) {
        // Get the value of the ETAT_SR column from the query result
        QString etat = query.value("ETAT_SR").toString();

        // Set the value of the ETAT_SR column to the UI label
        ui->etat_cafe->setText(etat);
    } else {
        // Handle no rows found
        qDebug() << "No rows found where TYPE_SR is 'Cafe'";
    }
}

void service::on_pushButton_Eactiver_cafe_clicked()
{
    // Set the text on the UI label
    ui->etat_cafe->setText("En service");

    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to update the ETAT_SR column
    QString updateStatement = "UPDATE SERVICES SET ETAT_SR = :etat WHERE TYPE_SR = 'Cafe'";
    query.prepare(updateStatement);

    // Bind the value for the ETAT_SR column to the prepared statement
    query.bindValue(":etat", "En service");

    // Execute the update statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error updating ETAT_SR:" << query.lastError().text();
    }

    // Set the current tab in the UI tab widget
    //ui->tabWidget->setCurrentIndex(0);
    afficherImageModeCafe();

}

void service::on_pushButton_Edesact_cafe_clicked()
{
    // Set the text on the UI label
    ui->etat_cafe->setText("Hors service");

    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to update the ETAT_SR column
    QString updateStatement = "UPDATE SERVICES SET ETAT_SR = :etat WHERE TYPE_SR = 'Cafe'";
    query.prepare(updateStatement);

    // Bind the value for the ETAT_SR column to the prepared statement
    query.bindValue(":etat", "Hors service");

    // Execute the update statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error updating ETAT_SR:" << query.lastError().text();
    }

    // Set the current tab in the UI tab widget
   // ui->tabWidget->setCurrentIndex(0);
    afficherImageModeCafe();




}






void service::afficherImageModeLavage() {
    QSqlQuery query;
    query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Lavage'");
    if (query.exec() && query.next()) {
        QString etat = query.value(0).toString();
        if (etat == "En service") {
            QPixmap image(":/ICON/open.png"); // charger l'image X depuis les ressources de l'application
            ui->label_etat_lavage->setPixmap(image);
        } else {
            QPixmap image(":/ICON/close.png"); // charger l'image Y depuis les ressources de l'application
            ui->label_etat_lavage->setPixmap(image);
        }
    } else {
        // afficher une erreur si la requête a échoué
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de récupérer les données des stations."));
    }
}

void service::displayEtatLavage()
{
    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to select the ETAT_SR column where TYPE_SR is 'Cafe'
    QString selectStatement = "SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Lavage'";
    query.prepare(selectStatement);

    // Execute the select statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error selecting ETAT_SR:" << query.lastError().text();
        return;
    }

    // Fetch the first row from the query result
    if (query.first()) {
        // Get the value of the ETAT_SR column from the query result
        QString etat = query.value("ETAT_SR").toString();

        // Set the value of the ETAT_SR column to the UI label
        ui->etat_lavage->setText(etat);
    } else {
        // Handle no rows found
        qDebug() << "No rows found where TYPE_SR is 'Lavage'";
    }
}

void service::on_pushButton_Eactiver_lavage_clicked()
{
    // Set the text on the UI label
    ui->etat_lavage->setText("En service");

    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to update the ETAT_SR column
    QString updateStatement = "UPDATE SERVICES SET ETAT_SR = :etat WHERE TYPE_SR = 'Lavage'";
    query.prepare(updateStatement);

    // Bind the value for the ETAT_SR column to the prepared statement
    query.bindValue(":etat", "En service");

    // Execute the update statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error updating ETAT_SR:" << query.lastError().text();
    }

    // Set the current tab in the UI tab widget
    //ui->tabWidget->setCurrentIndex(0);
    afficherImageModeLavage();

}

void service::on_pushButton_Edesact_lavage_clicked()
{
    // Set the text on the UI label
    ui->etat_lavage->setText("Hors service");

    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to update the ETAT_SR column
    QString updateStatement = "UPDATE SERVICES SET ETAT_SR = :etat WHERE TYPE_SR = 'Lavage'";
    query.prepare(updateStatement);

    // Bind the value for the ETAT_SR column to the prepared statement
    query.bindValue(":etat", "Hors service");

    // Execute the update statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error updating ETAT_SR:" << query.lastError().text();
    }

    // Set the current tab in the UI tab widget
    //ui->tabWidget->setCurrentIndex(0);
    afficherImageModeLavage();



}




void service::afficherImageModeEntretien() {
    QSqlQuery query;
    query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Entretien'");
    if (query.exec() && query.next()) {
        QString etat = query.value(0).toString();
        if (etat == "En service") {
            QPixmap image(":/ICON/open.png"); // charger l'image X depuis les ressources de l'application
            ui->label_etat_entretien->setPixmap(image);
        } else {
            QPixmap image(":/ICON/close.png"); // charger l'image Y depuis les ressources de l'application
            ui->label_etat_entretien->setPixmap(image);
        }
    } else {
        // afficher une erreur si la requête a échoué
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de récupérer les données des stations."));
    }
}

void service::displayEtatEntretien()
{
    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to select the ETAT_SR column where TYPE_SR is 'Cafe'
    QString selectStatement = "SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Entretien'";
    query.prepare(selectStatement);

    // Execute the select statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error selecting ETAT_SR:" << query.lastError().text();
        return;
    }

    // Fetch the first row from the query result
    if (query.first()) {
        // Get the value of the ETAT_SR column from the query result
        QString etat = query.value("ETAT_SR").toString();

        // Set the value of the ETAT_SR column to the UI label
        ui->etat_entretien->setText(etat);
    } else {
        // Handle no rows found
        qDebug() << "No rows found where TYPE_SR is 'Entretien'";
    }
}

void service::on_pushButton_Eactiver_entretien_clicked()
{
    // Set the text on the UI label
    ui->etat_entretien->setText("En service");

    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to update the ETAT_SR column
    QString updateStatement = "UPDATE SERVICES SET ETAT_SR = :etat WHERE TYPE_SR = 'Entretien'";
    query.prepare(updateStatement);

    // Bind the value for the ETAT_SR column to the prepared statement
    query.bindValue(":etat", "En service");

    // Execute the update statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error updating ETAT_SR:" << query.lastError().text();
    }

    // Set the current tab in the UI tab widget
    //ui->tabWidget->setCurrentIndex(0);
    afficherImageModeEntretien();
}

void service::on_pushButton_Edesact_entretien_clicked()
{
    // Set the text on the UI label
    ui->etat_entretien->setText("Hors service");

    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;

    // Prepare an SQL statement to update the ETAT_SR column
    QString updateStatement = "UPDATE SERVICES SET ETAT_SR = :etat WHERE TYPE_SR = 'Entretien'";
    query.prepare(updateStatement);

    // Bind the value for the ETAT_SR column to the prepared statement
    query.bindValue(":etat", "Hors service");

    // Execute the update statement
    if (!query.exec()) {
        // Handle error
        qDebug() << "Error updating ETAT_SR:" << query.lastError().text();
    }

    // Set the current tab in the UI tab widget
    //ui->tabWidget->setCurrentIndex(0);
    afficherImageModeEntretien();
}


//******************************* Jour Ferie ****************************************
//*******  cafe   *****
void service::on_comboBox_JF_cafe_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Cafe'");
    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la récupération de la valeur de ETAT_SR";
        return;
    }
    QString etatSR = query.value(0).toString();

    if (etatSR != "Hors service") {
        query.prepare("UPDATE SERVICES SET IMAGE_SR = :jour WHERE TYPE_SR = 'Cafe'");
        query.bindValue(":jour", arg1);
        if (!query.exec()) {
            qWarning() << "Erreur lors de la mise à jour du jour de la friture";
            // Show a message box to inform the user that the update was unsuccessful
            QMessageBox::critical(this, "Error", "Failed to update the database.");
        } else {
            // Show a message box to inform the user that the update was successful
            //QMessageBox::information(this, "Information", "Jour ferie set successfully.");

        compareDayOfWeekWith_cafe();
        displayEtatCafe();
        }
    } else {
        // Show a message box to inform the user that the update was not allowed
        QMessageBox::critical(this, "Error", "Cannot update the jour ferie while the service is 'Hors service'.");
        setComboBoxValueFromDatabase_cafe();
    }
}

void service::setComboBoxValueFromDatabase_cafe() {
    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;
    query.prepare("SELECT IMAGE_SR FROM SERVICES WHERE TYPE_SR = 'Cafe'");
    if (query.exec() && query.next()) {
        QString imageSR = query.value(0).toString();
        int index = ui->comboBox_JF_cafe->findText(imageSR);
        if (index != -1) { // If text is found
            ui->comboBox_JF_cafe->setCurrentIndex(index);
        }
    } else {
        // Display an error message if the query failed
        QMessageBox::critical(this, tr("Error"), tr("Unable to retrieve data from the database."));
    }
}

void service::compareDayOfWeekWith_cafe() {
    // Get the current day of the week
    QDate currentDate = QDate::currentDate();
    int currentDayOfWeek = currentDate.dayOfWeek();

    // Retrieve the value of IMAGE_SR from the database
    QSqlQuery query;
    query.prepare("SELECT IMAGE_SR FROM SERVICES WHERE TYPE_SR = 'Cafe'");
    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la récupération de la valeur de IMAGE_SR";
        return;
    }
    QString imageSR = query.value(0).toString();

    // Compare the value of IMAGE_SR with the current day of the week
    if (imageSR == "Dimanche" && currentDayOfWeek == Qt::Sunday) {
        // Do something if it's Sunday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    } else if (imageSR == "Lundi" && currentDayOfWeek == Qt::Monday) {
        // Do something if it's Monday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    } else if (imageSR == "Mardi" && currentDayOfWeek == Qt::Tuesday) {
        // Do something if it's Tuesday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    } else if (imageSR == "Mercredi" && currentDayOfWeek == Qt::Wednesday) {
        // Do something if it's Wednesday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    } else if (imageSR == "Jeudi" && currentDayOfWeek == Qt::Thursday) {
        // Do something if it's Thursday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    } else if (imageSR == "Vendredi" && currentDayOfWeek == Qt::Friday) {
        // Do something if it's Friday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    } else if (imageSR == "Samedi" && currentDayOfWeek == Qt::Saturday) {
        // Do something if it's Saturday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Cafe'");
        query.exec();
    }else {
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'En service' WHERE TYPE_SR = 'Cafe'");
        query.exec();

    }

}




//******************************* Jour Ferie ****************************************
//*******  lavage   *****
void service::on_comboBox_JF_lavage_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Lavage'");
    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la récupération de la valeur de ETAT_SR";
        return;
    }
    QString etatSR = query.value(0).toString();

    if (etatSR != "Hors service") {
        query.prepare("UPDATE SERVICES SET IMAGE_SR = :jour WHERE TYPE_SR = 'Lavage'");
        query.bindValue(":jour", arg1);
        if (!query.exec()) {
            qWarning() << "Erreur lors de la mise à jour du jour de la friture";
            // Show a message box to inform the user that the update was unsuccessful
            QMessageBox::critical(this, "Error", "Failed to update the database.");
        } else {
            // Show a message box to inform the user that the update was successful
           // QMessageBox::information(this, "Information", "Jour ferie set successfully.");
        }
        compareDayOfWeekWith_lavage();
        displayEtatLavage();
    } else {
        // Show a message box to inform the user that the update was not allowed
        QMessageBox::critical(this, "Error", "Cannot update the jour ferie while the service is 'Hors service'.");
        setComboBoxValueFromDatabase_lavage();
    }
}

void service::setComboBoxValueFromDatabase_lavage() {
    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;
    query.prepare("SELECT IMAGE_SR FROM SERVICES WHERE TYPE_SR = 'Lavage'");
    if (query.exec() && query.next()) {
        QString imageSR = query.value(0).toString();
        int index = ui->comboBox_JF_lavage->findText(imageSR);
        if (index != -1) { // If text is found
            ui->comboBox_JF_lavage->setCurrentIndex(index);
        }
    } else {
        // Display an error message if the query failed
        QMessageBox::critical(this, tr("Error"), tr("Unable to retrieve data from the database."));
    }
}

void service::compareDayOfWeekWith_lavage() {
    // Get the current day of the week
    QDate currentDate = QDate::currentDate();
    int currentDayOfWeek = currentDate.dayOfWeek();

    // Retrieve the value of IMAGE_SR from the database
    QSqlQuery query;
    query.prepare("SELECT IMAGE_SR FROM SERVICES WHERE TYPE_SR = 'Lavage'");
    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la récupération de la valeur de IMAGE_SR";
        return;
    }
    QString imageSR = query.value(0).toString();

    // Compare the value of IMAGE_SR with the current day of the week
    if (imageSR == "Dimanche" && currentDayOfWeek == Qt::Sunday) {
        // Do something if it's Sunday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    } else if (imageSR == "Lundi" && currentDayOfWeek == Qt::Monday) {
        // Do something if it's Monday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    } else if (imageSR == "Mardi" && currentDayOfWeek == Qt::Tuesday) {
        // Do something if it's Tuesday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    } else if (imageSR == "Mercredi" && currentDayOfWeek == Qt::Wednesday) {
        // Do something if it's Wednesday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    } else if (imageSR == "Jeudi" && currentDayOfWeek == Qt::Thursday) {
        // Do something if it's Thursday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    } else if (imageSR == "Vendredi" && currentDayOfWeek == Qt::Friday) {
        // Do something if it's Friday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    } else if (imageSR == "Samedi" && currentDayOfWeek == Qt::Saturday) {
        // Do something if it's Saturday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Lavage'");
        query.exec();
    }else {
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'En service' WHERE TYPE_SR = 'Lavage'");
        query.exec();

    }

}



//******************************* Jour Ferie ****************************************
//*******  entretien   *****

void service::on_comboBox_JF_entretien_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT ETAT_SR FROM SERVICES WHERE TYPE_SR = 'Entretien'");
    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la récupération de la valeur de ETAT_SR";
        return;
    }
    QString etatSR = query.value(0).toString();

    if (etatSR != "Hors service") {
        query.prepare("UPDATE SERVICES SET IMAGE_SR = :jour WHERE TYPE_SR = 'Entretien'");
        query.bindValue(":jour", arg1);
        if (!query.exec()) {
            qWarning() << "Erreur lors de la mise à jour du jour de la friture";
            // Show a message box to inform the user that the update was unsuccessful
            QMessageBox::critical(this, "Error", "Failed to update the database.");
        } else {
            // Show a message box to inform the user that the update was successful
           // QMessageBox::information(this, "Information", "Jour ferie set successfully.");

        compareDayOfWeekWith_entretien();
        displayEtatEntretien();
        }
    } else {
        // Show a message box to inform the user that the update was not allowed
        QMessageBox::critical(this, "Error", "Cannot update the jour ferie while the service is 'Hors service'.");
        setComboBoxValueFromDatabase_entretien();
    }
}

void service::setComboBoxValueFromDatabase_entretien() {
    // Create a QSqlQuery object to execute SQL statements
    QSqlQuery query;
    query.prepare("SELECT IMAGE_SR FROM SERVICES WHERE TYPE_SR = 'Entretien'");
    if (query.exec() && query.next()) {
        QString imageSR = query.value(0).toString();
        int index = ui->comboBox_JF_entretien->findText(imageSR);
        if (index != -1) { // If text is found
            ui->comboBox_JF_entretien->setCurrentIndex(index);
        }
    } else {
        // Display an error message if the query failed
        QMessageBox::critical(this, tr("Error"), tr("Unable to retrieve data from the database."));
    }
}
void service::compareDayOfWeekWith_entretien() {
    // Get the current day of the week
    QDate currentDate = QDate::currentDate();
    int currentDayOfWeek = currentDate.dayOfWeek();

    // Retrieve the value of IMAGE_SR from the database
    QSqlQuery query;
    query.prepare("SELECT IMAGE_SR FROM SERVICES WHERE TYPE_SR = 'Entretien'");
    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la récupération de la valeur de IMAGE_SR";
        return;
    }
    QString imageSR = query.value(0).toString();

    // Compare the value of IMAGE_SR with the current day of the week
    if (imageSR == "Dimanche" && currentDayOfWeek == Qt::Sunday) {
        // Do something if it's Sunday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    } else if (imageSR == "Lundi" && currentDayOfWeek == Qt::Monday) {
        // Do something if it's Monday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    } else if (imageSR == "Mardi" && currentDayOfWeek == Qt::Tuesday) {
        // Do something if it's Tuesday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    } else if (imageSR == "Mercredi" && currentDayOfWeek == Qt::Wednesday) {
        // Do something if it's Wednesday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    } else if (imageSR == "Jeudi" && currentDayOfWeek == Qt::Thursday) {
        // Do something if it's Thursday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    } else if (imageSR == "Vendredi" && currentDayOfWeek == Qt::Friday) {
        // Do something if it's Friday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    } else if (imageSR == "Samedi" && currentDayOfWeek == Qt::Saturday) {
        // Do something if it's Saturday
       // ui->etat_cafe->setText("Jour Férié ");
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'Jour Férié' WHERE TYPE_SR = 'Entretien'");
        query.exec();
    }else {
        query.prepare("UPDATE SERVICES SET ETAT_SR = 'En service' WHERE TYPE_SR = 'Entretien'");
        query.exec();

    }

}





//******************* arduino
/*
void service::RFID()
{
    data=A.read_from_arduino();
   QString state;
    // Define the SQL query to insert the RFID ID into the database
    QSqlQuery query;
    query.prepare("SELECT  PRIX_LAVAGE FROM SERVICES WHERE TYPE_SR = 'Cafe'");

    if(query.exec() && query.next()) {
                  state = query.value(0).toString();
              }

    // Connect to the signal emitted when data is available on the serial port
        QString id = QString(data).trimmed(); // Convert the data to a QString and remove any whitespace
if (id==state){

 A.write_to_arduino("1");


}

        if (!query.exec()) {
            qDebug() << "Failed to insert RFID ID into database:" << query.lastError().text();
        };

    // Run the Qt event loop
//    QCoreApplication::exec();

}


*/




void service::on_ComboBox_type_sr_currentIndexChanged(const QString &arg1)
{
    ui->ComboBox_produit->clear(); // clear the second combobox


    qDebug() << "Selected item in comboBox_1:" << arg1;
     QSqlQuery query;

        // add some options to the second combobox based on the selected item
        if (arg1 == "Cafe") {
           query.prepare("SELECT NOM_STK FROM STOCKS WHERE TYPE_STK IN ('Cafe','Chocolat','Cake', 'Sucre', 'Eau', 'Jus')");
        } else if (arg1 == "Lavage") {
            query.prepare("SELECT NOM_STK FROM STOCKS WHERE TYPE_STK = 'ProduitNet'");
        } else if (arg1 == "Entretien") {
             query.prepare("SELECT NOM_STK FROM STOCKS WHERE TYPE_STK IN ('HuileSynthetque', 'HuileMinerale')");
        }
        if (!query.exec()) {
                qDebug() << "Failed to execute query";
                return;
            }
        while (query.next()) {
                QString nom_produit = query.value(0).toString();
                ui->ComboBox_produit->addItem(nom_produit);
            }
}
