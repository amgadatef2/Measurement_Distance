/*
 * Button with LEDs.c
 *
 * Created: 9/12/2023 9:45:35 PM
 * Author : amgad atef
 */ 


#include "PORT_Core.h"
#include "LCD_Core.h"
#include "LED_Core.h"
#include <avr/interrupt.h> 
#include "IRQH_Core.h"
#include "ADC_Core.h"
#include "GPT_core.h"
#include "ultrasonic_core.h"

extern uint32 ADC_Vin_Value_mv;

int main(void)
{
	uint32 DISTANCE =0;

   PORT_Init();
 IRQH_SetGlobalInterrupts(INTERRUPT_ENABLE);
 GPT_INIT();
 ICU_INIT();
 LCD_Init();
 LCD_WriteString("Measurement_Distance");
 _delay_ms(1000);
 LCD_WriteString("Made by Amgad");
 _delay_ms(2000);
 LCD_Clear();


   while (1)
   {
	   LCD_GoTo(0,1);
	   LCD_WriteString("DIstance:");
	   ultrasonic_trigger();
	   DISTANCE=ultrasonic_calculateDistance();
		   LCD_GoTo(0,11);
		   LCD_WriteInteger(DISTANCE);
		   _delay_ms(500);
		  LCD_Clear();
		  
		  
		
	   
   }
}

