#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void getLocalIPAddress();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QHostAddress localIPAddress;
    QString validationStr;

private slots:
    void onCodeGenerationButtonClicked();
};

#endif // MAINWINDOW_H
