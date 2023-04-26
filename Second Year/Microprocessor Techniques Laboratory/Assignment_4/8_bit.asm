section .data
  num1 db 0x55       ; First operand
  num2 db 0x0A       ; Second operand

section .text
  global _start

_start:
  ; 8-bit Addition
  mov al, [num1]    ; Load first operand into AL
  add al, [num2]    ; Add second operand to AL
  ; Result is now in AL
  
  ; 8-bit Subtraction
  mov bl, 0x0F       ; Load a constant value into BL
  sub al, bl        ; Subtract BL from AL
  ; Result is now in AL
  
  ; 8-bit Multiplication
  mov bl, 0x02       ; Load a constant value into BL
  imul al, bl       ; Multiply AL by BL, result in AL
  ; Result is now in AL
  
  ; 8-bit Division
  mov bl, 0x04       ; Load a constant value into BL
  xor ah, ah        ; Clear AH
  div bl            ; Divide AL by BL, result in AL (quotient) and AH (remainder)
  ; Quotient is now in AL, remainder is in AH
  
  ; End of program
  ; You can now use the values in AL and AH as needed
