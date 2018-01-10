cmake_minimum_required(VERSION 3.8)
project(jeu_de_la_vie)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp jeu.cpp jeu.h grille.cpp grille.h)
add_executable(jeu_de_la_vie ${SOURCE_FILES})