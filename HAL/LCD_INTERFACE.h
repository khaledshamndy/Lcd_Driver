//libs
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//dio layer
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
//guards
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define PORT_DATA    PORTA
#define PORT_CTRL    PORTB
#define RS           PIN1    //PEGISTER SELECT PIN IN LCD ...................................... 
#define RW           PIN2    //READ/WRITE PIN IN LCD ...........................................
#define EN           PIN3    //ENABLE PIN IN LCD ...............................................
#define ZERO         0X00    //SHORT FOR ZERO...................................................
#define INIT_VAL     0x20    //SHORT FOR THE INITIAL VALUE,0b 0 0 1 0     0000..................
#define FUNSET       0x80    //function set...............,0b N F 0 0     0000, put N=1,F=0..... 
#define DIS_CLR      0X10    //SHORT FOR CLEAR............,0b 0 0 0 1     0000..................
#define DIS_MODE     0xC0    //SHORT FOR THE ON/OFF.......,0b 1 D C B     0000, put D=1,C=0,B=0.
#define ENTRY_MODE   0x60    //SHORT FOR THE ENTRY MODE...,0b 0 1 I/D SH  0000, put I/D=1,SH=0.
//FUNTCTIONS THE LCD DRIVER
/*0-INITIALIZATION FUNCTION .
1-FUNCTIONS TO WRITE COMMANDS
2-FUNCTIONS TO WRITE DATA */

void LCD_Init(void);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidSendCMD(u8 Copy_u8Cmd);
void LCD_voidWriteString(u8*Copy_pu8String);





#endif
