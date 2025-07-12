#pragma once
#include "characterset.c"
// Video Mode Memory : 0xb8000
// Odd is First , Even is after 8000 , CGA Video Memory placements.
// 320x200 is Pixel Resolution
#define WHITE 3
#define BLACK 0
#define PINK 2
#define BLUE 1

#define EVENSCREEN 0xb8000
#define ODDSCREEN (0xb8000 + 8192)
#define SCREENSIZE 8000
#define LINESIZE 80

int fore,back;

int colorPixel(int x,int y,int data){
	unsigned char *pixel;
	unsigned char *VIDMEM;
	if(y%2 == 1){
		VIDMEM = (char *)ODDSCREEN;
		y = (y-1)/2;

	} else {
		VIDMEM = (char *)EVENSCREEN;
		y = y/2;
	}
	int k = (x % 4);
	x = (x-k)/4;
	pixel = (VIDMEM + (80*y) + x);
	*pixel = (*pixel) & (~(3 << 2*(3-k)));
	*pixel = (data << (2*(3-k))) | *pixel;
	return 0;
}

int charPrint(int x,int y,int ch){
	unsigned char proc;
	fore = WHITE;
	back = PINK;
	for(int i = 0;i < 8;i++){
		proc = font8x8[8*ch + i];
		for(int j = 0;j < 8;j++){
			if(proc % 2 == 1){
				colorPixel((8*x)+(7-j),(y*8 + i),fore);
			} else {
				colorPixel((8*x)+(7-j),(y*8 + i),back);
			}
			proc = proc >> 1;
		}
	}
	return 0;
}

void clearScreen(){
	for(int i=0;i<40;i++){
		for(int j=0;j<25;j++){
			charPrint(i,j,32);
		}
	}
}