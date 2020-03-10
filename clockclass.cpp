#include "clockclass.h"

ClockClass::ClockClass(QWindow *parent)
    :QWindow(parent),
      m_pendingRequest(0)
{
    m_backingStore = new QBackingStore(this);
    create();

    setGeometry(300,300,400,400);
    setTitle("This is clock");
}


bool ClockClass::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest){
        render();
        m_pendingRequest = 0;
        return true;
    }
    return QWindow::event(event);
}


void ClockClass::resizeEvent(QResizeEvent *event)
{
    m_backingStore->resize(event->size());
}


void ClockClass::exposeEvent(QExposeEvent *)
{
    static int expose_counter=0;
    render();           // Отрисовка сразу
    //renderRequest();  // Отложенная отрисовка (медленнее но вернее)
    qDebug()<<"Expose event #"<<expose_counter++;
}


void ClockClass::renderRequest()
{
    if (!m_pendingRequest){
        m_pendingRequest = 1;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
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

    //painter.fillRect(0, 0, width(), height(), QGradient::NightFade);

    painter.fillRect(0, 0, width(), height(),
                     QBrush(Qt::darkCyan,Qt::Dense4Pattern));

    render(&painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}


void ClockClass::render(QPainter* p)
{
    p->drawText(QRectF(0, 0, width(), height()), Qt::AlignCenter, "QWindow");
}



