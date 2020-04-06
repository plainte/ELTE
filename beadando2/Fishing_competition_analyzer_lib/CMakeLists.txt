project(fishing_competition_analyzer)

set(HEADER_FILES FC_analyzer.h App.h)

set(SOURCE_FILES FC_analyzer.cpp App.cpp)

add_library(Fishing_competition_analyzer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})