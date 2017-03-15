cmake_minimum_required (VERSION 2.6)
project (01-DataStructs)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(inheritance-and-overloading.exe inheritance-and-overloading.cpp)
add_executable(pure-virtual-methods.exe pure-virtual-methods.cpp)
add_executable(virtual-methods-and-overriding.exe virtual-methods-and-overriding.cpp)
