# Create a library for the logic files
add_library(subbu_project_logic
    ../src/bitwise_add_subtraction_operators.c
    ../src/maximum_element_in_Array.c
    ../src/selection_sort.c
    ../src/numbers_to_word_conversion.c
    ../src/sum_of_unique_array_elements.c
)

# Add the test executable (only include the test files)
add_executable(run_tests 
    run_tests.c
    test_bitwise_add_subtraction.c
    test_maximum_element.c
    test_selection_sort.c
    test_numbers_to_word_conversion.c
    test_sum_of_unique_array_elements.c
)

# Link the logic library to the test executable
target_link_libraries(run_tests PRIVATE subbu_project_logic m)

# Ensure the source files are compiled with the correct flags (if needed)
target_compile_options(run_tests PRIVATE -Wall -Wextra)  # For example, enable all warnings

# Register the test with CTest
add_test(NAME run_tests COMMAND run_tests)
