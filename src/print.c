#pragma once
#include "types.h"
#include "characterset.c"
#include "timer.c"
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

#define VERTICALWALLS 186
#define TOPRIGHT 187
#define BOTTOMRIGHT 188
#define BOTTOMLEFT 200
#define TOPLEFT 201
#define HORIZONTALWALLS 205
#define BALL 9
#define SLIDER 219
#define SLIDERLENGTH 4
#define SCOREDISPLAY 7

// Screen Left : 176x184

uint_8 ScreenArray[176][184];

int fore,back,bord,score,oldscore;

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

void clearScreenAnimation(){
	for(int i=0;i<40;i++){
		for(int j=0;j<25;j++){
			charPrint(i,j,32);
		}
	}
	back = BLACK;
	for(int i=0;i<40;i++){
		for(int j=0;j<25;j++){
			charPrint(i,j,32);
		}
	}
}

void putBorder(){
	fore = bord;
	score = 0;
	for(int i = 1;i < 39;i++){
		charPrint(i,1,HORIZONTALWALLS);
		charPrint(i,24,HORIZONTALWALLS);
	}
	for(int i = 2;i < 24;i++){
		charPrint(0,i,VERTICALWALLS);
		charPrint(39,i,VERTICALWALLS);
	}
	charPrint(0,1,TOPLEFT);
	charPrint(0,24,BOTTOMLEFT);
	charPrint(39,1,TOPRIGHT);
	charPrint(39,24,BOTTOMRIGHT);
	fore = WHITE;
	charPrint(1,0,83);
	charPrint(2,0,67);
	charPrint(3,0,79);
	charPrint(4,0,82);
	charPrint(5,0,69);
	charPrint(6,0,58);
}

// Screen Left : 176x184

int spritePrint(int x,int y,int ch,int xold,int yold,int k){
	if(ch == BALL){
		for(int i=0;i < 1;i++){
			for(int j=0;j < 8;j++){
				colorPixel(8+xold+j,16+yold+i,BLACK);
			}
		}
		for(int i=7;i < 8;i++){
			for(int j=0;j < 8;j++){
				colorPixel(8+xold+j,16+yold+i,BLACK);
			}
		}
		for(int i=0;i < 8;i++){
			for(int j=0;j < 1;j++){
				colorPixel(8+xold+j,16+yold+i,BLACK);
			}
		}
		for(int i=0;i < 8;i++){
			for(int j=7;j < 8;j++){
				colorPixel(8+xold+j,16+yold+i,BLACK);
			}
		}
		unsigned char proc;
		for(int i = 0;i < 8;i++){
			proc = font8x8[8*ch + i];
			for(int j = 0;j < 8;j++){
				if(proc % 2 == 1){
					colorPixel(8+x+(7-j),16+(y + i),PINK);
				} else {
					colorPixel(8+x+(7-j),16+(y + i),BLACK);
				}
				proc = proc >> 1;
			}
		}
	}
	if(ch == SLIDER){
		if(k == 0){
		for(int i=-1;i < 1;i++){
			for(int j=0;j < 8;j++){
				colorPixel(8+xold+j,16+yold+i,BLACK);
			}
		}
		}
		if(k == (SLIDERLENGTH-1)){
		for(int i=7;i < 9;i++){
			for(int j=0;j < 8;j++){
				colorPixel(8+xold+j,16+yold+i,BLACK);
			}
		}
		}
		unsigned char proc;
		for(int i = 0;i < 8;i++){
			proc = font8x8[8*ch + i];
			for(int j = 0;j < 8;j++){
				if(proc % 2 == 1){
					colorPixel(8+x+(7-j),16+(y + i),WHITE);
				} else {
					colorPixel(8+x+(7-j),16+(y + i),WHITE);
				}
				proc = proc >> 1;
			}
		}
	}
	return 0;
}

void printScore(){
	if(oldscore != score){
	int k = score;
	int loop = 0;
	int kap = 0;
	for(int i = 0;i<10;i++){
		if(score % 10^i == score){
			kap = i;
			break;
		}
	}
	while(k != 0){
		for(int i = 0;i<10;i++){
			charPrint(SCOREDISPLAY+loop+kap+2,0,48+k%10);
		}
		k = (k-(k%10))/10;
		loop--;
	}
	oldscore = score;
	}
	return;
}
