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
include Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/depend.make

# Include the progress variables for this target.
include Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/progress.make

# Include the compile flags for this target's objects.
include Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make

Plugin-InfoSkeleton/ui_infoSkeletonWidget.hh: ../Plugin-InfoSkeleton/infoSkeletonWidget.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_infoSkeletonWidget.hh"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /opt/local/bin/uic -o /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/ui_infoSkeletonWidget.hh /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/infoSkeletonWidget.ui

Plugin-InfoSkeleton/moc_infoDialog.cpp: ../Plugin-InfoSkeleton/infoDialog.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_infoDialog.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-InfoSkeleton -I/Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/infoDialog.hh -o /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_infoDialog.cpp

Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp: ../Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_SkeletonObjectInfoPlugin.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/Plugin-InfoSkeleton -I/Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.hh -o /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp

Plugin-InfoSkeleton/qrc_icons.cpp: ../Plugin-InfoSkeleton/icons.qrc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating qrc_icons.cpp"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /opt/local/bin/rcc -o /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/qrc_icons.cpp /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/icons.qrc

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o: ../Plugin-InfoSkeleton/infoDialog.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o -c /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/infoDialog.cc

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/infoDialog.cc > CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.i

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/infoDialog.cc -o CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.s

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.requires:
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.provides: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.requires
	$(MAKE) -f Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.provides.build
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.provides

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.provides.build: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o: ../Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o -c /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.cc

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.cc > CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.i

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.cc -o CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.s

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.requires:
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.provides: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.requires
	$(MAKE) -f Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.provides.build
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.provides

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.provides.build: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o: ../Plugin-InfoSkeleton/SkeletonObjectInfoScripting.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o -c /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoScripting.cc

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoScripting.cc > CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.i

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton/SkeletonObjectInfoScripting.cc -o CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.s

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.requires:
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.provides: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.requires
	$(MAKE) -f Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.provides.build
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.provides

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.provides.build: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o: Plugin-InfoSkeleton/moc_infoDialog.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_infoDialog.cpp

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_infoDialog.cpp > CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.i

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_infoDialog.cpp -o CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.s

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.requires:
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.provides: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.requires
	$(MAKE) -f Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.provides.build
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.provides

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.provides.build: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o: Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp > CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.i

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp -o CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.s

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.requires:
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.provides: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.requires
	$(MAKE) -f Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.provides.build
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.provides

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.provides.build: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/flags.make
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o: Plugin-InfoSkeleton/qrc_icons.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o -c /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/qrc_icons.cpp

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/qrc_icons.cpp > CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.i

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/qrc_icons.cpp -o CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.s

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.requires:
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.provides: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.requires
	$(MAKE) -f Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.provides.build
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.provides

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.provides.build: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o

# Object files for target Plugin-InfoSkeleton
Plugin__InfoSkeleton_OBJECTS = \
"CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o" \
"CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o" \
"CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o" \
"CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o" \
"CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o" \
"CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o"

# External object files for target Plugin-InfoSkeleton
Plugin__InfoSkeleton_EXTERNAL_OBJECTS =

Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build.make
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtScript.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtUiTools.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtHelp.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtWebKit.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtGui.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtXml.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtSql.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtNetwork.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtCore.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: ACG/libACG.1.0.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtOpenGL.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtScript.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtUiTools.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtHelp.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtWebKit.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtScriptTools.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtXmlPatterns.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtGui.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtXml.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtSql.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtNetwork.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /opt/local/lib/libQtCore.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: /usr/local/lib/libGLEW.dylib
Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-InfoSkeleton.so"
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-InfoSkeleton.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/./libPlugin-InfoSkeleton.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-InfoSkeleton.so

# Rule to build all files generated by this target.
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build: Plugin-InfoSkeleton/libPlugin-InfoSkeleton.so
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/build

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/infoDialog.cc.o.requires
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoPlugin.cc.o.requires
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/SkeletonObjectInfoScripting.cc.o.requires
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_infoDialog.cpp.o.requires
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/moc_SkeletonObjectInfoPlugin.cpp.o.requires
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires: Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/qrc_icons.cpp.o.requires
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/requires

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-InfoSkeleton.dir/cmake_clean.cmake
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/clean

Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/depend: Plugin-InfoSkeleton/ui_infoSkeletonWidget.hh
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/depend: Plugin-InfoSkeleton/moc_infoDialog.cpp
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/depend: Plugin-InfoSkeleton/moc_SkeletonObjectInfoPlugin.cpp
Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/depend: Plugin-InfoSkeleton/qrc_icons.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/Plugin-InfoSkeleton /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton /Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Plugin-InfoSkeleton/CMakeFiles/Plugin-InfoSkeleton.dir/depend

