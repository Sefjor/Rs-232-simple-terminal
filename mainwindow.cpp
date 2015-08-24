#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QtSerialPort/QSerialPortInfo>
#include "port.h"
#include <QString>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ser = new Port;
    connect (ser, Port::gotNewData, this, putData);
    connect (this, baudRateChanged, ser, Port::changeBaudRate);
    connect (this, portChanged, ser, Port::changePort);
    connect (this, timeToSend, ser, Port::writeData );
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

void MainWindow::on_Send_clicked()
{
    QByteArray data;
     if (ui->buttonGroup->checkedId() == -3 )
     {
        std::string hex_chars = ui->tex->toPlainText().toUtf8().constData() ;
        std::istringstream hex_chars_stream(hex_chars);
        std::string bytes;
        unsigned int c;
        while (hex_chars_stream >> std::hex >> c)
        {
            bytes += c;
        }
      //  ui->statusBar->showMessage( QString::fromStdString(bytes) );
        data = QString::fromStdString(bytes).toLocal8Bit();
    }
     else
    data = ui->tex->toPlainText().toLocal8Bit();

    ui->myTxt->insertPlainText("Sent: " + QString(data) + "\n");
    emit timeToSend(data);

}
