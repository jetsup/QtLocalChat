#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "UiController/uicontroller.h"
#include <UiController/chatlistitemmodel.h>
#include <UiController/chatlistmodelcontroller.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    UiController m_uiHandler;

    QQmlApplicationEngine engine;

    // be done before loading the QML
    QQmlContext *context(engine.rootContext());
    context->setContextProperty("uiHandler", &m_uiHandler);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
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
