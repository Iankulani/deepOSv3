#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "keyboard.h"

void kmain() {
    vga_init();
    gdt_init();
    idt_init();
    timer_init(1000); // 1kHz timer
    keyboard_init();

    printf("CSOS Kernel Loaded\n");
    while (1) {
        asm("hlt"); // Halt CPU until interrupt
    }
}