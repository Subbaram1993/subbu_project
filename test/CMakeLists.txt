# First, make sure the logic library is built
add_library(subbu_project_logic STATIC
    ../src/bitwise_add_subtraction_operators.c
    ../src/maximum_element_in_Array.c
    ../src/selection_sort.c
    ../src/numbers_to_word_conversion.c
    ../src/sum_of_unique_array_elements.c
    ../src/manage.c
)

# Define the TESTING macro so main() isn't included in the logic files
target_compile_definitions(subbu_project_logic PRIVATE TESTING)

# Link the math library if needed
target_link_libraries(subbu_project_logic PUBLIC m)

# Now create the test executable
add_executable(run_tests
    run_tests.c
    test_bitwise_add_subtraction.c
    test_maximum_element.c
    test_selection_sort.c
    test_numbers_to_word_conversion.c
    test_sum_of_unique_array_elements.c
    test_manage.c
)

# Link the test executable with the logic library (which doesn't have main() due to TESTING)
target_link_libraries(run_tests PRIVATE subbu_project_logic)

# Optionally, add more test dependencies
target_link_libraries(run_tests PRIVATE m)

# Compile options (if needed)
target_compile_options(run_tests PRIVATE -Wall -Wextra)

# Register tests with CTest
add_test(NAME run_tests COMMAND run_tests)

# Set a timeout for the run_tests test
set_tests_properties(run_tests PROPERTIES TIMEOUT 60)
