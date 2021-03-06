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
include PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/flags.make

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp: ../PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/ClassicDepthPeeling.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ClassicDepthPeeling.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling -I/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/ClassicDepthPeeling.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/flags.make
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o: ../PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/ClassicDepthPeeling.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/ClassicDepthPeeling.cc

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/ClassicDepthPeeling.cc > CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.i

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/ClassicDepthPeeling.cc -o CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.s

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.requires:
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.requires

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.provides: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.requires
	$(MAKE) -f PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/build.make PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.provides.build
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.provides

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.provides.build: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/flags.make
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp > CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.i

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp -o CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.s

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.requires:
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.requires

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.provides: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.requires
	$(MAKE) -f PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/build.make PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.provides.build
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.provides

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.provides.build: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o

# Object files for target Plugin-Render-Old-DepthPeeling
Plugin__Render__Old__DepthPeeling_OBJECTS = \
"CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o" \
"CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o"

# External object files for target Plugin-Render-Old-DepthPeeling
Plugin__Render__Old__DepthPeeling_EXTERNAL_OBJECTS =

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/build.make
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtScript.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtGui.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtXml.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtSql.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtCore.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: ACG/libACG.1.0.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtScript.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtGui.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtXml.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtSql.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /opt/local/lib/libQtCore.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: /usr/local/lib/libGLEW.dylib
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-Render-Old-DepthPeeling.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/./libPlugin-Render-Old-DepthPeeling.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-Render-Old-DepthPeeling.so
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/Shaders/Blending/dual_peeling_blend_fragment.glsl /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Shaders/Blending/dual_peeling_blend_fragment.glsl
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/Shaders/Blending/dual_peeling_blend_vertex.glsl /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Shaders/Blending/dual_peeling_blend_vertex.glsl
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/Shaders/Blending/dual_peeling_final_fragment.glsl /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Shaders/Blending/dual_peeling_final_fragment.glsl
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/Shaders/Blending/dual_peeling_final_vertex.glsl /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Shaders/Blending/dual_peeling_final_vertex.glsl
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/Shaders/Blending/dual_peeling_init_fragment.glsl /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Shaders/Blending/dual_peeling_init_fragment.glsl
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/Shaders/Blending/dual_peeling_init_vertex.glsl /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Shaders/Blending/dual_peeling_init_vertex.glsl

# Rule to build all files generated by this target.
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/build: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/libPlugin-Render-Old-DepthPeeling.so
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/build

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/requires: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/ClassicDepthPeeling.cc.o.requires
PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/requires: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/moc_ClassicDepthPeeling.cpp.o.requires
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/requires

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/cmake_clean.cmake
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/clean

PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/depend: PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/moc_ClassicDepthPeeling.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling /Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/CMakeFiles/Plugin-Render-Old-DepthPeeling.dir/depend

