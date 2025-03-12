//
// Created by kkoni on 12.03.2025.
//

#ifndef FIRSTSCENE_H
#define FIRSTSCENE_H

#include <QGraphicsScene>
#include <QPushButton>

class FirstScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit FirstScene(QObject *parent = nullptr);

private:
    void setup();
};



#endif //FIRSTSCENE_H
