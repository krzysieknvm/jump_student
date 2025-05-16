//
// Created by kkoni on 16.05.2025.
//

#include "../module/Platform.h"

Platform::Platform(QPointF pos, QSizeF size) {
    qreal x = pos.x();
    qreal y = pos.y();
    qreal width = size.width();
    qreal height = size.height();

    top_wall = new QGraphicsRectItem(x + 4,y,width - 8,4);
    top_wall->setData(0, "top_surface");
    top_wall->setBrush(QBrush(Qt::darkGreen));

    bottom_wall = new QGraphicsRectItem(x + 4,y + height - 4, width - 8, 4);
    bottom_wall->setData(0, "bottom_surface");
    bottom_wall->setBrush(QBrush(Qt::darkRed));

    right_wall = new QGraphicsRectItem(x + width - 4, y, 4, height);
    right_wall->setData(0, "side_surface");
    right_wall->setBrush(QBrush(Qt::darkBlue));

    left_wall = new QGraphicsRectItem(x, y, 4, height);
    left_wall->setData(0, "side_surface");
    left_wall->setBrush(QBrush(Qt::darkYellow));

    this->addToGroup(top_wall);
    this->addToGroup(bottom_wall);
    this->addToGroup(right_wall);
    this->addToGroup(left_wall);
}
