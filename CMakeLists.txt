cmake_minimum_required(VERSION 3.17)
project(emulator8080 C)

set(CMAKE_C_STANDARD 99)

include_directories(deps/sdl/include)

link_directories(deps/sdl/lib/x86)

#add_executable(dissasembler src/disassembler.c)
add_executable(emulator src/emulator.c src/cpu.c src/cpu.h src/definitions.h src/definitions.c src/display.h src/display.c src/machine.h src/machine.c)
target_link_libraries(emulator SDL2main SDL2)

add_custom_command(TARGET emulator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/deps/sdl/lib/x86/SDL2.dll"
        $<TARGET_FILE_DIR:emulator>)
