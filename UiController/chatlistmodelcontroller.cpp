#include "chatlistmodelcontroller.h"

ChatListModelController::ChatListModelController()
{
    chatRecipients = {
        // Add your hardcoded profiles here
        {"John Doe",
         "12:09 AM",
         "This is a message bro sent me from home to let me know how he is doing."},
        {"Jane Doe", "10:30 PM", "Hey! How are you doing?"},
        {"Mike Smith", "08:15 AM", "Good morning!"},
    };
}

// ChatListModelController::ChatListModelController(QObject *paretn)
//     : QAbstractListModel(paretn)
// {
//     chatRecipients = {
//         // Add your hardcoded profiles here
//         {"John Doe",
//          "12:09 AM",
//          "This is a message bro sent me from home to let me know how he is doing."},
//         {"Jane Doe", "10:30 PM", "Hey! How are you doing?"},
//         {"Mike Smith", "08:15 AM", "Good morning!"},
//     };
// }

ChatListModelController *ChatListModelController::chatListModel() const
{
    return m_chatListModel;
}

void ChatListModelController::setChatListModel(ChatListModelController *newChatListModel)
{
    if (m_chatListModel == newChatListModel)
        return;
    m_chatListModel = newChatListModel;
    emit chatListModelChanged();
}

QList<ChatListModelController::ChatRecipient> ChatListModelController::getChatRecipients() const
{
    return chatRecipients;
}
