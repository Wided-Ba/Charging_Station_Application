/********************************************************************************
** Form generated from reading UI file 'service.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_H
#define UI_SERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_13;
    QTableView *tab_recent_sr;
    QWidget *tab_2;
    QComboBox *ComboBox_type_sr;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *le_quantite_sr;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pb_ajouter_sr;
    QDoubleSpinBox *db_prix_sr;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLabel *label_10;
    QLabel *label_14;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_4;
    QLabel *label_17;
    QPushButton *pushButton_6;
    QLabel *label_19;
    QPushButton *pushButton_supp;
    QComboBox *ComboBox_id_sr;
    QTableView *tab_recent_cafe;
    QWidget *tab_4;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_11;
    QLabel *label_15;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_7;
    QLabel *label_20;
    QPushButton *pushButton_8;
    QLabel *label_21;
    QPushButton *pushButton_27;
    QComboBox *ComboBox_type_sr_9;
    QTableView *tab_recent_lavage;
    QWidget *tab_5;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_12;
    QLabel *label_16;
    QGroupBox *groupBox_7;
    QPushButton *pushButton_5;
    QLabel *label_18;
    QPushButton *pushButton_9;
    QLabel *label_22;
    QPushButton *pushButton_28;
    QComboBox *ComboBox_type_sr_10;
    QTableView *tab_recent_entretien;
    QWidget *tab_6;
    QDoubleSpinBox *db_prix_sr_2;
    QLabel *label_23;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QComboBox *ComboBox_type_sr_2;
    QLineEdit *le_quantite_sr_2;
    QLabel *label_24;
    QPushButton *pb_ajouter_sr_2;

    void setupUi(QDialog *service)
    {
        if (service->objectName().isEmpty())
            service->setObjectName(QStringLiteral("service"));
        service->resize(1280, 720);
        stackedWidget = new QStackedWidget(service);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1231, 720));
        stackedWidget->setStyleSheet(QStringLiteral("background-image: url(:/Downloads/photo2.jpg);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1231, 720));
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
"    it reads QTabBar _not_ QTabWidget */\n"
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
"                                stop: 0.5 #e7e7e7, stop: 1.0 "
                        "#fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 450, 490, 230));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QLabel::title {\n"
"    subcontrol-origin: margin;\n"
"    padding: 0 3px;\n"
"}"));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images.png")));
        label->setScaledContents(true);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(710, 450, 450, 230));
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
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 60, 231, 31));
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 14pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 120, 231, 31));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 14pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 190, 291, 21));
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 14pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(70, 20, 191, 21));
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1020, 9, 141, 31));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331307335_580804193677575_966179827642562636_n.png")));
        label_13->setScaledContents(true);
        tab_recent_sr = new QTableView(tab);
        tab_recent_sr->setObjectName(QStringLiteral("tab_recent_sr"));
        tab_recent_sr->setGeometry(QRect(70, 40, 1091, 381));
        tab_recent_sr->setStyleSheet(QLatin1String("QHeaderView::section {\n"
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        ComboBox_type_sr = new QComboBox(tab_2);
        ComboBox_type_sr->setObjectName(QStringLiteral("ComboBox_type_sr"));
        ComboBox_type_sr->setGeometry(QRect(480, 80, 161, 31));
        ComboBox_type_sr->setStyleSheet(QLatin1String("QComboBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 40, 101, 31));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 9pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(480, 150, 201, 31));
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 9pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        le_quantite_sr = new QLineEdit(tab_2);
        le_quantite_sr->setObjectName(QStringLiteral("le_quantite_sr"));
        le_quantite_sr->setGeometry(QRect(480, 190, 161, 22));
        le_quantite_sr->setStyleSheet(QLatin1String("QLineEdit {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QLineEdit::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QLineEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QLineEdit::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QLineEdit::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(480, 260, 81, 31));
        label_5->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 9pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 440, 151, 31));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"}\n"
"QPushButton:enabled{\n"
" backgroundr: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"QPushButton:pressed{\n"
" background: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed{\n"
" background:   rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}"));
        pb_ajouter_sr = new QPushButton(tab_2);
        pb_ajouter_sr->setObjectName(QStringLiteral("pb_ajouter_sr"));
        pb_ajouter_sr->setGeometry(QRect(610, 440, 151, 31));
        pb_ajouter_sr->setFont(font);
        pb_ajouter_sr->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
"}\n"
"\n"
""));
        db_prix_sr = new QDoubleSpinBox(tab_2);
        db_prix_sr->setObjectName(QStringLiteral("db_prix_sr"));
        db_prix_sr->setGeometry(QRect(480, 300, 161, 31));
        db_prix_sr->setStyleSheet(QLatin1String("QDoubleSpinBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"    subcontrol-origin: padding;\n"
"    border-left-color: gray;\n"
"    width: 20px;\n"
"    border-left-style: solid;\n"
"    subcontrol-position: top right;\n"
"    border-down-width: 1px;\n"
"    border-left-width: 1px;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"    subcontrol-position: bottom right;\n"
"    subcontrol-origin: padding;\n"
"    border-left-color: gray;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-up-width: 1px;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius:"
                        " 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:hover, QDateEdit::down-button:hover {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QDoubleSpinBox::up-arrow {\n"
"        width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"QDoubleSpinBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(70, 450, 450, 230));
        groupBox_4->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    padding: 0 3px;\n"
"}"));
        checkBox_5 = new QCheckBox(groupBox_4);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(70, 70, 150, 20));
        checkBox_5->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"\n"
