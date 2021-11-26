cmake_minimum_required(VERSION 3.21)
project(raytracer)

set(CMAKE_CXX_STANDARD 23)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src)
