cmake_minimum_required(VERSION 3.13)
project(svm2csv)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
add_executable(svm2csv libsvm2csv.cpp)
