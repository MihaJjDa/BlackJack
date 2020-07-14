cmake_minimum_required(VERSION 3.16)
project(Dealer)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} Dealer.cpp Dealer.h)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} DeckPile Player)

add_subdirectory(tests)