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

    ListModel {
        id: myModel

        ListElement {
            profileName: qsTr("Name")
            msgTime: qsTr("Non")
            lastMsgContent: qsTr("Some message")
        }
    }

    // ChatListModelController {
    //     id: myModel
    // }
    // ChatListItemModel {}
    ListView {
        id: listView
        anchors.fill: parent
        model: _myModel

        delegate: PersonProfileView {
            id: demoProfileView
        }
    }
}
