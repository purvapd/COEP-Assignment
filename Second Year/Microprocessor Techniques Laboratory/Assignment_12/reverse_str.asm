DATA SEGMENT
    STRING DB 'Hello, world!', '$' ; declare string with terminating null character
    LENGTH DW 0                    ; declare variable to hold string length
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING  ; load SI with offset of string
    XOR CX, CX      ; clear CX register
LOOP1:
    CMP BYTE PTR [SI], 0 ; compare byte at SI to null character
    JE SET_LENGTH   ; if equal, end of string reached
    INC SI          ; increment SI to point to next byte
    INC CX          ; increment CX to count string length
    JMP LOOP1       ; continue loop
SET_LENGTH:
    MOV LENGTH, CX  ; store string length in variable
    MOV DI, SI      ; load DI with offset of last character in string
    DEC DI          ; decrement DI to point to second-to-last character
    MOV CX, LENGTH  ; reload CX with string length
    SHR CX, 1       ; divide length by 2 (rounded down) to get loop count
LOOP2:
    MOV AL, [SI]    ; load AL with byte from SI
    MOV BL, [DI]    ; load BL with byte from DI
    MOV [DI], AL    ; store byte from SI in DI
    MOV [SI], BL    ; store byte from DI in SI
    INC SI          ; increment SI to point to next character
    DEC DI          ; decrement DI to point to previous character
    LOOP LOOP2      ; continue loop
    ; string is now reversed
CODE ENDS
END START
