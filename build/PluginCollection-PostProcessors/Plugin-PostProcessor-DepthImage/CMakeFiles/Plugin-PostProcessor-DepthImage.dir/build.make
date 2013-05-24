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
include PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/flags.make

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp: ../PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_PostProcessorDepthImagePlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage -I/Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o: ../PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.cc

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.cc > CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.i

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.cc -o CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.s

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp > CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.i

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp -o CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.s

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o

# Object files for target Plugin-PostProcessor-DepthImage
Plugin__PostProcessor__DepthImage_OBJECTS = \
"CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o" \
"CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o"

# External object files for target Plugin-PostProcessor-DepthImage
Plugin__PostProcessor__DepthImage_EXTERNAL_OBJECTS =

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/build.make
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtScript.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtGui.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtXml.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtSql.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtCore.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: ACG/libACG.1.0.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtScript.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtGui.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtXml.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtSql.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /opt/local/lib/libQtCore.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: /usr/local/lib/libGLEW.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-PostProcessor-DepthImage.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-PostProcessor-DepthImage.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/./libPlugin-PostProcessor-DepthImage.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-PostProcessor-DepthImage.so

# Rule to build all files generated by this target.
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/build: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/libPlugin-PostProcessor-DepthImage.so
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/build

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/PostProcessorDepthImagePlugin.cc.o.requires
PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/moc_PostProcessorDepthImagePlugin.cpp.o.requires
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/requires

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-PostProcessor-DepthImage.dir/cmake_clean.cmake
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/clean

PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/depend: PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/moc_PostProcessorDepthImagePlugin.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/CMakeFiles/Plugin-PostProcessor-DepthImage.dir/depend

