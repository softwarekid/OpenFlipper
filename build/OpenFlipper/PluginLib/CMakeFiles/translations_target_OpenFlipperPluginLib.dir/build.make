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

# Utility rule file for translations_target_OpenFlipperPluginLib.

# Include the progress variables for this target.
include OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/progress.make

OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib: OpenFlipper/PluginLib/OpenFlipperPluginLib_de_DE.qm

OpenFlipper/PluginLib/OpenFlipperPluginLib_de_DE.qm: ../OpenFlipper/PluginLib/translations/OpenFlipperPluginLib_de_DE.ts
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating OpenFlipperPluginLib_de_DE.qm"
	cd /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib && /opt/local/bin/lrelease /Users/Juyong/OpenFlipper/OpenFlipper/PluginLib/translations/OpenFlipperPluginLib_de_DE.ts -qm /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib/OpenFlipperPluginLib_de_DE.qm

translations_target_OpenFlipperPluginLib: OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib
translations_target_OpenFlipperPluginLib: OpenFlipper/PluginLib/OpenFlipperPluginLib_de_DE.qm
translations_target_OpenFlipperPluginLib: OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/build.make
	cd /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib/OpenFlipperPluginLib_de_DE.qm /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Translations/OpenFlipperPluginLib_de_DE.qm
.PHONY : translations_target_OpenFlipperPluginLib

# Rule to build all files generated by this target.
OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/build: translations_target_OpenFlipperPluginLib
.PHONY : OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/build

OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib && $(CMAKE_COMMAND) -P CMakeFiles/translations_target_OpenFlipperPluginLib.dir/cmake_clean.cmake
.PHONY : OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/clean

OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/depend:
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/OpenFlipper/PluginLib /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib /Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : OpenFlipper/PluginLib/CMakeFiles/translations_target_OpenFlipperPluginLib.dir/depend

