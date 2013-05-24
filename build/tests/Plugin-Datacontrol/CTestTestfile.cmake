# CMake generated Testfile for 
# Source directory: /Users/Juyong/OpenFlipper/Plugin-Datacontrol/tests
# Build directory: /Users/Juyong/OpenFlipper/build/tests/Plugin-Datacontrol
# 
# This file includes the relevent testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(PLUGIN-DATACONTROL-group.ofs "/opt/local/bin/cmake" "-D" "test_cmd=/Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/MacOS/OpenFlipper" "-D" "test_args:string=-c -b testscript-PLUGIN-DATACONTROL-group.ofs" "-P" "/Users/Juyong/OpenFlipper/tests/run_script_test.cmake")
SET_TESTS_PROPERTIES(PLUGIN-DATACONTROL-group.ofs PROPERTIES  PROCESSORS "1" RUN_SERIAL "TRUE" TIMEOUT "180")
ADD_TEST(PLUGIN-DATACONTROL-dataType.ofs "/opt/local/bin/cmake" "-D" "test_cmd=/Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app/Contents/MacOS/OpenFlipper" "-D" "test_args:string=-c -b testscript-PLUGIN-DATACONTROL-dataType.ofs" "-P" "/Users/Juyong/OpenFlipper/tests/run_script_test.cmake")
SET_TESTS_PROPERTIES(PLUGIN-DATACONTROL-dataType.ofs PROPERTIES  PROCESSORS "1" RUN_SERIAL "TRUE" TIMEOUT "180")
