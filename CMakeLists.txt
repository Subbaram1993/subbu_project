cmake_minimum_required(VERSION "3.19.0")

project(subbu_project)

# Collect all C source files from the src directory
file(GLOB SRC_FILES "src/*.c")

add_executable("${PROJECT_NAME}" ${SRC_FILES})

install (TARGETS "${PROJECT_NAME}" DESTINATION bin)

# Install all files from the src folder
install(DIRECTORY "src/" DESTINATION src)
