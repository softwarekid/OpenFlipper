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
include PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/flags.make

PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp: ../PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_FileBundle.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle -I/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/flags.make
PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o: ../PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.cc

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.cc > CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.i

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.cc -o CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.s

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.requires:
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.requires

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.provides: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.requires
	$(MAKE) -f PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/build.make PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.provides.build
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.provides

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.provides.build: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/flags.make
PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o: PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp > CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.i

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp -o CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.s

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.requires:
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.requires

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.provides: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.requires
	$(MAKE) -f PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/build.make PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.provides.build
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.provides

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.provides.build: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o

# Object files for target Plugin-FileBundle
Plugin__FileBundle_OBJECTS = \
"CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o" \
"CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o"

# External object files for target Plugin-FileBundle
Plugin__FileBundle_EXTERNAL_OBJECTS =

PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/build.make
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtScript.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtGui.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtXml.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtSql.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtCore.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: ACG/libACG.1.0.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtScript.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtGui.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtXml.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtSql.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /opt/local/lib/libQtCore.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: /usr/local/lib/libGLEW.dylib
PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-FileBundle.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-FileBundle.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/./libPlugin-FileBundle.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-FileBundle.so

# Rule to build all files generated by this target.
PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/build: PluginCollection-FilePlugins/Plugin-FileBundle/libPlugin-FileBundle.so
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/build

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/requires: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/FileBundle.cc.o.requires
PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/requires: PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/moc_FileBundle.cpp.o.requires
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/requires

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-FileBundle.dir/cmake_clean.cmake
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/clean

PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/depend: PluginCollection-FilePlugins/Plugin-FileBundle/moc_FileBundle.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-FilePlugins/Plugin-FileBundle /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle /Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-FilePlugins/Plugin-FileBundle/CMakeFiles/Plugin-FileBundle.dir/depend

