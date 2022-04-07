#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <QBrush>
#include <QtGlobal>
#include <qpainter.h>
#include <qrgba64.h>
/*
Classes:
* QGraphicsScene : container of objects in scene, the info
* QGraphicsItem : anything in a scene has to be derived from this class
* QGraphicsView : widget used to visualise the scene
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create scene, put it on heap
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item to put into the scene (by default size 0,0)
    QGraphicsRectItem * rect = new QGraphicsRectItem();

    rect->setRect(0,0, 100,100);

    rect->setBrush(QColor(240,116,16,256));



    rect->setPen(Qt::NoPen);


    // add item to scene
    scene->addItem(rect);

    // create view
    QGraphicsView * view = new QGraphicsView(scene);
    // alternatively: view->setScene(scene);

    view->show();

    return a.exec();
}
