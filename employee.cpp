#include "employee.h"
#include "ui_employee.h"
#include <connection.h>
#include <QtDebug>
#include <QSqlQuery>
#include <iostream>
#include <QtWidgets>
#include <QSqlRecord>


employee::employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee)
{
    ui->setupUi(this);
       ui->tableView->setObjectName("tableauempl");
ui->tableView->setModel(afficher());
loadImage();
ui->tableView->setColumnHidden(5, true);
ui->tableView->setColumnHidden(6, true);
ui->tableView->setColumnHidden(12, true);
ui->tableView->setColumnHidden(4, true);
ui->tableView->setColumnHidden(14, true);
ui->tableView->setColumnHidden(10, true);
ui->tableView->setColumnHidden(7, true);
ui->tableView->setColumnHidden(13, true);
ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
ui->comboBox_statut_2->setModel(comboBox_statut_2());
ui->comboBox_statut_3->setModel(comboBox_statut_3());

ui->tableView_employe2->setModel(tableView_employe2());

  ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));  //only 8 numbers
  ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));//only letters
  ui->lineEdit_prenom->setValidator(new QRegExpValidator(QRegExp("[A-z]*"))); //only letters
  ui->lineEdit_mdp->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]*$")));  //only letters and numbers
  ui->lineEdit_tel->setValidator(new QIntValidator(0,99999999,this));  //only 8 numbers

connect(ui->lineEdit_mdp, &QLineEdit::textChanged, this, &employee::checkPassword);
connect(ui->lineEdit_modmdp, &QLineEdit::textChanged, this, &employee::checkPassword2);
/***image**/
auto fileSystemModel = new QFileSystemModel(this);
ui->lineEdit_image->setCompleter(new QCompleter(fileSystemModel,this));
ui->lineEdit_modimiage->setCompleter(new QCompleter(fileSystemModel,this));
 loadImage();
}


employee::employee(int cin,QString nom,QString prenom,QString sexe,QString mdp,QString conf_mdp,QDate ddn,QString email,int num_tel,QString statut,QByteArray image,int salaire)
{
//this->ID_E=id;
    this->CIN_E=cin;
    this->NOM_E=nom;
    this->PRENOM_E=prenom;
    this->SEXE_E=sexe;
    this->MDP_E=mdp;
    this->CONF_MDP_E=conf_mdp;
    this->DDN_E=ddn;
    this->EMAIL_E=email;
    this->NUM_TEL_E=num_tel;
    //this->NBR_H_TRAVAILLE_E=nbr_h;
    this->STATUT_E=statut;
    this->IMAGE_E=image;
    this->SALAIRE_E=salaire;
}

/*employee::~employee()
{
    delete ui;
}*/
/*void employee::on_pushButton_clicked() //afichage employe
{
    ui->tableView->setModel(afficher());
      ui->tableView->resizeColumnsToContents();
          ui->comboBox_statut_2->setModel(comboBox_statut_2());
           ui->comboBox_statut_3->setModel(comboBox_statut_3());
}*/

bool employee::ajouter()
{

    QString CIN_E_string=QString::number(CIN_E);
    //QString NUM_TEL_E_string=QString::number(NUM_TEL_E);
    QString SALAIRE_E_string=QString::number(SALAIRE_E);
    QSqlQuery query;//RELIEE AU BASE DE DONNEE (QSQLDATABASE)

          query.prepare("INSERT INTO EMPLOYES (CIN_E,NOM_E,PRENOM_E,SEXE_E,MDP_E,CONF_MDP_E,DDN_E,EMAIL_E,NUM_TEL_E,STATUT_E,IMAGE_E,SALAIRE_E) "
                        "VALUES (:cin, :nom, :prenom, :sexe, :mdp, :conf_mdp, :ddn, :email, :num_tel,:statut, :image, :salaire)");

          query.bindValue(":cin",CIN_E);
          query.bindValue(":nom",NOM_E);
          query.bindValue(":prenom",PRENOM_E);
          query.bindValue(":sexe",SEXE_E);
          query.bindValue(":mdp",MDP_E);
          query.bindValue(":conf_mdp",CONF_MDP_E);
          query.bindValue(":ddn",DDN_E);
          query.bindValue(":email",EMAIL_E);
          query.bindValue(":num_tel",NUM_TEL_E);
         // query.bindValue(":nbr_h",NBR_H_TRAVAILLE_E);
          query.bindValue(":statut",STATUT_E);
          query.bindValue(":image",IMAGE_E);
          query.bindValue(":salaire",SALAIRE_E);
          return query.exec();
}




