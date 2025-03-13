//
// Created by kkoni on 13.03.2025.
//

#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <QGraphicsPixmapItem>


class MainCharacter : public QGraphicsPixmapItem {
public:
    explicit MainCharacter(const QString &characterInRest, const QString &characterInJump);
    void inJump(bool in_jump);

private:
    QPixmap characterInRestPX;
    QPixmap characterInJumpPX;
};



#endif //MAINCHARACTER_H
