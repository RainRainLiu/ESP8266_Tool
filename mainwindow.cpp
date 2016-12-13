#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QtSerialPort/QSerialPortInfo"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"statrt";
    scanPorts(ui->COMCB_Debug);

    //connect(ui->portCtrl_Debug, SIGNAL(pressed()), this, SLOT(openSerialPort()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::scanPorts(QComboBox *combox)
{
    foreach ( const QSerialPortInfo &Info, QSerialPortInfo::availablePorts())
    {
        combox->addItem(Info.portName(), QVariant());
    }

}

void MainWindow::openSerialPort()
{
    bool ok;
    serialPort = new QSerialPort();

    serialPort->setBaudRate(ui->BAUDCB_Debug->currentText().toInt(&ok, 10));
    serialPort->setPortName(ui->COMCB_Debug->currentText());

    if (serialPort->open(QIODevice::ReadWrite))
    {
        qDebug()<<"open sucess";
    }
    else
    {
        qDebug()<<"open error";
    }

}
