//
// Created by kkoni on 12.03.2025.
//

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "../scenes/module/FirstScene.h"

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

private:
    FirstScene *fScene;

    QPushButton *startBtn;
    QLabel *descLabel;
    QBoxLayout *startingScreenLayout;
};



#endif //STARTWINDOW_H
