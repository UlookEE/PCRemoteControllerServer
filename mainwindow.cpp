#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PCRemoteControlerServer");
    this->setFixedSize(QSize(750, 600));
}

MainWindow::~MainWindow()
{
    delete ui;
}
