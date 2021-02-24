#ifndef WRITE_H
#define WRITE_H

#include <QObject>

class Write : public QObject
{


    Q_OBJECT


public slots:
    void writeNumber(int carCount,int occupancy);


};

#endif // WRITE_H
