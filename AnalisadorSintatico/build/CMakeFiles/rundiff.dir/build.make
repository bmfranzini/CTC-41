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
CMAKE_SOURCE_DIR = /home/rodrigo/CTC-41/AnalisadorSintatico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rodrigo/CTC-41/AnalisadorSintatico/build

# Utility rule file for rundiff.

# Include any custom commands dependencies for this target.
include CMakeFiles/rundiff.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rundiff.dir/progress.make

CMakeFiles/rundiff:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/rodrigo/CTC-41/AnalisadorSintatico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "running diff"
	../scripts/rundiff

rundiff: CMakeFiles/rundiff
rundiff: CMakeFiles/rundiff.dir/build.make
.PHONY : rundiff

# Rule to build all files generated by this target.
CMakeFiles/rundiff.dir/build: rundiff
.PHONY : CMakeFiles/rundiff.dir/build

CMakeFiles/rundiff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rundiff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rundiff.dir/clean

CMakeFiles/rundiff.dir/depend:
	cd /home/rodrigo/CTC-41/AnalisadorSintatico/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rodrigo/CTC-41/AnalisadorSintatico /home/rodrigo/CTC-41/AnalisadorSintatico /home/rodrigo/CTC-41/AnalisadorSintatico/build /home/rodrigo/CTC-41/AnalisadorSintatico/build /home/rodrigo/CTC-41/AnalisadorSintatico/build/CMakeFiles/rundiff.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rundiff.dir/depend
