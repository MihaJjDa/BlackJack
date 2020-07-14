cmake_minimum_required(VERSION 3.16)
project(Player_Test)

add_executable(${PROJECT_NAME} player_test.cpp)

target_link_libraries(${PROJECT_NAME} Player gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})