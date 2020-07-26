cmake_minimum_required(VERSION 3.16)
project(Players)

set(CMAKE_CXX_STANDARD 20)

add_library(Player Player.cpp Player.h)
target_include_directories(Player PUBLIC .)

target_link_libraries(Player DeckPile Hand)

add_subdirectory(tests)