set(COMPONENT_NAME core)

set(SOURCES
    ./src/HelloWorld.cpp
)

set(HEADERS
    ./include/HelloWorld.h
)

add_library(${COMPONENT_NAME} ${SOURCES} ${HEADERS})


target_include_directories(${COMPONENT_NAME} PUBLIC ./include)

target_link_libraries(core
    PRIVATE Qt6::Quick
)

