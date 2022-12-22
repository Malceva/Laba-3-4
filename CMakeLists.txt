cmake_minimum_required(VERSION 3.23)
project(Matrixx)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrixx main.cpp "Array .cpp" Array.h library.h library.cpp LinkedList.cpp Kramer.cpp Gauss.cpp)
