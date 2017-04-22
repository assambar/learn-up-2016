cmake_minimum_required (VERSION 2.6)
project (01-DataStructs)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(oop_sample_Customer.exe oop_sample_Customer.cpp)
add_executable(oop_sample_NumberGenerator.exe oop_sample_NumberGenerator.cpp)
