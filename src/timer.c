

void initTimer(){
	int divisor = 11932;
	outb(0x43,0x36);
	outb(0x40,(uint_8)(divisor & 0xff));
	outb(0x40,(uint_8)((divisor >> 8) & 0xff));
	return;
}

void timerRecord(){
	charPrint(0,0,3);
	return;
}