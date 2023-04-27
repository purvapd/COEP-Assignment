section .text
    global _start

_start:
    ; set up the input values
    mov eax, 0x12345678
    mov ebx, 0x87654321
    
    ; multiply by rotation and addition
    mov ecx, eax
    mov edx, 0
    mov esi, ebx
    xor ebx, ebx
    
.loop:
    ; check if the current bit of ecx is set
    test ecx, 1
    jz .not_set
    
    ; add esi to edx
    add edx, esi
    
.not_set:
    ; shift esi left by 1 bit
    shl esi, 1
    
    ; shift ecx right by 1 bit
    shr ecx, 1
    
    ; check if we've processed all the bits of ecx
    jnz .loop
    
    ; output the result
    mov eax, edx
    mov ebx, 1
    int 0x80
