#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Photo_Viewer.h"

#define __FI        1
#define DELAY_2N    18
int sel2=1;

void delay2 (int cnt) {
  cnt <<= DELAY_2N;
  while (cnt--);
}

void Photo_Gallery(){
	GLCD_Clear(White);  
	
	GLCD_SetBackColor(Magenta);		
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 0, __FI,(unsigned char*)"    MEDIA CENTER    ");
	GLCD_DisplayString(1, 0, __FI,(unsigned char*)"   PHOTO  GALLERY   ");

	GLCD_SetBackColor(White);	
	GLCD_SetTextColor(Magenta);	
	GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
	GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");		
	GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");	
	GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");	
	
	
	GLCD_SetTextColor(Black);		
	GLCD_DisplayString(26, 15, 0,(unsigned char*)"    TOGGLE UP/DOWN    ");		
	GLCD_DisplayString(27, 15, 0,(unsigned char*)"SELECT=PUSH, BACK=LEFT");
  
	while (1) {               

		if (get_button() ==  KBD_UP){
				sel2--;
				if (sel2 == 1){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");					
					delay2(5);
				}
				else if (sel2 == 2){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");		
					delay2(5);					
				}
				else if (sel2 == 3){				
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");	
					delay2(5);	
				}
				else if (sel2 == 4){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");	
					delay2(5);	
				}				
			
		}	else if (get_button() ==  KBD_DOWN){
				sel2++;
				if (sel2 == 1){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");					
					delay2(5);
				}
				else if (sel2 == 2){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");		
					delay2(5);					
				}
				else if (sel2 == 3){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
					GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");	
					delay2(5);	
				}
				else if (sel2 == 4){
					GLCD_SetTextColor(Magenta);
					GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");
					GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
					GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");	
					delay2(5);	
				}	
	
		} else if (get_button() ==  KBD_SELECT){
				if (sel2 == 1){
					Photo_Viewer(1);
				}
				else if (sel2 == 2){	
					Photo_Viewer(2);			
				}
				else if (sel2 == 3){		
					Photo_Viewer(3);	
				}
				else if (sel2 == 4){	
					Photo_Viewer(4);
				}
				
		} else if (get_button() ==  KBD_LEFT){		
				Media_Center();	
			}
		
		switch(sel2) { //Highlighting options on the LCD when hovering
			case 1:	
				GLCD_SetTextColor(Blue);
				GLCD_DisplayString(3, 0, __FI,(unsigned char*)"      PHOTO #1");	
        break;			
      case 2:
				GLCD_SetTextColor(Blue);
				GLCD_DisplayString(4, 0, __FI,(unsigned char*)"      PHOTO #2");
        break;			
      case 3:	
				GLCD_SetTextColor(Blue);
				GLCD_DisplayString(5, 0, __FI,(unsigned char*)"      PHOTO #3");	
        break;			
      case 4:			
				GLCD_SetTextColor(Blue);
				GLCD_DisplayString(6, 0, __FI,(unsigned char*)"      PHOTO #4");
        break;			
		}		
	} 
		
}	
