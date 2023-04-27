DATA SEGMENT
    SOURCE DB 'Hello, world!', '$'  ; declare source string with terminating null character
    DEST DB 20 DUP('$')             ; declare destination string with maximum length of 20 and terminating null character
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, SOURCE  ; load SI with offset of source string
    LEA DI, DEST    ; load DI with offset of destination string
    MOV CX, 20      ; set CX to maximum length of destination string
LOOP1:
    MOV AL, [SI]    ; load AL with byte from source string
    CMP AL, 0       ; compare byte to null character
    JE END_COPY     ; if equal, end of source string reached
    MOV [DI], AL    ; store byte to destination string
    INC SI          ; increment SI to point to next byte in source string
    INC DI          ; increment DI to point to next byte in destination string
    LOOP LOOP1      ; continue loop while CX is not zero
END_COPY:
    ; source string has been copied to destination string
CODE ENDS
END START
