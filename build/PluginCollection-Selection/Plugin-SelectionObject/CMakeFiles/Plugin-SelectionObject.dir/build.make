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
include PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/flags.make

PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp: ../PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ObjectSelectionPlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject -I/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/flags.make
PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o: ../PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionFunctions.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionFunctions.cc

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionFunctions.cc > CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.i

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionFunctions.cc -o CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.s

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.requires:
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.requires

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.provides: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.requires
	$(MAKE) -f PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/build.make PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.provides.build
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.provides

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.provides.build: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/flags.make
PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o: ../PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.cc

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.cc > CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.i

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.cc -o CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.s

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.requires:
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.requires

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.provides: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.requires
	$(MAKE) -f PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/build.make PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.provides.build
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.provides

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.provides.build: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/flags.make
PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o: PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp > CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.i

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp -o CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.s

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.requires:
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.requires

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.provides: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.requires
	$(MAKE) -f PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/build.make PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.provides.build
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.provides

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.provides.build: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o

# Object files for target Plugin-SelectionObject
Plugin__SelectionObject_OBJECTS = \
"CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o" \
"CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o" \
"CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o"

# External object files for target Plugin-SelectionObject
Plugin__SelectionObject_EXTERNAL_OBJECTS =

PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/build.make
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtScript.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtGui.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtXml.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtSql.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtCore.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: ACG/libACG.1.0.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtScript.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtGui.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtXml.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtSql.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /opt/local/lib/libQtCore.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: /usr/local/lib/libGLEW.dylib
PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-SelectionObject.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-SelectionObject.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/./libPlugin-SelectionObject.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-SelectionObject.so

# Rule to build all files generated by this target.
PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/build: PluginCollection-Selection/Plugin-SelectionObject/libPlugin-SelectionObject.so
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/build

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/requires: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionFunctions.cc.o.requires
PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/requires: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/ObjectSelectionPlugin.cc.o.requires
PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/requires: PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/moc_ObjectSelectionPlugin.cpp.o.requires
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/requires

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-SelectionObject.dir/cmake_clean.cmake
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/clean

PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/depend: PluginCollection-Selection/Plugin-SelectionObject/moc_ObjectSelectionPlugin.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-Selection/Plugin-SelectionObject /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject /Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-Selection/Plugin-SelectionObject/CMakeFiles/Plugin-SelectionObject.dir/depend
