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

# Utility rule file for doc-User-PrimitivesGenerator.

# Include the progress variables for this target.
include Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/progress.make

Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator:
	cd /Users/Juyong/OpenFlipper/build/Plugin-PrimitivesGenerator && /opt/local/bin/doxygen /Users/Juyong/OpenFlipper/build/Plugin-PrimitivesGenerator/doxy.config

doc-User-PrimitivesGenerator: Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator
doc-User-PrimitivesGenerator: Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/build.make
.PHONY : doc-User-PrimitivesGenerator

# Rule to build all files generated by this target.
Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/build: doc-User-PrimitivesGenerator
.PHONY : Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/build

Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-PrimitivesGenerator && $(CMAKE_COMMAND) -P CMakeFiles/doc-User-PrimitivesGenerator.dir/cmake_clean.cmake
.PHONY : Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/clean

Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-PrimitivesGenerator /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-PrimitivesGenerator /Users/Juyong/OpenFlipper/build/Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-PrimitivesGenerator/CMakeFiles/doc-User-PrimitivesGenerator.dir/depend

