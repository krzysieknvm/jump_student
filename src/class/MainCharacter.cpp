//
// Created by kkoni on 13.03.2025.
//

#include "../module/MainCharacter.h"

#include "../module/StartWindow.h"
#include "../scenes/module/FirstScene.h"

MainCharacter::MainCharacter(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent), dir(false), in_jump(false), is_on_ground(false), is_jumping(false), is_jump_dir_set(false) {
    //USTAWIENIE KLASY POD ODBIERANIE SYGNAŁÓW Z KLAWIATURY
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    //USTAWIENIE GRAWITACJI
    physicsTimer = new QTimer(this);
    connect(physicsTimer, &QTimer::timeout, this, &MainCharacter::physics);
    physicsTimer->start(refresh_rate);

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
        //SPRAWDZENIE CZY POSTAĆ NIE JEST W SKOKU
        if (!this->is_jumping) {
            this->in_jump = true;

            //ROZPOCZĘCIE LICZENIA CZASU TRZYMANIA KLAWIATURY
            this->jumpTimer.start();
            inJump();
        }
    }

    switch (event->key()) {
        case Qt::Key_A:
            //SPRAWDZENIE CZY POSTAĆ NIE JEST W SKOKU
            if (!this->is_jumping) {

                //ZANA KIERUNKU "PATRZENIA" POSTACI
                this->dir = false;
                changeDir();
            }

            if (this->in_jump && !this->is_jump_dir_set) {
                this->is_jump_dir_set = true;
                this->jump_dir = -1;
            }
        break;
        case Qt::Key_D:
            //SPRAWDZENIE CZY POSTAĆ NIE JEST W SKOKU
            if (!this->is_jumping) {

                //ZANA KIERUNKU "PATRZENIA" POSTACI
                this->dir = true;
                changeDir();
            }

            if (this->in_jump && !this->is_jump_dir_set) {
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

        //ZLICZENIE CZASU TRZYMANIA SPACJI
        double jumpStrenght = this->jumpTimer.elapsed();
        inJump();

        //RESET KIERUNKU SKOKU
        if (!this->is_jump_dir_set) {
            this->is_jump_dir_set = true;
            this->jump_dir = 0;
        }

        //SKOK
        if (!this->is_jumping) jump(jumpStrenght);
    }
    QGraphicsPixmapItem::keyReleaseEvent(event);
}

void MainCharacter::inJump() {
    if (is_game_running) {
        if (this->in_jump) {
            this->setPos(this->pos().x(), this->pos().y() + 6);
            setPixmap(this->dir ? characterInJumpPXRight : characterInJumpPXLeft);
        } else {
            this->setPos(this->pos().x(), this->pos().y() - 6);
            setPixmap(this->dir ? characterInRestPXRight : characterInRestPXLeft);
        }
    }
}

void MainCharacter::changeDir() {
    if (is_game_running) {
        if (this->in_jump) {
            setPixmap(this->dir ? characterInJumpPXRight : characterInJumpPXLeft);
        } else {
            setPixmap(this->dir ? characterInRestPXRight : characterInRestPXLeft);
        }
    }
}

void MainCharacter::jump(double jumpStrenght) {
    //ZMIENNA MOCY SKOKU
    if (jumpStrenght > 750) jumpStrenght = 750;
    else if (jumpStrenght < 250) jumpStrenght = 250;

    //NADANIE PRĘDKOŚCI SKOKU
    this->velocity = -0.02 * jumpStrenght;

    //ZMIENNE BLOKUJĄCE
    this->is_on_ground = false;
    this->is_jumping = true;
}

void MainCharacter::physics() {
    if (is_game_running) {
        //WSZYSTKO ZE SPADANIEM
        if (!is_on_ground) {
            //PRZYSPIESZENIE GRAWITACYJNE
            this->velocity += (1 * this->gravAcceleration);

            //SKOK W BOK
            if (this->jump_dir == -1) this->setX(this->pos().x() - slideVar);
            else if (this->jump_dir == 1) this->setX(this->pos().x() + slideVar);

            //GRAWITACJA
            this->setY(this->pos().y() + velocity);

            //SPAWDZENIE KOLIZJI Z PODŁOŻEM
            QList<QGraphicsItem *> floors = this->collidingItems();
            for (QGraphicsItem *floor: floors) {
                if (floor->data(0) == "top_surface") {
                    //POPRAWA POZYCJI POSTACI
                    double floorLevel = floor->sceneBoundingRect().top() - 72; //Pozycja obiektu (Y) + wysokość postaci
                    if (floorLevel != this->pos().y()) this->setPos(this->pos().x(), floorLevel);

                    this->is_on_ground = true;
                    this->is_jumping = false;
                    this->is_jump_dir_set = false;

                    this->slideVar = 4;
                    this->velocity = 0.0;
                    break;
                }
                if (floor->data(0) == "side_surface") {
                    if (this->slideVar == 4) this->slideVar = -4;
                    else this->slideVar = 4;
                }
                if (floor->data(0) == "bottom_surface") {
                    this->velocity = 0.0;
                    this->slideVar = 0;
                }
            }
        }

        //PRAWA I LEWA GRANICA EKRANU
        if (this->pos().x() > 1030) this->setX(-20);
        if (this->pos().x() < -30) this->setX(1022);

        //PRZEKROCZENIE GÓRNEJ GRANICY EKRANU (ZMIANA SCENY)
        if (this->pos().y() < -10 && can_switch_scene) {
            can_switch_scene = false;
            emit switchToNextSceneSignal();
            this->setY(758);
        }

        //PRZEKROCZENIE DOLNEJ GRANICY EKRANU (ZMIANA SCENY)
        if (this->pos().y() > 770 && can_switch_scene) {
            can_switch_scene = false;
            emit switchToPrevSceneSignal();
            this->setY(0);
        }
    }
}

