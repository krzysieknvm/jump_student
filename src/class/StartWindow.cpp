//
// Created by kkoni on 12.03.2025.
//

#include "../module/StartWindow.h"
#include "../scenes/module/FirstScene.h"

#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QDebug>

//TODO: Dorobić przycisk startowy

StartWindow::StartWindow(QWidget *parent) : QGraphicsView(parent) {
    qDebug() << "StartWindow::StartWindow";
    //USTAWIENIA OKNA
    setWindowTitle("Jump Student");
    setFixedSize(1024,768);

    //USTAWIENIE PIERWSZEJ SCENY
    FirstScene *fScene = new FirstScene(this);
    setScene(fScene);

    //PRZYCISK ROZPOCZNIJ
    QPushButton *startBtn = new QPushButton("Rozpocznij", this);
    connect(startBtn, &QPushButton::clicked, this, &StartWindow::clearForGame);
    startBtn->setFixedSize(100,50);

    //NAPIS TESTOWY
    QLabel *testLabel = new QLabel("Jump Student by Krzysztof Konieczny", this);
    testLabel->setAlignment(Qt::AlignCenter);
    testLabel->setGeometry(QRect(10, 10, 200, 50));

    //LAYOUT
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(startBtn);
    layout->setAlignment(startBtn,Qt::AlignCenter);
    setLayout(layout);
}

void StartWindow::clearForGame() {
    // testLabel->hide();
}

StartWindow::~StartWindow() {
    delete testLabel;
}