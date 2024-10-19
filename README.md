# Shellcodes
Assemble shellcodes by running:
```bash
make TARGET=<assembly_source>
```
The target is assumed to be `shellcode.s` by default.
The assembly will produce files named `shellcode-elf` and `shellcode-raw`, which are the shellcode ELF and shellcode bytes, respectively.
Clean by running:
```bash
make clean TARGET=<assembly_source>
```
Test the shellcode by running:
```bash
cat <raw_shellcode> | shellcode_loader
```
