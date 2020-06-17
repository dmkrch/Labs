cmake_minimum_required(VERSION 3.8)
project(main_project_name LANGUAGES CXX) 


source_group(src main.cpp)
add_executable(${PROJECT_NAME} main.cpp)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} debug dynamic_lib_project_name)
target_link_libraries(${PROJECT_NAME} optimized dynamic_lib_project_name)