/*QSqlQueryModel* employee::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel(this);
    QSqlQuery query1(" SELECT ID_E,CIN_E,NOM_E,PRENOM_E,SEXE_E,DDN_E,EMAIL_E,NUM_TEL_E,NBR_H_TRAVAILLE_E,STATUT_E,SALAIRE_E FROM EMPLOYES");
    model->setQuery(query1);
    return model;
}*/

QSqlTableModel* employee::afficher()
{
    QSqlTableModel* model=new QSqlTableModel(this);
    model->setTable("EMPLOYES");
   // model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    //trie  ordre croissant et decroissant
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView->setColumnHidden(5, true);
     ui->tableView->setColumnHidden(6, true);
     ui->tableView->setColumnHidden(4, true);
         ui->tableView->setColumnHidden(14, true);
         ui->tableView->setColumnHidden(10, true);
         ui->tableView->setColumnHidden(7, true);
         ui->tableView->setColumnHidden(13, true);
         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    return model;
}

void employee::on_pushButton_Ajouter_clicked()
{
/****hacher mdp**/

    auto plainText = ui->lineEdit_mdp->text();
    auto plainText2 = ui->lineEdit_conf_mdp->text();
           if (plainText.isEmpty()){
               return;
           }
           if (plainText2.isEmpty()){
               return;
           }
           DuCrypt crypt;

          ui->lineEdit_nom_2->setText(crypt.encrypt(plainText));

    QString MDP_E=ui->lineEdit_nom_2->text();
    ui->lineEdit_nom_2->setText(crypt.encrypt(plainText2));
QString CONF_MDP_E=ui->lineEdit_nom_2->text();
/*****/

int CIN_E=ui->lineEdit_cin->text().toInt();
QString NOM_E=ui->lineEdit_nom->text();
QString PRENOM_E=ui->lineEdit_prenom->text();
QString SEXE_E=ui->comboBox_sexe->currentText();
//QString MDP_E=ui->lineEdit_mdp->text();
//QString CONF_MDP_E=ui->lineEdit_conf_mdp->text();
QDate DDN_E=ui->dateEdit_DDN->date();
QString EMAIL_E=ui->lineEdit_email->text();
int NUM_TEL_E=ui->lineEdit_tel->text().toInt();
QString STATUT_E=ui->comboBox_statut->currentText();
//QString IMAGE_E=ui->lineEdit_image->text();
int SALAIRE_E=ui->doubleSpinBox_salaire->value();
QFile archivo(ui->lineEdit_image->text());
         if(!archivo.open(QIODevice::ReadOnly))
         {QMessageBox:: critical(this , "erreur ",archivo.errorString());
             return;
         }

/**********************Le controle de saisie******************/

/**********************Champs Obligatoires******************/

   QString CIN_E_string=QString::number(CIN_E);
   QString SALAIRE_E_string=QString::number(SALAIRE_E);
   if ((CIN_E_string.isEmpty()) || (NOM_E.isEmpty()) || (PRENOM_E.isEmpty()) || (SEXE_E.isEmpty()) || (MDP_E.isEmpty()) || (CONF_MDP_E.isEmpty()) || (EMAIL_E.isEmpty()) || (STATUT_E.isEmpty()) || (SALAIRE_E_string.isEmpty()) )
   {
                  QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoire");
                   qDebug() <<"Erreur! Remplir tous les champs" ;
                  return;
              }

/**********************Salaire******************/

   if (SALAIRE_E<= 0 ) {
                 QMessageBox::warning(this, "Erreur", "Le salaire doit être supérieur à zéro");
                 qDebug() <<"Erreur Salaire" ;
                  return;
              }

/**************************DDN******************/

   QDate dateOfBirth = ui->dateEdit_DDN->date();
   QDate currentDate = QDate::currentDate(); // get current date
   QDate minDate = currentDate.addYears(-18); // subtract 18 years from current date to get minimum date
   if (dateOfBirth > minDate) {
       QMessageBox::warning(this, "Erreur", "L'employe doit etre plus que 18");
       qDebug() <<"Erreur Age" ;
        return;
   }

   /**************************mot de pass******************/

   QString password = ui->lineEdit_mdp->text();

       QRegExp passwordRegex("^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z]).{8,16}$");
       if (!passwordRegex.exactMatch(password)) {
           QMessageBox::warning(this, "Erreur", "mot de pass doit contenir au moins 1 lettre majuscule, 1 lettre minuscule, 1 chiffre, et de taille 8 a 16 characters.");
            qDebug() <<"Erreur mdp" ;
           return;
       }


       /**************************confirme mdp******************/

             QString confirmPassword = ui->lineEdit_conf_mdp->text();

                 if (password != confirmPassword) {
                     QMessageBox::warning(this, "Erreur", "mot de pass and confirmation mot de passs ne sont pas identiques.");
                     qDebug() << "Erreur confirm mdp";
                     return;
            }

 /**************************Email******************/

 QString email = ui->lineEdit_email->text();
 QRegExp emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
 if (!emailRegex.exactMatch(email)) {
     QMessageBox::warning(this, "Erreur", "Format de Email invalide");
     qDebug() << "Erreur email";
     return;
}



     employee e(CIN_E,NOM_E,PRENOM_E,SEXE_E,MDP_E,CONF_MDP_E,DDN_E,EMAIL_E,NUM_TEL_E,STATUT_E,archivo.readAll(),SALAIRE_E);
      archivo.close();
     bool test=e.ajouter();

 if(test)
     {
  qDebug()<<"Success add";
                  ui->tableView->setModel(afficher());
                  loadImage();
                  ui->tableView->setColumnHidden(5, true);
                  ui->tableView->setColumnHidden(6, true);
                  ui->tableView->setColumnHidden(12, true);
                    ui->tableView->setColumnHidden(4, true);
                        ui->tableView->setColumnHidden(14, true);
                        ui->tableView->setColumnHidden(10, true);
                        ui->tableView->setColumnHidden(7, true);
                        ui->tableView->setColumnHidden(13, true);
                        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                    ui->tableView->resizeColumnsToContents();
                    ui->comboBox_statut_2->setModel(comboBox_statut_2());
                    ui->tableView_employe2->setModel(tableView_employe2());
                    QMessageBox::information(nullptr, QObject::tr("fermer"),
                                             QObject::tr("Ajout effectuée"), QMessageBox::Cancel);
     }
     else
     {
         qDebug() <<"Error add" ;
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("ajout non effectuée\n""Click cancel to exit"), QMessageBox::Cancel);

     }
 sendMail();
 ui->tabWidget->setCurrentIndex(0);
}




