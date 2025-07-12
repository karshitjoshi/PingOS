#pragma once
#include "scancodes.h"
#include "types.h"
#include "print.c"

int ShiftHolded = 0;
int CapOn = 0;
int X = 0;
int Y = 0;

void CheckAndPrintScanCodes(int ScanCode) {
	switch(ScanCode){
		case KEY_PRESSED_1:
			if(ShiftHolded == 1){
				charPrint(X,Y,33);
				return;
			}
			charPrint(X,Y,49);
			return;
			break;
		case KEY_PRESSED_2:
			if(ShiftHolded == 1){
				charPrint(X,Y,64);
				return;
			}
			charPrint(X,Y,50);
			return;
			break;
		case KEY_PRESSED_3:
			if(ShiftHolded == 1){
				charPrint(X,Y,35);
				return;
			}
			charPrint(X,Y,51);
			return;
			break;
		case KEY_PRESSED_4:
			if(ShiftHolded == 1){
				charPrint(X,Y,36);
				return;
			}
			charPrint(X,Y,52);
			return;
			break;
		case KEY_PRESSED_5:
			if(ShiftHolded == 1){
				charPrint(X,Y,37);
				return;
			}
			charPrint(X,Y,53);
			return;
			break;
		case KEY_PRESSED_6:
			if(ShiftHolded == 1){
				charPrint(X,Y,94);
				return;
			}
			charPrint(X,Y,54);
			return;
			break;
		case KEY_PRESSED_7:
			if(ShiftHolded == 1){
				charPrint(X,Y,38);
				return;
			}
			charPrint(X,Y,55);
			return;
			break;
		case KEY_PRESSED_8:
			if(ShiftHolded == 1){
				charPrint(X,Y,42);
				return;
			}
			charPrint(X,Y,56);
			return;
			break;
		case KEY_PRESSED_9:
			if(ShiftHolded == 1){
				charPrint(X,Y,40);
				return;
			}
			charPrint(X,Y,57);
			return;
			break;
		case KEY_PRESSED_0:
			if(ShiftHolded == 1){
				charPrint(X,Y,41);
				return;
			}
			charPrint(X,Y,48);
			return;
			break;
		case KEY_PRESSED_MINUS:
			if(ShiftHolded == 1){
				charPrint(X,Y,95);
				return;
			}
			charPrint(X,Y,173);
			return;
			break;
		case KEY_PRESSED_EQUALS:
			if(ShiftHolded == 1){
				charPrint(X,Y,43);
				return;
			}
			charPrint(X,Y,61);
			return;
			break;
		case KEY_PRESSED_BACKSPACE:
			charPrint(X-1,Y,32);
			X = X - 2;
			return;
			break;
		case KEY_PRESSED_Q:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,81);
				return;
			}
			charPrint(X,Y,113);
			return;
			break;
		case KEY_PRESSED_W:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,87);
				return;
			}
			charPrint(X,Y,119);
			return;
			break;
		case KEY_PRESSED_E:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,69);
				return;
			}
			charPrint(X,Y,101);
			return;
			break;
		case KEY_PRESSED_R:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,82);
				return;
			}
			charPrint(X,Y,114);
			return;
			break;
		case KEY_PRESSED_T:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,84);
				return;
			}
			charPrint(X,Y,116);
			return;
			break;
		case KEY_PRESSED_Y:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,89);
				return;
			}
			charPrint(X,Y,121);
			return;
			break;
		case KEY_PRESSED_U:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,85);
				return;
			}
			charPrint(X,Y,117);
			return;
			break;
		case KEY_PRESSED_I:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,73);
				return;
			}
			charPrint(X,Y,105);
			return;
			break;
		case KEY_PRESSED_O:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,79);
				return;
			}
			charPrint(X,Y,111);
			return;
			break;
		case KEY_PRESSED_P:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,80);
				return;
			}
			charPrint(X,Y,112);
			return;
			break;
		case KEY_PRESSED_OPEN_SQUARE_BRACKET:
			if(ShiftHolded == 1){
				charPrint(X,Y,123);
				return;
			}
			charPrint(X,Y,91);
			return;
			break;
		case KEY_PRESSED_CLOSE_SQUARE_BRACKET:
			if(ShiftHolded == 1){
				charPrint(X,Y,125);
				return;
			}
			charPrint(X,Y,93);
			return;
			break;
		case KEY_PRESSED_A:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,65);
				return;
			}
			charPrint(X,Y,97);
			return;
			break;
		case KEY_PRESSED_S:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,83);
				return;
			}
			charPrint(X,Y,115);
			return;
			break;
		case KEY_PRESSED_D:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,68);
				return;
			}
			charPrint(X,Y,100);
			return;
			break;
		case KEY_PRESSED_F:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,70);
				return;
			}
			charPrint(X,Y,102);
			return;
			break;
		case KEY_PRESSED_G:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,71);
				return;
			}
			charPrint(X,Y,103);
			return;
			break;
		case KEY_PRESSED_H:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,72);
				return;
			}
			charPrint(X,Y,104);
			return;
			break;
		case KEY_PRESSED_J:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,74);
				return;
			}
			charPrint(X,Y,106);
			return;
			break;
		case KEY_PRESSED_K:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,75);
				return;
			}
			charPrint(X,Y,107);
			return;
			break;
		case KEY_PRESSED_L:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,76);
				return;
			}
			charPrint(X,Y,108);
			return;
			break;
		case KEY_PRESSED_SEMICOLON:
			if(ShiftHolded == 1){
				charPrint(X,Y,58);
				return;
			}
			charPrint(X,Y,59);
			return;
			break;
		case KEY_PRESSED_SINGLE_QUOTE:
			charPrint(X,Y,39);
			return;
			break;
		case KEY_PRESSED_TILDE:
			if(ShiftHolded == 1){
				charPrint(X,Y,126);
				return;
			}
			charPrint(X,Y,96);
			return;
			break;
		case KEY_PRESSED_BACK_SLASH:
			if(ShiftHolded == 1){
				charPrint(X,Y,124);
				return;
			}
			charPrint(X,Y,92);
			return;
			break;
		case KEY_PRESSED_Z:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,90);
				return;
			}
			charPrint(X,Y,122);
			return;
			break;
		case KEY_PRESSED_X:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,88);
				return;
			}
			charPrint(X,Y,120);
			return;
			break;
		case KEY_PRESSED_C:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,67);
				return;
			}
			charPrint(X,Y,99);
			return;
			break;
		case KEY_PRESSED_V:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,86);
				return;
			}
			charPrint(X,Y,118);
			return;
			break;
		case KEY_PRESSED_B:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,66);
				return;
			}
			charPrint(X,Y,98);
			return;
			break;
		case KEY_PRESSED_N:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,78);
				return;
			}
			charPrint(X,Y,110);
			return;
			break;
		case KEY_PRESSED_M:
			if(CapOn == 1 | ShiftHolded == 1){
				charPrint(X,Y,77);
				return;
			}
			charPrint(X,Y,109);
			return;
			break;
		case KEY_PRESSED_COMMA:
			if(ShiftHolded == 1){
				charPrint(X,Y,60);
				return;
			}
			charPrint(X,Y,44);
			return;
			break;
		case KEY_PRESSED_PERIOD:
			if(ShiftHolded == 1){
				charPrint(X,Y,62);
				return;
			}
			charPrint(X,Y,46);
			return;
			break;
		case KEY_PRESSED_FORWARD_SLASH:
			if(ShiftHolded == 1){
				charPrint(X,Y,63);
				return;
			}
			charPrint(X,Y,47);
			return;
			break;
		case KEY_PRESSED_CAPS_LOCK:
			if(CapOn == 1){
				CapOn = 0;
				return;
			}
			CapOn = 1;
			return;
			break;
		case KEY_PRESSED_LEFT_SHIFT:
			ShiftHolded = 1;
			return;
			break;
		case KEY_RELEASED_LEFT_SHIFT:
			ShiftHolded = 0;
			return;
			break;
		case KEY_PRESSED_RIGHT_SHIFT:
			ShiftHolded = 1;
			return;
			break;
		case KEY_RELEASED_RIGHT_SHIFT:
			ShiftHolded = 0;
			return;
			break;
		case KEY_RELEASED_ENTER:
			Y = Y + 1;
			X = 0;
		case KEY_PRESSED_SPACE:
			charPrint(X,Y,32);
			return;
			break;
	}
	X++;
}

void keyboard_isr() {
	int keyPressed = inb(0x60);
	CheckAndPrintScanCodes(keyPressed);
	outb(PIC2_COMMAND,PIC_EOI);
	outb(PIC1_COMMAND,PIC_EOI);
	return;
}