MOV DX, 0x00     ; set port A address
MOV AL, 0x80     ; set control word for mode 0 input
OUT DX, AL       ; write control word to 8255
MOV DX, 0x00     ; set port A address
IN AL, DX        ; read data from port A
MOV BX, 0x1000   ; set destination memory address
MOV [BX], AL     ; write data to memory

