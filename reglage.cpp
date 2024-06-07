#include "reglage.h"
#include "ui_reglage.h"

reglage::reglage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reglage)

{
    ui->setupUi(this);
        initial_style = qApp->styleSheet();
        QObject::connect(ui->radioButton, &QRadioButton::clicked, this, &reglage::on_radioButton_clicked);
        M_Player=new QMediaPlayer();
            ui->pushButton_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            ui->pushButton_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            M_Player->setVolume(ui->horizontalSlider->value());
            ui->label_7->setObjectName("reglage");
            ui->label_3->setObjectName("55");
            ui->label_2->setObjectName("44");
            ui->label_10->setObjectName("33");
            ui->label->setObjectName("22");

}

reglage::~reglage()
{
    delete ui;
}




void reglage::on_pushButton_play_clicked()
{
    QString FileName=QFileDialog::getOpenFileName(this,tr("select audio File"),"",tr("MP3 Files (*.MP3)"));
        M_Player->setMedia(QUrl(FileName));
        ui->label_8->setText(FileName);
        M_Player->play();
}

void reglage::on_pushButton_pause_clicked()
{
    M_Player->stop();
}
void reglage::on_horizontalSlider_valueChanged(int value)
{
M_Player->setVolume(value);

}

/***************dark mode******/
void  reglage::on_radioButton_clicked(bool checked)
{
    if (checked)
        {
            ui->radioButton->setText("Nuit");
            // Load the dark stylesheet
            QFile dark_styleFile(":/themes/MaterialDark.qss");
            dark_styleFile.open(QFile::ReadOnly);
            QString style(dark_styleFile.readAll());
            qApp->setStyleSheet(style);

        }
        else
        {
            ui->radioButton->setText("Jour");
            QFile dark_styleFile(":/themes/MaterialLight.qss");
            dark_styleFile.open(QFile::ReadOnly);
            QString style(dark_styleFile.readAll());
            // Set the stylesheet back to the initial style
            qApp->setStyleSheet(style);
        }

}

