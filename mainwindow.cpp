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
    scanPorts(ui->CB_Port_Debug);
    scanPorts(ui->CB_Port_Download);
    serialPort = new mySerialPort();

    ui->PB_Download->setValue(0);
    ui->BT_Clean->setIcon(QIcon(":/ico/images/clean.png"));
    ui->BT_PortSwitch->setIcon(QIcon(":/ico/images/open.png"));


    QObject::connect(serialPort, &mySerialPort::receiceData, this, &MainWindow::receiveDebugInfo);


}

MainWindow::~MainWindow()
{
    delete ui;
}

/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void MainWindow::scanPorts(QComboBox *combox)
{
    combox->clear();
    foreach ( const QSerialPortInfo &Info, QSerialPortInfo::availablePorts())
    {
        combox->addItem(Info.portName(), QVariant());
    }

}

/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void MainWindow::receiveDebugInfo(QByteArray buf)
{
    if (buf.length() != 0)
    {
        QString str = ui->TE_DdebugInfo->toPlainText();
        str += tr(buf);
        ui->TE_DdebugInfo->clear();
        ui->TE_DdebugInfo->append(str);
    }
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void MainWindow::on_BT_PortSwitch_clicked()
{
    serialPort->setBaudRate(ui->CB_BaudRate_Debug->currentText());
    serialPort->setDataBits(ui->CB_DataBits->currentText());
    serialPort->setFlowCtrl(ui->CB_FlowCtrl->currentText());
    serialPort->setParity(ui->CB_Parity->currentText());
    serialPort->setStopBits(ui->CB_StopBits->currentText());

    if (ui->BT_PortSwitch->text() == "关闭串口")
    {
        serialPort->closePort();
        ui->BT_PortSwitch->setText("打开串口");
        ui->BT_PortSwitch->setIcon(QIcon(":/ico/images/open.png"));
    }
    else if (serialPort->openPort(ui->CB_Port_Debug->currentText()) == true)
    {
        ui->BT_PortSwitch->setText("关闭串口");
        ui->BT_PortSwitch->setIcon(QIcon(":/ico/images/close.png"));
    }

}

void MainWindow::on_CB_Port_Debug_activated(const QString &arg1)
{
    scanPorts(ui->CB_Port_Debug);
    scanPorts(ui->CB_Port_Download);
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void MainWindow::on_BT_Clean_clicked()
{
    ui->TE_DdebugInfo->clear();
}
