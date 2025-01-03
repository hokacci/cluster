cmake_minimum_required(VERSION 3.14)

project(yhok_cluster VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(lib_yhok_cluster INTERFACE)

target_include_directories(lib_yhok_cluster INTERFACE 
    include
)

# Example executables
add_executable(example_kmeans_blobs_2d
    example/example_kmeans_blobs_2d.cpp
    example/helpers/src/point_2d.cpp
    example/helpers/src/blobs_2d.cpp
)
target_include_directories(example_kmeans_blobs_2d PRIVATE
    example/helpers/include
)

target_link_libraries(example_kmeans_blobs_2d PRIVATE
    lib_yhok_cluster
)