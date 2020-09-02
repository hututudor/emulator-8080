cmake_minimum_required(VERSION 3.17)
project(emulator8080 C)

set(CMAKE_C_STANDARD 99)

#add_executable(dissasembler src/disassembler.c)
add_executable(emulator src/emulator.c)