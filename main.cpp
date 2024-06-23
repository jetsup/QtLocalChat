#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "UiController/chatlistmodel.h"
#include "UiController/uicontroller.h"
#include "localutils.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    UiController m_uiHandler;

    LocalUtils utils;
    QMap<QString, QString> networkDetails = utils.getNetworkTypeGateway();

    QQmlApplicationEngine engine;

    // be done before loading the QML
    QQmlContext *context(engine.rootContext());
    context->setContextProperty("uiHandler", &m_uiHandler);

    ChatListModel model; // = new ChatListModel("John Doe", "12:30 AM", "Hello worldy World!");
    context->setContextProperty("_myModel", &model);
    if (networkDetails["interface"] != "NONE") {
        context->setContextProperty("_networkType",
                                    networkDetails["interface"] + " (" + networkDetails["gateway"]
                                        + ")");
        if (networkDetails["interface"] == LocalUtils::STR_WIFI) {
            m_uiHandler.setConnectedNetwork(LocalUtils::WIFI_CONNECTED);
            m_uiHandler.setNetworkImageSrc("qrc:/ui/assets/wifi.png");
        } else {
            m_uiHandler.setConnectedNetwork(LocalUtils::ETHERNET_CONNECTED);
            m_uiHandler.setNetworkImageSrc("qrc:/ui/assets/ethernet.png");
        }
    } else {
        context->setContextProperty("_networkType", "Not Connected");
        m_uiHandler.setConnectedNetwork(LocalUtils::NOT_CONNECTED);
        m_uiHandler.setNetworkImageSrc("qrc:/ui/assets/no-connection.png");
    }

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
