#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"

#include <QtDebug>
#include <QNetworkInterface>
#include <QTcpSocket>
#include <QDateTime>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Find local address
    getLocalIPAddress();

    this->setWindowTitle("PCRemoteControlerServer");
    this->setFixedSize(QSize(750, 600));
    connect(this->ui->generateCodeButton, SIGNAL(clicked()), this, SLOT (onCodeGenerationButtonClicked()));

    // For random
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

    //load code
    loadCode();
    updateCodeLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getLocalIPAddress()
{
    QTcpSocket socket;
    socket.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable
    if (socket.waitForConnected()) {
           qDebug()
               << "local IPv4 address for Internet connectivity is"
               << socket.localAddress();
           this->localIPAddress = socket.localAddress();
    } else {
           qWarning()
               << "could not determine local IPv4 address:"
               << socket.errorString();
    }
}
void MainWindow::onCodeGenerationButtonClicked()
{
    QString randomStr = GetRandomString(10);
    this->validationStr = randomStr;
    saveCode();
    updateCodeLabel();
}

void MainWindow::saveCode()
{
    QString filename = "Data.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << this->validationStr;
    }
}

void MainWindow::loadCode()
{
    QString filename = "Data.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream >> this->validationStr;
    }
}

void MainWindow::updateCodeLabel()
{
    QString ip = IPToCode(this->localIPAddress);
    QString code = ip + this->validationStr;
    qDebug()<<code;
    this->ui->codeLabel->setText(code);
}
