
set ( CURRENT_PROJECT CcTftpServer )

########
# Add Source Files
########
file (GLOB SOURCE_FILES
      "src/*.c"
      "src/*.cpp"
      "*.h")
      

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
                     ${CMAKE_CURRENT_SOURCE_DIR}/../CcOS/CcNetwork/CcTftp )
                     
if(WINDOWS)
  CcTftpServerGenerateRcFileToCurrentDir(${CURRENT_PROJECT})
  list(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/CcTftpServerVersion.rc")
endif()

add_executable( ${CURRENT_PROJECT} ${SOURCE_FILES} )

# To keep Header an Source together, display them in same Directory
# It will only work with IDE's wich are supporting this features
SOURCE_GROUP( ""        FILES ${SOURCE_FILES})

target_link_libraries ( ${CURRENT_PROJECT} LINK_PUBLIC
                              CcTftp
                              CcKernel  )

                              

#################
# Post configuration steps
#################
CcTftpServerSetInstall( ${CURRENT_PROJECT} )
