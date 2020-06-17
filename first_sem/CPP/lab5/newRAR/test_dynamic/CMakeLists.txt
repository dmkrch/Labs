cmake_minimum_required(VERSION 3.8)
project(My_Project LANGUAGES CXX)

#####################################
# CMake configuration 
####################################

option(CMAKE_INCLUDE_CURRENT_DIR   ON)
option(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

#Set warnings interpretate as errors
if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

include_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
