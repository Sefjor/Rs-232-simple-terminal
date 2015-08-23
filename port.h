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
signals:
    void gotNewData(QByteArray data);
private slots:
 private:
    QSerialPort *serial;
    QString currentPort {};
};
#endif // PORT_H
