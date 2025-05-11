//
// Created by kkoni on 12.03.2025.
//

#ifndef FIRSTSCENE_H
#define FIRSTSCENE_H

#include "../../module/MainCharacter.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QString>

class FirstScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit FirstScene(QObject *parent = nullptr);
    void setup();

private:
    //Dla obiektów "stykowych" ustawiane są dodatkowe informacjie, dla ich dalszego rozróżniania
    //0 -> typ powierzchni (do sprawdzenia czy postać powinna się odbić czy zatrzymać się itp.

    MainCharacter *player;
    QGraphicsRectItem *floor;

    //Platforma 1
    QGraphicsRectItem *top_wall_p1;
    QGraphicsRectItem *bottom_wall_p1;
    QGraphicsRectItem *right_wall_p1;
    QGraphicsRectItem *left_wall_p1;

    //Platforma 2
    QGraphicsRectItem *top_wall_p2;
    QGraphicsRectItem *bottom_wall_p2;
    QGraphicsRectItem *right_wall_p2;
    QGraphicsRectItem *left_wall_p2;

    QString dirPath;

};
#endif //FIRSTSCENE_H
