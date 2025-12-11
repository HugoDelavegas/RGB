#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSlider>
#include <QStringList>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->Init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SLD_RD_valueChanged(int value)
{
    ui->SPB_RD->setValue(value);
}


void MainWindow::on_SLD_GN_valueChanged(int value)
{
    ui->SPB_GN->setValue(value);
}


void MainWindow::on_SLD_BL_valueChanged(int value)
{
    ui->SPB_BL->setValue(value);
}


void MainWindow::on_SPB_BL_valueChanged(int arg1)
{
    QPalette palette;
    ui->SPB_BL->setAutoFillBackground(true);
    palette.setColor(QPalette::Base, QColor(QColor(0,0,arg1)));

    if (arg1<200)
    {
        palette.setColor(QPalette::Text,Qt::white);
    }
    else
    {
        palette.setColor(QPalette::Text,Qt::black);
    }
    ui->SPB_BL->setPalette(palette);
    ui->SLD_BL->setValue(arg1);
}


void MainWindow::on_SPB_GN_valueChanged(int arg1)
{
    QPalette palette;
    ui->SPB_GN->setAutoFillBackground(true);
    palette.setColor(QPalette::Base, QColor(QColor(0,arg1,0)));

    if (arg1<100)
    {
        palette.setColor(QPalette::Text,Qt::white);
    }
    else
    {
        palette.setColor(QPalette::Text,Qt::black);
    }
    ui->SPB_GN->setPalette(palette);
    ui->SLD_GN->setValue(arg1);
}


void MainWindow::on_SPB_RD_valueChanged(int arg1)
{
    QPalette palette;
    ui->SPB_RD->setAutoFillBackground(true);
    palette.setColor(QPalette::Base, QColor(QColor(arg1,0,0)));

    if (arg1<200)
    {
        palette.setColor(QPalette::Text,Qt::white);
    }
    else
    {
        palette.setColor(QPalette::Text,Qt::black);
    }
    ui->SPB_RD->setPalette(palette);
    ui->SLD_RD->setValue(arg1);
}

void MainWindow::RGBAdjust()
{
    QPalette palette;
    ui->Label_Color->setAutoFillBackground(true);

    QColor color = QColor(ui->SPB_RD->value(), ui->SPB_GN->value(), ui->SPB_BL->value());
    palette.setColor(QPalette::Window,color );
    QString colorhex= color.name(QColor::HexRgb);
    ui->Label_Color->setPalette(palette);
    ui->Label_Color->setText(colorhex);
}

void MainWindow::Init()
{
    ui->SLD_RD->setStyleSheet("QSlider::handle:vertical{background:qlineargradient( x1:0 , y1:0 , x2:1 , y2:1 , stop:0 white, stop:1 red); border: 1px solid #999999; border-radius: 5px ;}");
    ui->SLD_GN->setStyleSheet("QSlider::handle:vertical{background:qlineargradient( x1:0 , y1:0 , x2:1 , y2:1 , stop:0 white, stop:1 green); border: 1px solid #999999; border-radius: 5px;}");
    ui->SLD_BL->setStyleSheet("QSlider::handle:vertical{background:qlineargradient( x1:0 , y1:0 , x2:1 , y2:1 , stop:0 white, stop:1 blue); border: 1px solid #999999; border-radius: 5px;}");


    ui->SLD_BL->setRange(0,255);
    ui->SLD_GN->setRange(0,255);
    ui->SLD_RD->setRange(0,255);

    ui->SPB_BL->setRange(0,255);
    ui->SPB_GN->setRange(0,255);
    ui->SPB_RD->setRange(0,255);


    connect(ui->SPB_RD,SIGNAL(valueChanged(int)),this,SLOT(RGBAdjust()));
    connect(ui->SPB_GN,SIGNAL(valueChanged(int)),this,SLOT(RGBAdjust()));
    connect(ui->SPB_BL,SIGNAL(valueChanged(int)),this,SLOT(RGBAdjust()));

    ui->SPB_BL->setValue(255);
    ui->SPB_GN->setValue(255);
    ui->SPB_RD->setValue(255);

    QStringList listeCouleurs = QColor::colorNames();
    QStringListModel *modeleCouleurs = new QStringListModel(listeCouleurs);
    ui->listView->setModel(modeleCouleurs);

}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    QVariant nom = index.data(Qt::DisplayRole);
    int red =nom.value<QColor>().red();
    int green=nom.value<QColor>().green();
    int blue=nom.value<QColor>().blue();

    ui->SLD_RD->setValue(red);
    ui->SLD_GN->setValue(green);
    ui->SLD_BL->setValue(blue);
}

