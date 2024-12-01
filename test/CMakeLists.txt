# Include the project's headers
include_directories(${PROJECT_SOURCE_DIR}/src)

# Collect all source files from the src directory
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.c")

# Collect all test files from the test directory
file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/test/*.c")

# Iterate through each test file and create an executable
foreach(TEST_FILE ${TEST_FILES})
    # Extract the test name (filename without extension)
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # Add the executable, linking only the current test file and the common src files
    add_executable(${TEST_NAME} ${TEST_FILE})

    # Link the source files from the src directory and the math library
    target_link_libraries(${TEST_NAME} PRIVATE ${SRC_FILES} m)

    # Register the test with CTest
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
