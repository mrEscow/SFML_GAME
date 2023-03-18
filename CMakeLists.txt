cmake_minimum_required(VERSION 3.5)

project(SFML_GAME)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS graphics audio system REQUIRED)

set(GAME_DIR "${CMAKE_SOURCE_DIR}/GAME")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/IMGUI")
set(ENTT_DIR "${CMAKE_SOURCE_DIR}/ENTT")

file(GLOB_RECURSE GAME_SOURCES
    "${GAME_DIR}/*.h"
    "${ENTT_DIR}/*.hpp"
    "${GAME_DIR}/*.cpp"
)

file(GLOB_RECURSE IMGUI_SOURCES
    "${IMGUI_DIR}/*.h"
    "${ENTT_DIR}/*.hpp"
    "${IMGUI_DIR}/*.cpp"
)

file(GLOB_RECURSE ENTT_SOURCES
    "${ENTT_DIR}/*.h"
    "${ENTT_DIR}/*.hpp"
    "${ENTT_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} ${GAME_SOURCES} ${IMGUI_SOURCES} ${ENTT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${GAME_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${ENTT_DIR})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

