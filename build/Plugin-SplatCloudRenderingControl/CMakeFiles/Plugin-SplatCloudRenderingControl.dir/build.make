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
include Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/depend.make

# Include the progress variables for this target.
include Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/progress.make

# Include the compile flags for this target's objects.
include Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/flags.make

Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp: ../Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_SplatCloudRenderingControlPlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl -I/Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.hh -o /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/flags.make
Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o: ../Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o -c /Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.cc

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.cc > CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.i

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.cc -o CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.s

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.requires:
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.requires

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.provides: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.requires
	$(MAKE) -f Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/build.make Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.provides.build
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.provides

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.provides.build: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/flags.make
Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o: Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp > CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.i

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp -o CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.s

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.requires:
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.requires

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.provides: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.requires
	$(MAKE) -f Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/build.make Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.provides.build
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.provides

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.provides.build: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o

# Object files for target Plugin-SplatCloudRenderingControl
Plugin__SplatCloudRenderingControl_OBJECTS = \
"CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o" \
"CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o"

# External object files for target Plugin-SplatCloudRenderingControl
Plugin__SplatCloudRenderingControl_EXTERNAL_OBJECTS =

Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/build.make
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtScript.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtUiTools.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtHelp.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtWebKit.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtGui.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtXml.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtSql.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtNetwork.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtCore.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: ACG/libACG.1.0.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtScript.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtUiTools.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtHelp.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtWebKit.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtGui.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtXml.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtSql.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtNetwork.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /opt/local/lib/libQtCore.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: /usr/local/lib/libGLEW.dylib
Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-SplatCloudRenderingControl.so"
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-SplatCloudRenderingControl.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/./libPlugin-SplatCloudRenderingControl.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-SplatCloudRenderingControl.so
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl/Icons/SplatCloudRenderingControl.png /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Icons/SplatCloudRenderingControl.png

# Rule to build all files generated by this target.
Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/build: Plugin-SplatCloudRenderingControl/libPlugin-SplatCloudRenderingControl.so
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/build

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/requires: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/SplatCloudRenderingControlPlugin.cc.o.requires
Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/requires: Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/moc_SplatCloudRenderingControlPlugin.cpp.o.requires
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/requires

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-SplatCloudRenderingControl.dir/cmake_clean.cmake
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/clean

Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/depend: Plugin-SplatCloudRenderingControl/moc_SplatCloudRenderingControlPlugin.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-SplatCloudRenderingControl /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl /Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-SplatCloudRenderingControl/CMakeFiles/Plugin-SplatCloudRenderingControl.dir/depend
