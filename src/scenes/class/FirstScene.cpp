//
// Created by kkoni on 12.03.2025.
//

#include "../module/FirstScene.h"

FirstScene::FirstScene(QObject *parent) : QGraphicsScene(parent) {
    dirPath = QCoreApplication::applicationDirPath();
    setSceneRect(0,0,1022,758);

    // USTAWIENIA SCENY
    setBackgroundBrush(QPixmap(dirPath.left(dirPath.lastIndexOf('/')) + "/src/resources/images/fscene_bg.png"));

    //GENEROWANIE PODŁOŻA
    floor = new QGraphicsRectItem(0,728,1024,40);

    //Platformy
    p1 = new Platform(QPoint(0,528), QSizeF(300, 200));
    p2 = new Platform(QPoint(724,528), QSizeF(300, 200));
    p3 = new Platform(QPoint(400,300), QSizeF(200, 100));
    p4 = new Platform(QPoint(0,100), QSizeF(350, 100));

    setup();
}

void FirstScene::setup() {
    //DODANIE PODŁOŻA DO SCENY
    floor->setData(0, "top_surface");
    floor->setBrush(QBrush(Qt::darkGreen));
    addItem(floor);

    addItem(p1);
    addItem(p2);
    addItem(p3);
    addItem(p4);
}
