#include <QtGui>
#include "clockclass.h"


class AnalogClock : public ClockClass
{
public:
    AnalogClock();
    ~AnalogClock(){}

protected:
    void timerEvent(QTimerEvent*) Q_DECL_OVERRIDE;
    void render(QPainter* p) Q_DECL_OVERRIDE;

private:
    int m_timer_id;
};


AnalogClock::AnalogClock()
{
    setTitle("Analog Clock Window");
    resize(300,300);

    m_timer_id = startTimer(1000);
}


void AnalogClock::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timer_id)
        renderRequest();
}


void AnalogClock::render(QPainter *p)
{
    static const QPoint hour_arrow[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-40)
    };
    static const QPoint minute_arrow[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-70)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    p->setRenderHint(QPainter::Antialiasing);

    p->translate(width()/2, height()/2);

    int side = qMin(width(), height());
    p->scale(side/200.0, side/200.0);

    p->setPen(Qt::NoPen);
    p->setBrush(hourColor);

    QTime time = QTime::currentTime();

    p->save();
    p->rotate(30.0 * (time.hour() + time.minute()/60.0));
    p->drawConvexPolygon(hour_arrow, 3);
    p->restore();

    p->setPen(hourColor);

    for (int i = 0; i < 12; ++i) {
        p->drawLine(88, 0, 96, 0);
        p->rotate(30.0);
    }

    p->setPen(Qt::NoPen);
    p->setBrush(minuteColor);

    p->save();
    p->rotate(6.0 * (time.minute() + time.second()/60.0));
    p->drawConvexPolygon(minute_arrow, 3);
    p->restore();

    p->setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            p->drawLine(92, 0, 96, 0);
        p->rotate(6.0);
    }

}




int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    //ClockClass w;
    AnalogClock w;
    w.show();

    return app.exec();
}
