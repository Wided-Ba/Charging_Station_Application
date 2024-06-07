/********************************************************************************
** Form generated from reading UI file 'stock.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCK_H
#define UI_STOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stock
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QTableView *tableView_stock;
    QLabel *label_15;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QLabel *label_11;
    QPushButton *pushButton_del_all;
    QPushButton *pushButton;
    QLabel *label_25;
    QComboBox *comboBox_supp;
    QToolBox *toolBox;
    QWidget *page_3;
    QLabel *label_alerte_3;
    QLabel *label_29;
    QWidget *page_4;
    QLabel *label_alerte_4;
    QLabel *label_30;
    QLabel *label_27;
    QLineEdit *lineEdit_chercher;
    QLabel *label_17;
    QLabel *label;
    QWidget *tab_ajouter;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox_type;
    QLabel *label_10;
    QPushButton *pushButton_ajouter;
    QDoubleSpinBox *doubleSpinBox_prix_achat;
    QPushButton *pushButton_annuler;
    QPushButton *pushButton_image;
    QLabel *label_13;
    QDateEdit *dateEdit;
    QLabel *label_14;
    QTextEdit *textEdit_marque;
    QTextEdit *textEdit_nom;
    QTextEdit *textEdit_reference;
    QSpinBox *spinBox_quantite;
    QWidget *tab_2;
    QLabel *label_18;
    QComboBox *comboBox_type_modif;
    QTextEdit *textEdit_nom_modif;
    QLabel *label_19;
    QLabel *label_20;
    QTextEdit *textEdit_reference_modif;
    QLabel *label_21;
    QPushButton *pushButton_image_2;
    QTextEdit *textEdit_marque_modif;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QDateEdit *dateEdit_modif;
    QDoubleSpinBox *doubleSpinBox_prix_achat_modif;
    QPushButton *pushButton_modifier;
    QLabel *label_26;
    QSpinBox *spinBox_quantite_modif;
    QComboBox *comboBox_modif;
    QWidget *tab;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_4;
    QLabel *label_16;
    QToolBox *toolBox_2;
    QWidget *page_13;
    QLabel *label_37;
    QLabel *label_alerte;
    QWidget *page_14;
    QLabel *label_38;
    QLabel *label_alerte_2;
    QLabel *label_28;
    QLabel *label_stat;
    QLabel *label_stat_2;
    QWidget *page_2;

    void setupUi(QDialog *stock)
    {
        if (stock->objectName().isEmpty())
            stock->setObjectName(QStringLiteral("stock"));
        stock->resize(1280, 720);
        stackedWidget = new QStackedWidget(stock);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1281, 720));
        stackedWidget->setStyleSheet(QStringLiteral("background-image: url(:/Desktop/image/photo2.jpg);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(-20, 0, 1301, 721));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"    position: absolute;\n"
"    top: -0.5em;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar not QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #f"
                        "afafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tableView_stock = new QTableView(tab_5);
        tableView_stock->setObjectName(QStringLiteral("tableView_stock"));
        tableView_stock->setGeometry(QRect(30, 50, 1161, 341));
        tableView_stock->setStyleSheet(QLatin1String("QHeaderView::section {\n"
"	font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"	color:rgb(66,117,102);\n"
"    padding: 4px;\n"
"    border-style: solid ;\n"
"    border-bottom: 2px solid rgb(85, 170, 127) ;\n"
"    border-right: 2px solid rgb(85, 170, 127) ;\n"
"}\n"
"QScrollBar:horizontal {\n"
"    border: 2px solid grey;\n"
"    background: #3f7265;\n"
"    height: 15px;\n"
"    margin: 0px 20px 0 20px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"    background:rgb(238, 238, 238);\n"
"    min-width: 20px;\n"
"}\n"
"QScrollBar::add-line:horizontal {\n"
"    border: 2px solid grey;\n"
"    background: #3f7265;\n"
"    width: 20px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 2px solid grey;\n"
"    background: #3f7265;\n"
"    width: 20px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QTableView {\n"
"    border: 3px solid rgb(85, 170, 127);\n"
"    inner-border: 3px dashed r"
                        "gb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"}"));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 20, 111, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_15->setFont(font1);
        label_15->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(650, 410, 541, 291));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    padding: 0 3px;\n"
"}"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 237, 91, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
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
"}\n"
""));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(50, 170, 61, 61));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/331585408_556456159849722_8965214278401908655_n (1).png")));
        label_11->setScaledContents(true);
        pushButton_del_all = new QPushButton(groupBox);
        pushButton_del_all->setObjectName(QStringLiteral("pushButton_del_all"));
        pushButton_del_all->setGeometry(QRect(320, 30, 151, 31));
        pushButton_del_all->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
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
"}\n"
""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 30, 171, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
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
"}\n"
"\303\211crire \303\240 1 2 HOPPA\n"
""));
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(95, 70, 91, 20));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        label_25->setFont(font2);
        comboBox_supp = new QComboBox(groupBox);
        comboBox_supp->setObjectName(QStringLiteral("comboBox_supp"));
        comboBox_supp->setGeometry(QRect(70, 90, 151, 22));
        comboBox_supp->setStyleSheet(QLatin1String("QComboBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        toolBox = new QToolBox(groupBox);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(170, 150, 361, 131));
        QPalette palette;
        QLinearGradient gradient(0, 0, 1, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(225, 225, 225, 255));
        gradient.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QLinearGradient gradient1(0, 0, 1, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(225, 225, 225, 255));
        gradient1.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient1.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient1.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush1(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QLinearGradient gradient2(0, 0, 1, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(225, 225, 225, 255));
        gradient2.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient2.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient2.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush2(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        QLinearGradient gradient3(0, 0, 1, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(225, 225, 225, 255));
        gradient3.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient3.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient3.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush3(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        QLinearGradient gradient4(0, 0, 1, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(225, 225, 225, 255));
        gradient4.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient4.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient4.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush4(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        QLinearGradient gradient5(0, 0, 1, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(225, 225, 225, 255));
        gradient5.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient5.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient5.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush5(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        QLinearGradient gradient6(0, 0, 1, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(225, 225, 225, 255));
        gradient6.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient6.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient6.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush6(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        QLinearGradient gradient7(0, 0, 1, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(225, 225, 225, 255));
        gradient7.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient7.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient7.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush7(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QLinearGradient gradient8(0, 0, 1, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(225, 225, 225, 255));
        gradient8.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient8.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient8.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush8(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        toolBox->setPalette(palette);
        QFont font3;
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        toolBox->setFont(font3);
        toolBox->setMouseTracking(false);
        toolBox->setTabletTracking(false);
        toolBox->setStyleSheet(QLatin1String("QToolBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"QToolBox ::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QToolBox ::pressed {\n"
" background: rgb(66, 117, 102);\n"
"}\n"
"\n"
"QToolBox ::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QToolBox ::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"\n"
"\n"
""));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 359, 65));
        label_alerte_3 = new QLabel(page_3);
        label_alerte_3->setObjectName(QStringLiteral("label_alerte_3"));
        label_alerte_3->setGeometry(QRect(0, 0, 301, 61));
        label_alerte_3->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_alerte_3->setScaledContents(true);
        label_29 = new QLabel(page_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(300, 0, 61, 61));
        label_29->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_29->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/331430109_901253524357909_6677201790829374939_n.png")));
        label_29->setScaledContents(true);
        toolBox->addItem(page_3, QStringLiteral("Repture de stock"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 359, 65));
        label_alerte_4 = new QLabel(page_4);
        label_alerte_4->setObjectName(QStringLiteral("label_alerte_4"));
        label_alerte_4->setGeometry(QRect(0, 0, 301, 61));
        label_alerte_4->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_alerte_4->setScaledContents(true);
        label_30 = new QLabel(page_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(300, 0, 61, 61));
        label_30->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_30->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/331430109_901253524357909_6677201790829374939_n.png")));
        label_30->setScaledContents(true);
        toolBox->addItem(page_4, QString::fromUtf8("Stock p\303\251rim\303\251s"));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setEnabled(true);
        label_27->setGeometry(QRect(318, 126, 61, 21));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        label_27->setFont(font4);
        label_27->setAcceptDrops(false);
        label_27->setAutoFillBackground(false);
        label_27->setStyleSheet(QLatin1String("QLabel{\n"
"	background:rgb(240, 240, 240);\n"
"  color:rgb(255, 0, 0);\n"
"	}"));
        lineEdit_chercher = new QLineEdit(tab_5);
        lineEdit_chercher->setObjectName(QStringLiteral("lineEdit_chercher"));
        lineEdit_chercher->setGeometry(QRect(950, 10, 221, 41));
        lineEdit_chercher->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QLineEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QLineEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QLineEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QLineEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        label_17 = new QLabel(tab_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1135, 15, 31, 31));
        label_17->setStyleSheet(QLatin1String("QLabel{\n"
"background: qlabelargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"\n"
"\n"
"	}"));
        label_17->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/recherche-a-la-loupe.png")));
        label_17->setScaledContents(true);
        label = new QLabel(tab_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 410, 581, 291));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
""));
        tabWidget->addTab(tab_5, QString());
        tab_ajouter = new QWidget();
        tab_ajouter->setObjectName(QStringLiteral("tab_ajouter"));
        label_6 = new QLabel(tab_ajouter);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 80, 56, 16));
        QFont font5;
        font5.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font5.setPointSize(9);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        label_6->setFont(font5);
        label_6->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_7 = new QLabel(tab_ajouter);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 240, 56, 16));
        label_7->setFont(font5);
        label_7->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_8 = new QLabel(tab_ajouter);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 320, 91, 16));
        label_8->setFont(font5);
        label_8->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_9 = new QLabel(tab_ajouter);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(670, 80, 131, 16));
        label_9->setFont(font5);
        label_9->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        comboBox_type = new QComboBox(tab_ajouter);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setGeometry(QRect(180, 100, 301, 31));
        comboBox_type->setStyleSheet(QLatin1String("QComboBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        label_10 = new QLabel(tab_ajouter);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(180, 160, 56, 16));
        label_10->setFont(font5);
        label_10->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        pushButton_ajouter = new QPushButton(tab_ajouter);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(610, 430, 131, 31));
        pushButton_ajouter->setAutoFillBackground(false);
        pushButton_ajouter->setStyleSheet(QLatin1String("QPushButton{\n"
"background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed{\n"
"background-color: rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background-color:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}\n"
""));
        doubleSpinBox_prix_achat = new QDoubleSpinBox(tab_ajouter);
        doubleSpinBox_prix_achat->setObjectName(QStringLiteral("doubleSpinBox_prix_achat"));
        doubleSpinBox_prix_achat->setGeometry(QRect(670, 100, 301, 31));
        doubleSpinBox_prix_achat->setStyleSheet(QLatin1String("QDoubleSpinBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-style: solid;\n"
"subcontrol-position: top right;\n"
"border-down-width: 1px;\n"
"border-left-width: 1px;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-position: bottom right;\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-up-width: 1px;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, s"
                        "top: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:hover, QDateEdit::down-button:hover {\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QDoubleSpinBox::up-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QDoubleSpinBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        pushButton_annuler = new QPushButton(tab_ajouter);
        pushButton_annuler->setObjectName(QStringLiteral("pushButton_annuler"));
        pushButton_annuler->setGeometry(QRect(440, 430, 131, 31));
        pushButton_annuler->setStyleSheet(QLatin1String("QPushButton{\n"
"background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed{\n"
"background-color: rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background-color:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}\n"
""));
        pushButton_image = new QPushButton(tab_ajouter);
        pushButton_image->setObjectName(QStringLiteral("pushButton_image"));
        pushButton_image->setGeometry(QRect(670, 340, 301, 31));
        QFont font6;
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setWeight(75);
        pushButton_image->setFont(font6);
        pushButton_image->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        label_13 = new QLabel(tab_ajouter);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(670, 160, 131, 16));
        label_13->setFont(font5);
        label_13->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        dateEdit = new QDateEdit(tab_ajouter);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(670, 260, 301, 31));
        dateEdit->setStyleSheet(QLatin1String("QDateEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QDateEdit::up-button {\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-style: solid;\n"
"subcontrol-position: top right;\n"
"border-down-width: 1px;\n"
"border-left-width: 1px;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDateEdit::down-button {\n"
"subcontrol-position: bottom right;\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-up-width: 1px;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0,"
                        " stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDateEdit::up-button:hover, QDateEdit::down-button:hover {\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QDateEdit::up-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDateEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QDateEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        label_14 = new QLabel(tab_ajouter);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(670, 240, 131, 16));
        label_14->setFont(font5);
        label_14->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        textEdit_marque = new QTextEdit(tab_ajouter);
        textEdit_marque->setObjectName(QStringLiteral("textEdit_marque"));
        textEdit_marque->setGeometry(QRect(180, 180, 301, 31));
        textEdit_marque->setStyleSheet(QLatin1String("\n"
"QTextEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QTextEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QTextEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QTextEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QTextEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        textEdit_nom = new QTextEdit(tab_ajouter);
        textEdit_nom->setObjectName(QStringLiteral("textEdit_nom"));
        textEdit_nom->setGeometry(QRect(180, 260, 301, 31));
        textEdit_nom->setStyleSheet(QLatin1String("\n"
"QTextEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QTextEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QTextEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QTextEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QTextEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        textEdit_reference = new QTextEdit(tab_ajouter);
        textEdit_reference->setObjectName(QStringLiteral("textEdit_reference"));
        textEdit_reference->setGeometry(QRect(180, 340, 301, 31));
        textEdit_reference->setStyleSheet(QLatin1String("\n"
"QTextEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QTextEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QTextEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QTextEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QTextEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        spinBox_quantite = new QSpinBox(tab_ajouter);
        spinBox_quantite->setObjectName(QStringLiteral("spinBox_quantite"));
        spinBox_quantite->setGeometry(QRect(670, 180, 301, 31));
        spinBox_quantite->setStyleSheet(QLatin1String("QSpinBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-style: solid;\n"
"subcontrol-position: top right;\n"
"border-down-width: 1px;\n"
"border-left-width: 1px;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"subcontrol-position: bottom right;\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-up-width: 1px;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, st"
                        "op: 1 #d8d8d8);\n"
"}\n"
"\n"
"QSpinBox::up-button:hover, QDateEdit::down-button:hover {\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QSpinBox::up-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QSpinBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QSpinBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        tabWidget->addTab(tab_ajouter, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 80, 56, 16));
        label_18->setFont(font5);
        label_18->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        comboBox_type_modif = new QComboBox(tab_2);
        comboBox_type_modif->setObjectName(QStringLiteral("comboBox_type_modif"));
        comboBox_type_modif->setGeometry(QRect(180, 100, 301, 31));
        comboBox_type_modif->setStyleSheet(QLatin1String("QComboBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        textEdit_nom_modif = new QTextEdit(tab_2);
        textEdit_nom_modif->setObjectName(QStringLiteral("textEdit_nom_modif"));
        textEdit_nom_modif->setGeometry(QRect(180, 260, 301, 31));
        textEdit_nom_modif->setStyleSheet(QLatin1String("\n"
"QTextEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QTextEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QTextEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QTextEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QTextEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(670, 240, 131, 16));
        label_19->setFont(font5);
        label_19->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(180, 320, 91, 16));
        label_20->setFont(font5);
        label_20->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        textEdit_reference_modif = new QTextEdit(tab_2);
        textEdit_reference_modif->setObjectName(QStringLiteral("textEdit_reference_modif"));
        textEdit_reference_modif->setGeometry(QRect(180, 340, 301, 31));
        textEdit_reference_modif->setStyleSheet(QLatin1String("\n"
"QTextEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QTextEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QTextEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QTextEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QTextEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(670, 80, 131, 16));
        label_21->setFont(font5);
        label_21->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        pushButton_image_2 = new QPushButton(tab_2);
        pushButton_image_2->setObjectName(QStringLiteral("pushButton_image_2"));
        pushButton_image_2->setGeometry(QRect(670, 340, 301, 31));
        pushButton_image_2->setFont(font6);
        pushButton_image_2->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        textEdit_marque_modif = new QTextEdit(tab_2);
        textEdit_marque_modif->setObjectName(QStringLiteral("textEdit_marque_modif"));
        textEdit_marque_modif->setGeometry(QRect(180, 180, 301, 31));
        textEdit_marque_modif->setStyleSheet(QLatin1String("\n"
"QTextEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QTextEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QTextEdit::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QTextEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QTextEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(180, 240, 56, 16));
        label_22->setFont(font5);
        label_22->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(180, 160, 56, 16));
        label_23->setFont(font5);
        label_23->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(670, 160, 131, 16));
        label_24->setFont(font5);
        label_24->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        dateEdit_modif = new QDateEdit(tab_2);
        dateEdit_modif->setObjectName(QStringLiteral("dateEdit_modif"));
        dateEdit_modif->setGeometry(QRect(670, 260, 301, 31));
        dateEdit_modif->setStyleSheet(QLatin1String("QDateEdit {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QDateEdit::up-button {\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-style: solid;\n"
"subcontrol-position: top right;\n"
"border-down-width: 1px;\n"
"border-left-width: 1px;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDateEdit::down-button {\n"
"subcontrol-position: bottom right;\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-up-width: 1px;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0,"
                        " stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDateEdit::up-button:hover, QDateEdit::down-button:hover {\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QDateEdit::up-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDateEdit::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QDateEdit::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        doubleSpinBox_prix_achat_modif = new QDoubleSpinBox(tab_2);
        doubleSpinBox_prix_achat_modif->setObjectName(QStringLiteral("doubleSpinBox_prix_achat_modif"));
        doubleSpinBox_prix_achat_modif->setGeometry(QRect(670, 100, 301, 31));
        doubleSpinBox_prix_achat_modif->setStyleSheet(QLatin1String("QDoubleSpinBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-style: solid;\n"
"subcontrol-position: top right;\n"
"border-down-width: 1px;\n"
"border-left-width: 1px;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"subcontrol-position: bottom right;\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-up-width: 1px;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, s"
                        "top: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:hover, QDateEdit::down-button:hover {\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QDoubleSpinBox::up-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QDoubleSpinBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        pushButton_modifier = new QPushButton(tab_2);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(506, 430, 141, 31));
        pushButton_modifier->setStyleSheet(QLatin1String("QPushButton{\n"
"background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"QPushButton:hover:!pressed{\n"
"background-color: rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background-color:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}\n"
"\n"
""));
        label_26 = new QLabel(tab_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(560, 30, 21, 16));
        label_26->setFont(font5);
        label_26->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        spinBox_quantite_modif = new QSpinBox(tab_2);
        spinBox_quantite_modif->setObjectName(QStringLiteral("spinBox_quantite_modif"));
        spinBox_quantite_modif->setGeometry(QRect(670, 180, 301, 31));
        spinBox_quantite_modif->setStyleSheet(QLatin1String("QSpinBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-style: solid;\n"
"subcontrol-position: top right;\n"
"border-down-width: 1px;\n"
"border-left-width: 1px;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"subcontrol-position: bottom right;\n"
"subcontrol-origin: padding;\n"
"border-left-color: gray;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-up-width: 1px;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, st"
                        "op: 1 #d8d8d8);\n"
"}\n"
"\n"
"QSpinBox::up-button:hover, QDateEdit::down-button:hover {\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QSpinBox::up-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QSpinBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QSpinBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
""));
        comboBox_modif = new QComboBox(tab_2);
        comboBox_modif->setObjectName(QStringLiteral("comboBox_modif"));
        comboBox_modif->setGeometry(QRect(535, 50, 81, 31));
        comboBox_modif->setStyleSheet(QLatin1String("QComboBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"background: #c8c8c8;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 30, 271, 21));
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 380, 191, 21));
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;}\n"
""));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(650, 410, 541, 291));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    padding: 0 3px;\n"
"}"));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 50, 161, 28));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
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
"}\n"
""));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 30, 61, 61));
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/331585408_556456159849722_8965214278401908655_n (1).png")));
        label_16->setScaledContents(true);
        toolBox_2 = new QToolBox(groupBox_2);
        toolBox_2->setObjectName(QStringLiteral("toolBox_2"));
        toolBox_2->setGeometry(QRect(170, 150, 361, 131));
        QPalette palette1;
        QLinearGradient gradient9(0, 0, 1, 0);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(225, 225, 225, 255));
        gradient9.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient9.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient9.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush9(gradient9);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QLinearGradient gradient10(0, 0, 1, 0);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(225, 225, 225, 255));
        gradient10.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient10.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient10.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush10(gradient10);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush10);
        QLinearGradient gradient11(0, 0, 1, 0);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(225, 225, 225, 255));
        gradient11.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient11.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient11.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush11(gradient11);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush11);
        QLinearGradient gradient12(0, 0, 1, 0);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(225, 225, 225, 255));
        gradient12.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient12.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient12.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush12(gradient12);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        QLinearGradient gradient13(0, 0, 1, 0);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(225, 225, 225, 255));
        gradient13.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient13.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient13.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush13(gradient13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        QLinearGradient gradient14(0, 0, 1, 0);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(225, 225, 225, 255));
        gradient14.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient14.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient14.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush14(gradient14);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        QLinearGradient gradient15(0, 0, 1, 0);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(225, 225, 225, 255));
        gradient15.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient15.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient15.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush15(gradient15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        QLinearGradient gradient16(0, 0, 1, 0);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(225, 225, 225, 255));
        gradient16.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient16.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient16.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush16(gradient16);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        QLinearGradient gradient17(0, 0, 1, 0);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(225, 225, 225, 255));
        gradient17.setColorAt(0.4, QColor(221, 221, 221, 255));
        gradient17.setColorAt(0.5, QColor(216, 216, 216, 255));
        gradient17.setColorAt(1, QColor(211, 211, 211, 255));
        QBrush brush17(gradient17);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        toolBox_2->setPalette(palette1);
        toolBox_2->setFont(font3);
        toolBox_2->setMouseTracking(false);
        toolBox_2->setTabletTracking(false);
        toolBox_2->setStyleSheet(QLatin1String("QToolBox {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"QToolBox ::hover {\n"
"background: #d0d0d0;\n"
"}\n"
"QToolBox ::pressed {\n"
" background: rgb(66, 117, 102);\n"
"}\n"
"\n"
"QToolBox ::down-arrow {\n"
"width: 0;\n"
"height: 0;\n"
"border-style: solid;\n"
"border-width: 6px 6px 0 6px;\n"
"border-color: gray transparent transparent transparent;\n"
"}\n"
"QToolBox ::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 20px;\n"
"border-left-width: 1px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"\n"
"\n"
""));
        page_13 = new QWidget();
        page_13->setObjectName(QStringLiteral("page_13"));
        page_13->setGeometry(QRect(0, 0, 359, 65));
        label_37 = new QLabel(page_13);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(300, 0, 61, 61));
        label_37->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_37->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/331430109_901253524357909_6677201790829374939_n.png")));
        label_37->setScaledContents(true);
        label_alerte = new QLabel(page_13);
        label_alerte->setObjectName(QStringLiteral("label_alerte"));
        label_alerte->setGeometry(QRect(0, 0, 301, 61));
        label_alerte->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_alerte->setScaledContents(true);
        toolBox_2->addItem(page_13, QStringLiteral("Repture de stock"));
        page_14 = new QWidget();
        page_14->setObjectName(QStringLiteral("page_14"));
        page_14->setGeometry(QRect(0, 0, 359, 65));
        label_38 = new QLabel(page_14);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(300, 0, 61, 61));
        label_38->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_38->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/331430109_901253524357909_6677201790829374939_n.png")));
        label_38->setScaledContents(true);
        label_alerte_2 = new QLabel(page_14);
        label_alerte_2->setObjectName(QStringLiteral("label_alerte_2"));
        label_alerte_2->setGeometry(QRect(0, 0, 301, 61));
        label_alerte_2->setStyleSheet(QLatin1String("QLabel{\n"
"	background: rgb(240, 240, 240);\n"
"	}"));
        label_alerte_2->setScaledContents(true);
        toolBox_2->addItem(page_14, QString::fromUtf8("Stock p\303\251rim\303\251s"));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setEnabled(true);
        label_28->setGeometry(QRect(318, 126, 61, 21));
        label_28->setFont(font4);
        label_28->setAcceptDrops(false);
        label_28->setAutoFillBackground(false);
        label_28->setStyleSheet(QLatin1String("QLabel{\n"
"	background:rgb(240, 240, 240);\n"
"  color:rgb(255, 0, 0);\n"
"	}"));
        label_stat = new QLabel(tab);
        label_stat->setObjectName(QStringLiteral("label_stat"));
        label_stat->setGeometry(QRect(30, 50, 571, 301));
        label_stat->setStyleSheet(QLatin1String("QLabel {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"\n"
""));
        label_stat_2 = new QLabel(tab);
        label_stat_2->setObjectName(QStringLiteral("label_stat_2"));
        label_stat_2->setGeometry(QRect(30, 400, 571, 301));
        label_stat_2->setStyleSheet(QLatin1String("QLabel {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"\n"
""));
        tabWidget->addTab(tab, QString());
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(stock);

        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(1);
        toolBox->layout()->setSpacing(8);
        toolBox_2->setCurrentIndex(1);
        toolBox_2->layout()->setSpacing(8);


        QMetaObject::connectSlotsByName(stock);
    } // setupUi

    void retranslateUi(QDialog *stock)
    {
        stock->setWindowTitle(QApplication::translate("stock", "Dialog", Q_NULLPTR));
        label_15->setText(QApplication::translate("stock", "Stocks:", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("stock", "Fonctionnalit\303\251 et notification:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("stock", "Generer PDF", Q_NULLPTR));
        label_11->setText(QString());
        pushButton_del_all->setText(QApplication::translate("stock", "Supprimer tout", Q_NULLPTR));
        pushButton->setText(QApplication::translate("stock", "Supprimer", Q_NULLPTR));
        label_25->setText(QApplication::translate("stock", "ID a supprim\303\251:", Q_NULLPTR));
        label_alerte_3->setText(QString());
        label_29->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("stock", "Repture de stock", Q_NULLPTR));
        label_alerte_4->setText(QString());
        label_30->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("stock", "Stock p\303\251rim\303\251s", Q_NULLPTR));
        label_27->setText(QApplication::translate("stock", "Alerte", Q_NULLPTR));
        label_17->setText(QString());
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("stock", "Afficher_stock", Q_NULLPTR));
        label_6->setText(QApplication::translate("stock", "Type", Q_NULLPTR));
        label_7->setText(QApplication::translate("stock", "Nom", Q_NULLPTR));
        label_8->setText(QApplication::translate("stock", "R\303\251f\303\251rence", Q_NULLPTR));
        label_9->setText(QApplication::translate("stock", "Prix_achat", Q_NULLPTR));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("stock", "HuileSynthetque", Q_NULLPTR)
         << QApplication::translate("stock", "HuileMinerale", Q_NULLPTR)
         << QApplication::translate("stock", "Cafe", Q_NULLPTR)
         << QApplication::translate("stock", "Cake", Q_NULLPTR)
         << QApplication::translate("stock", "Sucre", Q_NULLPTR)
         << QApplication::translate("stock", "Biscuit", Q_NULLPTR)
         << QApplication::translate("stock", "Eau", Q_NULLPTR)
         << QApplication::translate("stock", "Jus", Q_NULLPTR)
         << QApplication::translate("stock", "Papier", Q_NULLPTR)
         << QApplication::translate("stock", "Chocolat", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("stock", "Marque", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("stock", "Valid\303\251", Q_NULLPTR));
        pushButton_annuler->setText(QApplication::translate("stock", "Annuler", Q_NULLPTR));
        pushButton_image->setText(QApplication::translate("stock", "Ajouter image", Q_NULLPTR));
        label_13->setText(QApplication::translate("stock", "Quantite", Q_NULLPTR));
        label_14->setText(QApplication::translate("stock", "Date_fin_delais", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_ajouter), QApplication::translate("stock", "Ajouter_stock", Q_NULLPTR));
        label_18->setText(QApplication::translate("stock", "Type", Q_NULLPTR));
        comboBox_type_modif->clear();
        comboBox_type_modif->insertItems(0, QStringList()
         << QApplication::translate("stock", "HuileSynthetque", Q_NULLPTR)
         << QApplication::translate("stock", "HuileMinerale", Q_NULLPTR)
         << QApplication::translate("stock", "Cafe", Q_NULLPTR)
         << QApplication::translate("stock", "Cake", Q_NULLPTR)
         << QApplication::translate("stock", "Sucre", Q_NULLPTR)
         << QApplication::translate("stock", "Biscuit", Q_NULLPTR)
         << QApplication::translate("stock", "Eau", Q_NULLPTR)
         << QApplication::translate("stock", "Jus", Q_NULLPTR)
         << QApplication::translate("stock", "Papier", Q_NULLPTR)
         << QApplication::translate("stock", "Chocolat", Q_NULLPTR)
        );
        label_19->setText(QApplication::translate("stock", "Date_fin_delais", Q_NULLPTR));
        label_20->setText(QApplication::translate("stock", "R\303\251f\303\251rence", Q_NULLPTR));
        label_21->setText(QApplication::translate("stock", "Prix_achat", Q_NULLPTR));
        pushButton_image_2->setText(QApplication::translate("stock", "Ajouter image", Q_NULLPTR));
        label_22->setText(QApplication::translate("stock", "Nom", Q_NULLPTR));
        label_23->setText(QApplication::translate("stock", "Marque", Q_NULLPTR));
        label_24->setText(QApplication::translate("stock", "Quantite", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("stock", "Modifier", Q_NULLPTR));
        label_26->setText(QApplication::translate("stock", "Id", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("stock", "Modifier_stock", Q_NULLPTR));
        label_2->setText(QApplication::translate("stock", "Stock Caf\303\251 :", Q_NULLPTR));
        label_3->setText(QApplication::translate("stock", "Stock Huile :", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("stock", "Fonctionnalit\303\251 et notification:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("stock", "Generer PDF", Q_NULLPTR));
        label_16->setText(QString());
        label_37->setText(QString());
        label_alerte->setText(QString());
        toolBox_2->setItemText(toolBox_2->indexOf(page_13), QApplication::translate("stock", "Repture de stock", Q_NULLPTR));
        label_38->setText(QString());
        label_alerte_2->setText(QString());
        toolBox_2->setItemText(toolBox_2->indexOf(page_14), QApplication::translate("stock", "Stock p\303\251rim\303\251s", Q_NULLPTR));
        label_28->setText(QApplication::translate("stock", "Alerte", Q_NULLPTR));
        label_stat->setText(QString());
        label_stat_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("stock", "Etude_stock", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stock: public Ui_stock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCK_H
