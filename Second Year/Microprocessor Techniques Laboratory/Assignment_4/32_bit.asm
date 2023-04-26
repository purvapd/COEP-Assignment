section .data
  num1 dd 0x12345678  ; First operand (32-bit)
  num2 dd 0x87654321  ; Second operand (32-bit)

section .text
  global _start

_start:
  ; 32-bit Addition
  mov eax, [num1]    ; Load first operand into EAX
  add eax, [num2]    ; Add second operand to EAX
  ; Result is now in EAX

  ; 32-bit Subtraction
  mov eax, [num1]    ; Load first operand into EAX
  sub eax, [num2]    ; Subtract second operand from EAX
  ; Result is now in EAX

  ; 32-bit Multiplication
  mov eax, [num1]    ; Load first operand into EAX
  imul eax, [num2]   ; Multiply EAX by second operand, signed result in EAX
  ; Result is now in EAX

  ; 32-bit Division
  mov eax, [num1]    ; Load dividend into EAX
  cdq                ; Sign-extend EAX into EDX:EAX for signed division
  idiv dword [num2]  ; Divide EDX:EAX by second operand, signed quotient in EAX, remainder in EDX
  ; Quotient is now in EAX, remainder is in EDX
