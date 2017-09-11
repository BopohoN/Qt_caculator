#ifndef CACULATOR_H
#define CACULATOR_H

#include <QMainWindow>
#include<QString>
#include<QStack>
#include <math.h>

namespace Ui {
class caculator;
}

class caculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit caculator(QWidget *parent = 0);
    ~caculator();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_trans_clicked();

    void on_pushButton_mult2_clicked();

    void on_pushButton_div2_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_l_clicked();

    void on_pushButton_r_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mult_clicked();

    void on_pushButton_div_clicked();

private:
    Ui::caculator *ui;
    QString input="0";
    bool dotflag = false;
    bool ifres = false;
};

#endif // CACULATOR_H
