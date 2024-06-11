#include "chatlistitemmodel.h"

// ChatListItemModel::ChatListItemModel(QObject *parent)
//     : QAbstractListModel{parent}
// {}

ChatListItemModel::ChatListItemModel(const ChatListModelController *controller)
    : data_(controller->getChatRecipients())
{}

QString ChatListItemModel::contactName() const
{
    return m_contactName;
}

void ChatListItemModel::setContactName(const QString &newContactName)
{
    if (m_contactName == newContactName)
        return;
    m_contactName = newContactName;
    emit contactNameChanged();
}

QString ChatListItemModel::msgTime() const
{
    return m_msgTime;
}

void ChatListItemModel::setMsgTime(const QString &newMsgTime)
{
    if (m_msgTime == newMsgTime)
        return;
    m_msgTime = newMsgTime;
    emit msgTimeChanged();
}

QString ChatListItemModel::lastMessage() const
{
    return m_lastMessage;
}

void ChatListItemModel::setLastMessage(const QString &newLastMessage)
{
    if (m_lastMessage == newLastMessage)
        return;
    m_lastMessage = newLastMessage;
    emit lastMessageChanged();
}
