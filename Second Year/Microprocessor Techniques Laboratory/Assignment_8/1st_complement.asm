section .data
    prompt db "Enter a 16-bit integer: ", 0
    output db "1's complement: ", 0
section .bss
    input resw 1
section .text
    global _start
_start:
    ; Display prompt and read input
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt
    mov edx, 23
    int 0x80
    mov eax, 3
    mov ebx, 0
    mov ecx, input
    mov edx, 2
    int 0x80
    
    ; Find 1's complement of the input
    mov bx, [input]
    not bx
    
    ; Display output
    mov eax, 4
    mov ebx, 1
    mov ecx, output
    mov edx, 16
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, bx
    mov edx, 2
    int 0x80
    
    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80
