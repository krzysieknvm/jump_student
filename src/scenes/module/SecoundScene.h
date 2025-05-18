//
// Created by kkoni on 11.05.2025.
//

#ifndef SECOUNDSCENE_H
#define SECOUNDSCENE_H

#include <QGraphicsScene>

class SecoundScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit SecoundScene(QObject *parent = nullptr);
    void setup();
};



#endif //SECOUNDSCENE_H
