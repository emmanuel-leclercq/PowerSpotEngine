cmake_minimum_required(VERSION 3.20)
project(PowerSpotEngine VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TESTS "Build tests" ON)
option(BUILD_BINDINGS "Build Python bindings" ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)
if (BUILD_BINDINGS)
    add_subdirectory(bindings)
endif ()
if (BUILD_TESTS)
    add_subdirectory(tests)
endif ()

# FetchContent for dependencies
include(FetchContent)

# Fetch pybind11
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.11.1
)
FetchContent_MakeAvailable(pybind11)

# Fetch Apache Arrow (for Parquet support, if needed)
FetchContent_Declare(
  arrow
  GIT_REPOSITORY https://github.com/apache/arrow.git
  GIT_TAG        apache-arrow-12.0.0
)
FetchContent_MakeAvailable(arrow)