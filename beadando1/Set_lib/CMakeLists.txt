project(Set)

set(HEADER_FILES Set.h)

set(SOURCE_FILES Set.cpp App.cpp App.h)

add_library(Set_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})