#pragma once

#include <QObject>

class UiController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int netSpeed READ netSpeed WRITE setNetSpeed NOTIFY netSpeedChanged FINAL)
    Q_PROPERTY(int onlineMembers READ onlineMembers WRITE setOnlineMembers NOTIFY
                   onlineMembersChanged FINAL)
    /*-1 not connected 0 WiFi 1 Ethernet*/
    Q_PROPERTY(short connectedNetwork READ connectedNetwork WRITE setConnectedNetwork NOTIFY
                   connectedNetworkChanged FINAL)
    // epoch time
    Q_PROPERTY(unsigned long currentTime READ currentTime WRITE setCurrentTime NOTIFY
                   currentTimeChanged FINAL)
    Q_PROPERTY(QString networkImageSrc READ networkImageSrc WRITE setNetworkImageSrc NOTIFY
                   networkImageSrcChanged FINAL)

public:
    explicit UiController(QObject *parent = nullptr);

    int netSpeed() const;
    void setNetSpeed(int newNetSpeed);

    int onlineMembers() const;
    void setOnlineMembers(int newOnlineMembers);

    short connectedNetwork() const;
    void setConnectedNetwork(short newConnectedNetwork);

    unsigned long currentTime() const;
    void setCurrentTime(unsigned long newCurrentTime);

    QString networkImageSrc() const;
    void setNetworkImageSrc(const QString &newNetworkImageSrc);

signals:
    void netSpeedChanged();

    void onlineMembersChanged();

    void connectedNetworkChanged();

    void currentTimeChanged();

    void networkImageSrcChanged();

private:
    int m_netSpeed;
    int m_onlineMembers;
    short m_connectedNetwork;
    unsigned long m_currentTime;
    QString m_networkImageSrc;
};
