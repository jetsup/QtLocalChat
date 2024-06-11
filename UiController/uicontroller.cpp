#include "uicontroller.h"

UiController::UiController(QObject *parent)
    : QObject{parent}
    , m_netSpeed(0)
    , m_onlineMembers(0)
    , m_connectedNetwork(-1)
{}

int UiController::netSpeed() const
{
    return m_netSpeed;
}

void UiController::setNetSpeed(int newNetSpeed)
{
    if (m_netSpeed == newNetSpeed)
        return;
    m_netSpeed = newNetSpeed;
    emit netSpeedChanged();
}

int UiController::onlineMembers() const
{
    return m_onlineMembers;
}

void UiController::setOnlineMembers(int newOnlineMembers)
{
    if (m_onlineMembers == newOnlineMembers)
        return;
    m_onlineMembers = newOnlineMembers;
    emit onlineMembersChanged();
}

short UiController::connectedNetwork() const
{
    return m_connectedNetwork;
}

void UiController::setConnectedNetwork(short newConnectedNetwork)
{
    if (m_connectedNetwork == newConnectedNetwork)
        return;
    m_connectedNetwork = newConnectedNetwork;
    emit connectedNetworkChanged();
}

unsigned long UiController::currentTime() const
{
    return m_currentTime;
}

void UiController::setCurrentTime(unsigned long newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}
