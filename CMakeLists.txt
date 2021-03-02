cmake_minimum_required(VERSION 3.17)
project(Console_battle)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Console_battle
        Player.cpp
        Player.h
        monster.cpp
        monster.h
        main.cpp
        Console_draw.cpp
        Console_draw.h
        console.txt
        list_of_strings.cpp
        list_of_strings.h
        Dice.cpp
        Dice.h)
