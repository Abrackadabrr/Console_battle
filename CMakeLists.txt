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
        INOUT.cpp
        INOUT.h
        console.txt
        list_of_strings.cpp
        list_of_strings.h
        dragon.cpp
        dragon.h
        GLogic.cpp
        GLogic.h
        warrior.cpp
        warrior.h
        help_classes.cpp
        help_classes.h
        troll.cpp
        troll.h)
