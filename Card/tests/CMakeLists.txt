cmake_minimum_required(VERSION 3.16)
project(Card_Test)

add_executable(${PROJECT_NAME} card_test.cpp)

target_link_libraries(${PROJECT_NAME} Card gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})