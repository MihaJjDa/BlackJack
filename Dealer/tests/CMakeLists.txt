cmake_minimum_required(VERSION 3.16)
project(Dealer_Test)

add_executable(${PROJECT_NAME} dealer_test.cpp)

target_link_libraries(${PROJECT_NAME} Dealer gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})