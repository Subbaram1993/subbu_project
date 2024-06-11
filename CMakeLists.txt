cmake_minimum_required(VERSION "3.19.0")

project("/home/runner/work/subbu_project/subbu_project")

add_executable("${PROJECT_NAME}" "src/bitwise_add_subtraction_operators.c")

install (TARGETS "${PROJECT_NAME}" DESTINATION bin)

install (FILES "src/bitwise_add_subtraction_operators.c" DESTINATION src)
