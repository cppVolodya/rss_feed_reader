# --------------------------------------------------------------------------- #
# basic settings

cmake_minimum_required(VERSION 3.23)

project(rss_feed_reader VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CSS_STANDARD_REQUIRED ON)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# enable settings for Qt

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# set build directive depending on os

if(WIN32)
    message("--- OS Windows!")
    set(CMAKE_PREFIX_PATH "C:/user_programs/qt/6.4.1/mingw_64")
    set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/config/rss_feed_reader.rc")
elseif(UNIX)
    message("--- OS Unix!")
    set(CMAKE_PREFIX_PATH "/user_files_volodya/qt/6.4.0/gcc_64/")
endif()
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# find Qt

find_package(Qt6 COMPONENTS
                 Core
                 Gui
                 Widgets
                 REQUIRED)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# settings directories

include_directories(headers/main_window/
                    headers/window_with_rounded_border_and_graphic_effects/)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# variable for 'settings executable(program)'

# source files
set(SOURCE_MAIN sources/main.cpp)

set(SOURCE_MAIN_WINDOW sources/main_window/main_window.cpp)

set(SOURCE_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS sources/window_with_rounded_border_and_graphic_effects/window_with_rounded_border_and_graphic_effects.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/rounded_border_of_window.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/central_part_of_window_with_graphic_effects.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/painter_of_rounded_border_of_widget.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/layout_of_rounded_border_of_widget.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/shape_of_rounded_border_of_widget.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/cursors_of_widget.cpp
                                                          sources/window_with_rounded_border_and_graphic_effects/changing_size_of_widget.cpp)


# header files
set(HEADER_MAIN_WINDOW headers/main_window/main_window.h)

set(HEADER_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS headers/window_with_rounded_border_and_graphic_effects/window_with_rounded_border_and_graphic_effects.h
                                                          headers/window_with_rounded_border_and_graphic_effects/rounded_border_of_window.h
                                                          headers/window_with_rounded_border_and_graphic_effects/layout_of_size_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/central_part_of_window_with_graphic_effects.h
                                                          headers/window_with_rounded_border_and_graphic_effects/painter_of_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/layout_of_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/layout_of_external_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/layout_of_internal_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/roundness_of_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/shape_of_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/thickness_of_rounded_border_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/cursors_of_widget.h
                                                          headers/window_with_rounded_border_and_graphic_effects/changing_size_of_widget.h)


# other files
set(OTHER_WIN32 resources.qrc
                ${app_icon_resource_windows})

set(OTHER_UNIX resources.qrc)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# executable(program) settings
if(WIN32)
    add_executable(rss_feed_reader
                   ${SOURCE_MAIN}
                   ${SOURCE_MAIN_WINDOW}
                   ${SOURCE_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS}

                   ${HEADER_MAIN_WINDOW}
                   ${HEADER_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS}

                   ${OTHER_WIN32})
elseif(UNIX)
    add_executable(rss_feed_reader
                   ${SOURCE_MAIN}
                   ${SOURCE_MAIN_WINDOW}
                   ${SOURCE_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS}

                   ${HEADER_MAIN_WINDOW}
                   ${HEADER_WINDOW_WITH_ROUNDED_BORDER_AND_GRAPHIC_EFFECTS}

                   ${OTHER_UNIX})
endif()

target_link_libraries(rss_feed_reader
                      PRIVATE Qt::Core
                      PRIVATE Qt::Gui
                      PRIVATE Qt::Widgets)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# special settings
if(WIN32)
    set_target_properties(rss_feed_reader PROPERTIES WIN32_EXECUTABLE ON)
endif()
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# default settings
if(WIN32)
    set(DEBUG_SUFFIX)
    if(MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif()
    endif()
    if(EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
    foreach(QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif()
# --------------------------------------------------------------------------- #