void employee::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
 DuCrypt crypt;
    QSqlQuery qry;
    qry.prepare("select * from EMPLOYES where ID_E='"+val+"'");
    if(qry.exec( ))
    {
        while(qry.next())
        {
                    ui->lineEdit_modnom->setText(qry.value(2).toString());
                    ui->lineEdit_modprenom->setText(qry.value(3).toString());
                    //ui->lineEdit_modcin->setText(qry.value(1).toString());
                    ui->label_27->setText(qry.value(1).toString());
                    ui->doubleSpinBox_modsalaire->setValue(qry.value(13).toDouble());
                    ui->lineEdit_modimiage->setText(qry.value(12).toString());
                    ui->lineEdit_modtel->setText(qry.value(9).toString());
                    ui->lineEdit_modemail->setText(qry.value(8).toString());

                    //ui->lineEdit_modmdp->setText(qry.value(5).toString());

                       ui->lineEdit_nom_2->setText(qry.value(5).toString());
                       auto password=ui->lineEdit_nom_2->text();
                    ui->lineEdit_modmdp->setText(crypt.decrypt(password));
                    ui->lineEdit_modconf_mdp->setText(qry.value(6).toString());
                    ui->comboBox_modstatut->setCurrentText(qry.value(11).toString());
        }
    }
ui->tabWidget->setCurrentIndex(2);
}

bool employee::modifier(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("update EMPLOYES set NOM_E=:nom,PRENOM_E=:prenom,SALAIRE_E=:salaire,IMAGE_E=:image,NUM_TEL_E=:num_tel,EMAIL_E=:email,MDP_E=:mdp,CONF_MDP_E=:conf_mdp,STATUT_E=:statut where CIN_E=:cin");
    //query.bindValue(":num",res);
    query.bindValue(":nom",NOM_E);
    query.bindValue(":prenom",PRENOM_E);
    query.bindValue(":cin",res);
    query.bindValue(":salaire",SALAIRE_E);
    query.bindValue(":image",IMAGE_E);
    query.bindValue(":num_tel",NUM_TEL_E);
    query.bindValue(":email",EMAIL_E);
    query.bindValue(":mdp",MDP_E);
    query.bindValue(":conf_mdp",CONF_MDP_E);
    query.bindValue(":statut",STATUT_E);

   return query.exec();

}


