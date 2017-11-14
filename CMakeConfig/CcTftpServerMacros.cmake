SET(CCTFTPSERVER_EXPORT_CMAKECONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CMakeConfig)

################################################################################
# Setup default installation targets for a project
################################################################################
MACRO (CcTftpServerSetInstall ProjectName )
  set_property( TARGET ${ProjectName} APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR};${CMAKE_CURRENT_BINARY_DIR}>
              )

  INSTALL( TARGETS  ${ProjectName}
           EXPORT  "${ProjectName}Config"
           RUNTIME DESTINATION bin
           LIBRARY DESTINATION lib
           ARCHIVE DESTINATION lib/static
           PUBLIC_HEADER DESTINATION include/${ProjectName}
         )
  
  # If we are building just CcOS Framework we have to package all headers and configs
  if(${CMAKE_PROJECT_NAME} STREQUAL "CcOS")
    set_property( TARGET ${ProjectName} APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR};${CMAKE_CURRENT_BINARY_DIR}>
                )
    install(EXPORT "${ProjectName}Config" DESTINATION "lib/${ProjectName}")
    
    INSTALL( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include
             FILES_MATCHING PATTERN "*.h"
             PATTERN "*/src"  EXCLUDE
             PATTERN "*/test" EXCLUDE)
  endif()
ENDMACRO()

################################################################################
# Add Xml Configurations to cmake install
################################################################################
MACRO (CcTftpServerSetInstallConfig ProjectName )
  INSTALL( DIRECTORY    ${CMAKE_CURRENT_SOURCE_DIR}/config/
           DESTINATION  config/${ProjectName}
           PATTERN "*.xml" )
ENDMACRO()

################################################################################
# Set Cmake Version Info to Project
################################################################################
MACRO (CcSetOSVersion ProjectName )
  SET_TARGET_PROPERTIES(  ${ProjectName}
                          PROPERTIES
                          VERSION ${CCTFTPSERVER_EXPORT_VERSION_CMAKE}
                          SOVERSION ${CCTFTPSERVER_EXPORT_VERSION_CMAKE})
ENDMACRO()

################################################################################
# Setup Include Directorys for importing CcTftpServer
################################################################################
MACRO( CcTftpServerTargetIncludeDirs ProjectName )
  foreach(DIR ${ARGN})
    LIST(APPEND DIRS ${DIR} )
    target_include_directories(${ProjectName} PUBLIC $<BUILD_INTERFACE:${DIR}> )
  ENDFOREACH()
  target_include_directories( ${ProjectName} PUBLIC
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                                $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include/${ProjectName}> )
ENDMACRO()

################################################################################
# Generate RC-File for MSVC Builds, output is a Version.h File in current dir
################################################################################
MACRO( CcTftpServerGenerateRcFileToCurrentDir ProjectName )
  SET(PROJECT_NAME "${ProjectName}")
  configure_file( ${CCTFTPSERVER_EXPORT_CMAKECONFIG_DIR}/InputFiles/CcTftpServerVersion.rc.in ${CMAKE_CURRENT_SOURCE_DIR}/CcTftpServerVersion.rc @ONLY)
ENDMACRO()

################################################################################
# Rename Endings of Project output file to CcTftpServer default.
# CURRENTLY NOT IN USE!!
################################################################################
MACRO( CcTftpServerProjectNaming ProjectName )
  set_target_properties(${ProjectName} PROPERTIES OUTPUT_NAME "${ProjectName}" )
  # Debug becomes and d at the end.
  set_target_properties(${ProjectName} PROPERTIES OUTPUT_NAME_DEBUG "${ProjectName}d" )
ENDMACRO()
