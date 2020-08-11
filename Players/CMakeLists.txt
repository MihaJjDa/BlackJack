cmake_minimum_required(VERSION 3.16)
project(Players)

set(CMAKE_CXX_STANDARD 20)

add_library(IHolder IHolder.cpp IHolder.h)
target_include_directories(IHolder PUBLIC .)

add_library(IPlayer IPlayer.cpp IPlayer.h)
target_include_directories(IPlayer PUBLIC .)

add_library(Dealer Dealer.cpp Dealer.h)
target_include_directories(Dealer PUBLIC .)

add_library(ArtificalPlayer ArtificalPlayer.cpp ArtificalPlayer.h)
target_include_directories(ArtificalPlayer PUBLIC .)

add_library(LocalPlayer LocalPlayer.cpp LocalPlayer.h)
target_include_directories(LocalPlayer PUBLIC .)

target_link_libraries(IHolder Hand)
target_link_libraries(IPlayer IHolder Dealer)
target_link_libraries(Dealer IHolder IPlayer DeckPile)
target_link_libraries(ArtificalPlayer IPlayer)
target_link_libraries(LocalPlayer IPlayer)

add_subdirectory(tests)