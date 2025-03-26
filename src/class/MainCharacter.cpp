//
// Created by kkoni on 13.03.2025.
//

#include "../module/MainCharacter.h"

#include <QKeyEvent>
#include <QCoreApplication>
#include <QTimer>

#include "../scenes/module/FirstScene.h"

MainCharacter::MainCharacter(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent), dir(false), in_jump(false), is_on_ground(false), is_jumping(false), is_jump_dir_set(false) {
    //USTAWIENIE KLASY POD ODBIERANIE SYGNAŁÓW Z KLAWIATURY
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //USTAWIENIE GRAWITACJI
    physicsTimer = new QTimer(this);
    connect(physicsTimer, &QTimer::timeout, this, &MainCharacter::physics);
    physicsTimer->start(refresh_rate);

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
    //BLOKOWANIE AUTOPOWTARZANIA PRZYCISKÓW
    if (event->isAutoRepeat()) return;

    if (event->key() == Qt::Key_Space) {
        this->in_jump = true;
        inJump();
    }

    switch (event->key()) {
        case Qt::Key_A:
            this->dir = false;
            changeDir();

            if (this->in_jump && !this->is_jump_dir_set) {
                qDebug() << "Skok w lewo " << this->is_jump_dir_set;
                this->is_jump_dir_set = true;
                this->jump_dir = -1;
            }
        break;
        case Qt::Key_D:
            this->dir = true;
            changeDir();

            if (this->in_jump && !this->is_jump_dir_set) {
                qDebug() << "Skok w prawo " << this->is_jump_dir_set;
                this->is_jump_dir_set = true;
                this->jump_dir = 1;
            }
        break;
    }
    QGraphicsPixmapItem::keyPressEvent(event);
}

void MainCharacter::keyReleaseEvent(QKeyEvent *event) {
    //BLOKOWANIE AUTOPOWTARZANIA PRZYCISKÓW
    if (event->isAutoRepeat()) return;

    if (event->key() == Qt::Key_Space) {
        this->in_jump = false;
        inJump();

        //SKOK
        if (!this->is_jumping) jump();
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
    //ZMIENNE BLOKUJĄCE
    this->is_on_ground = false;
    this->is_jumping = true;

    //NADANIE PRĘDKOŚCI SKOKU
    this->velocity = -14;
}

void MainCharacter::physics() {
    //TODO: Sprawić by po skoku kierunek skoku zmieniał się na 0

    //WSZYSTKO ZE SPADANIEM
    if (!is_on_ground) {
        //PRZYSPIESZENIE GRAWITACYJNE
        this->velocity += (1 * this->gravAcceleration);

        //SKOK W BOK
        if (this->jump_dir == -1) this->setX(this->pos().x() - 4);
        else if (this->jump_dir == 1) this->setX(this->pos().x() + 4);

        //GRAWITACJA
        this->setY(this->pos().y() + velocity);
    }

    //PRAWA I LEWA GRANICA EKRANU
    if (this->pos().x() > 1030) this->setX(-20);
    if (this->pos().x() < -30) this->setX(1022);

    //SPAWDZENIE KOLIZJI Z PODŁOŻEM
    QList<QGraphicsItem *> floors = this->collidingItems();
    for (QGraphicsItem *floor : floors) {
        if (floor->type() == QGraphicsRectItem::Type) {
            this->is_on_ground = true;
            this->is_jumping = false;
            this->is_jump_dir_set = false;

            this->velocity = 0.0;
            break;
        }
    }
}

