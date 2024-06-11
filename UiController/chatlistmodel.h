#pragma once

#include <QAbstractListModel>
#include <QQmlEngine>

class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    enum Roles { NameRole = Qt::UserRole, userNameRole, lastMessageTimeRole, lastMessageRole };

    explicit ChatListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    struct Recipient
    {
        QString userName;
        QString lastMsgTime;
        QString lastMesssage;
    };
    QVector<Recipient> m_recipient;
};
