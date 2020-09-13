cmake_minimum_required(VERSION 3.0.0)
project(Logger VERSION 0.1.0)

include_directories( ${CMAKE_PROJECT_SOURCE_DIR} )

add_executable(Logger main.cpp Logger.cpp)

set_target_properties(Logger PROPERTIES
  CXX_STANDARD 17
)
