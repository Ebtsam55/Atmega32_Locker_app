/*
 * Locker.c
 *
 * Created: 4/9/2020 1:12:14 AM
 *  Author: Ebtsam
 */ 
#include "Locker.h"
extern IsLocked ;

void IsCorrectPass(uint8_t * saved_pass , uint8_t* reading_pass)
{   uint8_t i;
	for (i=0; i<size ; i++)
	{
		if(saved_pass[i]!=reading_pass[i])
		{
			IsLocked=1;
			LCD_clear();
			LCD_goToRowColumn(0,0);
			LCD_write_string("wrong pass");
			_delay_ms(1000);
			reading_pass_process(reading_pass);

		}
	}
	
	LCD_clear();
	LCD_goToRowColumn(0,0);
	LCD_write_string("Right pass");
	_delay_ms(1000);
	LCD_clear();
	IsLocked=0;
	
}

void reading_pass_process (uint8_t* reading_pass )
{
	LCD_clear();
	LCD_goToRowColumn(0,0);
	LCD_write_string("Enter Password : ");
	uint8_t pass_index =0;
	while(pass_index < size)
	{
		int8_t key = keypad_read();
		
		if (key!=-1  )
		{
			while(keypad_read()==key);
			LCD_goToRowColumn(1,pass_index);
			LCD_write_char(key);
			reading_pass[pass_index++]=key;
			
		}
		
	}
	
	_delay_ms(1000);
}

void change_pass(uint8_t * new_pass)
{
	LCD_clear();
	LCD_goToRowColumn(0,0);
	LCD_write_string("Change Pass: ");
	uint8_t pass_index =0;
	while(pass_index < size){
		int8_t key = keypad_read();
		if(key!=-1 )
		{
			while(keypad_read()==key);
			
			LCD_goToRowColumn(1,pass_index);
			LCD_write_char(key);
			
			new_pass[pass_index++]=key;
			
		}
	}
	
	
	
}
void save_new_pass(uint8_t* saved_pass ,uint8_t* new_pass )
{
	uint8_t i ;
	
	for (i=0; i<size ; i++)
	{
		saved_pass[i]=new_pass[i];
	}
	
}

uint8_t check_newPass (uint8_t* saved_pass ,uint8_t* new_pass ) // check if a new pass has been entered or not
{   uint8_t i ;
	for (i=0; i<size ; i++)
	{
		if(saved_pass[i]!=new_pass[i])
		return 1;
	}
	return 0;
}
