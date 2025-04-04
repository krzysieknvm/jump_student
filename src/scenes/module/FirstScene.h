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
    MainCharacter *player;
    QGraphicsRectItem *floor;

    QString dirPath;

};
#endif //FIRSTSCENE_H
