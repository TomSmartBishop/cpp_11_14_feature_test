cmake_minimum_required (VERSION 2.6)
project(cpp_11_14_feature_test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) # For VS to organize the project in folders

# We need C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
# But that seems to fail sometimes so we also add this flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O0 --coverage -fno-inline -fno-inline-small-functions -fno-default-inline") #MSVC will ignore these additional flags
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# Looks like clang needs dome extras to find the stdlib
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")

message ("cxx flags: " ${CMAKE_CXX_FLAGS})

file (GLOB SOURCES "src/*.cpp" "src/*.h")
file (GLOB TEST_SOURCES "src/tests/*.h")

source_group ("src" FILES ${SOURCES})
source_group ("src/tests" FILES ${TEST_SOURCES})

set (VERSION_NUMBER 0.1)

if (WIN32)
	set(PLATFORM _WIN32)
else()
    set(PLATFORM _LINUX)
endif()

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/config.h.in" #The template to generate the actual header
  "${PROJECT_SOURCE_DIR}/src/generated/config.h"
)

add_executable(cpp_test ${SOURCES} ${TEST_SOURCES})

