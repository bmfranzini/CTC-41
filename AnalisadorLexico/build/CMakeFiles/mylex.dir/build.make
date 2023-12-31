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
CMAKE_SOURCE_DIR = /home/bmfranzini/CTC-41/AnalisadorLexico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bmfranzini/CTC-41/AnalisadorLexico/build

# Include any dependencies generated for this target.
include CMakeFiles/mylex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mylex.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mylex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mylex.dir/flags.make

lexer.c: ../src/cminus.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bmfranzini/CTC-41/AnalisadorLexico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[FLEX][scanner] Building scanner with flex 2.6.4"
	cd /home/bmfranzini/CTC-41/AnalisadorLexico && /usr/bin/flex -o/home/bmfranzini/CTC-41/AnalisadorLexico/build/lexer.c src/cminus.l

CMakeFiles/mylex.dir/src/main.c.o: CMakeFiles/mylex.dir/flags.make
CMakeFiles/mylex.dir/src/main.c.o: ../src/main.c
CMakeFiles/mylex.dir/src/main.c.o: CMakeFiles/mylex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmfranzini/CTC-41/AnalisadorLexico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mylex.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mylex.dir/src/main.c.o -MF CMakeFiles/mylex.dir/src/main.c.o.d -o CMakeFiles/mylex.dir/src/main.c.o -c /home/bmfranzini/CTC-41/AnalisadorLexico/src/main.c

CMakeFiles/mylex.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylex.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bmfranzini/CTC-41/AnalisadorLexico/src/main.c > CMakeFiles/mylex.dir/src/main.c.i

CMakeFiles/mylex.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylex.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bmfranzini/CTC-41/AnalisadorLexico/src/main.c -o CMakeFiles/mylex.dir/src/main.c.s

CMakeFiles/mylex.dir/src/util.c.o: CMakeFiles/mylex.dir/flags.make
CMakeFiles/mylex.dir/src/util.c.o: ../src/util.c
CMakeFiles/mylex.dir/src/util.c.o: CMakeFiles/mylex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmfranzini/CTC-41/AnalisadorLexico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mylex.dir/src/util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mylex.dir/src/util.c.o -MF CMakeFiles/mylex.dir/src/util.c.o.d -o CMakeFiles/mylex.dir/src/util.c.o -c /home/bmfranzini/CTC-41/AnalisadorLexico/src/util.c

CMakeFiles/mylex.dir/src/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylex.dir/src/util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bmfranzini/CTC-41/AnalisadorLexico/src/util.c > CMakeFiles/mylex.dir/src/util.c.i

CMakeFiles/mylex.dir/src/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylex.dir/src/util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bmfranzini/CTC-41/AnalisadorLexico/src/util.c -o CMakeFiles/mylex.dir/src/util.c.s

CMakeFiles/mylex.dir/lexer.c.o: CMakeFiles/mylex.dir/flags.make
CMakeFiles/mylex.dir/lexer.c.o: lexer.c
CMakeFiles/mylex.dir/lexer.c.o: CMakeFiles/mylex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmfranzini/CTC-41/AnalisadorLexico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mylex.dir/lexer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mylex.dir/lexer.c.o -MF CMakeFiles/mylex.dir/lexer.c.o.d -o CMakeFiles/mylex.dir/lexer.c.o -c /home/bmfranzini/CTC-41/AnalisadorLexico/build/lexer.c

CMakeFiles/mylex.dir/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylex.dir/lexer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bmfranzini/CTC-41/AnalisadorLexico/build/lexer.c > CMakeFiles/mylex.dir/lexer.c.i

CMakeFiles/mylex.dir/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylex.dir/lexer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bmfranzini/CTC-41/AnalisadorLexico/build/lexer.c -o CMakeFiles/mylex.dir/lexer.c.s

# Object files for target mylex
mylex_OBJECTS = \
"CMakeFiles/mylex.dir/src/main.c.o" \
"CMakeFiles/mylex.dir/src/util.c.o" \
"CMakeFiles/mylex.dir/lexer.c.o"

# External object files for target mylex
mylex_EXTERNAL_OBJECTS =

mylex: CMakeFiles/mylex.dir/src/main.c.o
mylex: CMakeFiles/mylex.dir/src/util.c.o
mylex: CMakeFiles/mylex.dir/lexer.c.o
mylex: CMakeFiles/mylex.dir/build.make
mylex: /usr/lib/x86_64-linux-gnu/libfl.so
mylex: CMakeFiles/mylex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bmfranzini/CTC-41/AnalisadorLexico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable mylex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mylex.dir/build: mylex
.PHONY : CMakeFiles/mylex.dir/build

CMakeFiles/mylex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mylex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mylex.dir/clean

CMakeFiles/mylex.dir/depend: lexer.c
	cd /home/bmfranzini/CTC-41/AnalisadorLexico/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bmfranzini/CTC-41/AnalisadorLexico /home/bmfranzini/CTC-41/AnalisadorLexico /home/bmfranzini/CTC-41/AnalisadorLexico/build /home/bmfranzini/CTC-41/AnalisadorLexico/build /home/bmfranzini/CTC-41/AnalisadorLexico/build/CMakeFiles/mylex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mylex.dir/depend