""));
        checkBox_6 = new QCheckBox(groupBox_4);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(70, 140, 150, 20));
        checkBox_6->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
""));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 20, 190, 20));
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(1020, 9, 141, 31));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331307335_580804193677575_966179827642562636_n.png")));
        label_14->setScaledContents(true);
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(710, 450, 450, 230));
        groupBox_6->setStyleSheet(QLatin1String("QGroupBox {\n"
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
        pushButton_4 = new QPushButton(groupBox_6);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(90, 40, 186, 31));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 30, 51, 51));
        label_17->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331585408_556456159849722_8965214278401908655_n (1).png")));
        label_17->setScaledContents(true);
        pushButton_6 = new QPushButton(groupBox_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(90, 120, 186, 31));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 110, 51, 51));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/calendar (1).png")));
        label_19->setScaledContents(true);
        pushButton_supp = new QPushButton(groupBox_6);
        pushButton_supp->setObjectName(QStringLiteral("pushButton_supp"));
        pushButton_supp->setGeometry(QRect(240, 180, 186, 31));
        pushButton_supp->setFont(font);
        pushButton_supp->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        ComboBox_id_sr = new QComboBox(groupBox_6);
        ComboBox_id_sr->setObjectName(QStringLiteral("ComboBox_id_sr"));
        ComboBox_id_sr->setGeometry(QRect(30, 180, 161, 31));
        ComboBox_id_sr->setStyleSheet(QLatin1String("QComboBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        tab_recent_cafe = new QTableView(tab_3);
        tab_recent_cafe->setObjectName(QStringLiteral("tab_recent_cafe"));
        tab_recent_cafe->setGeometry(QRect(70, 40, 1091, 381));
        tab_recent_cafe->setStyleSheet(QLatin1String("QHeaderView::section {\n"
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
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(70, 450, 450, 230));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    padding: 0 3px;\n"
"}"));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(70, 70, 150, 20));
        checkBox_3->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"\n"
""));
        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(70, 140, 150, 20));
        checkBox_4->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
""));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(70, 20, 190, 20));
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1020, 9, 141, 31));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331307335_580804193677575_966179827642562636_n.png")));
        label_15->setScaledContents(true);
        groupBox_8 = new QGroupBox(tab_4);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(710, 450, 450, 230));
        groupBox_8->setStyleSheet(QLatin1String("QGroupBox {\n"
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
        pushButton_7 = new QPushButton(groupBox_8);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(90, 40, 186, 31));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        label_20 = new QLabel(groupBox_8);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 30, 51, 51));
        label_20->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331585408_556456159849722_8965214278401908655_n (1).png")));
        label_20->setScaledContents(true);
        pushButton_8 = new QPushButton(groupBox_8);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(90, 120, 186, 31));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 110, 51, 51));
        label_21->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/calendar (1).png")));
        label_21->setScaledContents(true);
        pushButton_27 = new QPushButton(groupBox_8);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(240, 180, 186, 31));
        pushButton_27->setFont(font);
        pushButton_27->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        ComboBox_type_sr_9 = new QComboBox(groupBox_8);
        ComboBox_type_sr_9->setObjectName(QStringLiteral("ComboBox_type_sr_9"));
        ComboBox_type_sr_9->setGeometry(QRect(30, 180, 161, 31));
        ComboBox_type_sr_9->setStyleSheet(QLatin1String("QComboBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        tab_recent_lavage = new QTableView(tab_4);
        tab_recent_lavage->setObjectName(QStringLiteral("tab_recent_lavage"));
        tab_recent_lavage->setGeometry(QRect(70, 40, 1091, 381));
        tab_recent_lavage->setStyleSheet(QLatin1String("QHeaderView::section {\n"
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
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(70, 450, 450, 230));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 3px dashed rgb(85, 170, 127);\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    padding: 0 3px;\n"
"}"));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(70, 70, 150, 20));
        checkBox->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"\n"
""));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(70, 140, 150, 20));
        checkBox_2->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color: #333;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
