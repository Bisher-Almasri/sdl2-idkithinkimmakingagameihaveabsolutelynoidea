cmake_minimum_required(VERSION 3.10)

project(LEARN VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SRC_DIR}
)

set(HEADERS
    ${SRC_DIR}/Entity/Entity.hpp
    ${SRC_DIR}/Entity/Player/Player.hpp
    ${SRC_DIR}/Entity/Enemy/Enemy.hpp
    ${SRC_DIR}/Window/Window.hpp
    ${SRC_DIR}/Utils/collider.hpp
)

set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Entity/Entity.cpp
    ${SRC_DIR}/Entity/Player/Player.cpp
    ${SRC_DIR}/Entity/Enemy/Enemy.cpp
    ${SRC_DIR}/Window/Window.cpp
    ${SRC_DIR}/Utils/collider.cpp
)

add_executable(LEARN ${SOURCES} ${HEADERS})

target_link_libraries(LEARN ${SDL2_LIBRARIES} dl)
