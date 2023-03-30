cmake_minimum_required(VERSION 3.11)

project(SFML_GAME)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF (WIN32)
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/Windows/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
ELSE()
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/Linux/lib/cmake/SFML")
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
    include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
ENDIF()


find_package(SFML 2.5.1 COMPONENTS graphics audio system REQUIRED)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
#FetchContent_Declare(json
#    GIT_REPOSITORY  https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
#    GIT_TAG v3.11.2
#)
FetchContent_MakeAvailable(json)

set(GAME_DIR "${CMAKE_SOURCE_DIR}/GAME")
set(IMAGES_DIR "${CMAKE_SOURCE_DIR}/GAME/Images")
set(MAPS_DIR "${CMAKE_SOURCE_DIR}/GAME/Maps")

set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/IMGUI")
set(ENTT_DIR "${CMAKE_SOURCE_DIR}/ENTT")

file(GLOB_RECURSE MAPS
     "${MAPS_DIR}/*.json"
)

#копируем директорию maps
FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/GAME/Maps"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)

file(GLOB_RECURSE IMAGES
     "${IMAGES_DIR}/*.jpg"
     "${IMAGES_DIR}/*.jpeg"
     "${IMAGES_DIR}/*.png"
)

#копируем директорию images
FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/GAME/Images"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)

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

add_executable(${PROJECT_NAME}
    ${GAME_SOURCES}
    ${IMGUI_SOURCES}
    ${ENTT_SOURCES}
    ${MAPS}
    ${IMAGES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${GAME_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${ENTT_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${IMAGES_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${MAPS_DIR})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

IF (WIN32)
ELSE()
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
ENDIF()
