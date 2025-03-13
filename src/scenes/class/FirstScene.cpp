//
// Created by kkoni on 12.03.2025.
//

#include "../module/FirstScene.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>

FirstScene::FirstScene(QObject *parent) : QGraphicsScene(parent) {
    setSceneRect(0,0,1022,758);
    setup();
}

void FirstScene::setup() {
    // USTAWIENIA SCENY
    setBackgroundBrush(QBrush(Qt::blue));

    //GENEROWANIE BOHATERA
    player = new MainCharacter("C:/Users/kkoni/Documents/PW/MCHTR/sem_2/ZAP_pr/jump_student/src/resources/images/mainChar_ver1_l.png", "C:/Users/kkoni/Documents/PW/MCHTR/sem_2/ZAP_pr/jump_student/src/resources/images/mainChar_ver1_l_in_jump.png");
    player->setPos(480,660);
    addItem(player);

    //GENEROWANIE PODŁOŻA
    floor = new QGraphicsRectItem(0,728,1024,40);
    floor->setBrush(QBrush(Qt::darkGreen));
    addItem(floor);
}

void FirstScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        qDebug() << "Key_Press";
        player->setPos(480,player->pos().y() + 6);
        player->inJump(true);
    }
    QGraphicsScene::keyPressEvent(event);
}

void FirstScene::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        qDebug() << "Key_Release";
        player->setPos(480,player->pos().y() - 6);
        player->inJump(false);
    }
    QGraphicsScene::keyReleaseEvent(event);
}

FirstScene::~FirstScene() {

}