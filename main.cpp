#include "src/module/StartWindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QFile file("app_loggs.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << msg << "\n";
    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();

    qInstallMessageHandler(customMessageHandler);
    return a.exec();
}
