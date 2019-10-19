cmake_minimum_required(VERSION 3.10)
project(AEDA_Team_Manager)

set(CMAKE_CXX_STANDARD 11)


add_executable(AEDA_Team_Manager Main.cpp  Date.cpp Date.h FootbalPlayer.cpp FootbalPlayer.h Game.cpp Game.h Person.cpp Person.h Technician.cpp Technician.h StringManipulator.cpp StringManipulator.h Team.cpp Team.h CallUp.cpp CallUp.h CallUpPlayer.cpp CallUpPlayer.h)

target_link_libraries(AEDA_Team_Manager)
