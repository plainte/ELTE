cmake_minimum_required(VERSION 3.15)
project(restaurant)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS " -static-libstdc++ -static-libgcc ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(SOURCE_FILES main.cpp)
add_executable(restaurant ${SOURCE_FILES})

include_directories(Restaurant_analyzer_lib)
add_subdirectory(Restaurant_analyzer_lib)

target_link_libraries(restaurant Restaurant_analyzer_lib)

add_subdirectory(Catch_tests)