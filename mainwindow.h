#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "QtSerialPort/QSerialPort"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_portCtrl_Debug_clicked();

    void on_clearWindows_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort *serialPort;
    void scanPorts(QComboBox *combox);
    bool openSerialPort_Debug();
    void Read_Data();

};

#endif // MAINWINDOW_H
