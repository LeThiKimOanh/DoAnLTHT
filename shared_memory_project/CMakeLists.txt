# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(DACK)

set(CMAKE_C_STANDARD 11)
include_directories(include)

add_executable(writer src/writer.c)
add_executable(reader src/reader.c)
add_executable(editor src/editor.c)
add_executable(cleaner src/cleaner.c)
