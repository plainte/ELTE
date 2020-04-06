cmake_minimum_required(VERSION 3.15)
project(fishing_competition_analyzer)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS " -static-libstdc++ -static-libgcc ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(SOURCE_FILES main.cpp)
add_executable(fishing_competition_analyzer ${SOURCE_FILES})

include_directories(Fishing_competition_analyzer_lib)
add_subdirectory(Fishing_competition_analyzer_lib)

target_link_libraries(fishing_competition_analyzer Fishing_competition_analyzer_lib)

add_subdirectory(Catch_tests)