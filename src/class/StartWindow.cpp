//
// Created by kkoni on 12.03.2025.
//

#include "../module/StartWindow.h"

StartWindow::StartWindow(QWidget *parent) : QGraphicsView(parent) {
    //USTAWIENIA OKNA
    setWindowTitle("Jump Student");
    setFixedSize(1024,768);

    //GENEROWANIE SCEN
    fScene = new FirstScene(this);
    sScene = new SecoundScene(this);
    player = new MainCharacter();
    connect(player, &MainCharacter::switchToNextSceneSignal, this, &StartWindow::nextScene);
    connect(player, &MainCharacter::switchToPrevSceneSignal, this, &StartWindow::prevScene);

    //PRZYCISK ROZPOCZNIJ
    startBtn = new QPushButton("Rozpocznij", this);
    startBtn->setObjectName("startBtn");
    connect(startBtn, &QPushButton::clicked, this, &StartWindow::clearForGame);
    startBtn->setFixedSize(100,50);

    //NAPIS TESTOWY
    descLabel = new QLabel("Jump Student by Krzysztof Konieczny 2025", this);
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
    this->startBtn->hide();
    this->descLabel->hide();

    //USTAWIENIE PIERWSZEJ SCENY
    setScene(fScene);
    player->setPos(480,660);//x-480,y-660
    fScene->addItem(player);

    player->is_game_running = true;
}

void StartWindow::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return;

    if (event->key() == Qt::Key_Escape) {
        if (player->is_game_running) player->is_game_running = false;
        else player->is_game_running = true;
    }

    QGraphicsView::keyPressEvent(event);
}

void StartWindow::nextScene() {
    fScene->removeItem(player);
    setScene(sScene);
    sScene->addItem(player);

    player->can_switch_scene = true;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

void StartWindow::prevScene() {
    sScene->removeItem(player);
    setScene(fScene);
    fScene->addItem(player);

    player->can_switch_scene = true;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}