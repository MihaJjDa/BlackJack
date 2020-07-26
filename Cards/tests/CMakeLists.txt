cmake_minimum_required(VERSION 3.16)
project(Cards_Test)

add_executable(Card_Test card_test.cpp)
target_link_libraries(Card_Test Card gtest)

add_executable(Deck_Test deck_test.cpp)
target_link_libraries(Deck_Test Deck gtest)

add_executable(DeckPile_Test deckPile_test.cpp)
target_link_libraries(DeckPile_Test DeckPile gtest)

add_executable(Hand_Test hand_test.cpp)
target_link_libraries(Hand_Test Hand gtest)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
