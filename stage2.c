#include <stdint.h>

#define MENU_ITEMS 5
const char* menu_items[MENU_ITEMS] = {
    "1. Live System",
    "2. Cyber Security Mode",
    "3. Binary Analysis",
    "4. Deep Terminal",
    "5. Biometric PenTest"
};

void print_menu() {
    clear_screen();
    printf("CSOS Boot Menu (Purple Theme)\n");
    for (int i = 0; i < MENU_ITEMS; i++) {
        printf("%s\n", menu_items[i]);
    }
}

void boot_selected(int option) {
    switch (option) {
        case 1: load_kernel("kernel.bin"); break;
        case 2: load_kernel("cybersec.bin"); break;
        // ... other options
    }
}