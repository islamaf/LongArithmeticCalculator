#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BigNumCalc.cpp"
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(500,250);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString number_one = ui->number1->text();
    QString number_two = ui->number2->text();

    std::string s1 = number_one.toUtf8().constData();
    std::string s2 = number_two.toUtf8().constData();

    calculator c;

    std::string res = c.addition(s1, s2);

    QString qres = QString::fromStdString(res);
    ui->result->setText(qres);
}

void MainWindow::on_subtractButton_clicked()
{
    QString number_one = ui->number1->text();
    QString number_two = ui->number2->text();

    std::string s1 = number_one.toUtf8().constData();
    std::string s2 = number_two.toUtf8().constData();

    calculator c;

    std::string res = c.subtraction(s1, s2);

    QString qres = QString::fromStdString(res);
    ui->result->setText(qres);
}

void MainWindow::on_multiplyButton_clicked()
{
    QString number_one = ui->number1->text();
    QString number_two = ui->number2->text();

    std::string s1 = number_one.toUtf8().constData();
    std::string s2 = number_two.toUtf8().constData();

    calculator c;

    std::string res = c.multiplication(s1, s2);

    QString qres = QString::fromStdString(res);
    ui->result->setText(qres);
}

void MainWindow::on_divideButton_clicked()
{
    QString number_one = ui->number1->text();
    QString number_two = ui->number2->text();

    std::string s1 = number_one.toUtf8().constData();
    std::string s2 = number_two.toUtf8().constData();

    calculator c;

    std::string res = c.check_division(s1, s2);

    QString qres = QString::fromStdString(res);
    ui->result->setText(qres);
}
