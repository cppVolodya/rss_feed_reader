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
if (WIN32)
    message("--- OS Windows!")
    set(CMAKE_PREFIX_PATH "C:/user_programs/Qt/6.4.1/msvc2019_64")
    set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/config/rss_feed_reader.rc")
elseif (UNIX)
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
include_directories(headers/main_window)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# executable(program) settings
if (WIN32)
    add_executable(rss_feed_reader
                   sources/main_window/main.cpp
                   sources/main_window/main_window.cpp
                   sources/main_window/window_with_rounded_border_and_graphic_effect.cpp
                   sources/main_window/central_part_of_window_with_graphic_effect.cpp
                   sources/main_window/rounded_border_of_window.cpp
                   sources/main_window/characteristic_of_rounded_border_of_window.cpp
                   sources/main_window/roundness_of_rounded_border_of_window.cpp
                   sources/main_window/thickness_of_rounded_border_of_window.cpp
            sources/main_window/painter_of_rounded_border.cpp
            sources/main_window/painter_of_rounded_border.cpp
            sources/main_window/painter_of_external_rounded_border.cpp
            sources/main_window/painter_of_internal_rounded_border.cpp

                   headers/main_window/main_window.h
                   headers/main_window/window_with_rounded_border_and_graphic_effect.h
                   headers/main_window/central_part_of_window_with_graphic_effect.h
                   headers/main_window/rounded_border_of_window.h
                   headers/main_window/characteristic_of_rounded_border_of_window.h
                   headers/main_window/roundness_of_rounded_border_of_window.h
                   headers/main_window/thickness_of_rounded_border_of_window.h
            headers/main_window/painter_of_rounded_border.h
            headers/main_window/painter_of_rounded_border.h
            headers/main_window/painter_of_external_rounded_border.h
            headers/main_window/painter_of_internal_rounded_border.h

                   resources.qrc
                   ${app_icon_resource_windows})
elseif (UNIX)
    add_executable(rss_feed_reader
                   sources/main_window/main.cpp
                   sources/main_window/main_window.cpp
                   sources/main_window/window_with_rounded_border_and_graphic_effect.cpp
                   sources/main_window/central_part_of_window_with_graphic_effect.cpp
                   sources/main_window/rounded_border_of_window.cpp
                   sources/main_window/characteristic_of_rounded_border_of_window.cpp
                   sources/main_window/roundness_of_rounded_border_of_window.cpp
                   sources/main_window/thickness_of_rounded_border_of_window.cpp
            sources/main_window/painter_of_rounded_border.cpp
            sources/main_window/painter_of_rounded_border.cpp
            sources/main_window/painter_of_external_rounded_border.cpp
            sources/main_window/painter_of_internal_rounded_border.cpp

                   headers/main_window/main_window.h
                   headers/main_window/window_with_rounded_border_and_graphic_effect.h
                   headers/main_window/central_part_of_window_with_graphic_effect.h
                   headers/main_window/rounded_border_of_window.h
                   headers/main_window/characteristic_of_rounded_border_of_window.h
                   headers/main_window/roundness_of_rounded_border_of_window.h
                   headers/main_window/thickness_of_rounded_border_of_window.h
            headers/main_window/painter_of_rounded_border.h
            headers/main_window/painter_of_rounded_border.h
            headers/main_window/painter_of_external_rounded_border.h
            headers/main_window/painter_of_internal_rounded_border.h

                   resources.qrc)
endif()

target_link_libraries(rss_feed_reader
                      PRIVATE Qt::Core
                      PRIVATE Qt::Gui
                      PRIVATE Qt::Widgets)
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# special settings
if (WIN32)
    set_target_properties(rss_feed_reader PROPERTIES WIN32_EXECUTABLE ON)
endif()
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# default settings
if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
# --------------------------------------------------------------------------- #
