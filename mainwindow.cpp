#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSensors>
#include <QGeoCoordinate>

#include <QtDebug>
#include <math.h>
#include <QAccelerometer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    t1.start();
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerSlot()
{

   ui->LatitudeLabel->setText("Широта : "+QString::number(s1.Latitude()));
   ui->LongitudeLabel->setText("Долгота : "+QString::number(s1.Longitude()));
   t1.append(s1.Cordinate());
   ui->DistanseLabel->setText("Расстояние : "+t1.distanceKm()+" Km");
   ui->SpeedLabel->setText("Скорость : "+t1.speedKmh());
}

