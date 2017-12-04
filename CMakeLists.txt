# @Author Andreas Dirmeier
# @brief Main CMakeList.txt for CcTftpServer
#############
cmake_minimum_required (VERSION 3.0)

################################################################################
# Setup Globals
################################################################################
include( ${CMAKE_CURRENT_SOURCE_DIR}/VERSION.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/CMakeConfig/CcMacros.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/CMakeConfig/ProjectMacros.cmake )

if(WINDOWS)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/CcTftpServer")
endif()

################################################################################
# Configuration is done, setup Project
################################################################################
project("CcTftpServer" VERSION "${CCTFTPSERVER_VERSION_CMAKE}")

################################################################################
# Setup Debug
################################################################################
if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
  message("Build-Type set to ${CMAKE_BUILD_TYPE}")
  set(CCTFTPSERVER_BUILD_TYPE "DEBUG" )
  set(CMAKE_VERBOSE_MAKEFILE          ON)
else()
  message("Build-Type set to release")
  set(CCTFTPSERVER_BUILD_TYPE "RELEASE" )
endif()

################################################################################
# Setup Output Paths
################################################################################
# To be able to overwrite global output root use -DCCTFTPSERVER_OUTPUT_DIR=/path on configuration
if(NOT CCTFTPSERVER_OUTPUT_DIR)
  set(CCTFTPSERVER_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Output")
endif()

# Set runtime output dir to root/output if no other location was defined
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CCTFTPSERVER_OUTPUT_DIR}/bin")
endif()

# Set library output dir to root/output if no other location was defined
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CCTFTPSERVER_OUTPUT_DIR}/lib")
endif()

# Set archive output dir to root/output if no other location was defined
if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CCTFTPSERVER_OUTPUT_DIR}/lib/static")
endif()

CcNoConfigurationDirs()
enable_testing()
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Import CcOS
################################################################################
include(CcOSImport.cmake)

ADD_SUBDIRECTORY(CcTftpServer)

################################################################################
# Update dokumentation
################################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Documents/Doxygen)


set(CPACK_PACKAGE_DESCRIPTION         ${CMAKE_PROJECT})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CcTftpServer Project")
set(CPACK_PACKAGE_VENDOR              "Andreas Dirmeier")
set(CPACK_PACKAGE_CONTACT             "coolcow_ccos@yahoo.com")
set(CPACK_PACKAGE_INSTALL_DIRECTORY   ${CMAKE_INSTALL_PREFIX})
set(CPACK_RESOURCE_FILE_LICENSE       ${CMAKE_CURRENT_SOURCE_DIR}/Documents/COPYING.LESSER.rtf)

if(LINUX)
  set(CPACK_GENERATOR "DEB")
  set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_VENDOR})
  
  INCLUDE(CPack)
elseif(WINDOWS)
  CcLoadWixTools()
  
  set(CPACK_GENERATOR "WIX")
  set(CPACK_WIX_UPGRADE_GUID "552E2605-4939-4FD9-842C-324CFDB6CCF0")
  INCLUDE(CPack)
endif()