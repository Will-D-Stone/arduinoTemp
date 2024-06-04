//megaTemp.c displays the current temperature on an OLED in both fahrenheit and celsius
//W. Stone 4/21/24 Initial code for lab8.2 Umass ECE231--Spring 2024
#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "SSD1306.h"
#include "my_adc_lib.h"
#include "my_uart_lib.h"

#define REDLED PD6      // Arduino Uno pin 6

int main(void)          //main function
{
  int tempThreshold = 60;       //temperature threshold for the redLED
  DDRD = 1<<REDLED;             //set output to pin6
  unsigned int digValue;        //digital value pulled from the temperature sensor
  double tempC, tempF;          //converted temperatures
  uart_init();                  //initializes the uart
  OLED_Init();                  //initializes the OLED
  adc_init();                   //initializes the ADC

  while (1)                     //creates an infinite loop
  {
    digValue = get_adc();           //gets the digital value
    tempC = ((digValue-750)/10)+25; //temperature in celsius
    tempF = (tempC*9/5)+32;         //temperature in fahrenheit
    
    if(tempF>tempThreshold){        //evaluates the threshold for the LED
        PORTD |= (1<<REDLED);       //On when over the threshold
    }
      int temp1 = tempF*10;
      OLED_GoToLine(3);                   //sends the temp to the OLED
      OLED_DisplayString("Temperature");
      OLED_GoToLine(5);
      OLED_DisplayNumber(10, tempF, 3);
      OLED_DisplayString(".");            //required to be precise to the tenths digit
      int temp = temp1%10;
      OLED_DisplayNumber(10, temp, 1);
      OLED_DisplayString("F");

      temp1 = tempC*10;
      OLED_GoToLine(7);
      OLED_DisplayNumber(10, tempC, 3);
      OLED_DisplayString(".");
      temp = temp1%10;        //required to be precise to the tenths digit
      OLED_DisplayNumber(10, temp, 1);
      OLED_DisplayString("C");
      _delay_ms(100);

      PORTD &= ~(1<<REDLED);          // REDLED off when temperature threshold is not met
  }

}