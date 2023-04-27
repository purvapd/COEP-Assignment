DATA SEGMENT
    STRING DB 'The quick brown fox jumps over the lazy dog.', '$' ; declare string with terminating null character
    SUBSTR DB 'DATA SEGMENT
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
', '$'          ; declare substring with terminating null character
DATA ENDS

CODE SEGMENT
START:
    MOV AX, @DATA   ; load data segment address
    MOV DS, AX      ; point DS to data segment
    LEA SI, STRING  ; load SI with offset of string
    LEA DI, SUBSTR  ; load DI with offset of substring
    XOR CX, CX      ; clear CX register
    XOR DX, DX      ; clear DX register
LOOP1:
    MOV AL, [SI]    ; load AL with byte from string
    CMP AL, 0       ; compare byte to null character
    JE END_SEARCH   ; if equal, end of string reached
    MOV BL, [DI]    ; load BL with byte from substring
    CMP AL, BL      ; compare bytes
    JNE SKIP_MATCH   ; if not equal, skip to next character in string
    MOV DX, CX      ; save offset of first matching character in DX
    INC CX          ; increment CX to point to next character in substring
    CMP BYTE PTR [DI + CX], 0 ; compare byte at DI+CX to null character
    JE MATCH_FOUND  ; if equal, end of substring reached and match found
    CMP BYTE PTR [SI + CX], 0 ; compare byte at SI+CX to null character
    JE END_SEARCH   ; if equal, end of string reached and no match found
    JMP LOOP1       ; continue loop
SKIP_MATCH:
    INC CX          ; increment CX to reset offset to 0
    MOV DX, 0       ; clear DX register to mark no match found
    JMP LOOP1       ; continue loop
MATCH_FOUND:
    ; DX now contains the offset of the first matching character
    ; perform any necessary operations for match found
END_SEARCH:
CODE ENDS
END START
