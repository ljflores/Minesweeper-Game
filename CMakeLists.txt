cmake_minimum_required(VERSION 3.15)
project(Object_Oriented_software_design_final_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Object_Oriented_software_design_final_project
    AdvBoard.cpp
    AdvSquareBuilder.cpp
    Board.cpp
    Board.h
    Game.cpp
    Game.h
    GameBuilder.h
    GameEngineer.cpp
    Generate.h
    main.cpp
    MediumBoard.cpp
    MediumSquareBuilder.cpp
    MediumSquareRules.cpp
    MediumSquareRules.h
    RandomGeneration.cpp
    RandomGeneration.h
    Rules.h
    SimpleBoard.cpp
    SimpleSquareBuilder.cpp
    SimpleSquareRules.cpp
    SimpleSquareRules.h
    SquareTile.cpp
    SquareTile.h
        Tile.h)
