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

# Utility rule file for doc-install.

# Include the progress variables for this target.
include libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/progress.make

libs_required/OpenMesh/Doc/CMakeFiles/doc-install:
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Installing Documentation"

doc-install: libs_required/OpenMesh/Doc/CMakeFiles/doc-install
doc-install: libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/build.make
.PHONY : doc-install

# Rule to build all files generated by this target.
libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/build: doc-install
.PHONY : libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/build

libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/libs_required/OpenMesh/Doc && $(CMAKE_COMMAND) -P CMakeFiles/doc-install.dir/cmake_clean.cmake
.PHONY : libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/clean

libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/libs_required/OpenMesh/Doc /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/libs_required/OpenMesh/Doc /Users/Juyong/OpenFlipper/build/libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs_required/OpenMesh/Doc/CMakeFiles/doc-install.dir/depend
