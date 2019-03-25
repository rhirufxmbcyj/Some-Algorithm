cmake_minimum_required(VERSION 2.8)
project(BinarySearch)
file(GLOB SRC_FILES "*.c")
file(GLOB HEAD_FILES "*.h")
add_compile_options(-g)
add_executable(BinarySearc ${SRC_FILES} ${HEAD_FILES})

