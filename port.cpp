#include "port.h"
#include <QThread>
#include <QWidget>
#include <QObject>
Port::Port(): QObject()
{
    serial = new QSerialPort();
    if (currentPort == "")
        currentPort = "com3";
    serial->setPortName(currentPort);
    serial->setBaudRate(115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    //ui->statusBar->showMessage(tr("Connected to %1").arg(currentPort));
    serial->open(QIODevice::ReadWrite);

     connect(serial, SIGNAL( readyRead()), this, SLOT( myRead() ) );
}


 void Port::myRead()
 {
     QByteArray data = serial->readAll();
     emit gotNewData(data);
 }
