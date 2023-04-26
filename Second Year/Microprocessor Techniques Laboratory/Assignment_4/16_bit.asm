section .data
  num1 dw 0x1234     ; First operand (16-bit)
  num2 dw 0x5678     ; Second operand (16-bit)

section .text
  global _start

_start:
  ; 16-bit Addition
  mov ax, [num1]     ; Load first operand into AX
  add ax, [num2]     ; Add second operand to AX
  ; Result is now in AX
  
  ; 16-bit Subtraction
  mov ax, [num1]     ; Load first operand into AX
  sub ax, [num2]     ; Subtract second operand from AX
  ; Result is now in AX
  
  ; 16-bit Multiplication
  mov ax, [num1]     ; Load first operand into AX
  imul ax, [num2]    ; Multiply AX and second operand, result in AX
  ; Result is now in AX
  
  ; 16-bit Division
  mov ax, [num1]     ; Load dividend into AX
  cwd                ; Sign-extend AX to DX:AX for signed division
  idiv word [num2]   ; Divide DX:AX by second operand, quotient in AX, remainder in DX
  ; Quotient is now in AX, remainder is in DX
