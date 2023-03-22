
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Project name and enable C++ support
project(square_solver LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)
add_subdirectory(tests)
