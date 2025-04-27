#include "io.h"

void play_sound(uint32_t freq) {
    uint32_t div = 1193180 / freq;
    outb(0x43, 0xB6);
    outb(0x42, (uint8_t)div);
    outb(0x42, (uint8_t)(div >> 8));
    uint8_t tmp = inb(0x61);
    outb(0x61, tmp | 0x03);
}

void stop_sound() {
    uint8_t tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}