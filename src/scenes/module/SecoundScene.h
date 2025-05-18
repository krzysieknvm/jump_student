//
// Created by kkoni on 11.05.2025.
//

#ifndef SECOUNDSCENE_H
#define SECOUNDSCENE_H

#include <QGraphicsScene>
#include <QCoreApplication>

#include "../../utils/module/Platform.h"

class SecoundScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit SecoundScene(QObject *parent = nullptr);
    void setup();

private:
    QString dirPath;

    Platform *p1;
    Platform *p2;
    Platform *p3;
    Platform *p4;
    Platform *p5;

};



#endif //SECOUNDSCENE_H
