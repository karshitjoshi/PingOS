#include "print.c"
#include "idt.c"
#include "outb_inb.c"
#include "keyboard.c"

// Pixel Resolution 320x200
// Text Resolution 40x25
// Pixel Box Size 8x8

extern void StartIDT();

int _start()
{
    InitializeIDT();
    clearScreen();
    while(1);
}