void employee::on_pushButton_Modifier_clicked()
{
    auto plainText = ui->lineEdit_modmdp->text();
 auto plainText2 = ui->lineEdit_modconf_mdp->text();
        DuCrypt crypt;

        ui->lineEdit_nom_2->setText(crypt.encrypt(plainText));
    QString password2=ui->lineEdit_nom_2->text();

    employee e;
     int cin= ui->label_27->text().toInt();
    // ui->lineEdit_modcin->setReadOnly(true);
     e.setNOM_E(ui->lineEdit_modnom->text());
     e.setPRENOM_E(ui->lineEdit_modprenom->text());
     e.setMDP_E(password2);
     e.setCONF_MDP_E(ui->lineEdit_modconf_mdp->text());
     e.setStatut_E(ui->comboBox_modstatut->currentText());
     e.setEMAIL_E(ui->lineEdit_modemail->text());
     e.setNUM_TEL_E(ui->lineEdit_modtel->text().toInt());
     e.setSALAIRE_E(ui->doubleSpinBox_modsalaire->value());
        /**********************Le controle de saisie******************/

        /**********************Salaire******************/

           if (e.SALAIRE_E<= 0 ) {
                         QMessageBox::warning(this, "Erreur", "Le salaire doit être supérieur à zéro");
                         qDebug() <<"Error Salaire" ;
                          return;
                      }

           /**************************mot de pass******************/

           QString password = ui->lineEdit_modmdp->text();

               QRegExp passwordRegex("^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z]).{8,16}$");
               if (!passwordRegex.exactMatch(password)) {
                   QMessageBox::warning(this, "Error", "mot de pass doit contenir 1 uppercase letter, 1 lowercase letter, 1 digit, et de taille 8 a 16 characters.");
                    qDebug() <<"Error mdp" ;
                   return;
               }
               /**************************confirme mdp******************/

                     QString confirmPassword = ui->lineEdit_modconf_mdp->text();

                         if (password != confirmPassword) {
                             QMessageBox::warning(this, "Error", "Password and confirmation password do not match.");
                             qDebug() << "Error confirm mdp";
                             return;
                    }
         /**************************Email******************/

         QString email = ui->lineEdit_modemail->text();
         QRegExp emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
         if (!emailRegex.exactMatch(email)) {
             QMessageBox::warning(this, "Error", "Format de Email invalide");
             qDebug() << "Error email";
             return;
        }
     bool test=e.modifier(cin);
     if (test) {
         ui->tableView->setModel(afficher());
         ui->tableView->setColumnHidden(5, true);
         ui->tableView->setColumnHidden(6, true);
         ui->tableView->setColumnHidden(12, true);
           ui->tableView->setColumnHidden(4, true);
               ui->tableView->setColumnHidden(14, true);
               ui->tableView->setColumnHidden(10, true);
               ui->tableView->setColumnHidden(7, true);
               ui->tableView->setColumnHidden(13, true);
               ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         ui->comboBox_statut_2->setModel(comboBox_statut_2());
         ui->tableView->resizeColumnsToContents();
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Modification effectuée\n"
                                              "Click cancel to exit."), QMessageBox::Cancel);
     } else {
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée\n""Click cancel to exit"), QMessageBox::Cancel);
     }
ui->tabWidget->setCurrentIndex(0);

}




bool employee::supprimer(int id)
    {
        QSqlQuery query;
        QString res= QString::number(id);
        query.prepare("delete from EMPLOYES where ID_E= :id");
        query.bindValue(":id",res);
        return query.exec();

    }



void employee::on_pushButton_supprimer_clicked()
{
    QString id;
     id=ui->comboBox_statut_2->currentText();
     QSqlQuery query;
     query.prepare("DELETE FROM EMPLOYES WHERE ID_E='"+id+"'");

     QMessageBox::StandardButton reply = QMessageBox::warning(this,"Base de données", "Etes vous sur de le supprimer?", QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes) {
                if(query.exec()){
                    QMessageBox::critical(this,tr("Base de données"),tr("Suppression effectuée"));
                    ui->tableView->setModel(afficher());
                    ui->tableView->setColumnHidden(5, true);
                    ui->tableView->setColumnHidden(6, true);
                    ui->tableView->setColumnHidden(12, true);
                      ui->tableView->setColumnHidden(4, true);
                          ui->tableView->setColumnHidden(14, true);
                          ui->tableView->setColumnHidden(10, true);
                          ui->tableView->setColumnHidden(7, true);
                          ui->tableView->setColumnHidden(13, true);
                          ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                      ui->tableView->resizeColumnsToContents();
                      ui->tableView_employe2->setModel(tableView_employe2());

                    ui->comboBox_statut_2->setModel(comboBox_statut_2());
                    auto fileSystemModel = new QFileSystemModel(this);
                    ui->lineEdit_image->setCompleter(new QCompleter(fileSystemModel,this));
                    ui->lineEdit_modimiage->setCompleter(new QCompleter(fileSystemModel,this));

            } else {QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));
           }
 }else QMessageBox::critical(this,tr("Base de données"),tr("Suppression non effectuée"));



}

