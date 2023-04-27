ORG 0x100
    JMP START

; Interrupt Service Routine for Timer Interrupt
TIMER_ISR:
    ; Code for Timer Interrupt Service Routine
    IRET

START:
    ; Initialize the 8259
    MOV AL, 0x11         ; ICW1 - Edge Triggered Mode, Cascaded
    OUT 0x20, AL         ; Send Initialization Command to Master 8259
    JMP SHORT SKIP       ; Wait for a short time
    MOV AL, 0x11         ; ICW1 - Edge Triggered Mode, Cascaded
    OUT 0xA0, AL         ; Send Initialization Command to Slave 8259
SKIP:
    ; Set Interrupt Vector for Timer Interrupt to ISR
    MOV AX, SEG TIMER_ISR ; Segment of Timer ISR
    MOV DS, AX           ; Set DS to Timer ISR Segment
    MOV AX, OFFSET TIMER_ISR ; Offset of Timer ISR
    MOV WORD PTR [0x08], AX   ; Set IVT entry for IRQ 0 to Timer ISR

    ; Enable Timer Interrupt (IRQ 0) and Mask all other Interrupts
    MOV AL, 0x01         ; OCW1 - Enable IRQ 0
    OUT 0x21, AL         ; Send Mask to Master 8259
    MOV AL, 0xFF         ; OCW1 - Mask all IRQs
    OUT 0xA1, AL         ; Send Mask to Slave 8259

    ; Enable Interrupts
    STI

    ; Code for Main Program
    ; ...
    ; ...

    ; Disable Interrupts
    CLI

    ; End of Program
    HLT
