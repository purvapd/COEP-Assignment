DATA SEGMENT
    STRING DB 'racecar', '$' ; declare string with terminating null character
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING  ; load SI with offset of string
    MOV CX, 0       ; clear CX register
LOOP1:
    MOV AL, [SI + CX]   ; load AL with byte from string at current offset
    CMP AL, 0           ; compare byte to null character
    JE CHECK_PALINDROME ; if equal, end of string reached
    INC CX              ; increment CX to point to next byte in string
    JMP LOOP1           ; continue loop
CHECK_PALINDROME:
    DEC CX          ; decrement CX to point to last byte in string
    XOR DI, DI      ; clear DI register
LOOP2:
    MOV AL, [SI + DI]   ; load AL with byte from string at current offset
    MOV BL, [SI + CX]   ; load BL with byte from string at opposite offset
    CMP AL, BL          ; compare bytes
    JNE NOT_PALINDROME   ; if not equal, string is not a palindrome
    CMP DI, CX          ; compare offsets
    JAE PALINDROME      ; if greater than or equal to CX, string is a palindrome
    INC DI              ; increment DI to point to next byte in string
    DEC CX              ; decrement CX to point to previous byte in string
    JMP LOOP2           ; continue loop
PALINDROME:
    ; string is a palindrome
    ; perform any necessary operations for palindrome
    JMP END_PROGRAM
NOT_PALINDROME:
    ; string is not a palindrome
    ; perform any necessary operations for not palindrome
END_PROGRAM:
CODE ENDS
END START
