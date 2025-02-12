# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.22.1)

# Define the project name
project(subbu_project)

# Step: Collect all .c source files from the src directory
file(GLOB SRC_FILES "src/*.c")

# Step: Create an executable for each source file found in the src directory
foreach(SRC_FILE ${SRC_FILES})
    # Extract the executable name from the source file name (without the .c extension)
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)

    # Step: Add an executable target for the current source file
    add_executable(${EXEC_NAME} ${SRC_FILE})

    # Step: Link the math library (m) if required
    target_link_libraries(${EXEC_NAME} PUBLIC m)
endforeach()

# Step: Install all generated executables into the bin directory
install(TARGETS ${EXEC_NAME} DESTINATION bin)

# Step: Install all source files from the src directory into the src destination
install(DIRECTORY "src/" DESTINATION src)

# Step: Define a custom target to clean and reset the build directory
add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning and resetting the build directory"
)

# Step: Enable testing in CMake
enable_testing()

# Step: Include the test directory for unit testing
add_subdirectory(test)
