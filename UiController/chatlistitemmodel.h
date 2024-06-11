#pragma once

#include <QAbstractListModel>
#include "chatlistmodelcontroller.h"

class ChatListItemModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(
        QString contactName READ contactName WRITE setContactName NOTIFY contactNameChanged FINAL)
    Q_PROPERTY(QString msgTime READ msgTime WRITE setMsgTime NOTIFY msgTimeChanged FINAL)
    Q_PROPERTY(
        QString lastMessage READ lastMessage WRITE setLastMessage NOTIFY lastMessageChanged FINAL)

public:
    // explicit ChatListItemModel(QObject *parent = nullptr);
    ChatListItemModel(const ChatListModelController *controller);

    QString contactName() const;
    void setContactName(const QString &newContactName);
    QString msgTime() const;
    void setMsgTime(const QString &newMsgTime);

    QString lastMessage() const;
    void setLastMessage(const QString &newLastMessage);

signals:
    void contactNameChanged();

    void msgTimeChanged();

    void lastMessageChanged();

private:
    QString m_contactName;
    QString m_msgTime;
    QString m_lastMessage;

    QList<ChatListModelController::ChatRecipient> data_;
};
