[org 0x7C00]
[bits 16]

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    ; Load Stage 2 (0x7E00)
    mov bx, 0x7E00
    mov ah, 0x02
    mov al, 4       ; Sectors to read
    mov ch, 0       ; Cylinder
    mov dh, 0       ; Head
    mov cl, 2       ; Sector
    int 0x13

    jmp 0x0000:0x7E00

times 510-($-$$) db 0
dw 0xAA55