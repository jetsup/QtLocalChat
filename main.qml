import QtQuick 2.12
import QtQuick.Window 2.12
import "ui/BottomBar"
import "ui/ChatMessageView"
import "ui/ChatPersonView"

Window {
    width: 1280
    height: 720
    minimumWidth: 810
    minimumHeight: 360
    visible: true
    title: qsTr("Local Chat")

    BottomBar {
        id: bottomBar
    }

    ChatMessageView {
        id: messageViewPanel
    }

    ChatPersonView {
        id: messangerProfiles
    }
}
