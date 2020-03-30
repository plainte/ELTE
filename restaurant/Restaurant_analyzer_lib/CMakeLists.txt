project(restaurant)

set(HEADER_FILES Restaurant_analyzer.h)

set(SOURCE_FILES Restaurant_analyzer.cpp App.cpp App.h)

add_library(Restaurant_analyzer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})