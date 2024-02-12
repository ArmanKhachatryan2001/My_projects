cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(visualCompiler)

add_executable(prog main.cpp visualCompiler.h visualCompiler.cpp)

target_precompile_headers(prog PRIVATE <iostream> <fstream> <sstream> <map>)
target_precompile_headers(prog PRIVATE visualCompiler.h)
#add_test(NAME ctest COMMAND prog text.txt)

