cmake_minimum_required(VERSION 3.10)
project(AEDA_Team_Manager)

set(CMAKE_CXX_STANDARD 11)


add_executable(AEDA_Team_Manager Main.cpp  Date.cpp Date.h People//FootballPlayer.cpp People//FootballPlayer.h Game.cpp Game.h People//Person.cpp People//Person.h People//Technician.cpp People//Technician.h CallUp.cpp CallUp.h PlayerGameStatistics.cpp PlayerGameStatistics.h CallUpPlayerStatistics.h CallUpPlayerStatistics.cpp Utilities.cpp Utilities.h NationalTeam.cpp NationalTeam.h Test.h display/Menu.cpp display/Menu.h Exceptions.h display/PeopleMenu.cpp display/PeopleMenu.h display/GameMenu.cpp display/GameMenu.h display/CallUpMenu.cpp display/CallUpMenu.h)

target_link_libraries(AEDA_Team_Manager)
