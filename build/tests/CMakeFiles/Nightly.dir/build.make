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

# Utility rule file for Nightly.

# Include the progress variables for this target.
include tests/CMakeFiles/Nightly.dir/progress.make

tests/CMakeFiles/Nightly:
	cd /Users/Juyong/OpenFlipper/build/tests && /opt/local/bin/ctest -C . -D Nightly

Nightly: tests/CMakeFiles/Nightly
Nightly: tests/CMakeFiles/Nightly.dir/build.make
.PHONY : Nightly

# Rule to build all files generated by this target.
tests/CMakeFiles/Nightly.dir/build: Nightly
.PHONY : tests/CMakeFiles/Nightly.dir/build

tests/CMakeFiles/Nightly.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/Nightly.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Nightly.dir/clean

tests/CMakeFiles/Nightly.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/tests /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/tests /Users/Juyong/OpenFlipper/build/tests/CMakeFiles/Nightly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Nightly.dir/depend