/*****supprimer tout le tableau******************/

void employee::on_pushButton_supprimertab_clicked()
{
    QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete EMPLOYES table", "Confirmer la suppression du table?",
                                        QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QSqlQuery query;
            bool result = query.exec("DELETE FROM EMPLOYES");
            if (result) {
                // show success message
                QMessageBox::information(this, "Data Deleted", "suppression en succes.");
            } else {
                // show error message
                QMessageBox::critical(this, "Error", "echec.");
            }
        }
}





QSqlQueryModel* employee::comboBox_statut_2()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_E FROM EMPLOYES");
    model4->setQuery(query4);
    return model4;
}

/*************************bouton annuler du modification************/
void employee::on_pushButton_Annuler_3_clicked()
{

                    ui->lineEdit_modnom->setText(0);
                    ui->lineEdit_modprenom->setText(0);
                    //ui->lineEdit_modcin->setText(qry.value(1).toString());
                    ui->label_27->setText(0);
                    ui->doubleSpinBox_modsalaire->setValue(0);
                    ui->lineEdit_modimiage->setText(0);
                    ui->lineEdit_modtel->setText(0);
                    ui->lineEdit_modemail->setText(0);
                    ui->lineEdit_modmdp->setText(0);
                    ui->lineEdit_modconf_mdp->setText(0);
                    ui->comboBox_modstatut->setCurrentText(0);
}


QSqlQueryModel* employee::comboBox_statut_3()
{
    QSqlQueryModel* model4=new QSqlQueryModel();
    QSqlQuery query4("SELECT ID_E FROM EMPLOYES");
    model4->setQuery(query4);
    return model4;
}

void employee::on_comboBox_statut_3_currentIndexChanged()
{

    QString val=ui->comboBox_statut_3->currentText();
    QSqlQuery qry;
    qry.prepare("select * from EMPLOYES where ID_E='"+val+"'");
    if(qry.exec( ))
    {
        while(qry.next())
        {
                    ui->lineEdit_modnom->setText(qry.value(2).toString());
                    ui->lineEdit_modprenom->setText(qry.value(3).toString());
                    //ui->lineEdit_modcin->setText(qry.value(1).toString());
                    ui->label_27->setText(qry.value(1).toString());
                    ui->doubleSpinBox_modsalaire->setValue(qry.value(13).toDouble());
                    ui->lineEdit_modimiage->setText(qry.value(12).toString());
                    ui->lineEdit_modtel->setText(qry.value(9).toString());
                    ui->lineEdit_modemail->setText(qry.value(8).toString());

                    ui->lineEdit_modmdp->setText(qry.value(5).toString());

                    ui->lineEdit_modconf_mdp->setText(qry.value(6).toString());
                    ui->comboBox_modstatut->setCurrentText(qry.value(11).toString());


        }
    }


}

void employee::on_pushButton_Annuler_clicked()
{
            ui->lineEdit_nom->setText(0);
            ui->lineEdit_prenom->setText(0);
            ui->lineEdit_cin->setText(0);
            ui->doubleSpinBox_salaire->setValue(0);
            ui->lineEdit_image->setText(0);
            ui->lineEdit_tel->setText(0);
            ui->lineEdit_email->setText(0);
            ui->lineEdit_mdp->setText(0);
            ui->lineEdit_conf_mdp->setText(0);
            ui->comboBox_statut->setCurrentText(0);
}



/****************************recherche************************/

void employee::on_lineEdit_rechercher_textChanged()
{
    QString rech = ui->lineEdit_rechercher->text();

                    recherche(ui->tableView,rech);

                    if (ui->lineEdit_rechercher->text().isEmpty())

                    {
                        ui->tableView->setModel(afficher());
                        ui->tableView->setColumnHidden(5, true);
                        ui->tableView->setColumnHidden(6, true);
                        ui->tableView->setColumnHidden(12, true);
                          ui->tableView->setColumnHidden(4, true);
                         ui->tableView->setColumnHidden(14, true);
                         ui->tableView->setColumnHidden(10, true);
                         ui->tableView->setColumnHidden(7, true);
                         ui->tableView->setColumnHidden(13, true);
                         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                        ui->tableView_employe2->setModel(tableView_employe2());
                        ui->comboBox_statut_2->setModel(comboBox_statut_2());
                    }
}
void employee::recherche(QTableView * table, QString rech)

