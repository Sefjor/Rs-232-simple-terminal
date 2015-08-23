#include "out.h"

#include <QScrollBar>

#include <QMenu>


Out::Out(QWidget *parent)
    : QPlainTextEdit(parent)
    , localEchoEnabled(false)
{
    document()->setMaximumBlockCount(100);



}

void Out::putData(const QByteArray &data)
{
    insertPlainText(QString(data));

    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Out::setLocalEchoEnabled(bool set)
{
    localEchoEnabled = set;
}
