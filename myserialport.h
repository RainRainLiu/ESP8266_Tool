#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>

class mySerialPort : public QObject
{
    Q_OBJECT
public:
    explicit mySerialPort(QObject *parent = 0);

signals:

public slots:
};

#endif // MYSERIALPORT_H