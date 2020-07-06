/*
 * Locker_app.c
 *
 * Created: 4/8/2020 7:34:54 PM
 *  Author: Ebtsam
 */ 


#include "Locker.h"
uint8_t IsLocked=1;

int main(void)
{ 
   LCD_init(); 
   keypad_init(); 
   
   SETBIT(DDRC ,Led);
   SETBIT(DDRC ,Relay);
   CLRBIT(PORTC,Led);
   CLRBIT(PORTC,Relay);
   
   
   
   uint8_t saved_pass[size] = {'0','0','0','0'};
   uint8_t reading_pass[size];
   uint8_t new_pass[size]={'0','0','0','0'};
   
   reading_pass_process(reading_pass);
   
   
   IsCorrectPass(saved_pass,reading_pass);
  
 
    while(!IsLocked)
    {  
	   
       int8_t key = keypad_read();
	   if(key!=-1)
	   {
		   while(keypad_read()==key);
		   switch (key)
		   {
			   case '1':
			        LCD_clear();
					LCD_goToRowColumn(0,0); 
					LCD_write_string("1 is pressed");
					TOGBIT(PORTC,Led);
					break;
				
			   case '2':
					LCD_clear();
					LCD_goToRowColumn(0,0);
				    LCD_write_string("2 is pressed");
					TOGBIT(PORTC,Relay);
					break;
					
			   case '3' :
			        change_pass(new_pass) ;
					break;
					
			   case '4':
			        if(check_newPass(saved_pass, new_pass))
					{
			        save_new_pass(saved_pass,new_pass);
					LCD_clear();
					LCD_goToRowColumn(0,0);
					LCD_write_string("new pass saved");
					}
					else {
						LCD_clear();
						LCD_goToRowColumn(0,0);
						LCD_write_string("set newPass first");
					}
					
					break;
					
			   case '6':
			        CLRBIT(PORTC,Relay);
			        LCD_clear();
					LCD_goToRowColumn(0,0);
					LCD_write_string("Locked !");
					_delay_ms(1000);
					
					reading_pass_process(reading_pass);
					IsCorrectPass(saved_pass,reading_pass);
					break;
					
				
		   }
	   }
	   
		
    }
}

