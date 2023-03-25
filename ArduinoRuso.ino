// C++ code
//
/*
  LiquidCrystal Library - Hello World

   Demonstrates the use of a 16x2 LCD display.
  The LiquidCrystal library works with all LCD
  displays that are compatible with the  Hitachi
  HD44780 driver. There are many of them out
  there, and you  can usually tell them by the
  16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008  by David
  A. Mellis
  library modified 5 Jul 2009  by Limor Fried
  (http://www.ladyada.net)
  example added 9 Jul 2009  by Tom Igoe
  modified 22 Nov 2010  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

#include <LiquidCrystal.h>
byte EstadoDip[4];
int seconds = 0;
String txt = "0,0,0,0";

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  // Print a message to the LCD.
  //lcd_1.print("hello world!");
}

void loop()
{
  for(int i =0; i <= 3; i++){
    EstadoDip[i] = digitalRead(i+6);
  }
  
  if(EstadoDip[0] == 1 ){    
    lcd_1.clear();    
    lcd_1.setCursor(1, 0);
    lcd_1.print("Si se pudo if");
  }else{
    lcd_1.clear();
    lcd_1.print("Si se pudo else");
  } 
  
  delay(1000);
  EstadoDip[0] = 0;
}