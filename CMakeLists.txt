cmake_minimum_required(VERSION 3.10)
project(pyramid)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS graphics window system)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB SOURCES src/*.cpp src/Game/*.cpp src/Gui/*.cpp src/Utils/*.cpp)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
