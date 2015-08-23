#include "port.h"
#include <QThread>
#include <QWidget>
#include <QObject>
Port::Port(): QObject()
{
    serial = new QSerialPort(this);
    serial->setPortName("com3");
    serial->setBaudRate(115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial, SIGNAL( readyRead() ), this, SLOT( myRead() ) );
}

void Port::myRead()
{
    QByteArray data = serial->readAll();
    emit gotNewData(data);
}
void Port::changeBaudRate(qint32 rate)
{
    serial->setBaudRate(rate);
}

void Port::changePort(QString port)
{
    serial->setPortName(port);
    serial->close();
    serial->open(QIODevice::ReadWrite);
}
void Port::writeData(QByteArray data)
{
    serial->write(data);
}
