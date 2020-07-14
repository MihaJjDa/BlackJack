cmake_minimum_required(VERSION 3.16)
project(Game_Test)

add_executable(${PROJECT_NAME} game_test.cpp)

target_link_libraries(${PROJECT_NAME} BlackJackGame gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})