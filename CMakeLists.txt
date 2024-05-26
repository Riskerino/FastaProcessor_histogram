cmake_minimum_required(VERSION 3.10)
project(FastaProcessor)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(FastaProcessor
    src/main.cpp
    src/FastaFile.cpp
    src/Sequence.cpp
    src/FastaFormat.cpp
)
