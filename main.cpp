#include "login.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test = c.createconnect();
/*********************************************/
    reglage r;
       profil w;
       login l;
       bool hasExecuted = false;

       QTimer timer;
       int inactivityCounter = 0;
       int maxInactivity = 0; // Seuil de 60 secondes

       QObject::connect(&timer, &QTimer::timeout, [&]() {
           if (!hasExecuted && inactivityCounter == maxInactivity) {

               QTime current_time = QTime::currentTime();
                   int hour = current_time.hour();
                   if (hour >= 8 && hour < 17){
               r.on_radioButton_clicked(false);}
                   else{
               r.on_radioButton_clicked(true);}

               hasExecuted = true;
           }
       });

       timer.start(200); // Vérifier l'activité toutes les secondes

       // Connecter les signaux de souris pour réinitialiser le compteur
       a.installEventFilter(&l);
       QObject::connect(&a, &QApplication::focusChanged, [&](QWidget* old, QWidget* now) {
           Q_UNUSED(old);
           Q_UNUSED(now);
           inactivityCounter = 0; // Réinitialiser le compteur
       });

       // Initialiser un timer pour vérifier si l'application est inactive
           QTimer timer2;
           int inactivityCounter2 = 0;
           int maxInactivity2 = 180; // Seuil de 60 secondes
           QObject::connect(&timer2, &QTimer::timeout, [&]() {
               if (++inactivityCounter2 > maxInactivity2) {
                   a.quit(); // Fermer l'application
               }
           });
           timer2.start(1000); // Vérifier l'activité toutes les secondes

           // Connecter les signaux de souris pour réinitialiser le compteur
           a.installEventFilter(&l);
           QObject::connect(&a, &QApplication::focusChanged, [&](QWidget* old, QWidget* now) {
               Q_UNUSED(old);
               Q_UNUSED(now);
               inactivityCounter2 = 0; // Réinitialiser le compteur
           });
           /*********************/

    // Load translation
    QTranslator t;
    QStringList languages;
    languages << "Francais" << "English";
    QString lang ;


    // Apply custom style sheet to input dialog
    QDialog dialog;
    dialog.setWindowTitle("Choix du langage");
    dialog.setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    dialog.setStyleSheet("QDialog { background-image: url(:/ICON/photo2.jpg); border-radius: 10px; } \
                          QLabel { font-size: 16px; font-weight: bold; color: #444; margin-bottom: 10px; } \
                          QComboBox { background-color: #f8f8f8; border: none; border-radius: 5px; padding: 5px; \
                                      font-size: 14px; color: #444; } \
                          QComboBox::drop-down { width: 25px; height: 25px; } \
                          QComboBox::down-arrow { image: url(:/ICON/traduire.png); width: 20px; height: 20px; } \
                          QPushButton { background-color: #f8f8f8; border: none; border-radius: 5px; padding: 8px; \
                                        font-size: 14px; color: #444; } \
                          QPushButton:hover { background-color: #eee; }");

    QLabel label("Choix du langage:");
    QComboBox combo;
    combo.addItems(languages);
    combo.setCurrentText(lang);
    QPushButton button("OK");

    QVBoxLayout layout(&dialog);
    layout.addWidget(&label);
    layout.addWidget(&combo);
    layout.addWidget(&button);
    layout.setMargin(20);
    layout.setSpacing(10);

    QObject::connect(&button, &QPushButton::clicked, &dialog, &QDialog::accept);

    if (dialog.exec() == QDialog::Accepted) {
        lang = combo.currentText();
        if (lang == "English")
        {
            t.load(":/anglais.qm");
        }
        if (lang != "Francais")
        {
            a.installTranslator(&t);
        }
    }



    if (test) {
        l.show();
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
            QObject::tr("Connection failed.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
