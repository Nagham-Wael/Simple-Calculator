/************************************************************
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Author: Nagham
 *
 * Created on: Nov 2, 2020
 *
 * Description: Header file of lcd driver
 ***********************************************************/
#ifndef LCD_H_
#define LCD_H_

/*************************INCLUDES*************************/

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/***************Definitions & Configurations***************/

/* LCD Data bits mode configuration */
#define DATA_BITS_MODE 4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

#undef UPPER_PORT_PINS /*We use the lower 4 pins*/

#define RS PB1
#define RW PB2
#define E  PB3

#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_PORT_DIR DDRB

#define LCD_DATA_PORT PORTD
#define LCD_DATA_PORT_DIR DDRD

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80
#define SET_CURSOR_LOCATION 0x80

/******************FUNCTIONS DECLARATIONS******************/

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_clearScreen(void);
void LCD_intgerToString(int data);


#endif /* LCD_H_ */
