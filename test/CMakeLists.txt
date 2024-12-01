# Include the project's headers
include_directories(${PROJECT_SOURCE_DIR}/src)

# Collect all source files from the src directory
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.c")

# Collect all test files from the test directory (excluding main functions)
file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/test/test_*.c")

# Add run_tests as the main executable that runs all tests
add_executable(run_tests ${SRC_FILES} ${TEST_FILES} ${PROJECT_SOURCE_DIR}/test/run_tests.c)

# Link necessary libraries (e.g., math library)
target_link_libraries(run_tests PUBLIC m)

# Register the test with CTest (optional if you want to run with CTest)
add_test(NAME RunTests COMMAND run_tests)
