#include <QDebug>
#include <QObject>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDateTime>
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusMessage>


#include "write.h"


void Write :: writeNumber(int carCount, int occupancy)
{
    QDateTime currentTime;
    currentTime.currentMSecsSinceEpoch();
    
    QFile occupancyFile("Occupancy.txt");
    if (!occupancyFile.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    
    QTextStream outOccupancy(&occupancyFile);
    outOccupancy << "Current time: "<< QDateTime:: currentMSecsSinceEpoch() << " Occupancy: " << occupancy << "\n";
    occupancyFile.close();
    
    
    QFile carCountFile("CarCount.txt");
    if (!carCountFile.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QTextStream outCarCount(&carCountFile);
    outCarCount << "Current time: " << QDateTime :: currentMSecsSinceEpoch() << " Car count: " << carCount << endl;
    
    carCountFile.close();


}
