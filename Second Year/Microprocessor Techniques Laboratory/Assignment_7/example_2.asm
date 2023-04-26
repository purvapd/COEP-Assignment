section .data
a dw 2  ; a = 2 (word size)
b dw 3  ; b = 3 (word size)
c dw 4  ; c = 4 (word size)
d dw 5  ; d = 5 (word size)
result dw 0  ; variable to store the result (word size)

section .text
global _start
_start:
  ; Load a, b, c, d into registers
  mov ax, [a]
  mov bx, [b]
  mov cx, [c]
  mov dx, [d]

  ; Perform (a * b) and store the result in ax
  imul ax, bx

  ; Perform (c * d) and store the result in cx
  imul cx, dx

  ; Add (a * b) + (c * d) and store the result in ax
  add ax, cx

  ; Store the result in the result variable
  mov [result], ax

  ; Exit the program
  mov eax, 1
  xor ebx, ebx
  int 0x80
