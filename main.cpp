#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load("qrc:/qml/main.qml");

    return app.exec();
}
