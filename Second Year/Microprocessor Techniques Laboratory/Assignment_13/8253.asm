ORG 100h     ; set origin to 100h for COM file

MOV AL, 34h  ; load control word into AL
OUT 43h, AL  ; send control word to timer

MOV AX, 0B00h ; set initial count value
OUT 40h, AL  ; send LSB of count to timer
MOV AL, AH
OUT 40h, AL  ; send MSB of count to timer

DELAY_LOOP: ; loop to wait for timer to expire
  IN AL, 40h ; read status of timer
  AND AL, 1  ; check if timer has expired
  JZ DELAY_LOOP ; jump back to loop if not expired

RET ; return from program
