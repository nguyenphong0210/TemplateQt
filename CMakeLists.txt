cmake_minimum_required(VERSION 3.16)

project(WinApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)

qt_add_executable(appWinApp
    main.cpp
)

qt_add_qml_module(appWinApp
    URI WinApp
    VERSION 1.0
    QML_FILES Main.qml
)

target_link_libraries(appWinApp
    PRIVATE Qt6::Quick
)

# Xác định đường dẫn tới windeployqt
set(QT_DEPLOY_TOOL "${Qt6_DIR}/../../../bin/windeployqt.exe")

# Thêm custom command để chạy windeployqt sau khi build
add_custom_command(TARGET appWinApp POST_BUILD
    COMMAND "${QT_DEPLOY_TOOL}" "$<TARGET_FILE:appWinApp>"
    COMMENT "Running windeployqt to deploy dependencies"
)
