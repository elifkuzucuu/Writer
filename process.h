#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>

class Process : public QObject
{
    Q_OBJECT

public:
        void createNumber();
        void callDBus();
signals:
        void signalNumber(int carCount, int occupancy);


};

#endif // PROCESS_H
