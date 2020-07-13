cmake_minimum_required(VERSION 3.16)
project(DeckPile)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} DeckPile.cpp DeckPile.h)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} Deck)

add_subdirectory(tests)