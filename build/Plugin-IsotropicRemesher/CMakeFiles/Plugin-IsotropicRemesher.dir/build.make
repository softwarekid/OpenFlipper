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
include Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/depend.make

# Include the progress variables for this target.
include Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/progress.make

# Include the compile flags for this target's objects.
include Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/flags.make

Plugin-IsotropicRemesher/ui_toolbox.hh: ../Plugin-IsotropicRemesher/toolbox.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_toolbox.hh"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /opt/local/bin/uic -o /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/ui_toolbox.hh /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/toolbox.ui

Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp: ../Plugin-IsotropicRemesher/IsotropicRemesherPlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_IsotropicRemesherPlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher -I/Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherPlugin.hh -o /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp

Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp: ../Plugin-IsotropicRemesher/IsotropicRemesherToolbox.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_IsotropicRemesherToolbox.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher -I/Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherToolbox.hh -o /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp

Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp: ../Plugin-IsotropicRemesher/ProgressEmitter.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ProgressEmitter.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher -I/Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/ProgressEmitter.hh -o /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/flags.make
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o: ../Plugin-IsotropicRemesher/IsotropicRemesherPlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o -c /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherPlugin.cc

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherPlugin.cc > CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.i

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherPlugin.cc -o CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.s

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.requires:
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.requires

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.provides: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.requires
	$(MAKE) -f Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build.make Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.provides.build
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.provides

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.provides.build: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/flags.make
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o: ../Plugin-IsotropicRemesher/IsotropicRemesherToolbox.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o -c /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherToolbox.cc

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherToolbox.cc > CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.i

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher/IsotropicRemesherToolbox.cc -o CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.s

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.requires:
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.requires

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.provides: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.requires
	$(MAKE) -f Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build.make Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.provides.build
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.provides

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.provides.build: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/flags.make
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o: Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp > CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.i

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp -o CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.s

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.requires:
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.requires

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.provides: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.requires
	$(MAKE) -f Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build.make Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.provides.build
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.provides

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.provides.build: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/flags.make
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o: Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp > CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.i

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp -o CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.s

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.requires:
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.requires

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.provides: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.requires
	$(MAKE) -f Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build.make Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.provides.build
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.provides

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.provides.build: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/flags.make
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o: Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp > CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.i

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp -o CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.s

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.requires:
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.requires

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.provides: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.requires
	$(MAKE) -f Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build.make Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.provides.build
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.provides

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.provides.build: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o

# Object files for target Plugin-IsotropicRemesher
Plugin__IsotropicRemesher_OBJECTS = \
"CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o" \
"CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o" \
"CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o" \
"CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o" \
"CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o"

# External object files for target Plugin-IsotropicRemesher
Plugin__IsotropicRemesher_EXTERNAL_OBJECTS =

Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build.make
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtScript.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtUiTools.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtHelp.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtWebKit.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtGui.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtXml.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtSql.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtNetwork.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtCore.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: ACG/libACG.1.0.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtScript.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtUiTools.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtHelp.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtWebKit.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtGui.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtXml.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtSql.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtNetwork.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /opt/local/lib/libQtCore.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: /usr/local/lib/libGLEW.dylib
Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-IsotropicRemesher.so"
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-IsotropicRemesher.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/./libPlugin-IsotropicRemesher.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-IsotropicRemesher.so

# Rule to build all files generated by this target.
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build: Plugin-IsotropicRemesher/libPlugin-IsotropicRemesher.so
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/build

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/requires: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherPlugin.cc.o.requires
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/requires: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/IsotropicRemesherToolbox.cc.o.requires
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/requires: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherPlugin.cpp.o.requires
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/requires: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_IsotropicRemesherToolbox.cpp.o.requires
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/requires: Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/moc_ProgressEmitter.cpp.o.requires
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/requires

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-IsotropicRemesher.dir/cmake_clean.cmake
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/clean

Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/depend: Plugin-IsotropicRemesher/ui_toolbox.hh
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/depend: Plugin-IsotropicRemesher/moc_IsotropicRemesherPlugin.cpp
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/depend: Plugin-IsotropicRemesher/moc_IsotropicRemesherToolbox.cpp
Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/depend: Plugin-IsotropicRemesher/moc_ProgressEmitter.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-IsotropicRemesher /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher /Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-IsotropicRemesher/CMakeFiles/Plugin-IsotropicRemesher.dir/depend
