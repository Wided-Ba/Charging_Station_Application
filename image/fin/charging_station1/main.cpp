#include "profil.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
     bool test=c.createconnection();
     profil w;
     if(test)
        {w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();

}
