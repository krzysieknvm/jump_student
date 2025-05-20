//
// Created by kkoni on 12.03.2025.
//

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "../scenes/module/FirstScene.h"
#include "../scenes/module/SecoundScene.h"

#include <QLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QString>

class StartWindow : public QGraphicsView {
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);

private slots:
    void clearForGame();
    void nextScene();
    void prevScene();

private:
    int curent_scene = 1;

    FirstScene *fScene;
    SecoundScene *sScene;

    MainCharacter *player;

    QPushButton *startBtn;
    QLabel *descLabel;
    QBoxLayout *startingScreenLayout;

protected:
    void keyPressEvent(QKeyEvent *event) override;
};



#endif //STARTWINDOW_H
