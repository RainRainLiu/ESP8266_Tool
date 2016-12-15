#include "myserialport.h"
#include "QtSerialPort/qserialport.h"
#include "QtSerialPort/qserialportinfo.h"

mySerialPort::mySerialPort(QObject *parent) : QObject(parent)
{
    serialPort = new QSerialPort();
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/

void mySerialPort::setBaudRate(QString str)
{
    bool result = true;

    int baudRate = str.toInt(&result, 10);

    serialPort->setBaudRate(baudRate);
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void mySerialPort::setParity(QString str)
{
    if (str == QString::fromLocal8Bit("无校验"))
    {
        serialPort->setParity(QSerialPort::NoParity);
    }
    else if (str == QString::fromLocal8Bit("奇校验"))
    {
        serialPort->setParity(QSerialPort::OddParity);
    }
    else if (str == QString::fromLocal8Bit("偶校验"))
    {
        serialPort->setParity(QSerialPort::EvenParity);
    }
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void mySerialPort::setDataBits(QString str)
{
    if (str == "8")
    {
        serialPort->setDataBits(QSerialPort::Data8);
    }
    else if (str == "7")
    {
        serialPort->setDataBits(QSerialPort::Data7);
    }
    else if (str == "6")
    {
        serialPort->setDataBits(QSerialPort::Data6);
    }
    else if (str == "5")
    {
        serialPort->setDataBits(QSerialPort::Data5);
    }
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void mySerialPort::setStopBits(QString str)
{
    if (str == "1")
    {
        serialPort->setStopBits(QSerialPort::OneStop);
    }
    else if (str == "1.5")
    {
        serialPort->setStopBits(QSerialPort::OneAndHalfStop);
    }
    else if (str == "2")
    {
        serialPort->setStopBits(QSerialPort::TwoStop);
    }
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void mySerialPort::setFlowCtrl(QString str)
{
    if (str == "off")
    {
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
    }
    else if (str == "hardware")
    {
        serialPort->setFlowControl(QSerialPort::HardwareControl);
    }
    else if (str == "off")
    {
        serialPort->setFlowControl(QSerialPort::SoftwareControl);
    }
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
bool mySerialPort::openPort(QString str)
{
    serialPort->setPortName(str);
    return serialPort->open(QIODevice::ReadWrite);
}
/******************************************
 * @函数说明：
 * @输入参数：
 * @返回参数：
 * @修订日期：
******************************************/
void mySerialPort::closePort(void)
{
    serialPort->close();
}
