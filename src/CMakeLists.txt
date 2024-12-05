# Add the logic library
add_library(subbu_project_logic STATIC
    bitwise_add_subtraction_operators.c
    maximum_element_in_Array.c
    selection_sort.c
    numbers_to_word_conversion.c
    sum_of_unique_array_elements.c
)

# Define the TESTING macro only for the test executable (so the 'main' function will be excluded)
target_compile_definitions(subbu_project_logic PRIVATE TESTING)

# Link necessary libraries
target_link_libraries(subbu_project_logic PUBLIC m)
