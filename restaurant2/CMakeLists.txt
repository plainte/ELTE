cmake_minimum_required(VERSION 3.15)
project(restaurant2)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS " -static-libstdc++ -static-libgcc ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(SOURCE_FILES main.cpp)
add_executable(restaurant2 ${SOURCE_FILES})

include_directories(RestaurantAnalyzer_lib)
add_subdirectory(RestaurantAnalyzer_lib)

target_link_libraries(restaurant2 RestaurantAnalyzer_lib)

add_subdirectory(CatchTests)