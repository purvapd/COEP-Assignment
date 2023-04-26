section .data
    numbers db 45, 78, 12, 90, 34, 56, 23, 89   ; List of integers
    len equ $ - numbers     ; Length of the list

section .text
    global _start
_start:
    mov al, [numbers]      ; Load the first number into AL
    mov ah, al             ; Initialize AH with the same value for comparison
    mov bl, [numbers]      ; Load the first number into BL
    mov bh, bl             ; Initialize BH with the same value for comparison
    lea si, numbers + 1    ; Load the address of the second number into SI

    ; Loop through the list to find the smallest and largest numbers
compare_loop:
    cmp al, [si]           ; Compare AL with the current number
    ja smaller             ; Jump if AL is greater (unsigned comparison)
    cmp ah, [si]           ; Compare AH with the current number
    jb larger              ; Jump if AH is smaller (unsigned comparison)

smaller:
    mov al, [si]           ; Update AL with the smaller number
    jmp continue           ; Continue to the next iteration

larger:
    mov ah, [si]           ; Update AH with the larger number

continue:
    cmp bl, [si]           ; Compare BL with the current number
    jb smaller2            ; Jump if BL is smaller (unsigned comparison)
    cmp bh, [si]           ; Compare BH with the current number
    ja larger2             ; Jump if BH is greater (unsigned comparison)

smaller2:
    mov bl, [si]           ; Update BL with the smaller number
    jmp continue2          ; Continue to the next iteration

larger2:
    mov bh, [si]           ; Update BH with the larger number

continue2:
    inc si                 ; Move to the next number in the list
    cmp si, numbers + len  ; Compare SI with the end of the list
    jb compare_loop        ; Jump if SI is less than the end of the list

    ; Print the smallest and largest numbers
    mov dl, al             ; Move the smallest number to DL for printing
    add dl, '0'            ; Convert the number to ASCII
    mov [result_smallest], dl ; Store the ASCII value in result_smallest
    mov dl, ah             ; Move the largest number to DL for printing
    add dl, '0'            ; Convert the number to ASCII
    mov [result_largest], dl  ; Store the ASCII value in result_largest

    ; Print the result
    mov ah, 02h            ; AH=02h for printing character
    mov dl, [result_smallest] ; Load the smallest number to DL for printing
    int 21h                ; Call DOS interrupt to print DL (smallest number)
    mov dl, [result_largest]  ; Load the largest number to DL for printing
    int 21h                ; Call DOS interrupt to print DL (largest number)

exit:
    mov ah, 4Ch            ; AH=4Ch for exit program
    xor al, al             ; Return 0 as exit code
    int 21h                ; Call DOS interrupt to exit the program

section .bss
    result_smallest resb 1 ;
