//
// Created by kkoni on 11.05.2025.
//

#include "../module/SecoundScene.h"

SecoundScene::SecoundScene(QObject *parent) : QGraphicsScene(parent) {
    dirPath = QCoreApplication::applicationDirPath();
    setBackgroundBrush(QPixmap(dirPath.left(dirPath.lastIndexOf('/')) + "/src/resources/images/sscene_bg.png"));

    setSceneRect(0,0,1022,758);

    p1 = new Platform(QPointF(300, 650), QSizeF(150, 50));
    p2 = new Platform(QPointF(600, 550), QSizeF(200, 50));
    p3 = new Platform(QPointF(980, 450), QSizeF(50, 50));
    p4 = new Platform(QPointF(50, 350), QSizeF(200, 50));
    p5 = new Platform(QPointF(200, 150), QSizeF(200, 50));

    setup();
}

void SecoundScene::setup() {
    addItem(p1);
    addItem(p2);
    addItem(p3);
    addItem(p4);
    addItem(p5);
}