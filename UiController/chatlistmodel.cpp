#include "chatlistmodel.h"

ChatListModel::ChatListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_recipient << Recipient{"George", "09:30", "Hi there! How are you doing?"}
                << Recipient{"Jack", "10:15", "I got your message and will respond soon."}
                << Recipient{"Juliet", "11:00", "Good morning!"};
}

int ChatListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_recipient.size();
}

QVariant ChatListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const Recipient &recipient = m_recipient.at(index.row());
    if (role == NameRole) {
        return recipient.userName;
    } else if (role == lastMessageTimeRole) {
        return recipient.lastMsgTime;
    } else if (role == lastMessageRole) {
        return recipient.lastMesssage;
    } else {
        return QVariant();
    }
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    static QHash<int, QByteArray> mapping{{NameRole, "name"},
                                          {lastMessageTimeRole, "time"},
                                          {lastMessageRole, "message"}};
    return mapping;
}
