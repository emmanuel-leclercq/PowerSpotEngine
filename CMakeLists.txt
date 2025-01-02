cmake_minimum_required(VERSION 3.15...3.31)
project(PowerSpotEngine VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -Wall")

if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.10 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TESTS "Build tests" ON)
#option(BUILD_BINDINGS "Build Python bindings" OFF)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)


# Add subdirectories
add_subdirectory(src)

#if (BUILD_BINDINGS)
#    add_subdirectory(bindings)
#    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/nanobind)
#endif ()

if (BUILD_TESTS)
    add_subdirectory(tests)
endif ()

# FetchContent for dependencies
include(FetchContent)

# Fetch Apache Arrow (for Parquet support, if needed)
#FetchContent_Declare(
#  arrow
#  GIT_REPOSITORY https://github.com/apache/arrow.git
#  GIT_TAG        apache-arrow-12.0.0
#)
#FetchContent_MakeAvailable(arrow)