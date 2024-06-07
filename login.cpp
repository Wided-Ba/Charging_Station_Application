#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
     ui->stackedWidget->setObjectName("login");
    ui->lineEdit_loginid->setValidator(new QIntValidator(0,999999,this));
    /******arduino ******/
/*

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); */// permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_verifier_clicked()
{
    QSqlQuery query;

    QString username=ui->lineEdit_loginid->text();
    //QString password=ui->lineEdit_loginmdp->text();



     auto plainText = ui->lineEdit_loginmdp->text();

            DuCrypt crypt;

            ui->llinededit->setText(crypt.encrypt(plainText));
    QString password=ui->llinededit->text();

    query =E.login(username,password);

    if(query.exec())
    {

       if(query.next())
        {
QString userType = query.value(11).toString();
            if (userType == "Gerant"){
            login::close();
            profil *m = new profil();
            m->show();

                                     }
            else if (userType != "Gerant")

        {   profilemp *m = new profilemp();
                 login::close();

            m->show();}
}
        else
        {
            QMessageBox::warning(this,"Login", "ID et mot de pass sont incorrectes");
        }

}
}

void login::on_envoyeremail_clicked()
{
    sendMail();
    ui->stackedWidget->setCurrentIndex(0);
}


unsigned int login::getRan() const
{
  return ran;
}

void login::sendMail()
{
  smtp = new Smtp("applicationvoltifyy@gmail.com", "gtvcymonmuyzdkal", "smtp.gmail.com",465);
  connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  ran=std::rand();
  QString message = "Bienvenue sur l'application Voltify !\n\n"
                    "Veuillez copier ce numéro et l'entrer dans l'application pour continuer :\n"
                    + QString::number(ran);
  smtp->sendMail("applicationvoltifyy@gmail.com", ui->emailenvoie->text() , "Launcher Application code : "+QString::number(ran),message);

}

void login::mailSent(QString status)
{

  if(status == "Message sent"){

      if((ui->uname->text()==""||ui->pass->text()=="")){

          activatoncodeclass *act= new activatoncodeclass(this);
          act->setCode(ran);

          act->setUname(ui->uname->text());
          act->setPass(ui->pass->text());

          act->setEmail(ui->emailenvoie->text());
          act->raise();
          act->activateWindow();
          act->show();

          //this->hide();

        }
    }else{
      ui->envoyeremail->setEnabled(true);

    }

}

void login::on_pushButton_oublie_clicked()
{
ui->stackedWidget->setCurrentIndex(1);

}

/*
void login::update_label()
{
    data = A.read_from_arduino();
        qDebug() << "RFID:" << data;

        QSqlQuery query;
        query = request(data);

        bool test = false;

        if(query.exec())
        {

           if(query.next())
            {
                test = true;
                QString userid = query.value(0).toString();
                QString mmdp = query.value(5).toString();
                ui->lineEdit_loginid->setText(userid);
                DuCrypt crypt;
             ui->lineEdit_loginmdp->setText(crypt.decrypt(query.value(5).toString()));

                qDebug() << "User ID:" << userid;
                qDebug() << "User Password:" << mmdp;
            }
        }
         qDebug() << "User ID:" << test;

        if (test) {
            A.write_to_arduino("1");
            qDebug() << "samir";
        } else {
            A.write_to_arduino("2");
             qDebug() << "ali";
        }

        //c = "";

}QSqlQuery login::request(QString code)
{
    QSqlQuery query;
    query.prepare("select * from EMPLOYES where IDE= '"+code+"'");
    query.addBindValue(code);
    query.exec();
    return query;
}

*/
