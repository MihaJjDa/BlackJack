cmake_minimum_required(VERSION 3.16)
project(BlackJackGame)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} BlackJackGame.cpp BlackJackGame.h)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} Player)

add_subdirectory(tests)