cmake_minimum_required(VERSION 3.16)
project(Cards)

set(CMAKE_CXX_STANDARD 20)

add_library(Card Card.cpp Card.h)
target_include_directories(Card PUBLIC .)

add_library(DeckPile DeckPile.cpp DeckPile.h)
target_include_directories(DeckPile PUBLIC .)
target_link_libraries(DeckPile Card)

add_library(Hand Hand.cpp Hand.h)
target_include_directories(Hand PUBLIC .)
target_link_libraries(Hand Card)

add_subdirectory(tests)