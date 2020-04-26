cmake_minimum_required(VERSION 3.15)
project(PetrolStation)

set(CMAKE_CXX_STANDARD 17)

add_executable(PetrolStation main.cpp PetrolStation.cpp PetrolStation.h Charger.cpp Charger.h PayDesk.cpp PayDesk.h Customer.cpp Customer.h)