//
// Created by kkoni on 13.03.2025.
//

#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <QElapsedTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QTimer>


class MainCharacter : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit MainCharacter(QGraphicsPixmapItem *parent = nullptr);

    // dir -> kierunek patrzenia postaci --> left = false, right = true
    // in_jump -> czy postać jest w fazie "ładowania" koku (wygląd)
    // in_on_ground -> czy postać znajduje się na podłożu
    // is_jumping -> czy postać jest w fazie skoku (pozycja)
    // is_jump_dir_set -> czy postać w danym skoku ma ustawiony kierunek
    // slideVar -> w zależności od znaku dodaje lub odejmuje pozycje w X przy skoku

    bool dir, in_jump, is_on_ground, is_jumping, is_jump_dir_set, is_game_running = false, can_switch_scene = true;
    int jump_dir = 0; //jump dir -> 0 = none, -1 = left, 1 = right
    const double gravAcceleration = 0.4;
    double velocity = 0.0;
    int slideVar = 4;
    const int refresh_rate = 16;

    void inJump();
    void jump(double jumpStrenght);
    void changeDir();
    void physics();

signals:
    void switchToNextSceneSignal();
    void switchToPrevSceneSignal();

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

    QTimer *physicsTimer;
    QElapsedTimer jumpTimer;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};



#endif //MAINCHARACTER_H
