#ifndef PORT_H
#define PORT_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>
class Port : public QObject
{
    Q_OBJECT
public:
    Port();
public slots:

    void myRead();
    void changeBaudRate(qint32);
signals:
    void gotNewData(QByteArray data);
 private:
    QSerialPort *serial;
    QString currentPort {};
};
#endif // PORT_H
