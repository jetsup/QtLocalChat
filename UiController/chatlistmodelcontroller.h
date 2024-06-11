#pragma once

#include <QAbstractListModel>
#include <QDebug>
#include <QObject>
#include <QString>

class ChatListModelController : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ChatListModelController *chatListModel READ chatListModel WRITE setChatListModel
                   NOTIFY chatListModelChanged FINAL)

    // QML_ELEMENT
public:
    ChatListModelController();
    // explicit ChatListModelController(QObject *paretn = 0);

    ChatListModelController *chatListModel() const;
    void setChatListModel(ChatListModelController *newChatListModel);
    // ~ChatListModelController(); //

    struct ChatRecipient
    {
        QString name;
        QString msgTime;
        QString lastMessage;
    };
    QList<ChatRecipient> getChatRecipients() const;
    QList<ChatRecipient> chatRecipients;
signals:
    void chatListModelChanged();

private:
    // QList<ChatRecipient> chatRecipients = {
    //     // Add your hardcoded profiles here
    //     {"John Doe",
    //      "12:09 AM",
    //      "This is a message bro sent me from home to let me know how he is doing."},
    //     {"Jane Doe", "10:30 PM", "Hey! How are you doing?"},
    //     {"Mike Smith", "08:15 AM", "Good morning!"},
    // };
    ChatListModelController *m_chatListModel = nullptr;
};
