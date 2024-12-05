# Create a static library for logic files (exclude files with main)
add_library(subbu_project_logic STATIC
    ../src/bitwise_add_subtraction_operators.c
    ../src/maximum_element_in_Array.c
    ../src/selection_sort.c
    ../src/numbers_to_word_conversion.c
    ../src/sum_of_unique_array_elements.c
)

# Create the test executable (only include test files)
add_executable(run_tests
    run_tests.c
    test_bitwise_add_subtraction.c
    test_maximum_element.c
    test_selection_sort.c
    test_numbers_to_word_conversion.c
    test_sum_of_unique_array_elements.c
)

# Link the test executable with the static library (subbu_project_logic) containing all logic files
target_link_libraries(run_tests PRIVATE subbu_project_logic m)

# Add necessary compile options for the tests (e.g., warning flags)
target_compile_options(run_tests PRIVATE -Wall -Wextra)

# Register the test with CTest (optional)
enable_testing()
add_test(NAME run_tests COMMAND run_tests)
