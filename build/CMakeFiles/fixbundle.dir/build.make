# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Juyong/OpenFlipper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Juyong/OpenFlipper/build

# Utility rule file for fixbundle.

# Include the progress variables for this target.
include CMakeFiles/fixbundle.dir/progress.make

CMakeFiles/fixbundle:
	/opt/local/bin/cmake -P /Users/Juyong/OpenFlipper/build/fixbundle.cmake

fixbundle: CMakeFiles/fixbundle
fixbundle: CMakeFiles/fixbundle.dir/build.make
.PHONY : fixbundle

# Rule to build all files generated by this target.
CMakeFiles/fixbundle.dir/build: fixbundle
.PHONY : CMakeFiles/fixbundle.dir/build

CMakeFiles/fixbundle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fixbundle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fixbundle.dir/clean

CMakeFiles/fixbundle.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/CMakeFiles/fixbundle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fixbundle.dir/depend
