# Install script for directory: /home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/build/src/tracy/libTracyClient.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/tracy" TYPE FILE FILES
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyC.h"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/Tracy.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyD3D11.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyD3D12.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyLua.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyOpenCL.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyOpenGL.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/tracy/TracyVulkan.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/client" TYPE FILE FILES
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/tracy_concurrentqueue.h"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/tracy_rpmalloc.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/tracy_SPSCQueue.h"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyArmCpuTable.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyCallstack.h"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyCallstack.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyDebug.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyDxt1.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyFastVector.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyLock.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyProfiler.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyRingBuffer.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyScoped.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyStringHelpers.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracySysTime.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracySysTrace.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/client/TracyThread.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/common" TYPE FILE FILES
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/tracy_lz4.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/tracy_lz4hc.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyAlign.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyAlloc.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyApi.h"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyColor.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyForceInline.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyMutex.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyProtocol.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyQueue.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracySocket.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyStackFrames.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracySystem.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyUwp.hpp"
    "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/src/tracy/public/common/TracyYield.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Tracy/TracyConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Tracy/TracyConfig.cmake"
         "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/build/src/tracy/CMakeFiles/Export/7430802ac276f58e70c46cf34d169c6f/TracyConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Tracy/TracyConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Tracy/TracyConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Tracy" TYPE FILE FILES "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/build/src/tracy/CMakeFiles/Export/7430802ac276f58e70c46cf34d169c6f/TracyConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Tracy" TYPE FILE FILES "/home/raj/Documents/Projects/computervision/ConcurrentGaussianFilter/build/src/tracy/CMakeFiles/Export/7430802ac276f58e70c46cf34d169c6f/TracyConfig-release.cmake")
  endif()
endif()

