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
    Material.accent: Material.color(Material.Green)

    ColumnLayout {
        anchors.fill: parent

        Label {
            text: qsTr("Выберите команду и нажмите \"Отправить\"")

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            wrapMode: Text.WordWrap

            font.family: "Courier"
            font.pointSize: 10

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ComboBox {
                id: comboBox
                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.7
                Layout.margins: 5
            }

            Button {
                id: button
                Layout.fillWidth: true
                Layout.margins: 5
            }
        }
    }
}
