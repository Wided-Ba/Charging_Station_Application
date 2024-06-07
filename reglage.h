#ifndef REGLAGE_H
#define REGLAGE_H

#include <QDialog>
#include <QFile>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QTranslator>
#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTranslator>
namespace Ui {
class reglage;
}

class reglage : public QDialog
{
    Q_OBJECT

public:
    explicit reglage(QWidget *parent = nullptr);
    void  on_radioButton_clicked(bool checked);

       bool isRadioButtonChecked(bool *checked);
void showLanguageDialog(QApplication& app);
    ~reglage();
    private slots:


    void on_horizontalSlider_valueChanged(int value);

     void on_pushButton_play_clicked();

     void on_pushButton_pause_clicked();




private:
    Ui::reglage *ui;
   QString initial_style;
       QMediaPlayer *M_Player;
};

#endif // REGLAGE_H
