//
// Created by kkoni on 13.03.2025.
//

#include "../module/MainCharacter.h"

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QString>
#include <QTimer>

MainCharacter::MainCharacter(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent), dir(false), in_jump(false), is_on_ground(false) {
    //USTAWIENIE KLASY POD ODBIERANIE SYGNAŁÓW Z KLAWIATURY
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //USTAWIENIE GRAWITACJI
    gravTimer = new QTimer(this);
    connect(gravTimer, &QTimer::timeout, this, &MainCharacter::gravity);
    gravTimer->start(16);

    //TIMER DLA SKOKU
    jumpTimer = new QTimer(this);
    connect(jumpTimer, &QTimer::timeout, this, &MainCharacter::jump);

    //TODO: Zrobić kolejne warianty postaci
    //MODELE POSTACI
    charVariant = "mainChar_ver";

    dirPath = QCoreApplication::applicationDirPath();

    characterInRestLeft = dirPath.left(dirPath.lastIndexOf('/')) + "/src/resources/images/" + charVariant + "1_l.png";
    characterInRestRight =  dirPath.left(dirPath.lastIndexOf('/')) + "/src/resources/images/" + charVariant + "1_r.png";
    characterInJumpLeft = dirPath.left(dirPath.lastIndexOf('/')) +  "/src/resources/images/" + charVariant + "1_l_in_jump.png";
    characterInJumpRight = dirPath.left(dirPath.lastIndexOf('/')) +  "/src/resources/images/" + charVariant + "1_r_in_jump.png";

    characterInRestPXLeft = QPixmap(characterInRestLeft).scaled(57,72);
    characterInRestPXRight = QPixmap(characterInRestRight).scaled(57,72);
    characterInJumpPXLeft = QPixmap(characterInJumpLeft).scaled(57,66);
    characterInJumpPXRight = QPixmap(characterInJumpRight).scaled(57,66);

    setPixmap(characterInRestPXLeft);
}

void MainCharacter::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return;

    if (event->key() == Qt::Key_Space) {
        qDebug() << "Key_Press";
        this->in_jump = true;
        this->inJump();
    }

    switch (event->key()) {
        case Qt::Key_A:
            this->dir = false;
            this->changeDir();
        break;
        case Qt::Key_D:
            this->dir = true;
            this->changeDir();
        break;
    }
    QGraphicsPixmapItem::keyPressEvent(event);
}

void MainCharacter::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return;

    if (event->key() == Qt::Key_Space) {
        qDebug() << "Key_Release";
        this->in_jump = false;
        this->inJump();
    }
    QGraphicsPixmapItem::keyReleaseEvent(event);
}

void MainCharacter::inJump() {
    if (this->in_jump) {
        this->setPos(this->pos().x(),this->pos().y() + 6);
        setPixmap(this->dir ? characterInJumpPXRight : characterInJumpPXLeft);
    } else {
        this->setPos(this->pos().x(),this->pos().y() - 6);
        setPixmap(this->dir ? characterInRestPXRight : characterInRestPXLeft);
    }
}

void MainCharacter::changeDir() {
    if (this->in_jump) {
        setPixmap(this->dir ? characterInJumpPXRight : characterInJumpPXLeft);
    } else {
        setPixmap(this->dir ? characterInRestPXRight : characterInRestPXLeft);
    }
}

void MainCharacter::jump() {

    this->setY(this->pos().y() - 6);
}

void MainCharacter::gravity() {
    qDebug() << this->velocity;
    if (!is_on_ground) {
        this->velocity += (1 * gravAcceleration) + (1 * acceleration);
        this->setY(this->pos().y() + velocity);
    }

    QList<QGraphicsItem *> floors = this->collidingItems();
    for (QGraphicsItem *floor : floors) {
        if (floor->type() == QGraphicsRectItem::Type) {
            this->is_on_ground = true;
            this->velocity = 0.0;
            break;
        }
    }
}

