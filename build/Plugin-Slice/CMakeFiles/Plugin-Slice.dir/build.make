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
include Plugin-Slice/CMakeFiles/Plugin-Slice.dir/depend.make

# Include the progress variables for this target.
include Plugin-Slice/CMakeFiles/Plugin-Slice.dir/progress.make

# Include the compile flags for this target's objects.
include Plugin-Slice/CMakeFiles/Plugin-Slice.dir/flags.make

Plugin-Slice/ui_toolbox.hh: ../Plugin-Slice/toolbox.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_toolbox.hh"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /opt/local/bin/uic -o /Users/Juyong/OpenFlipper/build/Plugin-Slice/ui_toolbox.hh /Users/Juyong/OpenFlipper/Plugin-Slice/toolbox.ui

Plugin-Slice/moc_SlicePlugin.cpp: ../Plugin-Slice/SlicePlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_SlicePlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-Slice/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-Slice -I/Users/Juyong/OpenFlipper/build/Plugin-Slice -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-Slice/SlicePlugin.hh -o /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SlicePlugin.cpp

Plugin-Slice/moc_SliceToolbox.cpp: ../Plugin-Slice/SliceToolbox.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_SliceToolbox.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-Slice/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-Slice -I/Users/Juyong/OpenFlipper/build/Plugin-Slice -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-Slice/SliceToolbox.hh -o /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SliceToolbox.cpp

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/flags.make
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o: ../Plugin-Slice/SlicePlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o -c /Users/Juyong/OpenFlipper/Plugin-Slice/SlicePlugin.cc

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-Slice/SlicePlugin.cc > CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.i

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-Slice/SlicePlugin.cc -o CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.s

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.requires:
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.requires

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.provides: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.requires
	$(MAKE) -f Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build.make Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.provides.build
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.provides

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.provides.build: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/flags.make
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o: ../Plugin-Slice/SliceToolbox.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o -c /Users/Juyong/OpenFlipper/Plugin-Slice/SliceToolbox.cc

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-Slice/SliceToolbox.cc > CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.i

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-Slice/SliceToolbox.cc -o CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.s

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.requires:
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.requires

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.provides: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.requires
	$(MAKE) -f Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build.make Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.provides.build
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.provides

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.provides.build: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/flags.make
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o: Plugin-Slice/moc_SlicePlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SlicePlugin.cpp

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SlicePlugin.cpp > CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.i

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SlicePlugin.cpp -o CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.s

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.requires:
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.requires

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.provides: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.requires
	$(MAKE) -f Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build.make Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.provides.build
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.provides

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.provides.build: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/flags.make
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o: Plugin-Slice/moc_SliceToolbox.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SliceToolbox.cpp

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SliceToolbox.cpp > CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.i

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-Slice/moc_SliceToolbox.cpp -o CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.s

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.requires:
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.requires

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.provides: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.requires
	$(MAKE) -f Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build.make Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.provides.build
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.provides

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.provides.build: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o

# Object files for target Plugin-Slice
Plugin__Slice_OBJECTS = \
"CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o" \
"CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o" \
"CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o" \
"CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o"

# External object files for target Plugin-Slice
Plugin__Slice_EXTERNAL_OBJECTS =

Plugin-Slice/libPlugin-Slice.so: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o
Plugin-Slice/libPlugin-Slice.so: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o
Plugin-Slice/libPlugin-Slice.so: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o
Plugin-Slice/libPlugin-Slice.so: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o
Plugin-Slice/libPlugin-Slice.so: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build.make
Plugin-Slice/libPlugin-Slice.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtScript.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtUiTools.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtHelp.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtWebKit.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtGui.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtXml.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtSql.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtNetwork.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtCore.dylib
Plugin-Slice/libPlugin-Slice.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
Plugin-Slice/libPlugin-Slice.so: ACG/libACG.1.0.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtScript.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtUiTools.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtHelp.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtWebKit.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtGui.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtXml.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtSql.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtNetwork.dylib
Plugin-Slice/libPlugin-Slice.so: /opt/local/lib/libQtCore.dylib
Plugin-Slice/libPlugin-Slice.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
Plugin-Slice/libPlugin-Slice.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
Plugin-Slice/libPlugin-Slice.so: /usr/local/lib/libGLEW.dylib
Plugin-Slice/libPlugin-Slice.so: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-Slice.so"
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-Slice.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-Slice/./libPlugin-Slice.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-Slice.so
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/Plugin-Slice/Icons/slice.png /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Icons/slice.png

# Rule to build all files generated by this target.
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build: Plugin-Slice/libPlugin-Slice.so
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/build

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/requires: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SlicePlugin.cc.o.requires
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/requires: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/SliceToolbox.cc.o.requires
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/requires: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SlicePlugin.cpp.o.requires
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/requires: Plugin-Slice/CMakeFiles/Plugin-Slice.dir/moc_SliceToolbox.cpp.o.requires
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/requires

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-Slice && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-Slice.dir/cmake_clean.cmake
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/clean

Plugin-Slice/CMakeFiles/Plugin-Slice.dir/depend: Plugin-Slice/ui_toolbox.hh
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/depend: Plugin-Slice/moc_SlicePlugin.cpp
Plugin-Slice/CMakeFiles/Plugin-Slice.dir/depend: Plugin-Slice/moc_SliceToolbox.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-Slice /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-Slice /Users/Juyong/OpenFlipper/build/Plugin-Slice/CMakeFiles/Plugin-Slice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-Slice/CMakeFiles/Plugin-Slice.dir/depend

