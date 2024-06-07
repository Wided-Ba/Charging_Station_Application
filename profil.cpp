#include "profil.h"
#include "ui_profil.h"

profil::profil(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::profil)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1,&C);
    ui->stackedWidget->insertWidget(2,&E);
    ui->stackedWidget->insertWidget(3,&ST);
    ui->stackedWidget->insertWidget(4,&S);
    ui->stackedWidget->insertWidget(5,&SCK);
    ui->stackedWidget->insertWidget(6,&R);

        ui->label_10->setObjectName("photo");
        ui->label->setObjectName("logo");
        ui->pushButton_profil->setObjectName("profil");
        ui->pushButton_client->setObjectName("client");
        ui->pushButton_employee->setObjectName("employee");
        ui->pushButton_station->setObjectName("station");
        ui->pushButton_service->setObjectName("service");
        ui->pushButton_stock->setObjectName("stock");
        ui->pushButton_reglage->setObjectName("reglager");
        ui->pushButton_quitter->setObjectName("quitter");
        ui->label_7->setObjectName("profilLABEL");
        ui->label_6->setObjectName("clientLABEL");
        ui->label_5->setObjectName("employeeLABEL");
        ui->label_4->setObjectName("stationLABEL");
        ui->label_3->setObjectName("serviceLABEL");
        ui->label_2->setObjectName("stockLABEL");
        ui->label_8->setObjectName("reglageLABEL");
        ui->label_9->setObjectName("quitterLABEL");

}

profil::~profil()
{
    delete ui;
}


void profil::on_pushButton_profil_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: rgb(66,117,102) }");



ui->pushButton_client->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_station->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_service->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: }");

ui->pushButton_client->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_employee->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_station->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_service->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_stock->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_reglage->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");


}

void profil::on_pushButton_client_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_client->setStyleSheet("QPushButton{ background-color: rgb(66,117,102)}");
ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_station->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_service->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: }");

ui->pushButton_profil->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_employee->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_station->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_service->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_stock->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_reglage->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");

}

void profil::on_pushButton_employee_clicked()
{
ui->stackedWidget->setCurrentIndex(2);
ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_client->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:rgb(66,117,102) }");
ui->pushButton_station->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_service->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: }");

ui->pushButton_profil->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_client->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_station->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_service->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_stock->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_reglage->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");

}

void profil::on_pushButton_station_clicked()
{
ui->stackedWidget->setCurrentIndex(3);
ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_client->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_station->setStyleSheet("QPushButton{ background-color:rgb(66,117,102)   }");
ui->pushButton_service->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_profil->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_employee->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_client->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_service->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_stock->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_reglage->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");

}

void profil::on_pushButton_service_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_client->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_station->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_service->setStyleSheet("QPushButton{ background-color:rgb(66,117,102) }");
ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_profil->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_employee->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_station->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_client->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_stock->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_reglage->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");

}

void profil::on_pushButton_stock_clicked()
{
ui->stackedWidget->setCurrentIndex(5);
ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_client->setStyleSheet("QPushButton{ background-color:   }");
ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_station->setStyleSheet("QPushButton{ background-color:  }");
ui->pushButton_service->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: rgb(66,117,102)}");
ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: }");
ui->pushButton_profil->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_employee->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_station->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_service->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_client->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
ui->pushButton_reglage->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");

}

void profil::on_pushButton_reglage_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->pushButton_profil->setStyleSheet("QPushButton{ background-color: }");
    ui->pushButton_client->setStyleSheet("QPushButton{ background-color:  }");
    ui->pushButton_employee->setStyleSheet("QPushButton{ background-color:  }");
    ui->pushButton_station->setStyleSheet("QPushButton{ background-color:  }");
    ui->pushButton_service->setStyleSheet("QPushButton{ background-color: }");
    ui->pushButton_stock->setStyleSheet("QPushButton{ background-color: }");
    ui->pushButton_quitter->setStyleSheet("QPushButton{ background-color: }");
    ui->pushButton_reglage->setStyleSheet("QPushButton{ background-color: rgb(66,117,102)}");
    ui->pushButton_profil->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
    ui->pushButton_employee->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
    ui->pushButton_station->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
    ui->pushButton_service->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
    ui->pushButton_stock->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
    ui->pushButton_quitter->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");
    ui->pushButton_client->setStyleSheet("QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}");

}

void profil::on_pushButton_quitter_clicked()
{ 
    QMessageBox::StandardButton reply = QMessageBox::warning(this,
                                          "Confirmation", "Voulez-vous quitter?",
                                 QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes) {
               QApplication::quit();
           } else {
          }

}


