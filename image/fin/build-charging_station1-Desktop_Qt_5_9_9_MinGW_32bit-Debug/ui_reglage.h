/********************************************************************************
** Form generated from reading UI file 'reglage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGLAGE_H
#define UI_REGLAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reglage
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *horizontalSlider;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QWidget *page_2;

    void setupUi(QDialog *reglage)
    {
        if (reglage->objectName().isEmpty())
            reglage->setObjectName(QStringLiteral("reglage"));
        reglage->resize(1280, 720);
        stackedWidget = new QStackedWidget(reglage);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1280, 720));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        stackedWidget->setFont(font);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 350, 191, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Black"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"qproperty-alignment:AlignCenter;}"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 230, 161, 61));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"qproperty-alignment:AlignCenter;}"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 90, 221, 111));
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"qproperty-alignment:AlignCenter;\n"
"\n"
"}"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 350, 51, 51));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/image/330953609_1363978417769239_3908717119407741196_n.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 240, 51, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/image/271710699_646667173187007_1832342790172260621_n.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 130, 61, 41));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/image/251106676_1250940875319675_4710313500520744316_n.png")));
        label_6->setScaledContents(true);
        horizontalSlider = new QSlider(page);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(550, 240, 511, 41));
        horizontalSlider->setStyleSheet(QStringLiteral(""));
        horizontalSlider->setOrientation(Qt::Horizontal);
        comboBox = new QComboBox(page);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(720, 130, 151, 41));
        comboBox->setStyleSheet(QLatin1String("QComboBox{\n"
" background-color: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"}\n"
""));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(640, 360, 111, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
" background-color: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"}\n"
"QPushButton:enabled{\n"
" background-color: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed{\n"
" background-color:   rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background-color:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(860, 360, 121, 41));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
" background-color: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"}\n"
"QPushButton:enabled{\n"
" background-color: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed{\n"
" background-color: rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background-color:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 1280, 720));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/image/photo2.jpg")));
        label_7->setScaledContents(true);
        stackedWidget->addWidget(page);
        label_7->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        horizontalSlider->raise();
        comboBox->raise();
        pushButton->raise();
        pushButton_2->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(reglage);

        QMetaObject::connectSlotsByName(reglage);
    } // setupUi

    void retranslateUi(QDialog *reglage)
    {
        reglage->setWindowTitle(QApplication::translate("reglage", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("reglage", "Mode :", Q_NULLPTR));
        label_2->setText(QApplication::translate("reglage", "Son :", Q_NULLPTR));
        label_3->setText(QApplication::translate("reglage", "Langage :", Q_NULLPTR));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("reglage", "Fran\303\247ais", Q_NULLPTR)
         << QApplication::translate("reglage", "Anglais", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("reglage", "Jour", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("reglage", "Nuit", Q_NULLPTR));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class reglage: public Ui_reglage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGLAGE_H
