section .data
    number db 5  ; Change this value to the desired number for which factorial is to be calculated
    result dw 1  ; Initialize the result to 1

section .text
    global _start

_start:
    ; Load the number into a register
    mov al, [number]

    ; Loop to calculate the factorial
    loop_start:
        ; Multiply the result with the current number
        imul ax, [number]
        
        ; Decrement the number
        dec byte [number]
        
        ; Check if the number becomes zero
        cmp byte [number], 0
        jnz loop_start  ; If not zero, continue looping

    ; Store the factorial result in memory
    mov [result], ax

    ; Display the factorial result
    mov ax, [result]
    call print_word  ; Function to print a 16-bit word in hexadecimal or decimal format

exit:
    ; Exit the program
    mov eax, 1      ; Exit syscall
    xor ebx, ebx    ; Return code 0
    int 0x80        ; Call the kernel
