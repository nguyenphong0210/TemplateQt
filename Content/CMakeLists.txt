set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

qt_add_library(Content STATIC)

find_package(Qt6 REQUIRED COMPONENTS Core Qml)

qt6_add_qml_module(Content
    URI "Content"
    VERSION 1.0
    QML_FILES
        App.qml
        MainForm.ui.qml
    RESOURCES
        Image/TestImage.jpg
)

target_link_libraries(Content PRIVATE Qt6::Core Qt6::Qml)
