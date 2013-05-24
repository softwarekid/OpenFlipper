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
include PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/depend.make

# Include the progress variables for this target.
include PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/progress.make

# Include the compile flags for this target's objects.
include PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/flags.make

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/ui_philipsStereoSettingsWidget.hh: ../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_philipsStereoSettingsWidget.hh"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /opt/local/bin/uic -o /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/ui_philipsStereoSettingsWidget.hh /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.ui

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp: ../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_philipsStereoSettingsWidget.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo -I/Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp: ../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_PostProcessorPhilipsStereo.cpp"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /opt/local/bin/moc -I/opt/local/include -I/opt/local/include/QtOpenGL -I/opt/local/include/QtScript -I/opt/local/include/QtUiTools -I/opt/local/include/QtHelp -I/opt/local/include/QtWebKit -I/opt/local/include/QtScriptTools -I/opt/local/include/QtXmlPatterns -I/opt/local/include/QtGui -I/opt/local/include/QtXml -I/opt/local/include/QtSql -I/opt/local/include/QtNetwork -I/opt/local/include/QtCore -I/Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/. -I/Users/Juyong/OpenFlipper -I/Users/Juyong/OpenFlipper/libs_required/OpenMesh/src -I/Users/Juyong/OpenFlipper/libs_required/OpenVolumeMesh/src -I/Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo -I/Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo -F/System/Library/Frameworks -I/usr/local/include -I/System/Library/Frameworks/GLUT.framework/Headers -I/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES -DQT_OPENGL_LIB -DQT_SCRIPT_LIB -DQT_UITOOLS_LIB -DQT_HELP_LIB -DQT_WEBKIT_LIB -DQT_SCRIPTTOOLS_LIB -DQT_XMLPATTERNS_LIB -DQT_GUI_LIB -DQT_XML_LIB -DQT_SQL_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DENABLE_OPENVOLUMEMESH -DOPENFLIPPER_APPDIR="../Resources" -DOPENFLIPPER_PLUGINDIR="Plugins" -DOPENFLIPPER_DATADIR="." -DARCH_DARWIN -DINCLUDE_TEMPLATES /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.hh -o /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o: ../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.cc

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.cc > CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.i

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.cc -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.s

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o: ../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.cc
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/ui_philipsStereoSettingsWidget.hh
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.cc

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.cc > CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.i

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.cc -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.s

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o: ../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CRC/crc32.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o -c /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CRC/crc32.cc

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CRC/crc32.cc > CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.i

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CRC/crc32.cc -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.s

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp > CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.i

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.s

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/flags.make
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Juyong/OpenFlipper/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)    -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o -c /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.i"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -E /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp > CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.i

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.s"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)    -S /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp -o CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.s

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.requires:
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.requires

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.provides: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.requires
	$(MAKE) -f PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build.make PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.provides.build
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.provides

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.provides.build: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o

# Object files for target Plugin-PostProcessor-PhilipsStereo
Plugin__PostProcessor__PhilipsStereo_OBJECTS = \
"CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o" \
"CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o" \
"CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o" \
"CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o" \
"CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o"

# External object files for target Plugin-PostProcessor-PhilipsStereo
Plugin__PostProcessor__PhilipsStereo_EXTERNAL_OBJECTS =

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build.make
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: OpenFlipper/PluginLib/libOpenFlipperPluginLib.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtScript.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtGui.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtXml.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtSql.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtCore.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: libs_required/OpenVolumeMesh/src/libOpenVolumeMesh.1.1.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: ACG/libACG.1.0.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtOpenGL.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtScript.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtUiTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtHelp.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtWebKit.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtScriptTools.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtXmlPatterns.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtGui.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtXml.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtSql.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtNetwork.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /opt/local/lib/libQtCore.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: libs_required/OpenMesh/src/OpenMesh/Tools/libOpenMeshTools.2.4.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: libs_required/OpenMesh/src/OpenMesh/Core/libOpenMeshCore.2.4.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: /usr/local/lib/libGLEW.dylib
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libPlugin-PostProcessor-PhilipsStereo.so"
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && /opt/local/bin/cmake -E copy_if_different /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/./libPlugin-PostProcessor-PhilipsStereo.so /Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/Resources/Plugins/libPlugin-PostProcessor-PhilipsStereo.so

# Rule to build all files generated by this target.
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/libPlugin-PostProcessor-PhilipsStereo.so
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/build

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/PostProcessorPhilipsStereo.cc.o.requires
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/widgets/philipsStereoSettingsWidget.cc.o.requires
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/CRC/crc32.cc.o.requires
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_PostProcessorPhilipsStereo.cpp.o.requires
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/requires: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/moc_philipsStereoSettingsWidget.cpp.o.requires
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/requires

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/clean:
	cd /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo && $(CMAKE_COMMAND) -P CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/cmake_clean.cmake
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/clean

PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/depend: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/ui_philipsStereoSettingsWidget.hh
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/depend: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_philipsStereoSettingsWidget.cpp
PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/depend: PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/moc_PostProcessorPhilipsStereo.cpp
	cd /Users/Juyong/OpenFlipper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Juyong/OpenFlipper /Users/Juyong/OpenFlipper/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo /Users/Juyong/OpenFlipper/build /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo /Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/CMakeFiles/Plugin-PostProcessor-PhilipsStereo.dir/depend

