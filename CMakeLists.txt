cmake_minimum_required(VERSION 3.16)
project(BlackJack)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(contrib/googletest)
add_subdirectory(BlackJackGame)
add_subdirectory(Card)
add_subdirectory(Deck)
add_subdirectory(DeckPile)
add_subdirectory(Hand)
add_subdirectory(Dealer)
add_subdirectory(Player)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Card Deck Hand DeckPile)