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

# Utility rule file for translations_target_Plugin-Move.

# Include the progress variables for this target.
include Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/progress.make

Plugin-Move/CMakeFiles/translations_target_Plugin-Move: Plugin-Move/Plugin-Move_de_DE.qm

Plugin-Move/Plugin-Move_de_DE.qm: ../Plugin-Move/translations/Plugin-Move_de_DE.ts
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating Plugin-Move_de_DE.qm"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Move && /opt/local/bin/lrelease /Users/Juyong/OpenFlipper/Plugin-Move/translations/Plugin-Move_de_DE.ts -qm /Users/Juyong/OpenFlipper/build/Plugin-Move/Plugin-Move_de_DE.qm

translations_target_Plugin-Move: Plugin-Move/CMakeFiles/translations_target_Plugin-Move
translations_target_Plugin-Move: Plugin-Move/Plugin-Move_de_DE.qm
translations_target_Plugin-Move: Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/build.make
	cd /Users/Juyong/OpenFlipper/build/Plugin-Move && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-Move/Plugin-Move_de_DE.qm /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Translations/Plugin-Move_de_DE.qm
.PHONY : translations_target_Plugin-Move

# Rule to build all files generated by this target.
Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/build: translations_target_Plugin-Move
.PHONY : Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/build

Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-Move && $(CMAKE_COMMAND) -P CMakeFiles/translations_target_Plugin-Move.dir/cmake_clean.cmake
.PHONY : Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/clean

Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-Move /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-Move /Users/Juyong/OpenFlipper/build/Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-Move/CMakeFiles/translations_target_Plugin-Move.dir/depend

