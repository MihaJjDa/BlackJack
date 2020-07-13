cmake_minimum_required(VERSION 3.16)
project(DeckPile_Test)

add_executable(${PROJECT_NAME} deckPile_test.cpp)

target_link_libraries(${PROJECT_NAME} DeckPile gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})