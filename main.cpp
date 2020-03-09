#include <QtGui>
#include "clockclass.h"


class AnalogClock : public ClockClass
{
public:
    AnalogClock();
    ~AnalogClock(){}

protected:
    void timerEvent(QTimerEvent*) Q_DECL_OVERRIDE;
    //void render(QPainter* p) Q_DECL_OVERRIDE;

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


//void AnalogClock::render(QPainter *p)
//{
//    ;
//}




int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    //ClockClass w;
    AnalogClock w;
    w.show();

    return app.exec();
}
