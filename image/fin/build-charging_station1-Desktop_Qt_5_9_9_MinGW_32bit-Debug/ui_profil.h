/********************************************************************************
** Form generated from reading UI file 'profil.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFIL_H
#define UI_PROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profil
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_10;
    QPushButton *pushButton_profil;
    QPushButton *pushButton_client;
    QPushButton *pushButton_employee;
    QPushButton *pushButton_station;
    QPushButton *pushButton_service;
    QPushButton *pushButton_stock;
    QPushButton *pushButton_quitter;
    QPushButton *pushButton_reglage;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *profil)
    {
        if (profil->objectName().isEmpty())
            profil->setObjectName(QStringLiteral("profil"));
        profil->resize(1304, 763);
        profil->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(profil);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(79, 0, 1231, 720));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_10 = new QLabel(page);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 0, 1231, 720));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/image/photo.jpg")));
        label_10->setScaledContents(true);
        stackedWidget->addWidget(page);
        pushButton_profil = new QPushButton(centralwidget);
        pushButton_profil->setObjectName(QStringLiteral("pushButton_profil"));
        pushButton_profil->setGeometry(QRect(0, 80, 81, 81));
        pushButton_profil->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/ICON/profil.png);\n"
"qproperty-iconSize:42px 50px;\n"
"background-color:rgb(221,222,217);\n"
"\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}\n"
"\n"
""));
        pushButton_client = new QPushButton(centralwidget);
        pushButton_client->setObjectName(QStringLiteral("pushButton_client"));
        pushButton_client->setGeometry(QRect(0, 160, 81, 81));
        pushButton_client->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/ICON/326255698_1163241431028162_7304178811197381155_n.png);\n"
"qproperty-iconSize:48px 50px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}\n"
""));
        pushButton_employee = new QPushButton(centralwidget);
        pushButton_employee->setObjectName(QStringLiteral("pushButton_employee"));
        pushButton_employee->setGeometry(QRect(0, 240, 81, 81));
        pushButton_employee->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/new/prefix1/ICON/278261042_5242060219164606_8744602465667434102_n.png);\n"
"qproperty-iconSize:46px 50px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}"));
        pushButton_station = new QPushButton(centralwidget);
        pushButton_station->setObjectName(QStringLiteral("pushButton_station"));
        pushButton_station->setGeometry(QRect(0, 320, 81, 81));
        pushButton_station->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/ICON/326421902_3390623604598503_20181722436645681_n.png);\n"
"qproperty-iconSize:47px 50px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}"));
        pushButton_service = new QPushButton(centralwidget);
        pushButton_service->setObjectName(QStringLiteral("pushButton_service"));
        pushButton_service->setGeometry(QRect(0, 400, 81, 81));
        pushButton_service->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/new/prefix1/ICON/278717090_465620745314700_6179097996270868039_n.png);\n"
"qproperty-iconSize:50px 50px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}"));
        pushButton_stock = new QPushButton(centralwidget);
        pushButton_stock->setObjectName(QStringLiteral("pushButton_stock"));
        pushButton_stock->setGeometry(QRect(0, 480, 81, 81));
        pushButton_stock->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/ICON/326132086_1377220566362323_2334973245028434171_n.png);\n"
"qproperty-iconSize:50px 50px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}\n"
"\n"
""));
        pushButton_quitter = new QPushButton(centralwidget);
        pushButton_quitter->setObjectName(QStringLiteral("pushButton_quitter"));
        pushButton_quitter->setGeometry(QRect(0, 640, 81, 81));
        pushButton_quitter->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/new/prefix1/ICON/331021796_4060633687495639_3024885960259443867_n.png);\n"
"qproperty-iconSize:38px 40px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}"));
        pushButton_reglage = new QPushButton(centralwidget);
        pushButton_reglage->setObjectName(QStringLiteral("pushButton_reglage"));
        pushButton_reglage->setGeometry(QRect(0, 560, 81, 81));
        pushButton_reglage->setStyleSheet(QLatin1String("QPushButton{\n"
"qproperty-icon:url(:/ICON/326253185_1247096072879450_2122464190835713788_n.png);\n"
"qproperty-iconSize:44px 44px;\n"
"background-color:rgb(221,222,217);\n"
"}\n"
"QPushButton:hover:!pressed{  background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(66, 117, 102, 255), stop:1 rgba(255, 255, 255, 255));}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-6, -3, 91, 91));
        label->setStyleSheet(QStringLiteral("background-color:rgb(221,222,217);"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/image/hhg (1).png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(16, 540, 71, 20));
        label_2->setStyleSheet(QLatin1String("\n"
"font: 87 8pt \"Segoe UI Black\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(4, 460, 71, 20));
        label_3->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(4, 380, 81, 21));
        label_4->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(3, 300, 81, 20));
        label_5->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(5, 220, 61, 20));
        label_6->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(18, 140, 71, 20));
        label_7->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(11, 620, 101, 20));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Black"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(10);
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(5, 700, 71, 21));
        label_9->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        profil->setCentralWidget(centralwidget);
        pushButton_profil->raise();
        pushButton_client->raise();
        pushButton_employee->raise();
        pushButton_station->raise();
        pushButton_service->raise();
        pushButton_stock->raise();
        pushButton_reglage->raise();
        stackedWidget->raise();
        pushButton_quitter->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        menubar = new QMenuBar(profil);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1304, 26));
        profil->setMenuBar(menubar);
        statusbar = new QStatusBar(profil);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        profil->setStatusBar(statusbar);

        retranslateUi(profil);

        QMetaObject::connectSlotsByName(profil);
    } // setupUi

    void retranslateUi(QMainWindow *profil)
    {
        profil->setWindowTitle(QApplication::translate("profil", "profil", Q_NULLPTR));
        label_10->setText(QString());
        pushButton_profil->setText(QString());
        pushButton_client->setText(QString());
        pushButton_employee->setText(QString());
        pushButton_station->setText(QString());
        pushButton_service->setText(QString());
        pushButton_stock->setText(QString());
        pushButton_quitter->setText(QString());
        pushButton_reglage->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("profil", " STOCK", Q_NULLPTR));
        label_3->setText(QApplication::translate("profil", "   SERVICE", Q_NULLPTR));
        label_4->setText(QApplication::translate("profil", "  STATION", Q_NULLPTR));
        label_5->setText(QApplication::translate("profil", " EMPLOYEE", Q_NULLPTR));
        label_6->setText(QApplication::translate("profil", "    CLIENT", Q_NULLPTR));
        label_7->setText(QApplication::translate("profil", "PROFIL", Q_NULLPTR));
        label_8->setText(QApplication::translate("profil", "REGLAGE", Q_NULLPTR));
        label_9->setText(QApplication::translate("profil", "  QUITTER", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class profil: public Ui_profil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFIL_H
