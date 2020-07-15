cmake_minimum_required(VERSION 3.16)
project(Player)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} Player.cpp Player.h)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} DeckPile Hand Dealer)

add_subdirectory(tests)