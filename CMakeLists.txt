project(SIMPLE C CXX)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_INSTALL_PREFIX} /opt/software/local)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

# Find CLARA (the CMAKE_INSTALL_PREFIX should be the same used when compiling CLARA)
find_package(clara CONFIG REQUIRED)

# List the services implementation files, without extension
set(SERVICES
  SimpleEngine
)

# Create one shared library per service
foreach(service ${SERVICES})
  add_library(${service} SHARED ${service}.cxx)
  target_link_libraries(${service} Clara::clara)
endforeach()

# Install the services
install(TARGETS ${SERVICES} DESTINATION $ENV{CLARA_HOME}/plugins/clas12/services)

