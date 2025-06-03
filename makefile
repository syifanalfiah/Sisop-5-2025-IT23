prepare:
	mkdir -p bin
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880

bootloader:
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin
	dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc

stdlib:
	bcc -ansi -Iinclude -c src/std_lib.c -o bin/std_lib.o

shell:
	bcc -ansi -Iinclude -c src/shell.c -o bin/shell.o

kernel:
	nasm -f as86 src/kernel.asm -o bin/kernel_asm.o
	bcc -ansi -Iinclude -c src/kernel.c -o bin/kernel.o
	ld86 -o bin/kernel.bin -d bin/kernel.o bin/kernel_asm.o bin/std_lib.o bin/shell.o
	dd if=bin/kernel.bin of=bin/floppy.img bs=512 seek=1 conv=notrunc

link:
	@echo "Linking done via dd in kernel step, no additional link step required."

build: prepare bootloader stdlib shell kernel link

clean:
	rm -f bin/*.o bin/*.bin bin/*.img bin/kernel.bin
