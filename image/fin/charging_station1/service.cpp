#include "service.h"
#include "ui_service.h"
#include <QApplication>
#include <QMessageBox>
#include<QtDebug>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QIntValidator>
#include<QObject>
#include<QFloat16>
#include<QTableView>
#include<QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QStandardItemModel>
service::service(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::service)
{
    ui->setupUi(this);

//controle de saisie
    ui->le_quantite_sr->setValidator(new QIntValidator(0,99,this));

    ui->tab_recent_sr->setModel(S.tab_recent_sr());
    ui->tab_recent_cafe->setModel(S.tab_recent_cafe());
    ui->tab_recent_lavage->setModel(S.tab_recent_lavage());
    ui->tab_recent_entretien->setModel(S.tab_recent_entretien());
    ui->ComboBox_id_sr->setModel(ComboBox_id_sr());

   // ui->ComboBox_id_sr->setModel(S.ComboBox_id_sr());
}

service::~service()
{
    delete ui;
}





Services::Services()
{
    ID_SR=0;
    PROFIT_SR=0;
    NBR_CAFE=0 ; NBR_LAVAGE=0 ; NBR_ENTRETIEN=0;
    PRIX_CAFE=0 ; PRIX_LAVAGE=0 ; PRIX_ENTRETIEN=0;
    QUANTITE_SR=0;
    ETAT_SR=""; IMAGE_SR=""; TYPE_SR="";
}
Services::Services(int ID_SR,int PROFIT_SR,
                 int NBR_CAFE,int NBR_LAVAGE,int NBR_ENTRETIEN,
                 float PRIX_CAFE,int PRIX_LAVAGE,int PRIX_ENTRETIEN,
                 int QUANTITE_SR,
                 QString ETAT_SR,QString IMAGE_SR,QString TYPE_SR)
{
    this->ID_SR=ID_SR; this->PROFIT_SR=PROFIT_SR;
    this->NBR_CAFE=NBR_CAFE; this->NBR_LAVAGE=NBR_LAVAGE; this->NBR_ENTRETIEN=NBR_ENTRETIEN;
    this->PRIX_CAFE=PRIX_CAFE; this->PRIX_LAVAGE=PRIX_LAVAGE; this->PRIX_ENTRETIEN=PRIX_ENTRETIEN;
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

//CRUD
//AJOUTER
bool Services::ajouterServices()
{

    QSqlQuery query;
   // QString QUANTITE_SR_STRING= QString::number(QUANTITE_SR);
    //QString PRIX_CAFE_STRING= QString::number(PRIX_CAFE) ;

          query.prepare("INSERT INTO SERVICES (TYPE_SR, QUANTITE_SR, PRIX_CAFE) "
                        "VALUES (:TYPE_SR, :QUANTITE_SR, :PRIX_CAFE)");
          query.bindValue(":TYPE_SR", TYPE_SR);
          query.bindValue(":QUANTITE_SR", QUANTITE_SR);
          query.bindValue(":PRIX_CAFE", static_cast<double>(PRIX_CAFE));

          return  query.exec();



}
//end of ajouter

//AFFICHAGE
QSqlQueryModel * Services::tab_recent_sr()
{
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query1("SELECT ID_SR,PROFIT_SR,ETAT_SR,IMAGE_SR FROM SERVICES");
        model->setQuery(query1);
    return model;

}

QSqlQueryModel * Services::tab_recent_cafe()

{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM SERVICES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SR"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(9, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(10, Qt::Horizontal, QObject::tr("TYPE_SR"));
         model->setHeaderData(11, Qt::Horizontal, QObject::tr("TYPE_SR"));



    return model;

}


QSqlQueryModel * Services::tab_recent_lavage()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT  * FROM SERVICES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SR"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_SR"));


    return model;

}


QSqlQueryModel * Services::tab_recent_entretien()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT   * FROM SERVICES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SR"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_SR"));


    return model;

}
//end of affichage


//SUPPRIMER





// BUTTONS
void service::on_pb_ajouter_sr_clicked()
{
            QString TYPE_SR=ui->ComboBox_type_sr->currentText();
            int QUANTITE_SR=ui->le_quantite_sr->text().toInt();
            qfloat16 PRIX_CAFE=ui->db_prix_sr->value();

            Services SR(0, 0, 0, 0, 0, 0, PRIX_CAFE, 0, QUANTITE_SR, "", "", TYPE_SR);

    bool test= SR.ajouterServices();

    if (test)
        {
        ui->tab_recent_sr->setModel(S.tab_recent_sr());
        ui->tab_recent_cafe->setModel(S.tab_recent_cafe());
        ui->tab_recent_lavage->setModel(S.tab_recent_lavage());
        ui->tab_recent_entretien->setModel(S.tab_recent_entretien());
         ui->ComboBox_id_sr->setModel(ComboBox_id_sr());

            qDebug() << "Services added successfully";
        }
        else
        {
            qDebug() << "Error adding services";
        }
}



QSqlQueryModel* service::ComboBox_id_sr()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_SR FROM SERVICES");
    model4->setQuery(query4);
    return model4;
}

void service::on_pushButton_supp_clicked()
{
    QString id;
    id=ui->ComboBox_id_sr->currentText();
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICES WHERE ID_SR='"+id+"'");

    QMessageBox::StandardButton reply = QMessageBox::warning(this,"Base de données", "Etes vous sur de le supprimer?", QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes) {
               if(query.exec()){
                   QMessageBox::critical(this,tr("Base de données"),tr("Suppression effectuée"));

                   ui->tab_recent_sr->setModel(S.tab_recent_sr());
                   ui->tab_recent_cafe->setModel(S.tab_recent_cafe());
                   ui->tab_recent_lavage->setModel(S.tab_recent_lavage());
                   ui->tab_recent_entretien->setModel(S.tab_recent_entretien());
                    ui->ComboBox_id_sr->setModel(ComboBox_id_sr());
           } else {QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
          }
}else QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
}



//********************          modifier            ***************************************

//MODIFIER
bool Services::modifier(QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE SERVICES SET TYPE_SR = :type, PRIX_CAFE = :prix_cafe WHERE ID_SR = '"+id+"'");
    query.bindValue(":id",ID_SR);
    query.bindValue(":type",TYPE_SR);
    query.bindValue(":prix_cafe",static_cast<double>(PRIX_CAFE));
    return query.exec();
}
/*
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
               // Vérifier si la date est valide
            QDate currentDate = QDate::currentDate();//la date actuelle
            QDate maxDate = currentDate.addMonths(5); // ajouter 5 mois à la date actuelle

            if (DFD_STK <= maxDate) {

                QMessageBox::warning(this, "Erreur", "La date doit être supérieure à 5 mois après la date actuelle");
                qDebug() <<"Error date!" ;
                return; // arrêter l'exécution de la fonction
            }


    stock s(NOM_STK,REF_STK,PRIX_A_STK,DFD_STK,TYPE_STK, MARQUE_STK, QUANTITE_STK);
       bool test=s.modifier(ID_STK);
       if(test)
       {
           ui->tableView_stock->setModel(afficher());
           ui->tableView_stock->resizeColumnsToContents(); //tnadhem l tab
           ui->comboBox_supp->setModel(comboBox_id()); //combo box ta3 supprimer :y7ot l id jdyda fl combo box
           ui->comboBox_modif->setModel(comboBox_modif());
           qDebug() << "Success modification";
           QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Modification d'un evenement"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);


}
*/
