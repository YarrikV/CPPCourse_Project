#include "myRect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "myRect knows that a key is pressed.";
    if (event->key() == Qt::Key_Left) {
        setPos(x() -10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x() +10, y());
    }
    else if (event->key() == Qt::Key_Up) {
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down) {
        setPos(x() , y()+10);
    } else if (event->key() == Qt::Key_Space) {
        // create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());

        qDebug() << "bullet created";

        // add bullet to scene
        scene()->addItem(bullet);
    }
}
