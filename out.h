#ifndef OUT_H
#define OUT_H

#include <QPlainTextEdit>

class Out : public QPlainTextEdit
{
    Q_OBJECT

signals:
    void getData(const QByteArray &data);

public:
    explicit Out(QWidget *parent = 0);

    void putData(const QByteArray &data);

    void setLocalEchoEnabled(bool set);


private:
    bool localEchoEnabled;

};

#endif // OUT_H
