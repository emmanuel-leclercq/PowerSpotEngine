# Add testing framework
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Collect all test files
file(GLOB TEST_FILES *.cpp)

# Create test executable
add_executable(tests ${TEST_FILES})

# Link libraries
target_link_libraries(tests PRIVATE power_market_engine gtest gtest_main)

# Add tests
include(GoogleTest)
gtest_discover_tests(tests)