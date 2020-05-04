cmake_minimum_required(VERSION 3.15)
project(hunter)

set(CMAKE_CXX_STANDARD 17)

add_executable(hunter main.cpp Hunter.cpp Hunter.h WildAnimal.cpp WildAnimal.h Lion.cpp Lion.h Elephant.cpp Elephant.h Rhinoceros.cpp Rhinoceros.h)