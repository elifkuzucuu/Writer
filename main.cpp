#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QObject>

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




    return a.exec();
}
