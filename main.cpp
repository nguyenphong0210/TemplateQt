#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QResource>
#include "HelloWorld.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QResource::registerResource("Content/Images.rcc");

    HelloWorld aa;
    aa.sayHello();

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/WinApp/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
