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
include CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/flags.make

CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o: CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/flags.make
CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o: ../src/bubble_sort_and_binary_search_array.c
CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o: CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o -MF CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o.d -o CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/src/bubble_sort_and_binary_search_array.c

CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/src/bubble_sort_and_binary_search_array.c > CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.i

CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/src/bubble_sort_and_binary_search_array.c -o CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.s

# Object files for target subbu_project_bubble_sort_and_binary_search_array
subbu_project_bubble_sort_and_binary_search_array_OBJECTS = \
"CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o"

# External object files for target subbu_project_bubble_sort_and_binary_search_array
subbu_project_bubble_sort_and_binary_search_array_EXTERNAL_OBJECTS =

subbu_project_bubble_sort_and_binary_search_array: CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/src/bubble_sort_and_binary_search_array.c.o
subbu_project_bubble_sort_and_binary_search_array: CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/build.make
subbu_project_bubble_sort_and_binary_search_array: CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable subbu_project_bubble_sort_and_binary_search_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/build: subbu_project_bubble_sort_and_binary_search_array
.PHONY : CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/build

CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/clean

CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/depend:
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subbu_project_bubble_sort_and_binary_search_array.dir/depend

