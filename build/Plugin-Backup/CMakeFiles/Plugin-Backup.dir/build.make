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
include Plugin-Backup/CMakeFiles/Plugin-Backup.dir/depend.make

# Include the progress variables for this target.
include Plugin-Backup/CMakeFiles/Plugin-Backup.dir/progress.make

# Include the compile flags for this target's objects.
include Plugin-Backup/CMakeFiles/Plugin-Backup.dir/flags.make

Plugin-Backup/moc_BackupPlugin.cpp: ../Plugin-Backup/BackupPlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_BackupPlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-Backup/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-Backup -I/Users/Juyong/OpenFlipper/build/Plugin-Backup -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-Backup/BackupPlugin.hh -o /Users/Juyong/OpenFlipper/build/Plugin-Backup/moc_BackupPlugin.cpp

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/flags.make
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o: ../Plugin-Backup/BackupPlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o -c /Users/Juyong/OpenFlipper/Plugin-Backup/BackupPlugin.cc

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-Backup/BackupPlugin.cc > CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.i

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-Backup/BackupPlugin.cc -o CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.s

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.requires:
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.requires

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.provides: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.requires
	$(MAKE) -f Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build.make Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.provides.build
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.provides

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.provides.build: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/flags.make
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o: ../Plugin-Backup/GroupBackup.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o -c /Users/Juyong/OpenFlipper/Plugin-Backup/GroupBackup.cc

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-Backup/GroupBackup.cc > CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.i

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-Backup/GroupBackup.cc -o CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.s

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.requires:
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.requires

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.provides: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.requires
	$(MAKE) -f Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build.make Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.provides.build
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.provides

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.provides.build: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/flags.make
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o: ../Plugin-Backup/GroupData.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Backup.dir/GroupData.cc.o -c /Users/Juyong/OpenFlipper/Plugin-Backup/GroupData.cc

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Backup.dir/GroupData.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-Backup/GroupData.cc > CMakeFiles/Plugin-Backup.dir/GroupData.cc.i

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Backup.dir/GroupData.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-Backup/GroupData.cc -o CMakeFiles/Plugin-Backup.dir/GroupData.cc.s

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.requires:
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.requires

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.provides: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.requires
	$(MAKE) -f Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build.make Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.provides.build
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.provides

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.provides.build: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/flags.make
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o: Plugin-Backup/moc_BackupPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-Backup/moc_BackupPlugin.cpp

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-Backup/moc_BackupPlugin.cpp > CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.i

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-Backup/moc_BackupPlugin.cpp -o CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.s

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.requires:
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.requires

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.provides: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.requires
	$(MAKE) -f Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build.make Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.provides.build
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.provides

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.provides.build: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o

# Object files for target Plugin-Backup
Plugin__Backup_OBJECTS = \
"CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o" \
"CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o" \
"CMakeFiles/Plugin-Backup.dir/GroupData.cc.o" \
"CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o"

# External object files for target Plugin-Backup
Plugin__Backup_EXTERNAL_OBJECTS =

Plugin-Backup/libPlugin-Backup.so: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o
Plugin-Backup/libPlugin-Backup.so: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o
Plugin-Backup/libPlugin-Backup.so: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o
Plugin-Backup/libPlugin-Backup.so: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o
Plugin-Backup/libPlugin-Backup.so: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build.make
Plugin-Backup/libPlugin-Backup.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtScript.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtUiTools.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtHelp.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtWebKit.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtGui.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtXml.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtSql.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtNetwork.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtCore.dylib
Plugin-Backup/libPlugin-Backup.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
Plugin-Backup/libPlugin-Backup.so: ACG/libACG.1.0.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtScript.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtUiTools.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtHelp.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtWebKit.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtGui.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtXml.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtSql.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtNetwork.dylib
Plugin-Backup/libPlugin-Backup.so: /opt/local/lib/libQtCore.dylib
Plugin-Backup/libPlugin-Backup.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
Plugin-Backup/libPlugin-Backup.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
Plugin-Backup/libPlugin-Backup.so: /usr/local/lib/libGLEW.dylib
Plugin-Backup/libPlugin-Backup.so: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-Backup.so"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-Backup.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-Backup/./libPlugin-Backup.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-Backup.so

# Rule to build all files generated by this target.
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build: Plugin-Backup/libPlugin-Backup.so
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/build

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/requires: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/BackupPlugin.cc.o.requires
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/requires: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupBackup.cc.o.requires
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/requires: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/GroupData.cc.o.requires
Plugin-Backup/CMakeFiles/Plugin-Backup.dir/requires: Plugin-Backup/CMakeFiles/Plugin-Backup.dir/moc_BackupPlugin.cpp.o.requires
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/requires

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-Backup && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-Backup.dir/cmake_clean.cmake
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/clean

Plugin-Backup/CMakeFiles/Plugin-Backup.dir/depend: Plugin-Backup/moc_BackupPlugin.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-Backup /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-Backup /Users/Juyong/OpenFlipper/build/Plugin-Backup/CMakeFiles/Plugin-Backup.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-Backup/CMakeFiles/Plugin-Backup.dir/depend

