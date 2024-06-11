import QtQuick 2.15

Rectangle {
    anchors {
        // top will anchor to the previous
        left: parent.left
        right: parent.right
    }
    height: 70
    color: "brown"

    Rectangle {
        id: dpRectangle
        anchors {
            // top will anchor to the previous
            left: parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: 5
        }
        height: parent.height * 0.80
        width: parent.height * 0.80
        radius: (parent.height * 0.80) / 2

        Image {
            id: profileImageHome
            anchors.centerIn: parent
            source: "qrc:/ui/assets/user.png"
            width: parent.width
            height: parent.height
        }

        MouseArea {// view info about the profile
        }
    }
    Rectangle {
        anchors {
            left: dpRectangle.right
            right: parent.right
            top: parent.top
            margins: 5
        }
        color: "blue"
        height: parent.height - 10 //margins

        Text {
            id: txtRecepientName
            anchors {
                left: parent.left
                top: parent.top
                right: txtLastMessageTime.left
                topMargin: 5
                leftMargin: 5
            }
            font.pointSize: 13
            font.bold: true
            elide: Text.ElideRight
            text: model.name
        }

        Text {
            id: txtLastMessageTime
            anchors {
                right: parent.right
                top: parent.top
                topMargin: 5
                leftMargin: 5
            }
            font.pointSize: 13
            font.bold: true
            elide: Text.ElideRight
            text: model.time
        }

        Text {
            id: txtLastMessage
            anchors {
                left: parent.left
                top: txtRecepientName.bottom
                right: parent.right
                margins: 5
            }
            font.pointSize: 10
            elide: Text.ElideRight
            text: model.message
        }

        MouseArea {// open message on the right panel
        }
    }
}
