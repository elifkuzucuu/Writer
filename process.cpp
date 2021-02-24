#include <QDebug>
#include <QObject>

#include "process.h"


void Process::createNumber()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        int carCount = qrand() % 900 + 100 ;
        int occupancy = qrand() % 255;
        emit signalNumber(carCount,occupancy);

    }
}
