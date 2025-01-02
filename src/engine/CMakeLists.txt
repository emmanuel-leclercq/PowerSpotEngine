# Collect source files
file(GLOB SOURCES *.cpp)

# Add sources to the parent library
target_sources(${LIB_NAME} PRIVATE ${SOURCES})