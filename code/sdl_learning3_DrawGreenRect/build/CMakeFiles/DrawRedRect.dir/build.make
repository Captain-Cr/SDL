# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /opt/cmake-3.18.0/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.18.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rose/mount/code/sdl_learning3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rose/mount/code/sdl_learning3/build

# Include any dependencies generated for this target.
include CMakeFiles/DrawRedRect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DrawRedRect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DrawRedRect.dir/flags.make

CMakeFiles/DrawRedRect.dir/main.c.o: CMakeFiles/DrawRedRect.dir/flags.make
CMakeFiles/DrawRedRect.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rose/mount/code/sdl_learning3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DrawRedRect.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DrawRedRect.dir/main.c.o -c /home/rose/mount/code/sdl_learning3/main.c

CMakeFiles/DrawRedRect.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DrawRedRect.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rose/mount/code/sdl_learning3/main.c > CMakeFiles/DrawRedRect.dir/main.c.i

CMakeFiles/DrawRedRect.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DrawRedRect.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rose/mount/code/sdl_learning3/main.c -o CMakeFiles/DrawRedRect.dir/main.c.s

# Object files for target DrawRedRect
DrawRedRect_OBJECTS = \
"CMakeFiles/DrawRedRect.dir/main.c.o"

# External object files for target DrawRedRect
DrawRedRect_EXTERNAL_OBJECTS =

DrawRedRect: CMakeFiles/DrawRedRect.dir/main.c.o
DrawRedRect: CMakeFiles/DrawRedRect.dir/build.make
DrawRedRect: CMakeFiles/DrawRedRect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rose/mount/code/sdl_learning3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DrawRedRect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DrawRedRect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DrawRedRect.dir/build: DrawRedRect

.PHONY : CMakeFiles/DrawRedRect.dir/build

CMakeFiles/DrawRedRect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DrawRedRect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DrawRedRect.dir/clean

CMakeFiles/DrawRedRect.dir/depend:
	cd /home/rose/mount/code/sdl_learning3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rose/mount/code/sdl_learning3 /home/rose/mount/code/sdl_learning3 /home/rose/mount/code/sdl_learning3/build /home/rose/mount/code/sdl_learning3/build /home/rose/mount/code/sdl_learning3/build/CMakeFiles/DrawRedRect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DrawRedRect.dir/depend
