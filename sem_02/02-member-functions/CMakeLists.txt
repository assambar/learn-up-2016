cmake_minimum_required (VERSION 2.6)
project (01-DataStructs)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(student_print_method.exe student_print_method.cpp)
add_executable(numarray_ctor_dtor.exe numarray_ctor_dtor.cpp)
add_executable(overloading_in_out.exe overloading_in_out.cpp)
