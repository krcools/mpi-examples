cmake_minimum_required(VERSION 2.8)
project(mpi-examples CXX)

find_package(MPI REQUIRED)
include_directories(${MPI_CXX_INCLUDE_PATH})

add_subdirectory(src)
