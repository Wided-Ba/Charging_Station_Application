#include "activatoncodeclass.h"
#include "ui_activatoncodeclass.h"
static int attempt= 3;
activatoncodeclass::activatoncodeclass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activatoncodeclass)
{
     timer = nullptr;
    ui->setupUi(this);

    connect(ui->verififercode,&QPushButton::clicked,this,&activatoncodeclass::checkCode);
    QSettings settings("Comp","time");
    settings.beginGroup("Time");
    QDateTime dd=settings.value("mytime",0).toDateTime();
    settings.endGroup();
    qDebug()<<"GG"<<dd;
    connect(this,&activatoncodeclass::rejected,this,[=](){

        qDebug()<<"REJECT";
      if(timer!=nullptr){
        timer->stop();
      delete timer;
        }
      });
    connect(ui->mdp, &QLineEdit::textChanged, this, &activatoncodeclass::checkPassword);
}

activatoncodeclass::~activatoncodeclass()
{
    delete ui;
}

void activatoncodeclass::checkCode()
{
  int checker=ui->code->text().toInt();
  if(checker==getCode()){

      ui->stackedWidget->setCurrentIndex(1);

    }
  else{
      if(attempt!=0){
          QPoint point = QPoint(geometry().left() + ui->code->geometry().left(),
                                geometry().top() + ui->code->geometry().bottom());
          ui->code->clear();   // Reset previous text..
          QToolTip::showText(point,"Error Wrong Number Maximum Tries :"+ QString::number(attempt));
          attempt--;

        }else{
          qDebug() << "start timer code";
          ui->verififercode->setEnabled(false);
          current = QDateTime::currentDateTime();
          QSettings settings("Comp","time");
          settings.beginGroup("Time");
          expire = current.addSecs(120);
          settings.setValue("mytime",expire.currentDateTime().addSecs(300));
          settings.endGroup();

          timer = new QTimer(this);
          connect(timer, &QTimer::timeout, this, [&](){
              qDebug()<<"expire : "<<expire;
              qDebug()<<"current : "<<current;
              current = QDateTime::currentDateTime();
              if(expire <= current){
              timer->stop();
              delete timer;
              timer=0;
              attempt=3;
              ui->verififercode->setEnabled(true);
              }
            });
          if(timer!=0)
          timer->start(1000);
        }

    }
}
void activatoncodeclass::update()
{
  qDebug()<<"LOL";
}

QString activatoncodeclass::getEmail() const
{
  return email;
}

void activatoncodeclass::setEmail(const QString &value)
{
  email = value;
}

QString activatoncodeclass::getUname() const
{
  return uname;
}

void activatoncodeclass::setUname(QString value)
{
  uname = value;
}

QString activatoncodeclass::getPass() const
{
  return pass;
}

void activatoncodeclass::setPass(QString value)
{
  pass = value;
}

int activatoncodeclass::getCode() const
{
  return code;
}

void activatoncodeclass::setCode(int value)
{
  code = value;
}


QSqlQuery activatoncodeclass::give(QString mail)
{

    QSqlQuery query;

    query.prepare("select * from EMPLOYES where EMAIL_E= '"+mail+"' ");
    query.exec();
    return query;
}


bool activatoncodeclass::modify(employee& e)
{
    QSqlQuery query;
    QString mail = getEmail();

    query.prepare("update EMPLOYES set MDP_E=:mdp,CONF_MDP_E=:confmdp where EMAIL_E=:mail");
    query.bindValue(":mdp", e.getMDP_E());
    query.bindValue(":confmdp", e.getCONF_MDP_E());
    query.bindValue(":mail", mail);

    return query.exec();
}

void activatoncodeclass::on_modifier_clicked()
{auto plainText = ui->mdp->text();

    DuCrypt crypt;

    ui->lineEdit_nom_2->setText(crypt.encrypt(plainText));
QString password=ui->lineEdit_nom_2->text();

    employee e;
    e.setEMAIL_E(getEmail());
    e.setMDP_E(password);
    e.setCONF_MDP_E(ui->confmdp->text());

    QString password2 = ui->mdp->text();

        QRegExp passwordRegex("^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z]).{8,16}$");
        if (!passwordRegex.exactMatch(password2)) {
            QMessageBox::warning(this, "Error", "mot de pass doit contenir 1 uppercase letter, 1 lowercase letter, 1 digit, et de taille 8 a 16 characters.");
             qDebug() <<"Error mdp" ;
            return;
        }
        /**************************confirme mdp******************/

              QString confirmPassword = ui->confmdp->text();

                  if (password2 != confirmPassword) {
                      QMessageBox::warning(this, "Error", "Password and confirmation password do not match.");
                      qDebug() << "Error confirm mdp";
                      return;
             }
    bool test = modify(e);
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée\n"
                                             "Click cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée\n""Click cancel to exit"), QMessageBox::Cancel);
    }
          activatoncodeclass::close();
}
void activatoncodeclass::checkPassword(const QString &password) {
    if (password.contains(QRegExp("[a-z]"))) {
        ui->label_16->setStyleSheet("color: green;");
    } else {
        ui->label_16->setStyleSheet("color: red;");
    }
    if (password.contains(QRegExp("[A-Z]"))) {
        ui->label_18->setStyleSheet("color: green;");
    } else {
        ui->label_18->setStyleSheet("color: red;");
    }
    if (password.contains(QRegExp("\\d"))) {
        ui->label_17->setStyleSheet("color: green;");
    } else {
        ui->label_17->setStyleSheet("color: red;");
    }
}
