cmake_minimum_required(VERSION 3.12)
project(projetCpp)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_executable(projetCpp
              Sources/Game.h Sources/Game.cpp 

              Sources/Field/Tile.h Sources/Field/Tile.cpp
              Sources/Field/Team.h Sources/Field/Team.cpp

              Sources/Elements/GameElement.h Sources/Elements/GameElement.cpp
              Sources/Elements/Base.h Sources/Elements/Base.cpp 

              Sources/Elements/Units/Unit.h Sources/Elements/Units/Unit.cpp
              Sources/Elements/Units/Bowman.h Sources/Elements/Units/Bowman.cpp
              Sources/Elements/Units/Catapult.h Sources/Elements/Units/Catapult.cpp
              Sources/Elements/Units/Hoplite.h Sources/Elements/Units/Hoplite.cpp

              Sources/Utils.h Sources/Utils.cpp
             )