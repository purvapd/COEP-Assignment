; Initialize 8251 in asynchronous mode
MOV AL, 0Bh        ; Set control word: 8 data bits, 1 stop bit, no parity
OUT 82h, AL        ; Send control word to 8251
MOV AL, 0C7h       ; Set baud rate: 9600 bps with 1.8432 MHz clock
OUT 81h, AL        ; Send baud rate divisor to 8251

; Send a byte of data to serial device
MOV AL, 'A'        ; Load data to be sent
OUT 80h, AL        ; Send data to 8251

; Receive a byte of data from serial device
IN AL, 80h         ; Read data from 8251
