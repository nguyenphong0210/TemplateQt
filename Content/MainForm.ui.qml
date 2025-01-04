import QtQuick

Item {
    Rectangle {
        id: rectangle
        x: 26
        y: 17
        width: 200
        height: 200
        color: "red"
    }

    Image {
        id: image
        x: 277
        y: 182
        width: 200
        height: 198
        source: "Image/TestImage.jpg"
        fillMode: Image.PreserveAspectFit
    }
}
