import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    width: 320
    height: 100

    minimumHeight: height
    minimumWidth: width

    maximumHeight: height
    maximumWidth: width

    visible: true
    title: qsTr("Demlabs")

    Material.theme: Material.Dark
    Material.accent: Material.color(Material.Blue)

    ColumnLayout {
        anchors.fill: parent

        Label {
            text: qsTr("Выберите команду и нажмите кнопку для отправки")

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            wrapMode: Text.WordWrap
            font.bold: true
            color: Material.color(Material.Grey, Material.Shade400)

            font.family: "Courier"
            font.pointSize: 10

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ComboBox {
                id: commandsComboBox
                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.7
                Layout.margins: 5
            }

            Button {
                id: sendButton
                icon.source: "res/send.png"
                icon.color: Material.accentColor
                Layout.fillWidth: true
                Layout.margins: 5
            }
        }
    }
}
