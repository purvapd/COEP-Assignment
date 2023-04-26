; Assembly program to sort a given list of integers in descending order using Bubble Sort algorithm

section .data
  arr db 5, 2, 8, 1, 6, 3 ; List of integers to be sorted
  n equ $ - arr ; Number of integers in the list

section .bss
  temp resb 1 ; Temporary storage for swapping values

section .text
  global _start

_start:
  mov ecx, n ; Move number of integers to ECX register
  dec ecx ; Decrement ECX by 1 for comparison loop

outer_loop:
  mov edi, 0 ; Initialize inner loop counter to 0
  mov ebx, arr ; Load address of the list to EBX register

inner_loop:
  mov al, [ebx] ; Load current value to AL register
  cmp al, [ebx+1] ; Compare current value with next value
  jl swap ; Jump to swap if current value is less than next value

  inc ebx ; Move to next element in the list
  inc edi ; Increment inner loop counter

  cmp edi, ecx ; Compare inner loop counter with outer loop counter
  jl inner_loop ; Continue inner loop if inner loop counter is less than outer loop counter

  dec ecx ; Decrement outer loop counter
  jnz outer_loop ; Continue outer loop if outer loop counter is not zero

exit:
  ; Display sorted list
  mov eax, 1 ; System call for write
  mov ebx, 1 ; File descriptor for stdout
  mov ecx, arr ; Load address of the sorted list
  mov edx, n ; Load number of bytes to write
  sub edx, 1 ; Subtract 1 from number of bytes to exclude extra comma
  add ecx, edx ; Move the pointer to the end of the sorted list
  mov byte [ecx], 0 ; Null-terminate the string
  add edx, 1 ; Add 1 to number of bytes for null terminator
  int 0x80 ; Call kernel

  ; Exit program
  mov eax, 1 ; System call for exit
  xor ebx, ebx ; Exit code 0
  int 0x80 ; Call kernel

swap:
  ; Swap values in the list
  mov ah, [ebx+1] ; Move next value to AH register
  mov [ebx+1], al ; Move current value to next position
  mov [ebx], ah ; Move next value to current position

  inc ebx ; Move to next element in the list
  inc edi ; Increment inner loop counter

  cmp edi, ecx ; Compare inner loop counter with outer loop counter
  jl inner_loop ; Continue inner loop if inner loop counter is less than outer loop counter

  dec ecx ; Decrement outer loop counter
  jnz outer_loop ; Continue outer loop if outer loop counter is not zero
