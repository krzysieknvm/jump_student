//
// Created by kkoni on 12.03.2025.
//

#include "../module/FirstScene.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>

FirstScene::FirstScene(QObject *parent) : QGraphicsScene(parent) {
    setSceneRect(0,0,1022,758);
    setup();
}

void FirstScene::setup() {
    // USTAWIENIA SCENY
    setBackgroundBrush(QBrush(Qt::blue));

    //GENEROWANIE BOHATERA
    QPixmap pixmap("C:/Users/kkoni/Documents/PW/MCHTR/sem_2/ZAP_pr/jump_student/src/resources/images/mainChar_ver1.png");
    player = new QGraphicsPixmapItem(pixmap);
    player->setScale(3.0);
    player->setPos(480,660);
    addItem(player);
}