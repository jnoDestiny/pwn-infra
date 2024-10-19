.global _start

_start:
.intel_syntax noprefix
    
    lea rdi, [rip+flag_path]
    mov rsi, 0 # O_RDONLY
    mov rax, 2 # open
    syscall

    cmp rax, 0
    js Exit

    mov rdi, 1 # stdout
    mov rsi, rax # flag fd
    mov rdx, 0
    mov r10, 1000
    mov rax, 40 # sendfile
    syscall

Exit:
    mov rdi, 0
    mov rax, 60 # exit
    syscall

flag_path:
    .string "./flag"

