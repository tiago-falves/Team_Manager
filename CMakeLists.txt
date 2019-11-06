cmake_minimum_required(VERSION 3.10)
project(AEDA_Team_Manager)

set(CMAKE_CXX_STANDARD 11)


add_executable(AEDA_Team_Manager Main.cpp  Date.cpp Date.h FootballPlayer.cpp FootballPlayer.h Game.cpp Game.h Person.cpp Person.h Technician.cpp Technician.h CallUp.cpp CallUp.h PlayerGameStatistics.cpp PlayerGameStatistics.h CallUpPlayerStatistics.h CallUpPlayerStatistics.cpp Utilities.cpp Utilities.h NationalTeam.cpp NationalTeam.h)

target_link_libraries(AEDA_Team_Manager)
