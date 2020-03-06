cmake_minimum_required(VERSION 3.15)
project(Set_testing)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Set_run ${SOURCE_FILES})

include_directories(Set_lib)
add_subdirectory(Set_lib)

target_link_libraries(Set_run Set_lib)

add_subdirectory(Catch_tests)