cmake_minimum_required(VERSION 3.10)
project(RecordReader)

set(CMAKE_CXX_STANDARD 11)

link_directories(C:/xerces-c-3.1.4/Build/Win32/VC12/Debug)

include_directories(C:/xerces-c-3.1.4/src)
#find_library("C:/xerces-c-3.1.4/Build/Win32/VC12/Debug")

add_executable(RecordReader main.cpp RecordSchema.cpp RecordSchema.h)


#find_package(xerces-c)

target_link_libraries(RecordReader xerces-c_3D)
