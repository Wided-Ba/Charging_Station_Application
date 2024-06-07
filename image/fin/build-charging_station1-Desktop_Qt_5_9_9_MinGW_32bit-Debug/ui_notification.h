/********************************************************************************
** Form generated from reading UI file 'notification.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATION_H
#define UI_NOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_notification
{
public:
    QFrame *frame;
    QLabel *label;

    void setupUi(QDialog *notification)
    {
        if (notification->objectName().isEmpty())
            notification->setObjectName(QStringLiteral("notification"));
        notification->resize(358, 101);
        frame = new QFrame(notification);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, -20, 431, 121));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 341, 71));
        QFont font;
        font.setPointSize(7);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(notification);

        QMetaObject::connectSlotsByName(notification);
    } // setupUi

    void retranslateUi(QDialog *notification)
    {
        notification->setWindowTitle(QApplication::translate("notification", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("notification", "fait attention s'il vous plait ilya une panne dans l'avion", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class notification: public Ui_notification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATION_H
