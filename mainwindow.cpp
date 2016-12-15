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
    scanPorts(ui->CB_Port_Download);
    serialPort = new QSerialPort();
    ui->PB_Download->setValue(0);
    ui->clearWindows->setIcon(QIcon(":/ico/images/clean.png"));


    QObject::connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::Read_Data);

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

bool MainWindow::openSerialPort_Debug()
{
    bool ok;

    serialPort->setBaudRate(ui->BAUDCB_Debug ->currentText().toInt(&ok, 10));
    serialPort->setPortName(ui->COMCB_Debug->currentText());

    serialPort->setDataBits(QSerialPort::Data8);    //设置数据位数
    serialPort->setParity(QSerialPort::NoParity);      //设置奇偶校验
    serialPort->setStopBits(QSerialPort::OneStop);      //设置停止位
    serialPort->setFlowControl(QSerialPort::NoFlowControl);  //设置流控制

    return serialPort->open(QIODevice::ReadWrite);

}

void MainWindow::Read_Data(void)
{
    QByteArray buf;
    buf = serialPort->readAll();
    if (buf.length() != 0)
    {
        QString str = ui->TE_DdebugInfo->toPlainText();
        str+=tr(buf);
        ui->TE_DdebugInfo->clear();
        ui->TE_DdebugInfo->append(str);
    }
    buf.clear();

}
/*******************************
 * 打开串口按键槽
********************************/
void MainWindow::on_portCtrl_Debug_clicked()
{
    if (ui->portCtrl_Debug->text() == "关闭串口")
    {
        serialPort->close();
        ui->portCtrl_Debug->setText("打开串口");
    }
    else if (openSerialPort_Debug() == true)
    {
       ui->portCtrl_Debug->setText("关闭串口");
    }

}

void MainWindow::on_clearWindows_clicked()
{
    ui->TE_DdebugInfo->clear();
}
