cmake_minimum_required(VERSION 3.15)
project(Object_Oriented_software_design_final_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Object_Oriented_software_design_final_project
    AdvBoard.cpp
    AdvSquareBuilder.cpp
        AdvSqaureRules.cpp
        SquareBoard.cpp
        SquareBoard.h
    Game.h
        Game.cpp
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
        SquareRules.h
    SimpleBoard.cpp
    SimpleSquareBuilder.cpp
    SimpleSquareRules.cpp
    SimpleSquareRules.h
    SquareTile.cpp
    SquareTile.h
        Tile.h Game.cpp Tile.cpp SquareRules.cpp PlannedGeneration.h PlannedGeneration.cpp Generate.cpp Board.cpp Board.h)
