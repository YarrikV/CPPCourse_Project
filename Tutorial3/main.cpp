#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

/*
Events: (keyPressEvent() & QKeyEvent()
Event Propagation system
QDebug
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create scene, put it on heap
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item to put into the scene (by default size 0,0)
    MyRect * rect = new MyRect();
    rect->setRect(0,0, 100,100);

    // add item to scene
    scene->addItem(rect);

    // Only FOCUSED ITEM can respond to qkeyEvent
    // 1. make item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    // 2. set item as focus
    rect->setFocus();


    // create view
    QGraphicsView * view = new QGraphicsView(scene);
    // alternatively: view->setScene(scene);

    view->show();

    return a.exec();
}
