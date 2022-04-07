#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <qobject.h>

class Bullet : public QGraphicsRectItem, public QObject
{
    Q_OBJECT
public:
    Bullet();
public slots: // slot can be connected to a signal, needs QObject
    void move();

};

#endif // BULLET_H
