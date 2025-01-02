# Define Python bindings target
set(BINDINGS_TARGET power_market_bindings)

# Collect source files
file(GLOB SOURCES pybind_wrapper.cpp)

# Add the pybind11 module
pybind11_add_module(${BINDINGS_TARGET} ${SOURCES})

# Link to the core library
target_link_libraries(${BINDINGS_TARGET} PRIVATE power_market_engine)