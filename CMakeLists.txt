cmake_minimum_required(VERSION 3.14)

project(demlabs_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick QuickControls2 Network REQUIRED)

add_subdirectory(src)

add_executable(${PROJECT_NAME}
    src/main.cpp
    qml/qml.qrc
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt5::Core
    Qt5::Quick
    Qt5::QuickControls2

    UI::CommandsHandler
    Backend::CommunicationModule)
