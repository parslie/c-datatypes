cmake_minimum_required(VERSION 3.10)

project(Datatypes C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Datatypes src/main.c src/linkedlist.c src/hashmap.c)