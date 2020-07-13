cmake_minimum_required(VERSION 3.16)
project(Deck)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} Deck.cpp Deck.h)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} Card)

add_subdirectory(tests)