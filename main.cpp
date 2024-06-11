#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "UiController/chatlistmodel.h"
#include "UiController/uicontroller.h"

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

    ChatListModel model; // = new ChatListModel("John Doe", "12:30 AM", "Hello worldy World!");
    context->setContextProperty("_myModel", &model);

    qmlRegisterType<ChatListModel>("ui/ChatPersonView/ChatPersonView.qml", 1, 0, "ChatListModel");

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
