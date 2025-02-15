# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.22.1)

# Define the project name
project(subbu_project)

# Define an option for enabling Valgrind
option(ENABLE_VALGRIND "Enable Valgrind Support" OFF)

# Collect all .c source files from the src directory
file(GLOB SRC_FILES "src/*.c")

# Initialize an empty list to store executable names
set(EXECUTABLES "")

# Create an executable for each source file found in the src directory
foreach(SRC_FILE ${SRC_FILES})
    # Extract the executable name from the source file name (without the .c extension)
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)

    # Add an executable target for the current source file
    add_executable(${EXEC_NAME} ${SRC_FILE})

    # Link the math library (m) if required
    target_link_libraries(${EXEC_NAME} PUBLIC m)

    # If Valgrind is enabled, add appropriate compile definitions
    if(ENABLE_VALGRIND)
        target_compile_definitions(${EXEC_NAME} PRIVATE ENABLE_VALGRIND)
    endif()

    # Append executable name to the list
    list(APPEND EXECUTABLES ${EXEC_NAME})
endforeach()

# Install all generated executables into the bin directory
install(TARGETS ${EXECUTABLES} DESTINATION bin)

# Install all source files from the src directory into the src destination
install(DIRECTORY "src/" DESTINATION src)

# Define a custom target to clean and reset the build directory
add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} --build . --target clean
    COMMENT "Cleaning the build directory"
)

# Enable testing in CMake
enable_testing()

# Include the test directory for unit testing
add_subdirectory(test)
