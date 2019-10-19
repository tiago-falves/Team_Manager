cmake_minimum_required(VERSION 3.10)
project(AEDA_Team_Manager)

set(CMAKE_CXX_STANDARD 11)


add_executable(AEDA_Team_Manager Main.cpp  Convocatoria.cpp  Convocatoria.h Date.cpp Date.h Employee.cpp Employee.h FootbalPlayer.cpp FootbalPlayer.h Game.cpp Game.h GameStats.cpp GameStats.h Person.cpp Person.h TechnicalTeam.cpp TechnicalTeam.h StringManipulator.cpp StringManipulator.h)

target_link_libraries(AEDA_Team_Manager)
