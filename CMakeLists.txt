cmake_minimum_required(VERSION 3.5)

project(module28homework)

set(SRC_LIST 
          main.cpp)
 
 include_directories(mergesort)         
 include_directories(file) 

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CXX_FLAGS "${CXX_FLAGS} -std=c++17 -Wall")