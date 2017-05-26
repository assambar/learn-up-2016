cmake_minimum_required (VERSION 2.6)
project (08-list-based-stack-and-queue)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/_build)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(int_stack_list_based.exe int_stack_list_based.cpp)
add_executable(int_queue_list_based.exe int_queue_list_based.cpp)
