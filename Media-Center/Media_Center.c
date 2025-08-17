#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Game.h"
#include "usbdmain.h"
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbcore.h"
#include "usbaudio.h"
#include "type.h"

#define __FI        1
#define DELAY_2N    18

int sel=1; 
int music=0;
int k;

void delay (int cnt) {
  cnt <<= DELAY_2N;
  while (cnt--);
}

void MP3_Player2 (void){
    USB_Connect(TRUE);
    NVIC_EnableIRQ(TIMER0_IRQn);
    NVIC_EnableIRQ(USB_IRQn);
		
		while( 1 ){
			if (get_button() == KBD_LEFT){
				Media_Center();
			}
		}
}

int main (void) {                                           
	
  LED_Init ();
  GLCD_Init();
  KBD_Init();
  GLCD_Clear(Black);	
	 
	GLCD_SetBackColor(DarkCyan);		
	GLCD_SetTextColor(Black);
	GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	GLCD_DisplayString(1, 0, __FI,(unsigned char*)"      CHARRAN       ");
	
	GLCD_SetBackColor(Black);		
	GLCD_SetTextColor(DarkCyan);
	GLCD_DisplayString(4, 4, __FI,(unsigned char*) "PRESS SELECT");		
	GLCD_DisplayString(5, 6, __FI,(unsigned char*) "TO BEGIN.");
	
	GLCD_SetTextColor(White);
	GLCD_DisplayString(27, 15, 0,(unsigned char*)"     SELECT=PUSH      ");

	while (1) {
		if (get_button() ==  KBD_SELECT){
			for (k=0;k<2;k++){		
				GLCD_Clear(Black);  			
				GLCD_SetBackColor(Black);		
				GLCD_SetTextColor(White);		
				GLCD_DisplayString(5, 5, __FI,(unsigned char*) "LOADING.");
					
				LED_On(0); delay(5);
				LED_Off(0);
				LED_On(1); delay(5);
				LED_Off(1);
				LED_On(2); delay(5);
				LED_Off(2);				
				LED_On(3); delay(5);
				LED_Off(3);				
				LED_On(4); delay(5);
				LED_Off(4);				
				LED_On(5); delay(5);
				LED_Off(5);
				LED_On(6); delay(5);
				LED_Off(6);
				LED_On(7); delay(5);
				LED_Off(7);	
				GLCD_DisplayString(5, 5, __FI,(unsigned char*) "LOADING..");

				LED_On(7); delay(5);
				LED_Off(7);
				LED_On(6); delay(5);
				LED_Off(6);
				LED_On(5); delay(5);
				LED_Off(5);				
				LED_On(4); delay(5);
				LED_Off(4);				
				LED_On(3); delay(5);
				LED_Off(3);			
				LED_On(2); delay(5);
				LED_Off(2);
				LED_On(1); delay(5);
				LED_Off(1);
				LED_On(0); delay(5);
				LED_Off(0);	
				GLCD_DisplayString(5, 5, __FI,(unsigned char*) "LOADING...");
			}
			Media_Center();
		}
	}
}

