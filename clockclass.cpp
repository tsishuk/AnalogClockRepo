#include "clockclass.h"

ClockClass::ClockClass(QWindow *parent)
    :QWindow(parent)
{
    m_backingStore = new QBackingStore(this);
    //m_backingStore->resize(QSize(300,300));
    create();

    setGeometry(300,300,400,400);
    setTitle("This is clock");
}


void ClockClass::resizeEvent(QResizeEvent *event)
{
    m_backingStore->resize(event->size());
}


void ClockClass::exposeEvent(QExposeEvent *event)
{
    static int expose_counter=0;
    render();
    qDebug()<<"Expose event #"<<expose_counter++;
}


void ClockClass::render()
{
    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice* device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.setFont(QFont("Times", 50, QFont::Bold));
    painter.fillRect(0, 0, width(), height(),
                     QBrush(Qt::darkCyan,Qt::Dense5Pattern));
    painter.drawText(QRectF(0, 0, width(), height()), Qt::AlignCenter, "QWindow");

    m_backingStore->endPaint();
    m_backingStore->flush(rect);

//     qDebug()<<"In render func";
}



