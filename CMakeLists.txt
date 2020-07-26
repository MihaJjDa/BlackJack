cmake_minimum_required(VERSION 3.16)
project(BlackJack)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(contrib/googletest)
add_subdirectory(BlackJackGame)
add_subdirectory(Cards)
add_subdirectory(Players)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        Player Card DeckPile Hand BlackJackGame)