#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->addEllipse(QRectF(-100.0, -100.0, 100.0, 100.0));
}

MainWindow::~MainWindow()
{
    delete ui;
}
