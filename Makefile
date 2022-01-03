emulator: 
	mkdir -p build
	gcc -o build/emulator src/emulator.c src/cpu.c src/definitions.c src/display.c src/machine.c -lSDL2main -lSDL2 -I/usr/include/SDL2

disassembler: 
	mkdir -p build
	gcc -o build/disassembler src/disassembler.c -lSDL2main -lSDL2