//
// Created by kkoni on 12.03.2025.
//

#include "../module/StartWindow.h"
#include "../scenes/module/FirstScene.h"


StartWindow::StartWindow(QWidget *parent) : QGraphicsView(parent) {
    //USTAWIENIA OKNA
    setWindowTitle("Jump Student");
    setFixedSize(1024,768);

    //PRZYCISK ROZPOCZNIJ
    startBtn = new QPushButton("Rozpocznij", this);
    startBtn->setObjectName("startBtn");
    connect(startBtn, &QPushButton::clicked, this, &StartWindow::clearForGame);
    startBtn->setFixedSize(100,50);

    //NAPIS TESTOWY
    descLabel = new QLabel("Jump Student by Krzysztof Konieczny", this);
    descLabel->setObjectName("testLabel");
    descLabel->setAlignment(Qt::AlignCenter);
    descLabel->setGeometry(QRect(10, 10, 200, 50));

    //LAYOUT
    startingScreenLayout = new QVBoxLayout(this);

    startingScreenLayout->addWidget(startBtn);
    startingScreenLayout->addWidget(descLabel);
    startingScreenLayout->setContentsMargins(10,250,10,10);
    startingScreenLayout->setAlignment(startBtn,Qt::AlignCenter);
    setLayout(startingScreenLayout);
}

void StartWindow::clearForGame() {
    qDebug() << "Game start...";
    //CHOWANIE RZECZY POCZĄTKOWYCH
    this->findChild<QPushButton*>("startBtn")->hide();
    this->findChild<QLabel*>("testLabel")->hide();

    //USTAWIENIE PIERWSZEJ SCENY
    fScene = new FirstScene(this);
    setScene(fScene);
}