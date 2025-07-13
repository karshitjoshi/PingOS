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

int gameover;

extern void StartIDT();

int limiter;
int ballx,bally,slider1y,slider2y;
int brevy,brevx,init,srev1,srev2,osrev1,osrev2;

void gameLoop(){
    if(gameover != 1){
    // BALL ANIMATION
    if((bally+8) != 176 && (bally) != 0){
        spritePrint(ballx,bally+brevy,BALL,ballx,bally,0);
        bally = bally + brevy;
    } else {
        brevy *= -1;
        bally = bally + brevy;
    }
    if((ballx+8) != (320-16) && (ballx) != 0){
        spritePrint(ballx+brevx,bally,BALL,ballx,bally,0);
        ballx = ballx + brevx;
    } else {
        gameover = 1; // ":hGame Over:h"
        charPrint(21,0,3);
        charPrint(22,0,71);
        charPrint(23,0,65);
        charPrint(24,0,77);
        charPrint(25,0,69);
        charPrint(27,0,79);
        charPrint(28,0,86);
        charPrint(29,0,69);
        charPrint(30,0,82);
        charPrint(31,0,3);
        /*
        brevx *= -1;
        ballx = ballx + brevx;*/
    }
    // SLIDER 1 ANIMATION
    if((slider1y+(8*SLIDERLENGTH)) != 176 && (slider1y) != 0){
        for(int i = 0;i < SLIDERLENGTH;i++){
            spritePrint(2,slider1y+srev1+(8*i),SLIDER,2,slider1y+(8*i),i);
        }
        slider1y = slider1y + srev1;
    } else {
        srev1 *= -1;
        slider1y = slider1y + srev1;
    }
    if(init){
        putBorder();
        init = 0;
        score = 0;
    }
    // SLIDER 2 ANIMATION
    if((slider2y+(8*SLIDERLENGTH)) != 176 && (slider2y) != 0){
        for(int i = 0;i < SLIDERLENGTH;i++){
            spritePrint(295,slider2y+srev2+(8*i),SLIDER,295,slider2y+(8*i),i);
        }
        slider2y = slider2y + srev2;
    } else {
        srev2 *= -1;
        slider2y = slider2y + srev2;
    }
    if(init){
        putBorder();
        init = 0;
    }
    // SLIDER CONTROLS
    if(LeftShiftHolded == 1 && osrev1 == 0){
        srev1 *= -1;
        osrev1 = 1;
    }
    if(RightShiftHolded == 1 && osrev2 == 0){
        srev2 *= -1;
        osrev2 = 1;
    }
    if(LeftShiftHolded == 0 && osrev1 == 1){
        osrev1 = 0;
    }
    if(RightShiftHolded == 0 && osrev2 == 1){
        osrev2 = 0;
    }
    //Print Score
    printScore();
    //Check Collisions
    if((bally) < (slider1y+8*SLIDERLENGTH) && (bally+8) > slider1y && (ballx - 1) < (2+8)){
        brevx *= -1;
        score++;
    }
    if(bally < (slider2y+8*SLIDERLENGTH) && (bally+8) > slider2y && (ballx + 1) > (295-8)){
        brevx *= -1;
        score++;
    }
    // End Game Checker
    }
}

int _start()
{
    limiter = 1;
    ballx = 100;
    bally = 6;
    brevy = 1;
    brevx = 1;
    srev1 = 1;
    srev2 = -1;
    slider1y = 88;
    slider2y = 88;
    fore = WHITE;
    back = PINK;
    bord = BLUE;
    init=1;
    score = 0;
    gameover = 0;
    clearScreenAnimation();
    InitializeIDT();
}

void timerRecord(){
    gameLoop();
    ticks++;
    outb(PIC1_COMMAND,0x20);
    return;
}