#ifndef PORT_H
#define PORT_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>
class Port : public QObject
{
    Q_OBJECT
private:
   QSerialPort* serial;
public:
    Port();
public slots:
    void myRead();
    void changeBaudRate(qint32);
     void changePort(QString);
signals:
    void gotNewData(QByteArray data);
};
#endif // PORT_H
