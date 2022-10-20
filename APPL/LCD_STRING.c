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

int main (){
//SET THE DIRECTION OF THE PORTS AND THE PINS .   
    DIO_voidSetPinDir(PORT_CTRL,RS,OUTPUT);
	DIO_voidSetPinDir(PORT_CTRL,RW,OUTPUT);
	DIO_voidSetPinDir(PORT_CTRL,EN,OUTPUT);
	DIO_voidSetPortDir(PORT_DATA,OUTPUT);
	LCD_Init();
	u8*name_var[255]={"khaled abdelnasser./0"};
	whie(1){
		LCD_voidWriteString(name_var);
	}
	
}