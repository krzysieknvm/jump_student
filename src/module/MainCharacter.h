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

    bool dir, in_jump, is_on_ground, is_jumping; //dir(direction) -> left = false, right = true
    const double gravAcceleration = 0.4;
    double velocity = 0.0;
    const int refresh_rate = 16;

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

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};



#endif //MAINCHARACTER_H
