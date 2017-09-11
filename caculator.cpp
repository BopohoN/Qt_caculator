#include "caculator.h"
#include "ui_caculator.h"

int Change(const char *S,char OPS[],int &len);
int changeEX_MotherFucker(char B[], int len, double &result,bool &flag);

caculator::caculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::caculator)
{
    ui->setupUi(this);
    ui->lineEdit->setText(input);
}

caculator::~caculator()
{
    delete ui;
}

void caculator::on_pushButton_0_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "0";
        else
            input = input + "0";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "0";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_1_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "1";
        else
            input = input + "1";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "2";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_2_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "2";
        else
            input = input + "2";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "2";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_3_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "3";
        else
            input = input + "3";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "3";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_4_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "4";
        else
            input = input + "4";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "4";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_5_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "5";
        else
            input = input + "5";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "5";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_6_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "6";
        else
            input = input + "6";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "6";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_7_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "7";
        else
            input = input + "7";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "7";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_8_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "8";
        else
            input = input + "8";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "8";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}

void caculator::on_pushButton_9_clicked()
{
    if(ifres == false)
    {
        if(input == "0")
            input = "9";
        else
            input = input + "9";
        ui->lineEdit->setText(input);
        ifres = false;
    }
    else
    {
        input = "9";
        ui->lineEdit->setText(input);
        ifres = false;
    }
}



void caculator::on_pushButton_back_clicked()
{
    int i = 0;
    if(input.length() == 1)
        input = "0";
    else
        input = input.left(input.length()-1);

    while(i != input.length())
    {
        if(input.at(i)==".")
            dotflag = true;
        if(input.at(i)=="+" || input.at(i)=="-" || input.at(i)=="*" || input.at(i)=="/")
            dotflag = false;
        i++;
    }
    if(input.length() == 1)
    {
        dotflag = false;
    }
    ui->lineEdit->setText(input);
}


void caculator::on_pushButton_dot_clicked()
{
    if (dotflag == false)
    {
        input = input + ".";
        dotflag = true;
        if (input.at(input.length()-1) == "+" || input.at(input.length()-1) == "-" || input.at(input.length()-1) == "*" || input.at(input.length()-1) == "/")
        {
                input = input + "0.";
        }
    }
    ui->lineEdit->setText(input);
    ifres = false;
}

void caculator::on_pushButton_trans_clicked()
{
    try{
    if(input.length() == 0)
    {
        QString res;
        input = input + res;
        ui->lineEdit->setText(input);
        input = res;
        ifres = true;
    }
    else
    {
    std::string str=input.toStdString();
    const char *S=str.c_str();
    char OPS[50];
    int len;
    double result;
    QString change;
    bool flag;
    Change(S,OPS,len);
    changeEX_MotherFucker(OPS,len,result,flag);
    change=QString::number(result);
    input=input+"="+change;
    ui->lineEdit->setText(input);
    input = change;
    ifres = true;
    }
    }
    catch(int)
    {
        input = "0";
        ui->lineEdit->setText("NAN");
    }
}

int Change(const char *S,char OPS[],int &len)
{
    QStack<char> OPE;
    int i,j=0;
    for (i = 0; i < strlen(S); i++)
    {
        switch (S[i])
        {
        case'+':
            if(OPE.isEmpty())
             OPE.push(S[i]);
            else if (OPE.top() == '*' || OPE.top() == '/')
            {
                OPS[j++] = OPE.pop();
                i--;
            }
            else
                OPE.push(S[i]);
            break;
        case'-':
            if('('!=S[i-1]&&0!=i)
            {
             if(OPE.isEmpty())
              OPE.push(S[i]);
              else if (OPE.top() == '*' || OPE.top() == '/')
              {
                OPS[j++] = OPE.pop();
                i--;
              }
              else
                OPE.push(S[i]);
            }
            else
            {
                while ((S[i] >= '0'&&S[i] <= '9' )|| S[i] == '.'||('-'==S[i]&&(S[i-1]<'0'||S[i-1]>'9')))
                {
                    OPS[j++] = S[i];
                    if('-'==S[i])
                      OPS[j++]='@';
                    i++;
                }
                i--;
                OPS[j++] = '#';  //数字中的间隔符
            }
            break;
        case'*':
        case'/':
            OPE.push(S[i]);
            break;
        case'(':
            OPE.push(S[i]);
            break;
        case')':
            while (OPE.top() != '(')
            {
                OPS[j++] = OPE.pop();
            }
            OPE.pop();
            break;
        default:
            while (S[i] >= '0'&&S[i] <= '9' || S[i] == '.'||('-'==S[i]&&S[i-1]<'0'&&S[i-1]>'9'))
            {

                OPS[j++] = S[i];

                i++;
            }
            i--;
            OPS[j++] = '#';  //数字中的间隔符
            break;
        }
    }
    while (!OPE.isEmpty())
    {
        OPS[j++] = OPE.pop();
    }
    len = j;
    return 0;
}

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/


