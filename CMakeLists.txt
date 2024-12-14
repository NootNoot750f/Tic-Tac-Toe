cmake_minimum_required(VERSION 3.29)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tic_Tac_Toe
    archetype.cpp
    archetype.h
    board.cpp
    board.h
    game.cpp
    game.h
    main.cpp
    main.h
    player.cpp
    player.h)
