cmake_minimum_required(VERSION 3.0.0)
project(maze-builder VERSION 0.1.0 LANGUAGES C CXX)

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  src/game.cpp
  src/maze.cpp
  src/point.cpp
  src/line.cpp
)

find_package(SDL2 REQUIRED)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  include/
  ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(
  ${PROJECT_NAME}
  ${SDL2_LIBRARIES}
)
