# CMake generated Testfile for 
# Source directory: /Users/Juyong/OpenFlipper/tests
# Build directory: /Users/Juyong/OpenFlipper/build/tests
# 
# This file includes the relevent testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(BatchStart "/Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/MacOS/OpenFlipper" "-b" "-c")
SET_TESTS_PROPERTIES(BatchStart PROPERTIES  PROCESSORS "1" RUN_SERIAL "TRUE" TIMEOUT "180")
SUBDIRS(compareTool)
SUBDIRS(MinimalExecutionTest)
SUBDIRS(Plugin-Datacontrol)
SUBDIRS(Plugin-LBC)
SUBDIRS(Plugin-Smoother)
SUBDIRS(Plugin-FileOBJ)
SUBDIRS(Plugin-FileOFF)
SUBDIRS(Plugin-FileOM)
SUBDIRS(Plugin-FilePLY)
SUBDIRS(Plugin-FileSKL)
SUBDIRS(Plugin-FileSTL)
SUBDIRS(Plugin-FileVTK)
