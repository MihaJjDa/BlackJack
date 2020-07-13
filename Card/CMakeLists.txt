cmake_minimum_required(VERSION 3.16)
project(Card)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} Card.cpp Card.h )
target_include_directories(${PROJECT_NAME} PUBLIC .)

add_subdirectory(tests)