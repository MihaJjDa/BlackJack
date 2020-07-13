cmake_minimum_required(VERSION 3.16)
project(Deck_Test)

add_executable(${PROJECT_NAME} deck_test.cpp)

target_link_libraries(${PROJECT_NAME} Deck gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})