void Media_Center(){

	GLCD_Clear(Black);  
	GLCD_SetBackColor(DarkCyan);		
	GLCD_SetTextColor(Black);
	GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	GLCD_DisplayString(1, 0, __FI,(unsigned char*)"     MAIN  MENU     ");
	
	GLCD_SetBackColor(Black);
	GLCD_DisplayString(2, 0, __FI,(unsigned char*)"                     ");
	GLCD_DisplayString(3, 0, __FI,(unsigned char*)"                     ");
	
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(DarkCyan);	
	GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY");
	GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER");		
	GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME");
	GLCD_SetTextColor(White);	
	GLCD_DisplayString(26, 15, 0,(unsigned char*)"    TOGGLE UP/DOWN    ");		
	GLCD_DisplayString(27, 15, 0,(unsigned char*)"SELECT=PUSH, BACK=LEFT");
  
	while (1) {               

		if (get_button() ==  KBD_UP){
				sel--;
				if (sel == 1){
					GLCD_SetTextColor(DarkCyan);
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME");
					delay(5);
				}
				else if (sel == 2){
					GLCD_SetTextColor(DarkCyan);
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME");
					delay(5);					
				}
				else if (sel == 3){
					GLCD_SetTextColor(DarkCyan);
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER");
					delay(5);	
				}
			
		}	else if (get_button() ==  KBD_DOWN){
				sel++;
				if (sel == 1){
					GLCD_SetTextColor(DarkCyan);
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME");
					delay(5);
				}
				else if (sel == 2){
					GLCD_SetTextColor(DarkCyan);
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME");
					delay(5);					
				}
				else if (sel == 3){
					GLCD_SetTextColor(DarkCyan);
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER");
					delay(5);	
				}
	
		} else if (get_button() ==  KBD_SELECT){
				if (sel == 1){
					Photo_Gallery();
				}
				else if (sel == 2){
					GLCD_Clear(Black);
					GLCD_SetBackColor(Green);		
					GLCD_SetTextColor(Black);					
	        GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	        GLCD_DisplayString(1, 0, __FI,(unsigned char*)"     MP3 PLAYER     ");
					
					GLCD_SetBackColor(Black);		
					GLCD_SetTextColor(Green);		
					GLCD_DisplayString(4, 2, __FI,(unsigned char*) "  AUDIO");
					GLCD_DisplayString(5, 4, __FI,(unsigned char*) "STREAMING...");
					
					
          GLCD_SetTextColor(White);
	        GLCD_DisplayString(27, 15, 0,(unsigned char*)"     BACK=LEFT      ");					
					if(music == 0){
						MP3_Player ();
					}  
					else if (music == 1) { 
						MP3_Player2 ();
					}					
				}
				else if (sel == 3){
						Game_Check();	
				}	
		}
		
		switch(sel) {
			case 1:
				GLCD_SetBackColor(DarkCyan);		
	      GLCD_SetTextColor(Black);
	      GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	      GLCD_DisplayString(1, 0, __FI,(unsigned char*)"     MAIN  MENU     ");
			
	      GLCD_SetBackColor(Black);
	      GLCD_DisplayString(2, 0, __FI,(unsigned char*)"                     ");
        GLCD_DisplayString(3, 0, __FI,(unsigned char*)"                     ");
			
				GLCD_SetBackColor(DarkCyan);
			  GLCD_SetTextColor(Black);
				GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY          ");
			
				GLCD_SetBackColor(Black);
			  GLCD_SetTextColor(DarkCyan);
				GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER             ");
				GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME                   ");				
        break;
      case 2:
        GLCD_SetBackColor(DarkCyan);		
	      GLCD_SetTextColor(Black);
	      GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	      GLCD_DisplayString(1, 0, __FI,(unsigned char*)"     MAIN  MENU     ");
			
	      GLCD_SetBackColor(Black);
	      GLCD_DisplayString(2, 0, __FI,(unsigned char*)"                     ");
        GLCD_DisplayString(3, 0, __FI,(unsigned char*)"                     ");
			
			  GLCD_SetBackColor(DarkCyan);
			  GLCD_SetTextColor(Black);
				GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER             ");
			
				GLCD_SetBackColor(Black);
			  GLCD_SetTextColor(DarkCyan);
				GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY          ");
				GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME                   ");			
        break;
      case 3:
        GLCD_SetBackColor(DarkCyan);		
	      GLCD_SetTextColor(Black);
	      GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	      GLCD_DisplayString(1, 0, __FI,(unsigned char*)"     MAIN  MENU     ");
			
	      GLCD_SetBackColor(Black);
	      GLCD_DisplayString(2, 0, __FI,(unsigned char*)"                     ");
        GLCD_DisplayString(3, 0, __FI,(unsigned char*)"                     ");
			
			  GLCD_SetBackColor(DarkCyan);
			  GLCD_SetTextColor(Black);
				GLCD_DisplayString(6, 0, __FI,(unsigned char*)" -> GAME                   ");

				GLCD_SetBackColor(Black);
			  GLCD_SetTextColor(DarkCyan);
				GLCD_DisplayString(4, 0, __FI,(unsigned char*)" -> PHOTO GALLERY          ");
				GLCD_DisplayString(5, 0, __FI,(unsigned char*)" -> MP3 PLAYER             ");			
        break;	
		}		
  }
}	
