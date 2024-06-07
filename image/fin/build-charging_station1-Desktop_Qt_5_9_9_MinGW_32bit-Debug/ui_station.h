/********************************************************************************
** Form generated from reading UI file 'station.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATION_H
#define UI_STATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_station
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QRadioButton *radioButton;
    QWidget *page_2;

    void setupUi(QDialog *station)
    {
        if (station->objectName().isEmpty())
            station->setObjectName(QStringLiteral("station"));
        station->resize(1280, 720);
        stackedWidget = new QStackedWidget(station);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(79, 0, 1231, 720));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(390, 190, 291, 251));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(station);

        QMetaObject::connectSlotsByName(station);
    } // setupUi

    void retranslateUi(QDialog *station)
    {
        station->setWindowTitle(QApplication::translate("station", "Dialog", Q_NULLPTR));
        radioButton->setText(QApplication::translate("station", "RadioButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class station: public Ui_station {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATION_H
