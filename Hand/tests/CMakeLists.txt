cmake_minimum_required(VERSION 3.16)
project(Hand_Test)

add_executable(${PROJECT_NAME} hand_test.cpp)

target_link_libraries(${PROJECT_NAME} Hand gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})