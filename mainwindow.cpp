#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "out.h"
#include <QThread>
#include <QtSerialPort/QSerialPortInfo>
#include "port.h"
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
    out = new Out;
    ser = new Port;
      connect (ser, Port::gotNewData, this, putData);
      connect (this, baudRateChanged, ser, Port::changeBaudRate);
      connect (this, portChanged, ser, Port::changePort);
   // setCentralWidget(out);
    out->setMaximumHeight(100);

    QThread *thread = new QThread();
    ser->moveToThread(thread); //Отдельный поток для работы с последовательным портом
    thread->start();

    QMenu* baudRateMenu = ui->menuBar->addMenu("Set baud rate");
for ( auto x : QSerialPortInfo::standardBaudRates() )
{
     QAction* action = baudRateMenu->addAction(QString::number(x) );
    connect(action, &QAction::triggered, [=]()
    {
      emit baudRateChanged(x);
    });
}
QMenu* portMenu = ui->menuBar->addMenu("Set port");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QAction* action = portMenu->addAction( info.portName());
        connect(action, &QAction::triggered, [=]()
        {
            emit portChanged( info.portName() );
        });
    }

}
void MainWindow::putData(const QByteArray &data)
{
    ui->myTxt->insertPlainText(QString(data));


}

MainWindow::~MainWindow()
{
    delete ui;
}

//  ui->statusBar->showMessage(QString::number( ser->serial->baudRate() ) );






