cmake_minimum_required (VERSION 3.0)
project (advancedcpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory ("smartpointers/")
add_subdirectory ("movesemantics/")
add_subdirectory ("deletedfunc/")
add_subdirectory ("enumclases")