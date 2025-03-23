//
// Created by kkoni on 12.03.2025.
//

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

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
    QGraphicsScene *menuStart;

    QPushButton *startBtn;
    QLabel *testLabel;
    QBoxLayout *layout;
};



#endif //STARTWINDOW_H
