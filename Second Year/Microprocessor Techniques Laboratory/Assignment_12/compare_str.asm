DATA SEGMENT
    STRING1 DB 'Hello, world!', '$'   ; declare first string with terminating null character
    STRING2 DB 'HELLO, WORLD!', '$'   ; declare second string with terminating null character
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING1 ; load SI with offset of first string
    LEA DI, STRING2 ; load DI with offset of second string
LOOP1:
    MOV AL, [SI]    ; load AL with byte from first string
    MOV BL, [DI]    ; load BL with byte from second string
    CMP AL, BL      ; compare bytes
    JNE NOT_EQUAL   ; if not equal, strings are not equal
    CMP AL, 0       ; compare byte to null character
    JE EQUAL        ; if equal, end of strings reached and strings are equal
    INC SI          ; increment SI to point to next byte
    INC DI          ; increment DI to point to next byte
    JMP LOOP1       ; continue loop
EQUAL:
    ; strings are equal
    ; perform any necessary operations for equal strings
    JMP END_COMPARE
NOT_EQUAL:
    ; strings are not equal
    ; perform any necessary operations for unequal strings
END_COMPARE:
CODE ENDS
END START