{

    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;

        query->prepare("select * from EMPLOYES where NOM_E like '%"+rech+"%' or PRENOM_E like '%"+rech+"%' or ID_E like '%"+rech+"%';");

        query->exec();

        model->setQuery(*query);

        table->setModel(model);

        table->show();

}

/*****************PDF*******************/

/*void  employee::telechargerPDF(){

    QPdfWriter pdf("C:/Users/Chayma/OneDrive/Bureau/Export PDF/PDF.pdf");
    QPainter painter(&pdf);
    int i = 4000;

    // Set document title
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 40, QFont::Bold));
    painter.drawText(1300, 1500, "LISTE DES EMPLOYÉS");

    // Draw table header
    painter.setPen(Qt::black);
    painter.drawRect(0, 2700, 9600, 500);
    painter.setFont(QFont("Calibri Light", 12, QFont::Bold));
    painter.drawText(100, 3000, "ID");
    painter.drawText(900, 3000, "CIN");
    painter.drawText(1900, 3000, "Nom");
    painter.drawText(2900, 3000, "Prénom");
    painter.drawText(4100, 3000, "Sexe");
    painter.drawText(5200, 3000, "Email");
    painter.drawText(6500, 3000, "Tel");
    painter.drawText(7500, 3000, "Statut");
    painter.drawText(8800, 3000, "Salaire");

    // Draw table rows
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES");
    query.exec();
    while (query.next()) {
        painter.setFont(QFont("Calibri",9));
        painter.drawText(100, i, query.value(0).toString());
        painter.drawText(900, i, query.value(1).toString());
        painter.drawText(1900, i, query.value(2).toString());
        painter.drawText(2900, i, query.value(3).toString());
        painter.drawText(3900, i, query.value(4).toString());
        painter.drawText(4900, i, query.value(8).toString());
        painter.drawText(6500, i, query.value(9).toString());
        painter.drawText(7500, i, query.value(11).toString());
        painter.drawText(9000, i, query.value(13).toString());
        i += 500;
    }
                          }

*/

void employee::on_pushButton_PDF_clicked()
{
    QString filename = "employes.pdf";
        generatePDF(filename);
}


