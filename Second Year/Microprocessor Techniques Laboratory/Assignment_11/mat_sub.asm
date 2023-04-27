section .data
matrix1: dd 1, 2, 3, 4, 5, 6, 7, 8, 9   ; 3x3 matrix 1
matrix2: dd 9, 8, 7, 6, 5, 4, 3, 2, 1   ; 3x3 matrix 2
result: times 9 dd 0                  ; result matrix

section .text
global _start

_start:
    mov ecx, 0                       ; initialize loop counter
    mov edx, 0                       ; initialize result array index
loop_start:
    mov eax, [matrix1 + ecx * 4]     ; load value from matrix1
    sub eax, [matrix2 + ecx * 4]     ; subtract value from matrix2
    mov [result + edx * 4], eax      ; store result in result array
    inc ecx                          ; increment loop counter
    inc edx                          ; increment result array index
    cmp ecx, 9                       ; check if all elements processed
    jne loop_start                   ; if not, loop again

    ; result matrix is now in the "result" array
