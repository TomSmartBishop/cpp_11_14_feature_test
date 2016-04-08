cmake_minimum_required (VERSION 2.6)
project(cpp_11_14_feature_test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) # For VS to organize the project in folders

set (CMAKE_CXX_FLAS "${CMAKE_CXX_FLAGS} /W4")

message ("cxx flags: " ${CMAKE_CXX_FLAGS})

file (GLOB SOURCES "src/*.cpp" "src/*.h")

source_group ("src" FILES ${SOURCES})


set (VERSION_NUMBER 0.1)

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/config.h.in" #The template to generate the actual header
  "${PROJECT_SOURCE_DIR}/src/generated/config.h"
)

add_executable(cpp_test ${SOURCES})

