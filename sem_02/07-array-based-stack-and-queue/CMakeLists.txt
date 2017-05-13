cmake_minimum_required (VERSION 2.6)
project (07-array-based-stack-and-queue)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/_build)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(int_stack_non_optimal.exe int_stack_non_optimal.cpp)
add_executable(int_queue_non_optimal.exe int_queue_non_optimal.cpp)
add_executable(template_stack_non_optimal.exe template_stack_non_optimal.cpp)
add_executable(template_queue_non_optimal.exe template_queue_non_optimal.cpp)

