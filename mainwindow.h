#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "QtSerialPort/QSerialPort"
#include "myserialport.h"

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

    void on_BT_PortSwitch_clicked();

    void on_CB_Port_Debug_activated(const QString &arg1);

    void on_BT_Clean_clicked();

private:
    Ui::MainWindow *ui;

    //QSerialPort *serialPort;
    void scanPorts(QComboBox *combox);
    bool openSerialPort_Debug();
    void receiveDebugInfo(QByteArray buf);

    mySerialPort *serialPort;

};

#endif // MAINWINDOW_H
