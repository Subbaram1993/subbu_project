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
CMAKE_SOURCE_DIR = /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build

# Utility rule file for clean_build.

# Include any custom commands dependencies for this target.
include CMakeFiles/clean_build.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clean_build.dir/progress.make

CMakeFiles/clean_build:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Cleaning and resetting the build directory"
	/usr/bin/cmake -E remove_directory /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build
	/usr/bin/cmake -E make_directory /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build

clean_build: CMakeFiles/clean_build
clean_build: CMakeFiles/clean_build.dir/build.make
.PHONY : clean_build

# Rule to build all files generated by this target.
CMakeFiles/clean_build.dir/build: clean_build
.PHONY : CMakeFiles/clean_build.dir/build

CMakeFiles/clean_build.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clean_build.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clean_build.dir/clean

CMakeFiles/clean_build.dir/depend:
	cd /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build /home/subbaramaiah_ch/github_runner/project_files/_work/subbu_project/subbu_project/build/CMakeFiles/clean_build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clean_build.dir/depend

