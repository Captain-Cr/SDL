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
CMAKE_SOURCE_DIR = /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build

# Include any dependencies generated for this target.
include CMakeFiles/DrawGraphical.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DrawGraphical.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DrawGraphical.dir/flags.make

CMakeFiles/DrawGraphical.dir/main.cpp.o: CMakeFiles/DrawGraphical.dir/flags.make
CMakeFiles/DrawGraphical.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DrawGraphical.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DrawGraphical.dir/main.cpp.o -c /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/main.cpp

CMakeFiles/DrawGraphical.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DrawGraphical.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/main.cpp > CMakeFiles/DrawGraphical.dir/main.cpp.i

CMakeFiles/DrawGraphical.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DrawGraphical.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/main.cpp -o CMakeFiles/DrawGraphical.dir/main.cpp.s

# Object files for target DrawGraphical
DrawGraphical_OBJECTS = \
"CMakeFiles/DrawGraphical.dir/main.cpp.o"

# External object files for target DrawGraphical
DrawGraphical_EXTERNAL_OBJECTS =

DrawGraphical: CMakeFiles/DrawGraphical.dir/main.cpp.o
DrawGraphical: CMakeFiles/DrawGraphical.dir/build.make
DrawGraphical: CMakeFiles/DrawGraphical.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DrawGraphical"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DrawGraphical.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DrawGraphical.dir/build: DrawGraphical

.PHONY : CMakeFiles/DrawGraphical.dir/build

CMakeFiles/DrawGraphical.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DrawGraphical.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DrawGraphical.dir/clean

CMakeFiles/DrawGraphical.dir/depend:
	cd /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build /home/rose/mount/code/sdl_external_DrawGraphical/sdl_2_DrawImg/build/CMakeFiles/DrawGraphical.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DrawGraphical.dir/depend

