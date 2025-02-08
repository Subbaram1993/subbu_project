cmake_minimum_required(VERSION 3.22.1)

project(subbu_project)

# Collect all .c source files in the src directory
file(GLOB SRC_FILES "src/*.c")

# Create executables for each source file
foreach(SRC_FILE ${SRC_FILES})
    # Extract the executable name from the source file name (without the .c extension)
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)

    # Add executable for the current source file
    add_executable(${EXEC_NAME} ${SRC_FILE})

    # Link necessary libraries
    target_link_libraries(${EXEC_NAME} PUBLIC m)
endforeach()

# Install all executables
install(TARGETS ${EXEC_NAME} DESTINATION bin)

# Install all source files from the src directory
install(DIRECTORY "src/" DESTINATION src)

# Add a custom target for cleaning the build directory
add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
    COMMENT "Cleaning and resetting the build directory"
)

# Enable testing and include the test directory
enable_testing()
add_subdirectory(test)
