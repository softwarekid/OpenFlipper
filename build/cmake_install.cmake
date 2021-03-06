# Install script for directory: /Users/Juyong/OpenFlipper

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "/Users/Juyong/OpenFlipper/build/Build/OpenFlipper.app" USE_SOURCE_PERMISSIONS)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/Users/Juyong/OpenFlipper/build/ACG/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/OpenFlipper/PluginLib/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/tests/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperTarget/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/DeveloperQtHelpTarget/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/UserTarget/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/OpenFlipper/Documentation/UserQtHelpTarget/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/libs_required/OpenMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/libs_required/OpenVolumeMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Backup/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Color/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Datacontrol/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Decimater/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-GaussCurvature/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-InfoMeshObject/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-InfoSkeleton/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-InfoVolumeMeshObject/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-INI/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-IsotropicRemesher/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Laplace/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-LBC/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-MaterialPicker/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-MeanCurvature/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-MeshCompare/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-MeshRepair/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Move/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-PolyLine/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-PrimitivesGenerator/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Print/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-PropertyVis/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Remesher/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Ruler/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Scripting/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-SimpleSmoother/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-SkeletalAnimation/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-SkeletonEditing/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Slice/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Smoother/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-SplatCloudRenderingControl/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Subdivider/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Test/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-TextureControl/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-Topology/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-ViewControl/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/Plugin-VSI/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBundle/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileBVH/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileHeightFieldImage/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileLgt/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileOBJ/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileOFF/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileOfv/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileOM/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileOVM/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePla/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePLY/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePolyLine/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FilePTS/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileScript/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileSKL/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileSPH/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileSTL/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-FilePlugins/Plugin-FileVTK/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Classic/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-DepthPeeling/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Old-DepthPeeling/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-Picking/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-ShaderPipeline/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Renderers/Plugin-Render-SSAO/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionBase/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionBSplineCurve/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionBSplineSurface/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionMeshObject/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionObject/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionPolyLine/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionSplatCloudObject/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-Selection/Plugin-SelectionVolumeMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeBSplineCurve/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeBSplineSurface/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeCamera/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeCoordsys/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeHexahedralMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeLight/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePlane/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePolyhedralMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePolyLine/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypePolyMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeSkeleton/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeSphere/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeSplatCloud/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/PluginCollection-TypePlugins/Plugin-TypeTriangleMesh/cmake_install.cmake")
  INCLUDE("/Users/Juyong/OpenFlipper/build/OpenFlipper/CoreApp/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/Users/Juyong/OpenFlipper/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/Users/Juyong/OpenFlipper/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
