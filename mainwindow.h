#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QString>

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
  timeToSend(QByteArray);


private slots:
  void on_Send_clicked();

private:
  Ui::MainWindow* ui;
  Port* ser;
  QSerialPort *serial;
  QString currentPort {};
};

#endif // MAINWINDOW_H