""));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(70, 20, 190, 20));
        label_12->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_16 = new QLabel(tab_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1020, 9, 141, 31));
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331307335_580804193677575_966179827642562636_n.png")));
        label_16->setScaledContents(true);
        groupBox_7 = new QGroupBox(tab_5);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(710, 450, 450, 230));
        groupBox_7->setStyleSheet(QLatin1String("QGroupBox {\n"
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
        pushButton_5 = new QPushButton(groupBox_7);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(90, 40, 186, 31));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 30, 51, 51));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/331585408_556456159849722_8965214278401908655_n (1).png")));
        label_18->setScaledContents(true);
        pushButton_9 = new QPushButton(groupBox_7);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(90, 120, 186, 31));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 110, 51, 51));
        label_22->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/calendar (1).png")));
        label_22->setScaledContents(true);
        pushButton_28 = new QPushButton(groupBox_7);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(240, 180, 186, 31));
        pushButton_28->setFont(font);
        pushButton_28->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
        ComboBox_type_sr_10 = new QComboBox(groupBox_7);
        ComboBox_type_sr_10->setObjectName(QStringLiteral("ComboBox_type_sr_10"));
        ComboBox_type_sr_10->setGeometry(QRect(30, 180, 161, 31));
        ComboBox_type_sr_10->setStyleSheet(QLatin1String("QComboBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        tab_recent_entretien = new QTableView(tab_5);
        tab_recent_entretien->setObjectName(QStringLiteral("tab_recent_entretien"));
        tab_recent_entretien->setGeometry(QRect(70, 40, 1091, 381));
        tab_recent_entretien->setStyleSheet(QLatin1String("QHeaderView::section {\n"
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
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        db_prix_sr_2 = new QDoubleSpinBox(tab_6);
        db_prix_sr_2->setObjectName(QStringLiteral("db_prix_sr_2"));
        db_prix_sr_2->setGeometry(QRect(490, 300, 161, 31));
        db_prix_sr_2->setStyleSheet(QLatin1String("QDoubleSpinBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"    subcontrol-origin: padding;\n"
"    border-left-color: gray;\n"
"    width: 20px;\n"
"    border-left-style: solid;\n"
"    subcontrol-position: top right;\n"
"    border-down-width: 1px;\n"
"    border-left-width: 1px;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"    subcontrol-position: bottom right;\n"
"    subcontrol-origin: padding;\n"
"    border-left-color: gray;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-up-width: 1px;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius:"
                        " 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:hover, QDateEdit::down-button:hover {\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"QDoubleSpinBox::up-arrow {\n"
"        width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"\n"
"QDoubleSpinBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"QDoubleSpinBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        label_23 = new QLabel(tab_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(490, 260, 81, 31));
        label_23->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 9pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_4 = new QLabel(tab_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 150, 201, 31));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 9pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(tab_6);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 440, 151, 31));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
"border-radius:10px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color:#9999aa;\n"
"color:white;\n"
"}\n"
"QPushButton:enabled{\n"
" backgroundr: rgb(66, 117, 102);\n"
"color:white;\n"
"}\n"
"QPushButton:pressed{\n"
" background: qlineargradient(spread:pad, x1:0.5, y1:0.0342727, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:#fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed{\n"
" background:   rgb(221,222,217);\n"
"color:#0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"background:rgb(66, 117, 102);\n"
"color:#ffffff;\n"
"}"));
        ComboBox_type_sr_2 = new QComboBox(tab_6);
        ComboBox_type_sr_2->setObjectName(QStringLiteral("ComboBox_type_sr_2"));
        ComboBox_type_sr_2->setGeometry(QRect(490, 80, 161, 31));
        ComboBox_type_sr_2->setStyleSheet(QLatin1String("QComboBox {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QComboBox::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QComboBox::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        le_quantite_sr_2 = new QLineEdit(tab_6);
        le_quantite_sr_2->setObjectName(QStringLiteral("le_quantite_sr_2"));
        le_quantite_sr_2->setGeometry(QRect(490, 190, 161, 22));
        le_quantite_sr_2->setStyleSheet(QLatin1String("QLineEdit {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"        stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"QLineEdit::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-style: solid;\n"
"    border-width: 6px 6px 0 6px;\n"
"    border-color: gray transparent transparent transparent;\n"
"}\n"
"QLineEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: gray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #f0f0f0, stop: 1 #d8d8d8);\n"
"\n"
"}\n"
"QLineEdit::hover {\n"
"    background: #d0d0d0;\n"
"}\n"
"\n"
"QLineEdit::pressed {\n"
"    background: #c8c8c8;\n"
"}"));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(490, 40, 101, 31));
        label_24->setStyleSheet(QLatin1String("QLabel {\n"
"	font: 9pt \"MS Shell Dlg 2\";\n"
"    color: black;\n"
"    background-color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        pb_ajouter_sr_2 = new QPushButton(tab_6);
        pb_ajouter_sr_2->setObjectName(QStringLiteral("pb_ajouter_sr_2"));
        pb_ajouter_sr_2->setGeometry(QRect(620, 440, 151, 31));
        pb_ajouter_sr_2->setFont(font);
        pb_ajouter_sr_2->setStyleSheet(QLatin1String("QPushButton{\n"
" background: rgb(66, 117, 102);\n"
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
"}\n"
"\n"
""));
        tabWidget->addTab(tab_6, QString());
        stackedWidget->addWidget(page);

        retranslateUi(service);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(service);
    } // setupUi

    void retranslateUi(QDialog *service)
    {
        service->setWindowTitle(QApplication::translate("service", "Dialog", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("service", "Etat de service :", Q_NULLPTR));
        label_6->setText(QApplication::translate("service", "Cafe:  Disponible", Q_NULLPTR));
        label_7->setText(QApplication::translate("service", "Lavage: Jour F\303\251ri\303\251", Q_NULLPTR));
        label_8->setText(QApplication::translate("service", "Entrentien: Hors service", Q_NULLPTR));
        label_9->setText(QApplication::translate("service", "Service r\303\251cent :", Q_NULLPTR));
        label_13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("service", "Afficher Services", Q_NULLPTR));
        ComboBox_type_sr->clear();
        ComboBox_type_sr->insertItems(0, QStringList()
         << QApplication::translate("service", "Cafe", Q_NULLPTR)
         << QApplication::translate("service", "Lavage", Q_NULLPTR)
         << QApplication::translate("service", "Entretien", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("service", "Type :", Q_NULLPTR));
        label_3->setText(QApplication::translate("service", "Quantite :", Q_NULLPTR));
        label_5->setText(QApplication::translate("service", "prix :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("service", "Annuler", Q_NULLPTR));
        pb_ajouter_sr->setText(QApplication::translate("service", "Valider", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("service", "Ajouter Service", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("service", "\303\251tat de service:", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("service", "Activer", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("service", "D\303\251sactiver", Q_NULLPTR));
        label_10->setText(QApplication::translate("service", "Service r\303\251cent :", Q_NULLPTR));
        label_14->setText(QString());
        groupBox_6->setTitle(QApplication::translate("service", "Fonctionnalite", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("service", "Generer PDF", Q_NULLPTR));
        label_17->setText(QString());
        pushButton_6->setText(QApplication::translate("service", "Choisir jour f\303\251ri\303\251", Q_NULLPTR));
        label_19->setText(QString());
        pushButton_supp->setText(QApplication::translate("service", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("service", "Cafe", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("service", "\303\251tat de service:", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("service", "Activer", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("service", "D\303\251sactiver", Q_NULLPTR));
        label_11->setText(QApplication::translate("service", "Service r\303\251cent :", Q_NULLPTR));
        label_15->setText(QString());
        groupBox_8->setTitle(QApplication::translate("service", "Fonctionnalite", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("service", "Generer PDF", Q_NULLPTR));
        label_20->setText(QString());
        pushButton_8->setText(QApplication::translate("service", "Choisir jour f\303\251ri\303\251", Q_NULLPTR));
        label_21->setText(QString());
        pushButton_27->setText(QApplication::translate("service", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("service", "Lavage", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("service", "\303\251tat de service:", Q_NULLPTR));
        checkBox->setText(QApplication::translate("service", "Activer", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("service", "D\303\251sactiver", Q_NULLPTR));
        label_12->setText(QApplication::translate("service", "Service r\303\251cent :", Q_NULLPTR));
        label_16->setText(QString());
        groupBox_7->setTitle(QApplication::translate("service", "Fonctionnalite", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("service", "Generer PDF", Q_NULLPTR));
        label_18->setText(QString());
        pushButton_9->setText(QApplication::translate("service", "choisir jour f\303\251ri\303\251", Q_NULLPTR));
        label_22->setText(QString());
        pushButton_28->setText(QApplication::translate("service", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("service", "Entrentien", Q_NULLPTR));
        label_23->setText(QApplication::translate("service", "prix :", Q_NULLPTR));
        label_4->setText(QApplication::translate("service", "Quantite :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("service", "Annuler", Q_NULLPTR));
        ComboBox_type_sr_2->clear();
        ComboBox_type_sr_2->insertItems(0, QStringList()
         << QApplication::translate("service", "Cafe", Q_NULLPTR)
         << QApplication::translate("service", "Lavage", Q_NULLPTR)
         << QApplication::translate("service", "Entretien", Q_NULLPTR)
        );
        label_24->setText(QApplication::translate("service", "Type :", Q_NULLPTR));
        pb_ajouter_sr_2->setText(QApplication::translate("service", "Valider", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("service", "Modifier les donn\303\251es", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class service: public Ui_service {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_H
