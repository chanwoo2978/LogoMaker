cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME LogoMaker)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp BlinkCursor.cpp BlinkCursor.h DropdownMenu.cpp DropdownMenu.h EventHandler.h Fonts.cpp Fonts.h FontNames.h GUIComponent.h HistoryNode.h History.h History.cpp InputBox.cpp InputBox.h Item.cpp Item.h ItemList.cpp ItemList.h KeyboardShortcuts.cpp KeyboardShortcuts.h Letter.cpp Letter.h Menu.cpp Menu.h MenuBar.cpp MenuBar.h MouseEvents.cpp MouseEvents.h MultiText.cpp MultiText.h SnapshotInterface.h Snapshot.cpp Snapshot.h States.cpp States.h TextBox.cpp TextBox.h TextInput.cpp TextInput.h ColorBox.cpp ColorBox.h ColorList.cpp ColorList.h FontMenu.cpp FontMenu.h SettingMenu.cpp SettingMenu.h LogoMaker.cpp LogoMaker.h ColorPicker.cpp ColorPicker.h ColorMenu.cpp ColorMenu.h ColorRGB.cpp ColorRGB.h Slider.cpp Slider.h FilenameTyper.cpp FilenameTyper.h FilenameBox.cpp FilenameBox.h FilenameWindow.cpp FilenameWindow.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()