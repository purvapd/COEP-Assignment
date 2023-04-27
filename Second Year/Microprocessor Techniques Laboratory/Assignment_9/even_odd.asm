section .text
global _start

_start:
    mov ax, 7     ; replace 7 with the number you want to test
    test ax, 1    ; test the LSB of AX
    jz even       ; jump to the "even" label if the LSB is 0
    ; if we get here, the number is odd
    ; add code here to handle odd numbers
    jmp done      ; jump to the "done" label to exit the program

even:
    ; if we get here, the number is even
    ; add code here to handle even numbers

done:
    mov eax, 1    ; exit system call
    xor ebx, ebx  ; return code 0
    int 0x80      ; invoke the kernel to exit
