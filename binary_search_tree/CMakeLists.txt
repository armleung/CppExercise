cmake_minimum_required(VERSION 3.5)
project(binary_search_tree)

# Setup C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(. DIR_SRCS)
add_executable(output ${DIR_SRCS})