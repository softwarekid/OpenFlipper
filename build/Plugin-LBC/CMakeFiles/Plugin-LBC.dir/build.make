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
include Plugin-LBC/CMakeFiles/Plugin-LBC.dir/depend.make

# Include the progress variables for this target.
include Plugin-LBC/CMakeFiles/Plugin-LBC.dir/progress.make

# Include the compile flags for this target's objects.
include Plugin-LBC/CMakeFiles/Plugin-LBC.dir/flags.make

Plugin-LBC/ui_LBCToolbar.hh: ../Plugin-LBC/LBCToolbar.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_LBCToolbar.hh"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /opt/local/bin/uic -o /Users/Juyong/OpenFlipper/build/Plugin-LBC/ui_LBCToolbar.hh /Users/Juyong/OpenFlipper/Plugin-LBC/LBCToolbar.ui

Plugin-LBC/moc_LBCPlugin.cpp: ../Plugin-LBC/LBCPlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_LBCPlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-LBC/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-LBC -I/Users/Juyong/OpenFlipper/build/Plugin-LBC -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-LBC/LBCPlugin.hh -o /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCPlugin.cpp

Plugin-LBC/moc_LBCToolbarWidget.cpp: ../Plugin-LBC/LBCToolbarWidget.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_LBCToolbarWidget.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-LBC/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-LBC -I/Users/Juyong/OpenFlipper/build/Plugin-LBC -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-LBC/LBCToolbarWidget.hh -o /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCToolbarWidget.cpp

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/flags.make
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o: ../Plugin-LBC/LBCObject.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o -c /Users/Juyong/OpenFlipper/Plugin-LBC/LBCObject.cc

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-LBC.dir/LBCObject.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-LBC/LBCObject.cc > CMakeFiles/Plugin-LBC.dir/LBCObject.cc.i

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-LBC.dir/LBCObject.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-LBC/LBCObject.cc -o CMakeFiles/Plugin-LBC.dir/LBCObject.cc.s

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.requires:
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.requires

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.provides: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.requires
	$(MAKE) -f Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build.make Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.provides.build
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.provides

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.provides.build: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/flags.make
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o: ../Plugin-LBC/LBCPlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o -c /Users/Juyong/OpenFlipper/Plugin-LBC/LBCPlugin.cc

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-LBC/LBCPlugin.cc > CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.i

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-LBC/LBCPlugin.cc -o CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.s

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.requires:
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.requires

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.provides: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.requires
	$(MAKE) -f Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build.make Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.provides.build
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.provides

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.provides.build: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/flags.make
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o: ../Plugin-LBC/LBCToolbarWidget.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o -c /Users/Juyong/OpenFlipper/Plugin-LBC/LBCToolbarWidget.cc

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-LBC/LBCToolbarWidget.cc > CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.i

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-LBC/LBCToolbarWidget.cc -o CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.s

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.requires:
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.requires

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.provides: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.requires
	$(MAKE) -f Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build.make Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.provides.build
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.provides

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.provides.build: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/flags.make
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o: Plugin-LBC/moc_LBCPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCPlugin.cpp

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCPlugin.cpp > CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.i

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCPlugin.cpp -o CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.s

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.requires:
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.requires

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.provides: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.requires
	$(MAKE) -f Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build.make Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.provides.build
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.provides

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.provides.build: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/flags.make
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o: Plugin-LBC/moc_LBCToolbarWidget.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCToolbarWidget.cpp

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCToolbarWidget.cpp > CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.i

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-LBC/moc_LBCToolbarWidget.cpp -o CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.s

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.requires:
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.requires

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.provides: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.requires
	$(MAKE) -f Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build.make Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.provides.build
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.provides

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.provides.build: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o

# Object files for target Plugin-LBC
Plugin__LBC_OBJECTS = \
"CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o" \
"CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o" \
"CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o" \
"CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o" \
"CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o"

# External object files for target Plugin-LBC
Plugin__LBC_EXTERNAL_OBJECTS =

Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o
Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o
Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o
Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o
Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o
Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build.make
Plugin-LBC/libPlugin-LBC.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtScript.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtUiTools.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtHelp.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtWebKit.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtGui.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtXml.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtSql.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtNetwork.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtCore.dylib
Plugin-LBC/libPlugin-LBC.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
Plugin-LBC/libPlugin-LBC.so: ACG/libACG.1.0.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtScript.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtUiTools.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtHelp.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtWebKit.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtGui.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtXml.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtSql.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtNetwork.dylib
Plugin-LBC/libPlugin-LBC.so: /opt/local/lib/libQtCore.dylib
Plugin-LBC/libPlugin-LBC.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
Plugin-LBC/libPlugin-LBC.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
Plugin-LBC/libPlugin-LBC.so: /usr/local/lib/libGLEW.dylib
Plugin-LBC/libPlugin-LBC.so: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-LBC.so"
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-LBC.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-LBC/./libPlugin-LBC.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-LBC.so
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/Plugin-LBC/Icons/LBC2.png /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Icons/LBC2.png

# Rule to build all files generated by this target.
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build: Plugin-LBC/libPlugin-LBC.so
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/build

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/requires: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCObject.cc.o.requires
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/requires: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCPlugin.cc.o.requires
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/requires: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/LBCToolbarWidget.cc.o.requires
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/requires: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCPlugin.cpp.o.requires
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/requires: Plugin-LBC/CMakeFiles/Plugin-LBC.dir/moc_LBCToolbarWidget.cpp.o.requires
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/requires

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-LBC && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-LBC.dir/cmake_clean.cmake
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/clean

Plugin-LBC/CMakeFiles/Plugin-LBC.dir/depend: Plugin-LBC/ui_LBCToolbar.hh
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/depend: Plugin-LBC/moc_LBCPlugin.cpp
Plugin-LBC/CMakeFiles/Plugin-LBC.dir/depend: Plugin-LBC/moc_LBCToolbarWidget.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-LBC /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-LBC /Users/Juyong/OpenFlipper/build/Plugin-LBC/CMakeFiles/Plugin-LBC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-LBC/CMakeFiles/Plugin-LBC.dir/depend

