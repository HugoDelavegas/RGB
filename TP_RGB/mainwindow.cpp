#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SLD_RD->setStyleSheet("QSlider::handle:vertical{background:qlineargradient( x1:0 , y1:0 , x2:1 , y2:1 , stop:0 white, stop:1 red); border: 1px solid #999999; border-radius: 5px ;}");
    ui->SLD_GN->setStyleSheet("QSlider::handle:vertical{background:qlineargradient( x1:0 , y1:0 , x2:1 , y2:1 , stop:0 white, stop:1 green); border: 1px solid #999999; border-radius: 5px;}");
    ui->SLD_BL->setStyleSheet("QSlider::handle:vertical{background:qlineargradient( x1:0 , y1:0 , x2:1 , y2:1 , stop:0 white, stop:1 blue); border: 1px solid #999999; border-radius: 5px;}");


    ui->SLD_BL->setRange(0,255);
    ui->SLD_GN->setRange(0,255);
    ui->SLD_RD->setRange(0,255);

    ui->SPB_BL->setRange(0,255);
    ui->SPB_GN->setRange(0,255);
    ui->SPB_RD->setRange(0,255);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SLD_RD_valueChanged(int value)
{
    ui->SPB_RD->setValue(ui->SLD_RD->value());
}


void MainWindow::on_SLD_GN_valueChanged(int value)
{
    ui->SPB_GN->setValue(ui->SLD_GN->value());
}


void MainWindow::on_SLD_BL_valueChanged(int value)
{
    ui->SPB_BL->setValue(ui->SLD_BL->value());
}


void MainWindow::on_SPB_BL_valueChanged(int arg1)
{
    ui->SLD_BL->setValue(ui->SPB_BL->value());
}


void MainWindow::on_SPB_GN_valueChanged(int arg1)
{
    ui->SLD_GN->setValue(ui->SPB_GN->value());
}


void MainWindow::on_SPB_RD_valueChanged(int arg1)
{
    ui->SLD_RD->setValue(ui->SPB_RD->value());
}

void MainWindow::RGBAdjust()
{
    QPalette palette;
    ui->Label_Color->setAutoFillBackground(true);
    palette.setColor(QPalette::Window,QColor(QColor(ui->SLD_BL->value(),ui->SLD_GN->value(),ui->SLD_RD->value())));
    ui->Label_Color->setPalette(palette);
}

