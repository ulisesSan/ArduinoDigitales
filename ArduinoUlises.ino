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
byte EstadoParo = 0;
String txt = "";
String txtEstados = "";
String dipTxt[4] = ("0","0","0","0");
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
byte paro[1] = {1};
String Estados[4] = ("","","","");

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  // Print a message to the LCD.
  //lcd_1.print("hello world!");
  pinMode(10, INPUT);
  pinMode(1, OUTPUT);
  
}

void loop()
{
//Clear display  
  lcd_1.clear();
  paro[0] = digitalRead(10);
  if(paro[0] == 0){
    pinMode(1, HIGH);
    for(int i =0; i <= 3; i++){
    EstadoDip[i] = digitalRead(i+6);    
  }
  
  if(EstadoDip[0] == 1 ){    
    dipTxt[0]= "1";
    Estados[0] = "abarrotes ";
  }if(EstadoDip[1] == 1){
    dipTxt[1]= "1";
    Estados[1] = "micelaneos";
  }if(EstadoDip[2] == 1){
    dipTxt[1]= "1";
    Estados[2] = "No tipo";
  }if(EstadoDip[3] == 1){
    dipTxt[1]= "1";
    Estados[2] = "No categoria";
  }

  for(int i =0; i <= 3; i++){
    txt += EstadoDip[i];
    txtEstados += Estados[i];
  }

  if(txt == "0000" && txtEstados == ""){
    txtEstados = "No producto";  
  }


  //txt = EstadoDip[0] + EstadoDip[1] + EstadoDip[2] + EstadoDip[3];
  //lcd_1.println(EstadoDip[0] + EstadoDip[1] + EstadoDip[2] + EstadoDip[3]);
  lcd_1.setCursor(1,0);
  lcd_1.print(txt);
  lcd_1.setCursor(0,1);
  lcd_1.print(txtEstados);
  txt = "";
  txtEstados = "";
  memset(Estados, 0 , sizeof(Estados));
  memset(EstadoDip, 0 , sizeof(EstadoDip));
  }else{
    pinMode(1, LOW);
    lcd_1.setCursor(0 ,1);
    lcd_1.print("Paro de emergencia");
    txt = "";
    txtEstados = "";
    memset(EstadoDip, 0 , sizeof(EstadoDip));
  }
  delay(500);
}
