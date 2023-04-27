DATA SEGMENT
    STRING1 DB 'Hello, ', '$'   ; declare first string with terminating null character
    STRING2 DB 'world!', '$'    ; declare second string with terminating null character
    RESULT DB 32 DUP ('$')     ; declare result buffer with 32 bytes
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING1 ; load SI with offset of first string
    LEA DI, RESULT  ; load DI with offset of result buffer
COPY1:
    MOV AL, [SI]    ; load AL with byte from first string
    MOV [DI], AL    ; store byte in result buffer
    INC SI          ; increment SI to
