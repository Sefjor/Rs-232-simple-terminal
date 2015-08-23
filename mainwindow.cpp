#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "out.h"
#include <QThread>
#include <QtSerialPort/QSerialPortInfo>
#include "port.h"
#include <QString>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
    out = new Out;
    ser = new Port;
      connect (ser, Port::gotNewData, out, Out::putData);
  //  out->setEnabled(false);
    setCentralWidget(out);

    QThread *thread = new QThread();
    ser->moveToThread(thread); //Отдельный поток для работы с последовательным портом
    thread->start();

    QMenu* baudRateMenu = ui->menuBar->addMenu("Set baud rate");
for ( auto x : QSerialPortInfo::standardBaudRates() )
{
     QAction* action = baudRateMenu->addAction(QString::number(x) );
    connect(action, &QAction::triggered, [=]()
    {
    //  emit portChanged(x);

    });
}

QMenu* portMenu = ui->menuBar->addMenu("Set port");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QAction* action = portMenu->addAction( info.portName());
        connect(action, &QAction::triggered, [=]()
        {
            //serial->setPortName(currentPort);

        });
    }




}
MainWindow::~MainWindow()
{
    delete ui;
}








