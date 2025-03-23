//
// Created by kkoni on 12.03.2025.
//

#include "../module/FirstScene.h"

#include <QGraphicsPixmapItem>
#include <QString>

FirstScene::FirstScene(QObject *parent) : QGraphicsScene(parent) {
    player = nullptr;
    floor = nullptr;
    setSceneRect(0,0,1022,758);
    setup();
}

void FirstScene::setup() {
    // USTAWIENIA SCENY
    setBackgroundBrush(QBrush(Qt::blue));

    //GENEROWANIE BOHATERA
    player = new MainCharacter();
    player->setPos(480,400);//x-480,y-660
    addItem(player);

    //GENEROWANIE PODŁOŻA
    //TODO: PRZEROBIĆ TO W OBIEKT
    floor = new QGraphicsRectItem(0,728,1024,40);
    floor->setBrush(QBrush(Qt::darkGreen));
    addItem(floor);
}