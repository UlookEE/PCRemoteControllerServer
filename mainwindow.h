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
    void saveCode();
    void loadCode();
    void updateCodeLabel();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QHostAddress localIPAddress;
    QString validationStr;

private slots:
    void onCodeGenerationButtonClicked();
};

#endif // MAINWINDOW_H
