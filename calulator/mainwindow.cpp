#include "mainwindow.h"
#include "./ui_mainwindow.h"

double numFirst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(op()));
    connect(ui->pushButton_procent, SIGNAL(clicked()), this, SLOT(op()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(mathOp()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(mathOp()));
    connect(ui->pushButton_substraction, SIGNAL(clicked()), this, SLOT(mathOp()));
    connect(ui->pushButton_addition, SIGNAL(clicked()), this, SLOT(mathOp()));

    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_addition->setCheckable(true);
    ui->pushButton_substraction->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digitNumbers(){
    QPushButton* button = (QPushButton*)sender();

    double allNumbers;
    QString newLabel;

    if(ui->result_show->text().contains(".") && button->text() == "0"){
        newLabel = ui->result_show->text() + button->text();
    }
    else{
        allNumbers = (ui->result_show->text() + button->text()).toDouble();
        newLabel = QString::number(allNumbers, 'g', 15);
    }


    ui->result_show->setText(newLabel);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->result_show->text().contains('.'))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::op(){
    QPushButton* button = (QPushButton*)sender();

    double allNumbers;
    QString newLabel;

    if(button->text() == "+/-"){
        allNumbers = (ui->result_show->text()).toDouble();
        allNumbers *= -1;
        newLabel = QString::number(allNumbers, 'g', 15);

        ui->result_show->setText(newLabel);
    }
    else if(button->text() == "%"){
            allNumbers = (ui->result_show->text()).toDouble();
            allNumbers *= 0.01;
            newLabel = QString::number(allNumbers, 'g', 15);

            ui->result_show->setText(newLabel);
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_division->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_addition->setChecked(false);
    ui->pushButton_substraction->setChecked(false);

    numFirst = 0;
    ui->result_show->setText("0");
}


void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, numSecond;
    QString newLabel;

    numSecond = ui->result_show->text().toDouble();

    if(ui->pushButton_addition->isChecked()){
        labelNumber = numFirst + numSecond;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(newLabel);
        ui->pushButton_addition->setChecked(false);
    }
    else if(ui->pushButton_substraction->isChecked()){
        labelNumber = numFirst - numSecond;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(newLabel);
        ui->pushButton_substraction->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked()){
        if(numSecond == 0)
            ui->result_show->setText("Ошибка");
        else{
            labelNumber = numFirst / numSecond;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->result_show->setText(newLabel);
        }

        ui->pushButton_division->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()){
        labelNumber = numFirst * numSecond;
        newLabel = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
}

void MainWindow::mathOp(){
    QPushButton* button = (QPushButton*) sender();


    numFirst = ui->result_show->text().toDouble();
    ui->result_show->setText("");

    button->setChecked(true);
}

