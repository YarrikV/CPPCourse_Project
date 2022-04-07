#include "bullet.h"
#include <QTimer>

Bullet::Bullet()
{
    // drew rect
    setRect(0,0,10,50);
    // we want to add it to the scene, but not here

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    // ^Connects timeout fion of timer to move function of this bullet

    timer->start(50); // 50 ms
}

void Bullet::move()
{
    // move bullet up
    setPos(x(), y()-10);
}
