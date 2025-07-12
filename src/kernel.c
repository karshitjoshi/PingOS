#include "print.c"
#include "idt.c"
#include "outb_inb.c"
#include "keyboard.c"
#include "timer.c"

// Pixel Resolution 320x200
// Text Resolution 40x25
// Pixel Box Size 8x8
// 1st line -> text , 2nd line -> border
// Screen Left : 176x184

extern void StartIDT();

int _start()
{
    InitializeIDT();
    fore = WHITE;
    back = PINK;
    bord = BLUE;
    clearScreenAnimation();
    putBorder();
    charPrint(8,0,BALL);
    gameLoop();
}