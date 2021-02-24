#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QObject>
#include <QDBusReply>
#include <QDBusMessage>
#include <QtDBus/QtDBus>
#include <QtDBus/QDBusConnection>

#include "process.h"
#include "write.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread processThread;
    QThread writeThread;


    Process process ;
    Write write;


    write.moveToThread(&writeThread);
    process.moveToThread(&processThread);

    writeThread.start();
    processThread.start();
    QObject :: connect(&process , &Process :: signalNumber , &write , &Write :: writeNumber);
    process.createNumber();

    QString m_managerService = "org.issd.writer.service";
    QString m_managerPath = "/main";
    QString m_managerInterface = "org.issd.writer.interface";

    QDBusMessage dbusMessage = QDBusMessage::createMethodCall(m_managerService,m_managerPath,m_managerInterface, "isReportCreated");
    QDBusReply<bool> reply = QDBusConnection::sessionBus().call(dbusMessage);

    if (reply.isValid())
        qDebug() << reply.value();
    else
        qDebug() << reply.error();



    return a.exec();
}
