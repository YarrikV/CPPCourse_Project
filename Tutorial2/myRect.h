#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem {
public:
    void keyPressEvent(QKeyEvent * event); // allows class to respond to qkeyevent
};


#endif // MYRECT_H
