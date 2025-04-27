#include "graphics.h"

#define PURPLE_BG 0x5A007A
#define PURPLE_FG 0xAE00FF

void draw_window(int x, int y, int width, int height, const char* title) {
    // Draw window border
    draw_rect(x, y, width, height, PURPLE_BG);
    
    // Draw title bar
    draw_rect(x, y, width, 20, PURPLE_FG);
    draw_text(x + 5, y + 2, title, WHITE);
    
    // Draw close button
    draw_rect(x + width - 20, y, 20, 20, 0xFF0000);
    draw_text(x + width - 15, y + 2, "X", WHITE);
}