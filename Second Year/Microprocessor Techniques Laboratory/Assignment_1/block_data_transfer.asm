section .data
buffer1 db 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ; Source buffer
buffer2 db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ; Destination buffer

section .text
global _start

_start:
    ; Block data transfer with overlapping blocks
    mov si, buffer1   ; Source index points to the beginning of buffer1
    mov di, buffer1+1 ; Destination index points to the second byte of buffer1
    mov cx, 8         ; Number of bytes to transfer
    cld               ; Clear direction flag for forward movement

    rep movsb         ; Perform block data transfer

    ; Block data transfer with non-overlapping blocks
    mov si, buffer1+2 ; Source index points to the third byte of buffer1
    mov di, buffer2   ; Destination index points to buffer2
    mov cx, 6         ; Number of bytes to transfer
    cld               ; Clear direction flag for forward movement

    rep movsb         ; Perform block data transfer

    ; End of program
    mov eax, 1        ; System call number for exit
    xor ebx, ebx      ; Return 0 status
    int 0x80          ; Invoke the kernel

