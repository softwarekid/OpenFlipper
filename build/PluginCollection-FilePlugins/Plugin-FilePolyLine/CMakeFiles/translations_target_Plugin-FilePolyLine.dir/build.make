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

# Utility rule file for translations_target_Plugin-FilePolyLine.

# Include the progress variables for this target.
include PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/progress.make

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine: PluginCollection-FilePlugins/Plugin-FilePolyLine/Plugin-FilePolyLine_de_DE.qm

PluginCollection-FilePlugins/Plugin-FilePolyLine/Plugin-FilePolyLine_de_DE.qm: ../PluginCollection-FilePlugins/Plugin-FilePolyLine/translations/Plugin-FilePolyLine_de_DE.ts
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating Plugin-FilePolyLine_de_DE.qm"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /opt/local/bin/lrelease /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine/translations/Plugin-FilePolyLine_de_DE.ts -qm /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/Plugin-FilePolyLine_de_DE.qm

translations_target_Plugin-FilePolyLine: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine
translations_target_Plugin-FilePolyLine: PluginCollection-FilePlugins/Plugin-FilePolyLine/Plugin-FilePolyLine_de_DE.qm
translations_target_Plugin-FilePolyLine: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/build.make
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/Plugin-FilePolyLine_de_DE.qm /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Translations/Plugin-FilePolyLine_de_DE.qm
.PHONY : translations_target_Plugin-FilePolyLine

# Rule to build all files generated by this target.
PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/build: translations_target_Plugin-FilePolyLine
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/build

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && $(CMAKE_COMMAND) -P CMakeFiles/translations_target_Plugin-FilePolyLine.dir/cmake_clean.cmake
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/clean

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/translations_target_Plugin-FilePolyLine.dir/depend

