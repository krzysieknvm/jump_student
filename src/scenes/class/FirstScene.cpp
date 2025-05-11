//
// Created by kkoni on 12.03.2025.
//

#include "../module/FirstScene.h"

#include <QCoreApplication>
#include <QPixmap>

FirstScene::FirstScene(QObject *parent) : QGraphicsScene(parent) {
    dirPath = QCoreApplication::applicationDirPath();
    setSceneRect(0,0,1022,758);

    // USTAWIENIA SCENY
    setBackgroundBrush(QPixmap(dirPath.left(dirPath.lastIndexOf('/')) + "/src/resources/images/fscene_bg.png"));

    //GENEROWANIE BOHATERA
    player = new MainCharacter();

    //GENEROWANIE PODŁOŻA
    floor = new QGraphicsRectItem(0,728,1024,40);

    //Platforma 1
    top_wall_p1 = new QGraphicsRectItem(4, 524 ,300,4);
    bottom_wall_p1 = new QGraphicsRectItem(4, 724,300,4);
    right_wall_p1 = new QGraphicsRectItem(304, 524, 4, 200);
    left_wall_p1 = new QGraphicsRectItem(0, 524, 4, 200);

    //Platforma 2
    top_wall_p2 = new QGraphicsRectItem(724, 524 ,300,4);
    bottom_wall_p2 = new QGraphicsRectItem(724, 724,300,4);
    right_wall_p2 = new QGraphicsRectItem(720, 524, 4, 200);
    left_wall_p2 = new QGraphicsRectItem(1020, 524, 4, 200);

    setup();
}

void FirstScene::setup() {
    //DODANIE BOHATERA DO SCENY
    player->setPos(480,400);//x-480,y-660
    addItem(player);

    //DODANIE PODŁOŻA DO SCENY
    floor->setData(0, "top_surface");
    floor->setBrush(QBrush(Qt::darkGreen));
    addItem(floor);

    top_wall_p1->setData(0, "top_surface");
    top_wall_p1->setBrush(QBrush(Qt::darkGreen));
    addItem(top_wall_p1);

    bottom_wall_p1->setData(0, "bottom_surface");
    bottom_wall_p1->setBrush(QBrush(Qt::darkRed));
    addItem(bottom_wall_p1);

    right_wall_p1->setData(0, "side_surface");
    right_wall_p1->setBrush(QBrush(Qt::darkBlue));
    addItem(right_wall_p1);

    left_wall_p1->setData(0, "side_surface");
    left_wall_p1->setBrush(QBrush(Qt::darkYellow));
    addItem(left_wall_p1);

    top_wall_p2->setData(0, "top_surface");
    top_wall_p2->setBrush(QBrush(Qt::darkGreen));
    addItem(top_wall_p2);

    bottom_wall_p2->setData(0, "bottom_surface");
    bottom_wall_p2->setBrush(QBrush(Qt::darkRed));
    addItem(bottom_wall_p2);

    right_wall_p2->setData(0, "side_surface");
    right_wall_p2->setBrush(QBrush(Qt::darkBlue));
    addItem(right_wall_p2);

    left_wall_p2->setData(0, "side_surface");
    left_wall_p2->setBrush(QBrush(Qt::darkYellow));
    addItem(left_wall_p2);
}
