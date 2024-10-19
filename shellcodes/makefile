TARGET ?= shellcode
ASM_SRC = $(TARGET).s
ELF_BIN = $(TARGET)-elf
RAW_BIN = $(TARGET)-raw

CFLAGS = -nostdlib -static

.PHONY: all clean

all: $(RAW_BIN)

$(ELF_BIN): $(ASM_SRC)
	gcc $(CFLAGS) $< -o $@

$(RAW_BIN): $(ELF_BIN)
	objcopy --dump-section .text=$@ $<

clean:
	rm -f $(ELF_BIN) $(RAW_BIN)

