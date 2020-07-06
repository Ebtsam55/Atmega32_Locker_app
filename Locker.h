/*
 * Locker.h
 *
 * Created: 4/9/2020 1:12:31 AM
 *  Author: Ebtsam
 */ 


#ifndef LOCKER_H_
#define LOCKER_H_

#include "Header.h"

#define size 4       //size of password length
#define Led PC0
#define Relay PC4


void IsCorrectPass(uint8_t * initial_pass , uint8_t* reading_pass);
void reading_pass_process (uint8_t* reading_pass ) ;
void change_pass(uint8_t * new_pass);
void save_new_pass(uint8_t* saved_pass ,uint8_t* new_pass );
uint8_t check_newPass (uint8_t* saved_pass ,uint8_t* new_pass ) ;






#endif /* LOCKER_H_ */