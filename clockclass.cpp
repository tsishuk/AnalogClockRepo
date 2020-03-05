#include "clockclass.h"

ClockClass::ClockClass(QWindow *parent)
    :QWindow(parent)
{
    m_backingStore = new QBackingStore(this);
    create();

    setGeometry(100,100,300,300);
    setTitle("This is clock");
}


void ClockClass::exposeEvent(QExposeEvent *event)
{
    render();
}


void ClockClass::render()
{
    if (!isExposed())
        return;

    qDebug()<<"In render func";
}



