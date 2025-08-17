#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Photo_Viewer.h"

#define __FI        1

extern unsigned char GKMC[];
extern unsigned char JOEY1999[];
extern unsigned char MADVILLAINY[];
extern unsigned char MMLP[];

int Photo_Viewer(int j){

	GLCD_ClearLn(8,1);
	GLCD_ClearLn(9,1);
	
	while (1) { 
		
			if (j == 1){	 	
					GLCD_Bitmap (70, 50, 180, 180, GKMC);			
			}
			else if (j == 2){						  	
					GLCD_Bitmap (70, 50, 180, 180, JOEY1999);		
			}
			else if (j == 3){	  	
					GLCD_Bitmap (70, 50, 180, 180, MADVILLAINY);		
			}
			else if (j == 4){	  	
					GLCD_Bitmap (70, 50, 180, 180, MMLP);			
			}
				
			if (get_button() ==  KBD_LEFT){
				if (j == 1){
					Photo_Gallery();
				}
				else if (j == 2){					
					Photo_Gallery();				
				}
				else if (j == 3){		
					Photo_Gallery();			
				}
				else if (j == 4){	
					Photo_Gallery();					
				}					
			}
	} 		
}	
