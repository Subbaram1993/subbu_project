cmake_minimum_required(VERSION "3.19.0")

# Define the project name
project(subbu_project C)

# Collect all C source files in the src directory
file(GLOB SRC_FILES "src/*.c")

# Add the executable target using all collected source files
add_executable("${PROJECT_NAME}" ${SRC_FILES})

# Link necessary libraries (e.g., math library for `-lm`)
target_link_libraries("${PROJECT_NAME}" PUBLIC m)

# Ensure proper compiler flags for C (adjust as necessary)
target_compile_options("${PROJECT_NAME}" PRIVATE -Wall -Wextra -Wpedantic)

# Install the executable to the bin directory
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

# Install all source files from the src directory
install(DIRECTORY "src/" DESTINATION src)

# Add a custom target for cleaning the build directory
add_custom_target(clean_build
	    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
	        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
		    COMMENT "Cleaning and resetting the build directory"
		    )

