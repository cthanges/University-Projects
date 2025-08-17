#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Game.h"

#define __FI        1
#define DELAY_2N   18

int mario_x = 180;
int mario_y = 240;
int bounce=0;
int game_over=0, win = 0, blocknum = 1, once = 0;
int paddle, i;
int x1[] = {130, 70, 110, 150, 190, 230, 240, 60};					//array for the x-postion of the block
int x2[] = {169, 109, 149, 189, 229, 269, 279, 99};					//array for the 2nd x-postion of the block
int y1[] = {30, 90, 60, 110, 50, 150, 100 ,160};					//array for the y-postion of the block
int y2[] = {69, 129, 99, 149, 89, 189, 139, 199};					//array for the 2nd y-postion of the block

extern unsigned char MARIO[];
extern unsigned char BLOCKS[];
extern unsigned char MARIOINTRO[];

//Delay function
void delay3 (int cnt) {
  cnt <<= DELAY_2N;
  while (cnt--);
}

//Introduction Menu Screen
void Game_Check(void){
	GLCD_Clear(White);
	
	GLCD_SetBackColor(Red);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	GLCD_DisplayString(1, 0, __FI,(unsigned char*)"        GAME        ");
	GLCD_Bitmap (110, 60, 100, 101, MARIOINTRO);

	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Red);	
	GLCD_DisplayString(7, 2, __FI,(unsigned char*)"MARIO KART MAZE");

	GLCD_SetTextColor(Black);
	GLCD_DisplayString(27, 15, 0,(unsigned char*)"SELECT=PUSH, BACK=LEFT");
	while(1){
		if (get_button() ==  KBD_SELECT){
			Instructions();
		}
		else if(get_button() ==  KBD_LEFT){		
				Media_Center();	
			}
	}
}

//Instructions Menu Screen
void Instructions(void){
	GLCD_Clear(Red);
	
	GLCD_SetBackColor(Red);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(1, 3, __FI,(unsigned char*)"INSTRUCTIONS:");
	GLCD_DisplayString(3, 1, __FI,(unsigned char*)"Help Mario get to");
	GLCD_DisplayString(4, 1, __FI,(unsigned char*)"the other side!");	
	GLCD_DisplayString(5, 1, __FI,(unsigned char*)"Move the joystick");
	GLCD_DisplayString(6, 1, __FI,(unsigned char*)"left and right to");
	GLCD_DisplayString(7, 1, __FI,(unsigned char*)"drive without");
	GLCD_DisplayString(8, 1, __FI,(unsigned char*)"crashing!");
	GLCD_DisplayString(27, 15, 0,(unsigned char*)"     SELECT=PUSH      ");
	while(1){
		if (get_button() ==  KBD_SELECT){
				Game();
		}
	}
}

//---------- Game ----------
void Game (void) {   
	if(once == 0){
		LED_Init ();
		KBD_Init();	
		once++;
	}
	game_over = 0;
	win = 0;
	mario_x = 140;
	mario_y = 240;
	
	GLCD_Clear(Black);  
	GLCD_Bitmap (mario_x, mario_y, 45, 45, MARIO);
	
while(1){
	for(i=0;i<blocknum;i++){
			GLCD_Bitmap (x1[i],y1[i],55,17, BLOCKS);
			LED_On(i);	
	}
	
	while (1) {
		if (get_button() ==  KBD_RIGHT){
			if (mario_x+40 < 320){
				mario_x++;
			}
		}
		else if (get_button() ==  KBD_LEFT){
			if (mario_x-1 > 0){
				mario_x--;
			}
		}
		
		if (bounce ==0){
			mario_y=mario_y-0.1;
		}
		
			GLCD_Bitmap (mario_x, mario_y, 45, 45, MARIO);	

	
	//Collision Detection
	for(i=0;i<blocknum;i++){
		if(mario_x-10 < x2[i] && x1[i] < mario_x+39){
			if(mario_y+27 < y2[i] && y1[i] < mario_y+66){
				game_over = 1;
			}
		}
	}
	
	if(mario_y <= 0)	
		win = 1;
	
	if(game_over == 1 || win == 1)
		break;
	}
	
        //If Mario reaches top of the screen	
	if (win == 1){
		GLCD_Clear(Green); 
		GLCD_SetBackColor(Green);
		GLCD_SetTextColor(Black);
		GLCD_DisplayString(4, 5, __FI,(unsigned char*)"GOOD JOB!");
		GLCD_DisplayString(6, 4, __FI,(unsigned char*)"LEVEL UP...");
		delay3(250);
		blocknum++;
		Game();
	}	
	
        //If Mario collides with block 
	else if (game_over == 1){
		GLCD_Clear(Red); 
		GLCD_SetBackColor(Red);
		GLCD_SetTextColor(Black);
		GLCD_DisplayString(4, 5, __FI,(unsigned char*)"GAME OVER!");
		GLCD_DisplayString(6, 4, __FI,(unsigned char*)"YOU LOST...");
		blocknum=1;
		LED_Off(0);LED_Off(1);LED_Off(2);LED_Off(3);LED_Off(4);LED_Off(5);LED_Off(6);	LED_Off(7);			
		delay3(250);
		Media_Center();
	}
}
}	

