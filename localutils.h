#pragma once

#include <QObject>
#include <QProcess>
#include <QQmlEngine>
#include <QRegularExpression>

class LocalUtils
{
public:
    LocalUtils();

    /**
     * Get the network type and the Gateway IP
    */
    QMap<QString, QString> getNetworkTypeGateway();
};
