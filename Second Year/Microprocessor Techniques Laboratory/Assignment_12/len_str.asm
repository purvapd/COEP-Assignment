DATA SEGMENT
    STRING DB 'Hello, world!', '$' ; declare string with terminating null character
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING  ; load SI with offset of string
    XOR CX, CX      ; clear CX register
LOOP1:
    CMP BYTE PTR [SI], 0 ; compare byte at SI to null character
    JE DONE         ; if equal, end of string reached
    INC SI          ; increment SI to point to next byte
    INC CX          ; increment CX to count string length
    JMP LOOP1       ; continue loop
DONE:
    ; CX now contains the length of the string
    ; perform any necessary operations with the string length
CODE ENDS
END START
