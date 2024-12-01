# Include the project's headers
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add tests for each module
add_executable(test_bitwise test_bitwise.c ../src/bitwise_add_subtraction_operators.c)
add_executable(test_maximum_element test_maximum_element.c ../src/maximum_element_in_Array.c)

# Link necessary libraries
target_link_libraries(test_bitwise PUBLIC m)
target_link_libraries(test_maximum_element PUBLIC m)

# Register tests with CTest
add_test(NAME TestBitwise COMMAND test_bitwise)
add_test(NAME TestMaximumElement COMMAND test_maximum_element)
