//
// Created by kkoni on 16.05.2025.
//

#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsItemGroup>
#include <QBrush>

class Platform : public QGraphicsItemGroup {
public:
    Platform(QPointF pos, QSizeF size);

private:
    QGraphicsRectItem *top_wall;
    QGraphicsRectItem *bottom_wall;
    QGraphicsRectItem *right_wall;
    QGraphicsRectItem *left_wall;
};



#endif //PLATFORM_H
