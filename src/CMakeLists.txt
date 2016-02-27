cmake_minimum_required(VERSION 2.8)
project(Cars CXX)
add_executable(cars main.cpp Vector.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# OpenMP
set (ENABLE_OMP On CACHE BOOL "Enable OpenMP")

if(ENABLE_OMP)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp ")
endif()