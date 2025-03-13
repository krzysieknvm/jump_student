//
// Created by kkoni on 12.03.2025.
//

#ifndef FIRSTSCENE_H
#define FIRSTSCENE_H

#include "../../module/MainCharacter.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>


class FirstScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit FirstScene(QObject *parent = nullptr);
    ~FirstScene();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    MainCharacter *player;
    QGraphicsRectItem *floor;

    void setup();
};



#endif //FIRSTSCENE_H
