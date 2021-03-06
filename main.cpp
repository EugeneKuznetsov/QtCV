#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <opencv2/opencv.hpp>
#include "helloworldfilter.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<HelloWorldFilter>("Eugene.QtCV.Filters", 1, 0, "HelloWorldFilter");

    engine.load("qrc:/qml/main.qml");

    return app.exec();
}
