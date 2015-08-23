#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainwindow.h"
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QScrollBar>
#include <QString>

class Out;
class Port;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void putData(const QByteArray &data);

signals:
    baudRateChanged(qint32);
    portChanged(QString);


private:
    Ui::MainWindow *ui;
     Out* out;
     Port* ser;
    QSerialPort *serial;
    QString currentPort {};
};

#endif // MAINWINDOW_H

