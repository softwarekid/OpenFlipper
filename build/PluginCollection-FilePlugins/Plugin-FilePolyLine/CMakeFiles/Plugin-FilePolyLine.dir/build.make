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
include PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/flags.make

PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp: ../PluginCollection-FilePlugins/Plugin-FilePolyLine/FilePolyLine.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_FilePolyLine.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine -I/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine/FilePolyLine.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/flags.make
PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o: ../PluginCollection-FilePlugins/Plugin-FilePolyLine/FilePolyLine.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine/FilePolyLine.cc

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine/FilePolyLine.cc > CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.i

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine/FilePolyLine.cc -o CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.s

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.requires:
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.requires

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.provides: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.requires
	$(MAKE) -f PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/build.make PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.provides.build
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.provides

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.provides.build: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/flags.make
PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o: PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp > CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.i

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp -o CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.s

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.requires:
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.requires

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.provides: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.requires
	$(MAKE) -f PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/build.make PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.provides.build
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.provides

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.provides.build: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o

# Object files for target Plugin-FilePolyLine
Plugin__FilePolyLine_OBJECTS = \
"CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o" \
"CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o"

# External object files for target Plugin-FilePolyLine
Plugin__FilePolyLine_EXTERNAL_OBJECTS =

PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/build.make
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtScript.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtGui.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtXml.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtSql.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtCore.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: ACG/libACG.1.0.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtScript.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtGui.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtXml.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtSql.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /opt/local/lib/libQtCore.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: /usr/local/lib/libGLEW.dylib
PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-FilePolyLine.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-FilePolyLine.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/./libPlugin-FilePolyLine.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-FilePolyLine.so

# Rule to build all files generated by this target.
PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/build: PluginCollection-FilePlugins/Plugin-FilePolyLine/libPlugin-FilePolyLine.so
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/build

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/requires: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/FilePolyLine.cc.o.requires
PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/requires: PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/moc_FilePolyLine.cpp.o.requires
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/requires

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-FilePolyLine.dir/cmake_clean.cmake
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/clean

PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/depend: PluginCollection-FilePlugins/Plugin-FilePolyLine/moc_FilePolyLine.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FilePolyLine /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-FilePlugins/Plugin-FilePolyLine/CMakeFiles/Plugin-FilePolyLine.dir/depend

