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

# Include any dependencies generated for this target.
include tests/compareTool/CMakeFiles/compareTool.dir/depend.make

# Include the progress variables for this target.
include tests/compareTool/CMakeFiles/compareTool.dir/progress.make

# Include the compile flags for this target's objects.
include tests/compareTool/CMakeFiles/compareTool.dir/flags.make

tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o: tests/compareTool/CMakeFiles/compareTool.dir/flags.make
tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o: ../tests/compareTool/compareTool.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o"
	cd /Users/Juyong/OpenFlipper/build/tests/compareTool && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/compareTool.dir/compareTool.cc.o -c /Users/Juyong/OpenFlipper/tests/compareTool/compareTool.cc

tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compareTool.dir/compareTool.cc.i"
	cd /Users/Juyong/OpenFlipper/build/tests/compareTool && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Juyong/OpenFlipper/tests/compareTool/compareTool.cc > CMakeFiles/compareTool.dir/compareTool.cc.i

tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compareTool.dir/compareTool.cc.s"
	cd /Users/Juyong/OpenFlipper/build/tests/compareTool && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Juyong/OpenFlipper/tests/compareTool/compareTool.cc -o CMakeFiles/compareTool.dir/compareTool.cc.s

tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.requires:
.PHONY : tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.requires

tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.provides: tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.requires
	$(MAKE) -f tests/compareTool/CMakeFiles/compareTool.dir/build.make tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.provides.build
.PHONY : tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.provides

tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.provides.build: tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o

# Object files for target compareTool
compareTool_OBJECTS = \
"CMakeFiles/compareTool.dir/compareTool.cc.o"

# External object files for target compareTool
compareTool_EXTERNAL_OBJECTS =

tests/testBinaries/compareTool: tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o
tests/testBinaries/compareTool: tests/compareTool/CMakeFiles/compareTool.dir/build.make
tests/testBinaries/compareTool: /opt/local/lib/libQtOpenGL.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtScript.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtUiTools.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtHelp.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtWebKit.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtScriptTools.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtXmlPatterns.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtGui.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtXml.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtSql.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtNetwork.dylib
tests/testBinaries/compareTool: /opt/local/lib/libQtCore.dylib
tests/testBinaries/compareTool: tests/compareTool/CMakeFiles/compareTool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../testBinaries/compareTool"
	cd /Users/Juyong/OpenFlipper/build/tests/compareTool && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compareTool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/compareTool/CMakeFiles/compareTool.dir/build: tests/testBinaries/compareTool
.PHONY : tests/compareTool/CMakeFiles/compareTool.dir/build

tests/compareTool/CMakeFiles/compareTool.dir/requires: tests/compareTool/CMakeFiles/compareTool.dir/compareTool.cc.o.requires
.PHONY : tests/compareTool/CMakeFiles/compareTool.dir/requires

tests/compareTool/CMakeFiles/compareTool.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/tests/compareTool && $(CMAKE_COMMAND) -P CMakeFiles/compareTool.dir/cmake_clean.cmake
.PHONY : tests/compareTool/CMakeFiles/compareTool.dir/clean

tests/compareTool/CMakeFiles/compareTool.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/tests/compareTool /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/tests/compareTool /Users/Juyong/OpenFlipper/build/tests/compareTool/CMakeFiles/compareTool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/compareTool/CMakeFiles/compareTool.dir/depend

