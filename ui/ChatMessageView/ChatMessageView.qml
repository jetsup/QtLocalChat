import QtQuick 2.15

Rectangle {
    id: chatMessageViewContainer
    anchors {
        top: parent.top
        bottom: bottomBar.top
        right: parent.right
    }
    color: "gray"
    width: parent.width * (4 / 5)

    // populate a message view and text input layout
    Rectangle {
        id: chatMessageView
        anchors.fill: parent
        color: parent.color

        Rectangle {
            id: chatInputLayout
            anchors {
                right: parent.right
                left: parent.left
                bottom: parent.bottom
            }
            height: messageInput.height + 50
            color: "white"

            Rectangle {
                id: editTextBoundary
                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                    topMargin: 10
                    bottomMargin: 10
                    leftMargin: 10
                }
                height: parent.height * 0.8
                width: parent.width - (sendButton.width + (3 * 10 /*margin*/
                                                           ))
                radius: 20
                border.color: "red"

                TextEdit {
                    id: messageInput
                    anchors {
                        left: parent.left
                        verticalCenter: parent.verticalCenter
                        leftMargin: parent.width / 60
                        rightMargin: parent.width / 60
                    }
                    width: parent.width * 0.98
                    wrapMode: "WordWrap"
                    text: qsTr("Hello")
                }
            }

            Rectangle {
                id: sendButton
                anchors {
                    right: parent.right
                    bottom: parent.bottom
                    bottomMargin: 10
                    // leftMargin: 10
                    rightMargin: 10
                }
                color: "black"
                radius: 25
                height: 50
                width: 50

                Image {
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    anchors.centerIn: parent
                    source: "qrc:/ui/assets/send.png"

                    MouseArea {
                        id: btnSend
                    }
                }
            }
        }

        Rectangle {
            id: chatMessageViewArea
            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                bottom: chatInputLayout.top
            }

            // connection stats
            Rectangle {
                anchors {
                    right: parent.right
                    top: parent.top
                    rightMargin: 5
                    topMargin: 5
                }
                height: 50
                width: 100
                radius: 20
                color: "lightblue"

                Image {
                    id: connectionStatus
                    width: parent.height * 0.5
                    height: parent.height * 0.5
                    anchors {
                        right: parent.right
                        rightMargin: 15
                        verticalCenter: parent.verticalCenter
                    }
                    source: uiHandler.networkImageSrc

                    MouseArea {// get the network info on hover
                    }
                }

                Rectangle {
                    width: parent.height * 0.8
                    height: parent.height * 0.8
                    radius: (parent.height * 0.8) / 2
                    anchors {
                        right: connectionStatus.left
                        rightMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    color: "black"

                    Text {
                        id: currentUsers
                        text: qsTr("0")
                        color: {
                            (uiHandler.connectedNetwork > -1) ? "green" : "red"
                        }

                        anchors.centerIn: parent
                    }
                }
            }
        }
    }
}
