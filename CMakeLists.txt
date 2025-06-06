
cmake_minimum_required(VERSION 3.10)

project(LEARN VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    include
)

set(SOURCES
    src/main.cpp
)

add_executable(LEARN ${SOURCES})

target_link_libraries(LEARN ${SDL2_LIBRARIES} dl)
