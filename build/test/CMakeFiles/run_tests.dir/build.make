# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build

# Include any dependencies generated for this target.
include test/CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/run_tests.dir/flags.make

test/CMakeFiles/run_tests.dir/run_tests.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/run_tests.c.o: ../test/run_tests.c
test/CMakeFiles/run_tests.dir/run_tests.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/run_tests.dir/run_tests.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/run_tests.c.o -MF CMakeFiles/run_tests.dir/run_tests.c.o.d -o CMakeFiles/run_tests.dir/run_tests.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/run_tests.c

test/CMakeFiles/run_tests.dir/run_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/run_tests.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/run_tests.c > CMakeFiles/run_tests.dir/run_tests.c.i

test/CMakeFiles/run_tests.dir/run_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/run_tests.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/run_tests.c -o CMakeFiles/run_tests.dir/run_tests.c.s

test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o: ../test/test_bitwise_add_subtraction.c
test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o -MF CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o.d -o CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_bitwise_add_subtraction.c

test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_bitwise_add_subtraction.c > CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.i

test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_bitwise_add_subtraction.c -o CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.s

test/CMakeFiles/run_tests.dir/test_maximum_element.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_maximum_element.c.o: ../test/test_maximum_element.c
test/CMakeFiles/run_tests.dir/test_maximum_element.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object test/CMakeFiles/run_tests.dir/test_maximum_element.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_maximum_element.c.o -MF CMakeFiles/run_tests.dir/test_maximum_element.c.o.d -o CMakeFiles/run_tests.dir/test_maximum_element.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_maximum_element.c

test/CMakeFiles/run_tests.dir/test_maximum_element.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_maximum_element.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_maximum_element.c > CMakeFiles/run_tests.dir/test_maximum_element.c.i

test/CMakeFiles/run_tests.dir/test_maximum_element.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_maximum_element.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_maximum_element.c -o CMakeFiles/run_tests.dir/test_maximum_element.c.s

test/CMakeFiles/run_tests.dir/test_selection_sort.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_selection_sort.c.o: ../test/test_selection_sort.c
test/CMakeFiles/run_tests.dir/test_selection_sort.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object test/CMakeFiles/run_tests.dir/test_selection_sort.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_selection_sort.c.o -MF CMakeFiles/run_tests.dir/test_selection_sort.c.o.d -o CMakeFiles/run_tests.dir/test_selection_sort.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_selection_sort.c

test/CMakeFiles/run_tests.dir/test_selection_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_selection_sort.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_selection_sort.c > CMakeFiles/run_tests.dir/test_selection_sort.c.i

test/CMakeFiles/run_tests.dir/test_selection_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_selection_sort.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_selection_sort.c -o CMakeFiles/run_tests.dir/test_selection_sort.c.s

test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o: ../test/test_numbers_to_word_conversion.c
test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o -MF CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o.d -o CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_numbers_to_word_conversion.c

test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_numbers_to_word_conversion.c > CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.i

test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_numbers_to_word_conversion.c -o CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.s

test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o: ../test/test_sum_of_unique_array_elements.c
test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o -MF CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o.d -o CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_sum_of_unique_array_elements.c

test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_sum_of_unique_array_elements.c > CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.i

test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_sum_of_unique_array_elements.c -o CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.s

test/CMakeFiles/run_tests.dir/test_manage.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_manage.c.o: ../test/test_manage.c
test/CMakeFiles/run_tests.dir/test_manage.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object test/CMakeFiles/run_tests.dir/test_manage.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_manage.c.o -MF CMakeFiles/run_tests.dir/test_manage.c.o.d -o CMakeFiles/run_tests.dir/test_manage.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_manage.c

test/CMakeFiles/run_tests.dir/test_manage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_manage.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_manage.c > CMakeFiles/run_tests.dir/test_manage.c.i

test/CMakeFiles/run_tests.dir/test_manage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_manage.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_manage.c -o CMakeFiles/run_tests.dir/test_manage.c.s

test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o: ../test/test_bubble_sort_and_binary_search.c
test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o -MF CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o.d -o CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_bubble_sort_and_binary_search.c

test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_bubble_sort_and_binary_search.c > CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.i

test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_bubble_sort_and_binary_search.c -o CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.s

test/CMakeFiles/run_tests.dir/test_student_info.c.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/test_student_info.c.o: ../test/test_student_info.c
test/CMakeFiles/run_tests.dir/test_student_info.c.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object test/CMakeFiles/run_tests.dir/test_student_info.c.o"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/test_student_info.c.o -MF CMakeFiles/run_tests.dir/test_student_info.c.o.d -o CMakeFiles/run_tests.dir/test_student_info.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_student_info.c

test/CMakeFiles/run_tests.dir/test_student_info.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run_tests.dir/test_student_info.c.i"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_student_info.c > CMakeFiles/run_tests.dir/test_student_info.c.i

test/CMakeFiles/run_tests.dir/test_student_info.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run_tests.dir/test_student_info.c.s"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test/test_student_info.c -o CMakeFiles/run_tests.dir/test_student_info.c.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/run_tests.c.o" \
"CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o" \
"CMakeFiles/run_tests.dir/test_maximum_element.c.o" \
"CMakeFiles/run_tests.dir/test_selection_sort.c.o" \
"CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o" \
"CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o" \
"CMakeFiles/run_tests.dir/test_manage.c.o" \
"CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o" \
"CMakeFiles/run_tests.dir/test_student_info.c.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

test/run_tests: test/CMakeFiles/run_tests.dir/run_tests.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_bitwise_add_subtraction.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_maximum_element.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_selection_sort.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_numbers_to_word_conversion.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_sum_of_unique_array_elements.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_manage.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_bubble_sort_and_binary_search.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/test_student_info.c.o
test/run_tests: test/CMakeFiles/run_tests.dir/build.make
test/run_tests: test/libsubbu_project_logic.a
test/run_tests: test/CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable run_tests"
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/run_tests.dir/build: test/run_tests
.PHONY : test/CMakeFiles/run_tests.dir/build

test/CMakeFiles/run_tests.dir/clean:
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test && $(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/run_tests.dir/clean

test/CMakeFiles/run_tests.dir/depend:
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/test /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/test/CMakeFiles/run_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/run_tests.dir/depend

