#include "localutils.h"

const QString LocalUtils::STR_WIFI = "WIFI";
const QString LocalUtils::STR_ETHERNET = "ETHERNET";

LocalUtils::LocalUtils() {}

QMap<QString, QString> LocalUtils::getNetworkTypeGateway()
{
    QMap<QString, QString> data;

    QProcess process;
    process.start("route", QStringList() << "-n");
    process.waitForFinished();

    if (process.exitStatus() == QProcess::NormalExit) {
        QString output = process.readAllStandardOutput();

        QRegularExpression re(
            "(\\d{1,3}.\\d{1,3}.\\d{1,3}.\\d{1,3})\\s+\\d{1,3}.\\d{1,3}.\\d{1,3}.\\d{1,3}\\s+UG");

        QRegularExpressionMatchIterator matches = re.globalMatch(output);

        while (matches.hasNext()) {
            QRegularExpressionMatch match = matches.next();

            if (match.hasMatch()) {
                QString gateway = match.captured(1);
                qDebug() << "Gateway:" << gateway;
                data.insert("gateway", gateway);
                break;
            }
        }
    }

    process.start("arp", QStringList() << "-n");
    process.waitForFinished();
    data.insert("interface", "NONE");
    if (process.exitStatus() == QProcess::NormalExit) {
        QString output = process.readAllStandardOutput();
        // https://regexr.com/
        QRegularExpression re("(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})\\s+\\S+\\s+([0-9a-fA-f]{"
                              "2}(?::[0-9a-fA-F]{2}){5})\\s+\\S\\s+(\\S+)");

        QRegularExpressionMatchIterator matches = re.globalMatch(output);

        while (matches.hasNext()) {
            QRegularExpressionMatch match = matches.next();

            if (match.hasMatch()) {
                QString iface = match.captured(3);

                qDebug() << "Interface:" << iface;
                if (iface.contains("wl")) {
                    iface = STR_WIFI;
                } else {
                    iface = STR_ETHERNET;
                }
                data.insert("interface", iface);
                break;
            }
        }
    } else {
        qDebug() << "arp command not found. Network scanning might not work.";
        data.insert("interface", "NONE");
    }

    return data;
}