QSqlQueryModel* employee::tableView_employe2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query1("SELECT ID_E, CIN_E, NOM_E, PRENOM_E, SEXE_E, SUBSTR(DDN_E, 1, 10) AS DATE_DD_E, EMAIL_E, NUM_TEL_E, NBR_H_TRAVAILLE_E, STATUT_E, SALAIRE_E FROM EMPLOYES ORDER BY ID_E ASC;");
    model->setQuery(query1);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, tr("PRENOM"));
    model->setHeaderData(4, Qt::Horizontal, tr("SEXE"));
    model->setHeaderData(5, Qt::Horizontal, tr("DDN"));
    model->setHeaderData(6, Qt::Horizontal, tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, tr("TEL"));
    model->setHeaderData(8, Qt::Horizontal, tr("HEURES"));
    model->setHeaderData(9, Qt::Horizontal, tr("STATUT"));
    model->setHeaderData(10, Qt::Horizontal, tr("SALAIRE"));
    for(int i=0;i<model->rowCount();i++){
        QString datetimeString = model->record(i).value("DDN_E").toString();
        QDateTime datetime = QDateTime::fromString(datetimeString, "yyyy-MM-ddThh:mm:ss");
        QString dateString = datetime.toString("yyyy-MM-dd");
        model->setData(model->index(i, 4), dateString);
    }

    return model;
}
void employee::generatePDF(QString filename)
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
    QString title = "LES EMPLOYES";
    QFont titleFont("Arial", 18, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(370,100, title);
    QFont defaultFont;
    painter.setFont(defaultFont);

    // Récupérer les noms des colonnes
    QHeaderView *header = ui->tableView_employe2->horizontalHeader();
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
    for(int row=0; row<ui->tableView_employe2->model()->rowCount(); row++)
    {
        y = 280; // incrémenter la position verticale pour afficher la prochaine ligne de données
        x = 30;
        w = y+z;
        for(int col=0; col<ui->tableView_employe2->model()->columnCount(); col++)
        {
            index = ui->tableView_employe2->model()->index(row, col);
            QString data = ui->tableView_employe2->model()->data(index).toString();
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
/*******login***********/
QSqlQuery employee::login(QString ID,QString mdp)
{

    QSqlQuery query;

    query.prepare("select * from EMPLOYES where ID_E= '"+ID+"' and MDP_E='"+mdp+"'");
    query.exec();
    return query;
}


void employee::on_tableView_clicked(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

        // Prepare the query
        QSqlQuery qry;
        qry.prepare("SELECT * FROM EMPLOYES WHERE NOM_E=:nom_e");
        qry.bindValue(":nom_e", val);

        // Execute the query
        if (qry.exec() && qry.next()) {
            // If the query returned a row, retrieve the data and display it in a custom message box
            QString a = qry.value(2).toString();
            QString b = qry.value(3).toString();
            QString c = qry.value(1).toString();
            double d = qry.value(13).toDouble();
            QString e = qry.value(12).toString();
            QString f = qry.value(9).toString();
            QString g = qry.value(8).toString();
            QString h = qry.value(5).toString();
            QString i = qry.value(6).toString();
            QString j = qry.value(11).toString();

            // Create a custom message box
            QMessageBox msgBox;

            msgBox.setIconPixmap(QPixmap(":/new/prefix1/ICON/278261042_5242060219164606_8744602465667434102_n.png").scaled(64, 64)); // Set a custom icon
            msgBox.setWindowIcon(QIcon(":/ICON/profil.png"));
            msgBox.setWindowTitle(tr("Employee Data")); // Set a custom window title
            msgBox.setText(tr("<b>Detailles d'employé:</b>")); // Set a custom message text

            // Add the data to the message box
            QString dataText = tr("<p><b>Nom:</b> %1</p>"
                                  "<p><b>Prenom:</b> %2</p>"
                                  "<p><b>CIN:</b> %3</p>"
                                  "<p><b>Salaire:</b> %4</p>"
                                  "<p><b>Telephone:</b> %5</p>"
                                  "<p><b>Email:</b> %6</p>"
                                  "<p><b>Statut:</b> %7</p>"

                                  )
                                  .arg(a).arg(b).arg(c).arg(d).arg(f).arg(g).arg(j);
            msgBox.setInformativeText(dataText);

            // Add a custom button to the message box
            QPushButton* closeButton = msgBox.addButton(tr("Close"), QMessageBox::ActionRole);
            closeButton->setStyleSheet("QPushButton { color: white; background-color: #0072c6; border: 1px solid #0072c6; padding: 5px 10px; border-radius: 5px; }"
                                        "QPushButton:hover { background-color: #005ba1; border-color: #005ba1; }");
            msgBox.setDefaultButton(closeButton);

            // Show the message box and wait for it to be closed
            msgBox.exec();
        }
}
/**********************email****************/

void employee::sendMail()
{
    QSqlQuery query;
    QString mail=ui->lineEdit_email->text();
    query =give(mail);
    if(query.exec())
        {

           if(query.next())
            {
    QString userid = query.value(0).toString();
    Smtp* smtp = new Smtp("applicationvoltifyy@gmail.com", "gtvcymonmuyzdkal", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString))); // Uncomment this line

    smtp->sendMail("applicationvoltifyy@gmail.com", ui->lineEdit_email->text(),"Bienvenu","Bienvenue !\nNous sommes ravis de vous accueillir dans notre entreprise.\nNous espérons que vous vous sentirez rapidement à l'aise et que vous vous épanouirez dans votre nouveau poste.\nNous sommes convaincus que vous apporterez une contribution précieuse à notre équipe, et nous sommes impatients de travailler avec vous.\nN'hésitez pas à nous contacter si vous avez des questions ou des préoccupations.\nBienvenue dans notre équipe\n Votre IDENTIFIANT EST :"+userid+" !Cordialement\nVOLTIFY.");
   // QMessageBox::information(nullptr,QObject::tr("Mailing"),QObject::tr("Mail Sent\n" "Click Cancel to quit"),QMessageBox::Cancel);

           }
    }


}
void employee::mailSent(QString status)
{
   qDebug() << "Status of email:" << status; // Add this line
   if(status == "Message sent")
       QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}



QSqlQuery employee::give(QString mail)
{

    QSqlQuery query;

    query.prepare("select * from EMPLOYES where EMAIL_E= '"+mail+"' ");
    query.exec();
    return query;
}
/********************tir******/

/*QSqlTableModel* employee::afficher()
{
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable("EMPLOYES");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

   // Spécifier les colonnes à afficher et leurs noms d'en-tête
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, tr("PRENOM"));
    model->setHeaderData(4, Qt::Horizontal, tr("SEXE"));
    model->setHeaderData(7, Qt::Horizontal, tr("DDN"));
    model->setHeaderData(8, Qt::Horizontal, tr("EMAIL"));
    model->setHeaderData(9, Qt::Horizontal, tr("NUM TEL"));
    model->setHeaderData(10, Qt::Horizontal, tr("NB HEURES"));
    model->setHeaderData(11, Qt::Horizontal, tr("STATUT"));
    model->setHeaderData(13, Qt::Horizontal, tr("SALAIRE"));
    // Masquer les colonnes non souhaitées
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(12, true);


    // Activer le tri par défaut sur la colonne ID_ST
    model->setSort(0, Qt::AscendingOrder);

    // Sélectionner les données de la table
    model->select();

    // Activer le tri sur le TableView
    ui->tableView->setSortingEnabled(true);

    return model;
}
*/


/*********password****/
void employee::checkPassword(const QString &password) {
        if (password.contains(QRegExp("[a-z]"))) {
            ui->label_16->setStyleSheet("color: green;");
            ui->one->setPixmap(QPixmap(":/ICON/coche.png"));
        } else {
            ui->label_16->setStyleSheet("color: red;");
            ui->one->setPixmap(QPixmap(":/ICON/declin.png"));
        }
        if (password.contains(QRegExp("[A-Z]"))) {
            ui->label_18->setStyleSheet("color: green;");
            ui->two->setPixmap(QPixmap(":/ICON/coche.png"));
        } else {
            ui->label_18->setStyleSheet("color: red;");
            ui->two->setPixmap(QPixmap(":/ICON/declin.png"));
        }
        if (password.contains(QRegExp("\\d{1,}"))) {
            ui->label_17->setStyleSheet("color: green;");
            ui->three->setPixmap(QPixmap(":/ICON/coche.png"));
        } else {
            ui->label_17->setStyleSheet("color: red;");
            ui->three->setPixmap(QPixmap(":/ICON/declin.png"));
        }
    }
/*******employe du mois*****/

void employee::on_toolButton_clicked()
{
   auto nombreArchivo= QFileDialog::getOpenFileName(this,"abrir imagen",QDir::rootPath(),
    "Imagenes(*.png *.jpg *.jpeg);;Cualquier archivo (*.*)");
   ui->lineEdit_image->setText(nombreArchivo);

}



/*void employee::on_tableView_stock_activated(const QModelIndex &index)
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

*/


void employee::on_toolButtonmodif_clicked()
{
    auto nombreArchivo= QFileDialog::getOpenFileName(this,"abrir imagen",QDir::rootPath(),
     "Imagenes(*.png *.jpg *.jpeg);;Cualquier archivo (*.*)");
    ui->lineEdit_modimiage->setText(nombreArchivo);
}



void employee::loadImage() {
    QSqlQuery qry;
    qry.exec("SELECT IMAGE_E,NOM_E,PRENOM_E FROM EMPLOYES WHERE NBR_H_TRAVAILLE_E = (SELECT MAX(NBR_H_TRAVAILLE_E) FROM EMPLOYES)");
    qry.next();
    QByteArray imageData = qry.value(0).toByteArray();
    QString nom = qry.value(1).toString();
    QString prenom = qry.value(2).toString();
    QString fullname = nom + " " + prenom;
    QPixmap pixmap;
    pixmap.loadFromData(imageData);
    QPixmap pixmap_resized = pixmap.scaled(ui->label_image->size() * 2, Qt::KeepAspectRatio);
    ui->label_image->setPixmap(pixmap_resized);
    ui->employename->setText(fullname);
    ui->label_image->setAlignment(Qt::AlignCenter);
    ui->employename->setAlignment(Qt::AlignHCenter);

}


/*********password modify****/
void employee::checkPassword2(const QString &password) {
        if (password.contains(QRegExp("[a-z]"))) {
            ui->label_70->setStyleSheet("color: green;");
            ui->one_3->setPixmap(QPixmap(":/ICON/coche.png"));
        } else {
            ui->label_70->setStyleSheet("color: red;");
            ui->one_3->setPixmap(QPixmap(":/ICON/declin.png"));
        }
        if (password.contains(QRegExp("[A-Z]"))) {
            ui->label_69->setStyleSheet("color: green;");
            ui->two_3->setPixmap(QPixmap(":/ICON/coche.png"));
        } else {
            ui->label_69->setStyleSheet("color: red;");
            ui->two_3->setPixmap(QPixmap(":/ICON/declin.png"));
        }
        if (password.contains(QRegExp("\\d{1,}"))) {
            ui->label_71->setStyleSheet("color: green;");
            ui->three_3->setPixmap(QPixmap(":/ICON/coche.png"));
        } else {
            ui->label_71->setStyleSheet("color: red;");
            ui->three_3->setPixmap(QPixmap(":/ICON/declin.png"));
        }
    }
