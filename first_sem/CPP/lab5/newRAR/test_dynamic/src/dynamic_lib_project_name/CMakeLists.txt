cmake_minimum_required(VERSION 3.8)
project(dynamic_lib_project_name LANGUAGES CXX)

set(dir                            ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH         ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH            ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})

source_group(src FILES dynamic_lib.cpp dynamic_lib.h)
add_library(${PROJECT_NAME} SHARED dynamic_lib.cpp dynamic_lib.h)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${dir}/Debug")

