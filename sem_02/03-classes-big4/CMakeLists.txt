cmake_minimum_required (VERSION 2.6)
project (01-DataStructs)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(encapsulating_student.exe encapsulating_student.cpp)
add_executable(numarray_bigfour.exe numarray_bigfour.cpp)
