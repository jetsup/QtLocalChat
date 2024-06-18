import QtQuick 2.1
import QtQuick.Controls
import "../PersonProfileView"

Rectangle {
    id: chatView
    anchors {
        top: parent.top
        bottom: bottomBar.top
        left: parent.left
    }
    color: "green"
    width: parent.width * (1 / 5)
    Text {
        id: networkType
        text: _networkType
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
        font.italic: true
    }
    ListView {
        id: listView
        anchors {
            top: networkType.bottom
            bottom: parent.bottom
            right: parent.right
            left: parent.left
        }
        model: _myModel

        delegate: PersonProfileView {
            id: demoProfileView
        }
    }

    Rectangle {
        anchors {
            bottom: parent.bottom
            right: parent.right
            rightMargin: 10
            bottomMargin: 10
        }
        width: 40
        height: 40
        radius: 20

        Image {
            source: "qrc:/ui/assets/add-new.png"
            anchors.fill: parent
            anchors.margins: 10
        }

        MouseArea {
            id: newChat
            anchors.fill: parent
        }
    }
}
