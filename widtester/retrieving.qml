import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
//import QtQuick 1.1

Rectangle {
    id: screen
    width: 350
    height: 200
    color:  "black"
    Text    {
        id: text
        x: 50
        y: 70
        color: "white"
        text: "Retrieving Data"
        font.family: "Liberation Mono"
        font.pointSize: 22
    }
    Timer   {
        id: mainTimer
        interval: 120
        running: true
        repeat: true
        onTriggered: screen.state="State1"
    }

    Rectangle   {
        id: blob1
        width: 8
        height: 8
        x: 50
        y: 150
        radius: 3
        color: "white"
    }
    Rectangle   {
        id: blob2
        width: 8
        height: 8
        x: 100
        y: 150
        radius: 3
        color: "white"
    }
    Rectangle   {
        id: blob3
        width: 8
        height: 8
        x: 150
        y: 150
        radius: 3
        color: "white"
    }
    Rectangle   {
        id: blob4
        width: 8
        height: 8
        x: 200
        y: 150
        radius: 3
        color: "white"
    }
    Rectangle   {
        id: blob5
        width: 8
        height: 8
        x: 250
        y: 150
        radius: 3
        color: "white"
    }
    Rectangle   {
        id: blob6
        width: 8
        height: 8
        x: 300
        y: 150
        radius: 3
        color: "white"
    }
    states: [
        State {
            name: "State1"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State2"
            }
            PropertyChanges {
                target: blob1
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State2"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State3"
            }
            PropertyChanges {
                target: blob1
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob2
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State3"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State4"
            }
            PropertyChanges {
                target: blob2
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob3
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State4"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State5"
            }
            PropertyChanges {
                target: blob3
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob4
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State5"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State6"
            }
            PropertyChanges {
                target: blob4
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob5
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State6"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State7"
            }
            PropertyChanges {
                target: blob5
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob6
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State7"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State8"
            }
            PropertyChanges {
                target: blob6
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob5
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State8"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State9"
            }
            PropertyChanges {
                target: blob5
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob4
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State9"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State10"
            }
            PropertyChanges {
                target: blob4
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob3
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State10"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State11"
            }
            PropertyChanges {
                target: blob3
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob2
                width: 12
                height: 12
                color: "white"
            }
        },
        State {
            name: "State11"
            PropertyChanges {
                target: mainTimer
                onTriggered: screen.state="State1"
            }
            PropertyChanges {
                target: blob2
                width: 8
                height: 8
                color: "white"
            }
            PropertyChanges {
                target: blob1
                width: 12
                height: 12
                color: "white"
            }
        }
    ]
}
