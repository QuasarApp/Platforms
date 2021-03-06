#
# Copyright (C) 2020-2022 QuasarApp.
# Distributed under the GPLv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)
project(Platforms LANGUAGES CXX)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (ANDROID OR IOS)
    set(BUILD_SHARED_LIBS ON)
endif()

if (NOT QT_VERSION_MAJOR)
    find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Test QUIET)
endif()
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test QUIET)

include(submodules/CMake/QuasarApp.cmake)

updateGitVars()
set(PLATFORMS_VERSION "0.${GIT_COMMIT_COUNT}.${GIT_COMMIT_HASH}")
set(PLATFORMS_PACKAGE_ID "quasarapp.core.Platforms")

if (NOT DEFINED PLATFORMS_TESTS)
    set(PLATFORMS_TESTS ON)

    if (DEFINED TARGET_PLATFORM_TOOLCHAIN)
        if (${TARGET_PLATFORM_TOOLCHAIN} STREQUAL "wasm32")
            set(PLATFORMS_TESTS OFF)
        endif()
    endif()

    if (ANDROID OR IOS)
        set(PLATFORMS_TESTS OFF)
    endif()

    if (NOT QT_VERSION_MAJOR)
        set(PLATFORMS_TESTS OFF)
    endif()
endif()

make_directory(Distro)

initAll()

add_subdirectory(src/Library)

if (PLATFORMS_TESTS)
    add_subdirectory(tests)
else()
    message("The ${PROJECT_NAME} tests is disabled.")
endif()


addDoc(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)
