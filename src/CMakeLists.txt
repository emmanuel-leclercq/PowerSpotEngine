# Set the library name
set(LIB_NAME power_market_engine)

# Collect all source files
file(GLOB_RECURSE SOURCES engine/*.cpp utils/*.cpp)

# Add library target
add_library(${LIB_NAME} ${SOURCES}
        ../include/engine/)

# Include directories
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/examples)
# Link libraries
#target_link_libraries(${LIB_NAME} PUBLIC arrow parquet)

# Add subdirectories for modular builds
add_subdirectory(engine)
add_subdirectory(utils)