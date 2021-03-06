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
include PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/flags.make

PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp: ../PluginCollection-TypePlugins/Plugin-TypePlane/TypePlane.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_TypePlane.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane -I/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane/TypePlane.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/flags.make
PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o: ../PluginCollection-TypePlugins/Plugin-TypePlane/TypePlane.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane/TypePlane.cc

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane/TypePlane.cc > CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.i

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane/TypePlane.cc -o CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.s

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.requires:
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.requires

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.provides: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.requires
	$(MAKE) -f PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/build.make PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.provides.build
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.provides

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.provides.build: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/flags.make
PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o: PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp > CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.i

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp -o CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.s

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.requires:
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.requires

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.provides: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.requires
	$(MAKE) -f PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/build.make PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.provides.build
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.provides

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.provides.build: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o

# Object files for target Plugin-TypePlane
Plugin__TypePlane_OBJECTS = \
"CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o" \
"CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o"

# External object files for target Plugin-TypePlane
Plugin__TypePlane_EXTERNAL_OBJECTS =

PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/build.make
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtScript.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtGui.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtXml.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtSql.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtCore.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: ACG/libACG.1.0.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtScript.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtGui.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtXml.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtSql.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /opt/local/lib/libQtCore.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: /usr/local/lib/libGLEW.dylib
PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-TypePlane.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-TypePlane.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/./libPlugin-TypePlane.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-TypePlane.so
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane/Icons/PlaneType.png /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Icons/PlaneType.png

# Rule to build all files generated by this target.
PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/build: PluginCollection-TypePlugins/Plugin-TypePlane/libPlugin-TypePlane.so
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/build

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/requires: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/TypePlane.cc.o.requires
PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/requires: PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/moc_TypePlane.cpp.o.requires
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/requires

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-TypePlane.dir/cmake_clean.cmake
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/clean

PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/depend: PluginCollection-TypePlugins/Plugin-TypePlane/moc_TypePlane.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-TypePlugins/Plugin-TypePlane /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane /Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-TypePlugins/Plugin-TypePlane/CMakeFiles/Plugin-TypePlane.dir/depend

