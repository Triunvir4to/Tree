cmake_minimum_required(VERSION 3.28)
project(Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tree main.cpp
                LinkedList.h Stack.h Tree.h
                LinkedList.cpp Stack.cpp Tree.cpp)
