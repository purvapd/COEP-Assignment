DATA SEGMENT
    STRING DB 'Hello, world!', '$'   ; declare string with terminating null character
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING  ; load SI with offset of string
LOOP1:
    MOV AL, [SI]    ; load AL with byte from string
    CMP AL, 0       ; compare byte to null character
    JE END_CHANGE   ; if equal, end of string reached
    CMP AL, 'a'     ; compare byte to 'a'
    JB UPPER_CASE   ; if less than 'a', byte is already in uppercase
    CMP AL, 'z'     ; compare byte to 'z'
    JA UPPER_CASE   ; if greater than 'z', byte is already in uppercase
    SUB AL, 32      ; subtract 32 to convert lowercase to uppercase
    JMP STORE_CHAR  ; continue loop
UPPER_CASE:
    CMP AL, 'A'     ; compare byte to 'A'
    JB STORE_CHAR   ; if less than 'A', byte is already in lowercase
    CMP AL, 'Z'     ; compare byte to 'Z'
    JA STORE_CHAR   ; if greater than 'Z', byte is already in lowercase
    ADD AL, 32      ; add 32 to convert uppercase to lowercase
STORE_CHAR:
    MOV [SI], AL    ; store byte back to string
    INC SI          ; increment SI to point to next byte
    JMP LOOP1       ; continue loop
END_CHANGE:
    ; string case has been changed
CODE ENDS
END START
