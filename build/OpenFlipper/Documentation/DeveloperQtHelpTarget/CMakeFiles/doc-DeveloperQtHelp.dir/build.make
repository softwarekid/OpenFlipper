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

# Utility rule file for doc-DeveloperQtHelp.

# Include the progress variables for this target.
include OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/progress.make

OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp:
	cd /Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget && /opt/local/bin/doxygen /Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget/doxy.config

doc-DeveloperQtHelp: OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp
doc-DeveloperQtHelp: OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/build.make
	cd /Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget && /opt/local/bin/cmake -E remove_directory /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Help/html
.PHONY : doc-DeveloperQtHelp

# Rule to build all files generated by this target.
OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/build: doc-DeveloperQtHelp
.PHONY : OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/build

OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget && $(CMAKE_COMMAND) -P CMakeFiles/doc-DeveloperQtHelp.dir/cmake_clean.cmake
.PHONY : OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/clean

OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/OpenFlipper/Documentation/DeveloperQtHelpTarget /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget /Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : OpenFlipper/Documentation/DeveloperQtHelpTarget/CMakeFiles/doc-DeveloperQtHelp.dir/depend

