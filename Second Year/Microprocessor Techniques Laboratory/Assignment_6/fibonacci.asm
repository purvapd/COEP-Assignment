section .data
    output db "Fibonacci series up to %d terms: ", 0
    format db "%d, ", 0
    newline db 0Ah, 0

section .bss
    n resb 4

section .text
    global _start

_start:
    ; Read input (n) from user
    mov eax, 3       ; system call number for reading input (read)
    mov ebx, 0       ; file descriptor 0 (stdin)
    mov ecx, n       ; buffer to store input
    mov edx, 4       ; buffer size (4 bytes for int)
    int 0x80         ; execute system call

    mov eax, [n]     ; move input (n) into eax

    ; Initialize variables for Fibonacci series
    mov ebx, 0       ; first term (F0)
    mov ecx, 1       ; second term (F1)
    mov esi, 2       ; current term index (starting from 2)

    ; Print header
    mov eax, 4       ; system call number for writing output (write)
    mov ebx, 1       ; file descriptor 1 (stdout)
    mov ecx, output  ; address of output string
    mov edx, 27      ; length of output string
    int 0x80         ; execute system call

    ; Print first two terms of Fibonacci series
    mov eax, 4       ; system call number for writing output (write)
    mov ebx, 1       ; file descriptor 1 (stdout)
    mov ecx, ebx     ; move F0 into ecx
    add ecx, 0x30    ; convert to ASCII
    mov edx, 2       ; length of format
    mov esi, format  ; address of format string
    int 0x80         ; execute system call

    ; Loop to calculate and print remaining terms of Fibonacci series
    cmp eax, 2       ; check if n >= 2
    jle exit         ; if not, exit

fibonacci_loop:
    mov edx, ecx     ; save second term in edx
    add ecx, ebx     ; calculate next term (F(i+1) = F(i) + F(i-1))
    mov ebx, edx     ; move second term (F(i)) to first term (F(i-1))
    mov eax, ecx     ; move current term (F(i+1)) to eax
    add eax, 0x30    ; convert to ASCII
    mov edx, 2       ; length of format
    mov esi, format  ; address of format string
    int 0x80         ; execute system call

    inc esi          ; move to next format character
    jmp fibonacci_loop ; jump back to loop

exit:
    ; Print newline character
    mov eax, 4       ; system call number for writing output (write)
    mov ebx, 1       ; file descriptor 1 (stdout)
    mov ecx, newline ; address of newline character
    mov edx, 2       ; length of newline character
    int 0x80         ; execute system call

    ; Exit program
    mov eax, 1       ; system call number for exit (exit)
    xor ebx, ebx     ; return 0 status code
    int 0x80         ; execute system call