int changeEX_MotherFucker(char B[], int len, double &result,bool &flag)
{
    int i;
    double a;
    double b;
    double c;
    QStack<double>SZ;
        for (i = 0; i < len; i++)
    {
        switch (B[i])
        {
           case'+':
           {
            a = SZ.pop();
            b = SZ.pop();
            c = b + a;
            SZ.push(c);
            }
               break;
           case'-':
           {
            if('@'!=B[i+1])
            {
            a = SZ.pop();
            b = SZ.pop();
            c = b - a;
            SZ.push(c);
            }
            else
            {
                int jx = 0;
                double dx;
                char *stx = new char[10];
                while (B[i] != '#')
                {
                   if('@'!=B[i])
                    stx[jx++] = B[i];
                    i++;

                }
                dx = atof(stx);
                SZ.push(dx);
                delete stx;
            }
           }
               break;
           case'*':
           {
            a = SZ.pop();
            b = SZ.pop();
            c = b*a;
            SZ.push(c);
           }
               break;
           case'/':
           {
              a = SZ.pop();
              b = SZ.pop();
              if (a== 0)
              {
                  flag = false;
                  return 0;
              }
              c = b / a;
              SZ.push(c);
           }
               break;
           default:
               int j = 0;
               double d;
               char *st = new char[10];
               while (B[i] != '#')
               {
                   st[j++] = B[i];
                   i++;
               }
               d = atof(st);
               SZ.push(d);
               delete st;
               break;
        }
    }
    result=SZ.top();

    return 0;
}


void caculator::on_pushButton_mult2_clicked()
{
    int i = 0;
    bool flag = false;
    double res;
    while(i != input.length())
    {
        if(input.at(i)=="+" || input.at(i)=="-" || input.at(i)=="*" || input.at(i)=="/")
        {
            ui->lineEdit->setText("NAN");
            input = "0";
            flag = true;
            break;
        }
        i++;
    }
    if (flag == false)
    {
        res = input.toDouble();
        res = res * res;
        input = QString::number(res);
        ui->lineEdit->setText(input);
    }
    ifres = true;
}

void caculator::on_pushButton_div2_clicked()
{
    int i = 0;
    bool flag = false;
    double res;
    while(i != input.length())
    {
        if(input.at(i)=="+" || input.at(i)=="-" || input.at(i)=="*" || input.at(i)=="/")
        {
            ui->lineEdit->setText("NAN");
            input = "0";
            flag = true;
            break;
        }
        i++;
    }
    if (flag == false)
    {
        res = input.toDouble();
        res = sqrt(res);
        input = QString::number(res);
        ui->lineEdit->setText(input);
    }
    ifres = true;
}

void caculator::on_pushButton_mod_clicked()
{
    input = "0";
    ui->lineEdit->setText(input);
}

void caculator::on_pushButton_l_clicked()
{
    if(input=="0")
    input='(';
    else input=input+'(';
    ui->lineEdit->setText(input);
}

void caculator::on_pushButton_r_clicked()
{
    if(input=="0")
    input=')';
    else input=input+')';
    ui->lineEdit->setText(input);
}

void caculator::on_pushButton_add_clicked()
{
    if(input == "0")
        input = input + "+";
    else
        input = input + "+";
    dotflag = false;
    ifres = false;
    ui->lineEdit->setText(input);
}

void caculator::on_pushButton_sub_clicked()
{
    if(input == "0")
        input = input + "-";
    else
        input = input + "-";
    dotflag = false;
    ifres = false;
    ui->lineEdit->setText(input);
}

void caculator::on_pushButton_mult_clicked()
{
    if(input == "0")
        input = input + "*";
    else
        input = input + "*";
    dotflag = false;
    ifres = false;
    ui->lineEdit->setText(input);
}

void caculator::on_pushButton_div_clicked()
{
    if(input == "0")
        input = input + "/";
    else
        input = input + "/";
    dotflag = false;
    ifres = false;
    ui->lineEdit->setText(input);
}
