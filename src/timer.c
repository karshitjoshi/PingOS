#pragma once
#include "outb_inb.c"

uint_64 ticks;

void initTimer(){
	int divisor = 11932;
	outb(0x43,0x36);
	outb(0x40,(uint_8)(divisor & 0xff));
	outb(0x40,(uint_8)((divisor >> 8) & 0xff));
	// Clear The Mask
	uint_16 port;
    uint_8 value;
    port = PIC1_DATA;
    value = inb(port) & ~(1);
    outb(port, value); 
	return;
}

