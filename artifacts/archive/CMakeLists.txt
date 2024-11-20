cmake_minimum_required(VERSION "3.19.0")

project(subbu_project)

# Collect source files for each executable
# Here, we have different source files, each containing a `main` function
add_executable(subbu_project_bitwise_add_subtraction_operators "src/bitwise_add_subtraction_operators.c")
add_executable(subbu_project_maximum_element "src/maximum_element_in_Array.c")
add_executable(subbu_project_selection_sort "src/selection_sort.c")
add_executable(subbu_project_numbers_to_word_conversion "src/numbers_to_word_conversion.c")
add_executable(subbu_project_sum_of_unique_array_elements "src/sum_of_unique_array_elements.c")

# Link necessary libraries (e.g., math library for `-lm` if needed)
target_link_libraries(subbu_project_bitwise_add_subtraction_operators PUBLIC m)
target_link_libraries(subbu_project_maximum_element PUBLIC m)
target_link_libraries(subbu_project_selection_sort PUBLIC m)
target_link_libraries(subbu_project_numbers_to_word_conversion PUBLIC m)
target_link_libraries(subbu_project_sum_of_unique_array_elements PUBLIC m)

# Install all executables to the bin directory
install(TARGETS subbu_project_bitwise_add_subtraction_operators
	        subbu_project_maximum_element
		        subbu_project_selection_sort
			        subbu_project_numbers_to_word_conversion
				        subbu_project_sum_of_unique_array_elements
					        DESTINATION bin)

					# Install all source files from the src directory
					install(DIRECTORY "src/" DESTINATION src)

					# Add a custom target for cleaning the build directory
					add_custom_target(clean_build
						    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
						        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}
							    COMMENT "Cleaning and resetting the build directory"
							    )

