#pragma once

#include <QObject>

class ChatPerson : public QObject
{
    Q_OBJECT
private:
    struct ChatRecipient
    {
        QString name;
        QString msgTime;
        QString lastMessage;
    };

public:
    explicit ChatPerson(QString name,
                        QString msgTime,
                        QString lastMessage,
                        QObject *parent = nullptr /*later include image*/);

signals:
};
