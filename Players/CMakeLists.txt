cmake_minimum_required(VERSION 3.16)
project(Players)

set(CMAKE_CXX_STANDARD 20)

add_library(IPlayer IPlayer.cpp IPlayer.h)
target_include_directories(IPlayer PUBLIC .)

add_library(Player Player.cpp Player.h)
target_include_directories(Player PUBLIC .)

add_library(Dealer Dealer.cpp Dealer.h)
target_include_directories(Dealer PUBLIC .)

target_link_libraries(IPlayer DeckPile Hand)
target_link_libraries(Player IPlayer)
target_link_libraries(Dealer IPlayer)

add_subdirectory(tests)