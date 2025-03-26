//
// Created by kkoni on 12.03.2025.
//

#include "../module/StartWindow.h"
#include "../scenes/module/FirstScene.h"


StartWindow::StartWindow(QWidget *parent) : QGraphicsView(parent) {
    //USTAWIENIA OKNA
    setWindowTitle("Jump Student");
    setFixedSize(1024,768);

    //GENEROWANIE PIERWSZEJ SCENY
    fScene = new FirstScene(this);

    //PRZYCISK ROZPOCZNIJ
    startBtn = new QPushButton("Rozpocznij", this);
    startBtn->setObjectName("startBtn");
    connect(startBtn, &QPushButton::clicked, this, &StartWindow::clearForGame);
    startBtn->setFixedSize(100,50);

    //NAPIS TESTOWY
    descLabel = new QLabel("Jump Student by Krzysztof Konieczny", this);
    descLabel->setObjectName("descLabel");
    descLabel->setAlignment(Qt::AlignCenter);

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
    this->findChild<QLabel*>("descLabel")->hide();

    //USTAWIENIE PIERWSZEJ SCENY
    setScene(fScene);
}