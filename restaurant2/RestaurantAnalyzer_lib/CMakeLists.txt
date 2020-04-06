project(restaurant2)

set(HEADER_FILES RestaurantAnalyzer.h App.h)

set(SOURCE_FILES RestaurantAnalyzer.cpp App.cpp)

add_library(RestaurantAnalyzer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})