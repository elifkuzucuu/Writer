#include <QDebug>
#include <QObject>

#include "process.h"
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusMessage>


void Process::createNumber()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        int carCount = qrand() % 900 + 100 ;
        int occupancy = qrand() % 255;
        emit signalNumber(carCount,occupancy);

    }
    callDBus();
}

void Process::callDBus()
{
    QString m_managerService = "org.issd.report.service";
    QString m_managerPath = "/report";
    QString m_managerInterface = "org.issd.report.interface";

    QDBusMessage dbusMessage = QDBusMessage::createMethodCall(m_managerService,m_managerPath,m_managerInterface, "isReportCreated");
    QDBusReply<bool> reply = QDBusConnection::sessionBus().call(dbusMessage);

    if (reply.isValid())
        qDebug() << reply.value();
    else
        qDebug() << reply.error();

}
