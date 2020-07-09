#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PCRemoteControlerServer");
    this->setFixedSize(QSize(750, 600));
    connect(this->ui->generateCodeButton, SIGNAL(clicked()), this, SLOT (onCodeGenerationButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCodeGenerationButtonClicked()
{
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QNetworkInterface &interface: QNetworkInterface::allInterfaces()) {
            qDebug() << interface.humanReadableName();
    }
}
