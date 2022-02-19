#
# Copyright (C) 2020-2022 QuasarApp.
# Distributed under the GPLv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)

add_definitions(-DPLATFORMS_LIBRARY)


file(GLOB SOURCE_CPP
    "src/public/*.cpp"
    "src/public/Platforms/*.cpp"
    "src/private/*.cpp"

    "src/public/*.h"
    "src/public/Platforms/*.h"
    "src/private/*.h"
)

if (${QT_VERSION_MAJOR})
    file(GLOB SOURCE_QRC
        "*.qrc"
    )

endif()

set(PUBLIC_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/public")
set(PRIVATE_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/private")


add_library(${PROJECT_NAME} ${SOURCE_CPP} ${SOURCE_QRC})

if (${QT_VERSION_MAJOR})
    target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${PRIVATE_INCUDE_DIR})

set(LANGS ${CMAKE_CURRENT_SOURCE_DIR}/languages/en.ts)


prepareQM(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} "${LANGS}")

set(QML_IMPORT_PATH ${QML_IMPORT_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE STRING "" FORCE)

set(global_file "${CMAKE_CURRENT_SOURCE_DIR}/src/public/Platforms/global.h")
configure_file("${global_file}.in" ${global_file} @ONLY)

if (ANDROID)

    add_custom_target(copy_java_depends_of_platform ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src/Library/src/android/src ${ANDROID_PACKAGE_SOURCE_DIR}/src
        DEPENDS ${PROJECT_NAME}
        )

endif()
