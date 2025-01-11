cmake_minimum_required(VERSION 3.14)

project(yhok_cluster VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(lib_yhok_cluster INTERFACE)

target_include_directories(lib_yhok_cluster INTERFACE 
    include
)

# For examples

include(FetchContent)

FetchContent_Declare(matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG origin/master
)

FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Example: K-means on 2D blobs

add_executable(example_kmeans_blobs_2d
    example/example_kmeans_blobs_2d.cpp
    example/helpers/src/point_2d.cpp
    example/helpers/src/blobs_2d.cpp
)
target_include_directories(example_kmeans_blobs_2d PRIVATE
    example/helpers/include
)

target_link_libraries(example_kmeans_blobs_2d
    PRIVATE
    lib_yhok_cluster
    PUBLIC
    matplot
)

# Example: K-means++ on 2D blobs

add_executable(example_kmeans_plus_plus_blobs_2d
    example/example_kmeans_plus_plus_blobs_2d.cpp
    example/helpers/src/point_2d.cpp
    example/helpers/src/blobs_2d.cpp
)

target_include_directories(example_kmeans_plus_plus_blobs_2d PRIVATE
    example/helpers/include
)

target_link_libraries(example_kmeans_plus_plus_blobs_2d
    PRIVATE
    lib_yhok_cluster
)

# Example: Elbow method on 2D blobs

add_executable(example_kmeans_elbow_blobs_2d
    example/example_kmeans_elbow_blobs_2d.cpp
    example/helpers/src/point_2d.cpp
    example/helpers/src/blobs_2d.cpp
)

target_include_directories(example_kmeans_elbow_blobs_2d PRIVATE
    example/helpers/include
)

target_link_libraries(example_kmeans_elbow_blobs_2d
    PRIVATE
    lib_yhok_cluster
    PUBLIC
    matplot
)
