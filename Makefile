SOURCE = main.c syscalls.c rprintf.c serial.c spi.c rtt.c pmc.c radio.c
ASSEMBLE = reset.S
LINKERSCRIPT = at91sam3sd8.ld
BINARY = main.bin
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc 
CFLAGS = -mthumb -march=armv7 -mfix-cortex-m3-ldrd -g

.PHONY:main all clean exec debug monitor
all : main.bin exec
main:main.bin

main.elf : $(LINKERSCRIPT) $(SOURCE) $(ASSEMBLE)
	$(CC) $(CFLAGS) -T $^ -o $@
main.bin : main.elf
	$(PREFIX)objcopy -O binary $< $@
exec : main.bin
	qemu-system-arm -M at91sam3sd8 -m 64 -cpu cortex-m3 --kernel $^ --serial stdio
debug : main.bin
	qemu-system-arm -M at91sam3sd8 -m 64 -cpu cortex-m3 -kernel $^ -serial stdio -gdb tcp::5022 -S
monitor : main.bin
	qemu-system-arm -M at91sam3sd8 -m 64 -cpu cortex-m3 -kernel $^ -serial telnet:localhost:5022,server -monitor stdio -s -S

clean:
	@rm -f *.o
	@rm -f *~
	@rm -f *#
	@rm -f *.bin
	@rm -f *.elf
