cmake_minimum_required (VERSION 2.6)
project (01-DataStructs)

SET(GCC_DEBUG_INFO_FLAGS "-ggdb")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUG_INFO_FLAGS}")

add_executable(student_example.exe student_example.cpp)
add_executable(studentex_consistency.exe studentex_consistency.cpp)
add_executable(sort_products.exe sort_products.cpp)
add_executable(dynamic_memory.exe dynamic_memory.cpp)