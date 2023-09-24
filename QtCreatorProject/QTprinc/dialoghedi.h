#ifndef DIALOGHEDI_H
#define DIALOGHEDI_H

#include <QDialog>
#include "employe.h"
namespace Ui {
class Dialoghedi;
}

class Dialoghedi : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoghedi(QWidget *parent = nullptr);
    ~Dialoghedi();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_9_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_comboBox_4_currentIndexChanged(int index);

    void on_pushButton_8_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Dialoghedi *ui;
    EMPLOYE emp;
};

#endif // DIALOGHEDI_H
