//
// Created by kkoni on 13.03.2025.
//

#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class MainCharacter : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit MainCharacter(QGraphicsPixmapItem *parent = nullptr);
    // ~MainCharacter();

    bool dir, in_jump, is_on_ground; //dir(direction) -> left = false, right = true
    const double gravAcceleration = 0.098;
    double velocity = 0.0, acceleration = 0.0;

    void inJump();
    void jump();
    void changeDir();
    void gravity();

public slots:

private:
    QString dirPath;
    QString charVariant;

    QString characterInRestLeft;
    QString characterInRestRight;
    QString characterInJumpLeft;
    QString characterInJumpRight;

    QPixmap characterInRestPXLeft;
    QPixmap characterInRestPXRight;
    QPixmap characterInJumpPXLeft;
    QPixmap characterInJumpPXRight;

    QTimer *gravTimer;
    QTimer *jumpTimer;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};



#endif //MAINCHARACTER_H
