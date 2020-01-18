cmake_minimum_required(VERSION 3.10)
project(svm2csv)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
add_executable(svm2csv svm2csv.cpp convert.cpp )
