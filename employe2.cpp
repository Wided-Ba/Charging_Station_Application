#include "employe2.h"
#include "ui_employe2.h"
#include "ui_login.h"
employe2::employe2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employe2)
{
    ui->setupUi(this);
    ui->tableView->setObjectName("tableauempl2");
    ui->tableView->setModel(afficher());

}

employe2::~employe2()
{
    delete ui;
}

employe2::employe2(int cin,QString nom,QString prenom,QString sexe,QString mdp,QString conf_mdp,QDate ddn,QString email,int num_tel,QString statut,QString image,int salaire)
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

QSqlTableModel* employe2::afficher()
{
    QSqlTableModel* model=new QSqlTableModel(this);
    model->setTable("EMPLOYES");
   // model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    //trie  ordre croissant et decroissant
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView->setColumnHidden(5, true);
    return model;
}

void employe2::on_lineEdit_rechercher_textChanged()
{
    QString rech = ui->lineEdit_rechercher->text();

                    recherche(ui->tableView,rech);

                    if (ui->lineEdit_rechercher->text().isEmpty())

                    {
                        ui->tableView->setModel(afficher());
                    }
}
void employe2::recherche(QTableView * table, QString rech)

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



void employee::on_pushButton_PDF_clicked()
{
   telechargerPDF();


                 QMessageBox::information(nullptr,QObject::tr("OK"),



                            QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}
*/


void employe2::on_tableView_clicked(const QModelIndex &index)
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
