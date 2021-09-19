#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSensors>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerSlot()
{
   ui->LatitudeLabel->setText("Широта : "+ QString::number(s1.x));
   ui->LongitudeLabel->setText("Долгота : "+ QString::number(t1.nowLongitude));
}

