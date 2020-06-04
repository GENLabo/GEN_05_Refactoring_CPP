cmake_minimum_required(VERSION 3.14)
project(GEN_05_Refactoring_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GEN_05_Refactoring_CPP
        Customer.cpp
        Customer.h
        main.cpp
        Movie.cpp
        Movie.h
        Rental.h)
