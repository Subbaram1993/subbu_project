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
include CMakeFiles/subbu_project_maximum_element.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/subbu_project_maximum_element.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/subbu_project_maximum_element.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subbu_project_maximum_element.dir/flags.make

CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o: CMakeFiles/subbu_project_maximum_element.dir/flags.make
CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o: ../src/maximum_element_in_Array.c
CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o: CMakeFiles/subbu_project_maximum_element.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o -MF CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o.d -o CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o -c /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/src/maximum_element_in_Array.c

CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/src/maximum_element_in_Array.c > CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.i

CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/src/maximum_element_in_Array.c -o CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.s

# Object files for target subbu_project_maximum_element
subbu_project_maximum_element_OBJECTS = \
"CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o"

# External object files for target subbu_project_maximum_element
subbu_project_maximum_element_EXTERNAL_OBJECTS =

subbu_project_maximum_element: CMakeFiles/subbu_project_maximum_element.dir/src/maximum_element_in_Array.c.o
subbu_project_maximum_element: CMakeFiles/subbu_project_maximum_element.dir/build.make
subbu_project_maximum_element: CMakeFiles/subbu_project_maximum_element.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable subbu_project_maximum_element"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subbu_project_maximum_element.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subbu_project_maximum_element.dir/build: subbu_project_maximum_element
.PHONY : CMakeFiles/subbu_project_maximum_element.dir/build

CMakeFiles/subbu_project_maximum_element.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/subbu_project_maximum_element.dir/cmake_clean.cmake
.PHONY : CMakeFiles/subbu_project_maximum_element.dir/clean

CMakeFiles/subbu_project_maximum_element.dir/depend:
	cd /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build /home/subbaramaiah_chevuru/Runner/subbu_project/actions-runner/_work/subbu_project/subbu_project/build/CMakeFiles/subbu_project_maximum_element.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subbu_project_maximum_element.dir/depend

