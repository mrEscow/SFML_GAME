cmake_minimum_required(VERSION 3.5)

project(Sfml_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS graphics audio system REQUIRED)

set(GAME_DIR "${CMAKE_SOURCE_DIR}/GAME")

file(GLOB_RECURSE SOURCES
    "${GAME_DIR}/*.h"
    "${GAME_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${GAME_DIR})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
