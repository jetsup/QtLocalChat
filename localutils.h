#pragma once

#include <QObject>
#include <QProcess>
#include <QQmlEngine>
#include <QRegularExpression>

class LocalUtils
{
public:
    LocalUtils();

    enum ConnectionType { NOT_CONNECTED = -1, WIFI_CONNECTED, ETHERNET_CONNECTED };

    static const QString STR_WIFI;
    static const QString STR_ETHERNET;

    /**
     * Get the network type and the Gateway IP
    */
    QMap<QString, QString> getNetworkTypeGateway();
};
