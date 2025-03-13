//
// Created by kkoni on 12.03.2025.
//

#include "../module/StartWindow.h"
#include "../scenes/module/FirstScene.h"

#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QDebug>

//TODO: Zmienić bohatera na klase i dodać jakiś ruch

StartWindow::StartWindow(QWidget *parent) : QGraphicsView(parent) {
    //USTAWIENIA OKNA
    setWindowTitle("Jump Student");
    setFixedSize(1024,768);

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
    layout->addWidget(testLabel);
    layout->setContentsMargins(10,250,10,10);
    layout->setAlignment(startBtn,Qt::AlignCenter);
    setLayout(layout);
}

void StartWindow::clearForGame() {
    //TODO: Nie działa i nie wiem czemu
    //CHOWANIE RZECZY POCZĄTKOWYCH
    if (startBtn && testLabel) {
        startBtn->hide();
        testLabel->hide();
    }

    //USTAWIENIE PIERWSZEJ SCENY
    FirstScene *fScene = new FirstScene(this);
    setScene(fScene);
}

StartWindow::~StartWindow() {
    delete testLabel;
}