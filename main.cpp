#include <QtGui>
#include "clockclass.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    ClockClass w;
    w.show();

    return app.exec();
}
