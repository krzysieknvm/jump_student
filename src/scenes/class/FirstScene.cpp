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
    player->setPos(480,400);//x-480,y-660
    addItem(player);

    //GENEROWANIE PODŁOŻA
    //TODO: PRZEROBIĆ TO W OBIEKT
    floor = new QGraphicsRectItem(0,728,1024,40);
    floor->setBrush(QBrush(Qt::darkGreen));
    addItem(floor);
}