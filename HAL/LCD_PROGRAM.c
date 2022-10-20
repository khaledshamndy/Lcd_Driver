//include HAL.
//libs
#avr<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//dio layer
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
//interface file .
#include "LCD_INTERFACE.h"
//implentations.
void LCD_Init(void){
// intialization sequance for 4_bit mode .
	
//delay for more than 30ms.
    _delay_ms(50);
	
//write function set-writing high nibble three commands .
	LCD_voidSendCMD(INIT_VAL);//0b 0 0 1 0     0000
	LCD_voidSendCMD(INIT_VAL);//0b 0 0 1 0     0000
    LCD_voidSendCMD(FUNSET);//0b N F 0 0    0000 , put N=1,F=0.

//delay for more than 39 micros.
    _delay_ms(1);
	
//Display on/off control.
    LCD_voidSendCMD(ZERO);//0b 0 0 0 0     0000
	LCD_voidSendCMD( DIS_MODE);//0b 1 D C B     0000, put D=1,C=0,B=0.
	
//delay for more than 39 micros.
    _delay_ms(1);
	
//Display clear.
    LCD_voidSendCMD(ZERO);//0b 0 0 0 0     0000
    LCD_voidSendCMD( DIS_CLR );//0b 0 0 0 1     0000
	
//delay for more than 1.35ms.
    _delay_ms(2);

//Entry mode set.
    LCD_voidSendCMD(ZERO);//0b 0 0 0 0     0000
    LCD_voidSendCMD( ENTRY_MODE );//0b 0 1 I/D SH    0000, put I/D=,SH=.
	
}
void LCD_voidWriteData(u8 Copy_u8Data){
	DIO_voidSetPinValue(PORT_CTRL,RS,HIGH);
	DIO_voidSetPinValue(PORT_CTRL,RW,LOW);
    DIO_voidSetPortValue(PORT_DATA,Copy_u8Data);
//LATCH FOR ENABLE PIN .
    DIO_voidSetPinValue(PORT_CTRL,EN,HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(PORT_CTRL,EN,LOW);
    _delay_ms(2);
 	
}
void LCD_voidSendCMD(u8 Copy_u8Cmd){
	DIO_voidSetPinValue(PORT_CTRL,RS,LOW);
	DIO_voidSetPinValue(PORT_CTRL,RW,LOW);
	DIO_voidSetPortValue(PORT_DATA,Copy_u8Cmd);
//LATCH FOR ENABLE PIN .
    DIO_voidSetPinValue(PORT_CTRL,EN,HIGH);
    _delay_ms(2);
	DIO_voidSetPinValue(PORT_CTRL,EN,LOW);
    _delay_ms(2);
}
void LCD_voidWriteString(u8*Copy_pu8String){
//what's could go wrong with the pointer.
	while(*Copy_pu8String!="\0"){
		LCD_voidWriteData(*Copy_pu8String);
		Copy_pu8String++;
	}
		
}