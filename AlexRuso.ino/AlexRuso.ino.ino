

#include <LiquidCrystal.h>
LiquidCrystal 
lcd(12, 11, 5, 4, 3, 2); 
void setup() {   lcd.begin(16, 2); 
// Inicializar el display LCD  
pinMode(9, INPUT_PULLUP);
// Configurar el pin 9 como entrada con pull-up  
pinMode(8, INPUT_PULLUP); // Configurar el pin 8 como entrada con pull-up  
pinMode(7, INPUT_PULLUP); // Configurar el pin 7 como entrada con pull-up 
pinMode(6, INPUT_PULLUP); // Configurar el pin 6 como entrada con pull-up
} 
void loop() {   
  // Leer el estado de los pines y concatenar los valores en un número binario de 4 bits  
  int estado = digitalRead(9) + digitalRead(8) * 2 + digitalRead(7) * 4 + digitalRead(6) * 8;      
  // Mostrar la leyenda correspondiente al estado en el display LCD  
  switch (estado) {     
    case 0:      
    lcd.clear();       
    lcd.print("Funcionamiento");       
    lcd.setCursor(0, 1);       
    lcd.print("correcto");      
    break;     
    case 1:       
    lcd.clear();       
    lcd.print("Falla 1");       
    break;     
    case 2:       
    lcd.clear();       
    lcd.print("Falla 2");      
    break;     
    case 3:       
    lcd.clear();       
    lcd.print("Falla 3");       
    break;     
    case 4:       
    lcd.clear();       
    lcd.print("Error 1");       
    break;     
    case 5:       
    lcd.clear();       
    lcd.print("Error 2");       
    break;     
    case 6:       
    lcd.clear();       
    lcd.print("Error 3");       
    break;     
    case 7:       
    lcd.clear();       
    lcd.print("Falla y Error");       
    break;     
    case 8:       
    lcd.clear();       
    lcd.print("Paro por");       
    lcd.setCursor(0, 1);       
    lcd.print("mantenimiento");       
    break;     
    case 9:       
    lcd.clear();       
    lcd.print("Paro por");       
    lcd.setCursor(0, 1);       
    lcd.print("falla crítica");       
    break;     
    case 10:       
    lcd.clear();       
    lcd.print("Paro por");       
    lcd.setCursor(0, 1);       
    lcd.print("error crítico");       
    break;     
    case 11:      
    lcd.clear();       
    lcd.print("Paro por");       
    lcd.setCursor(0, 1);       
    lcd.print("falla y error");       
    break;     
    default:       
    lcd.clear();       
    lcd.print("Estado no");       
    lcd.setCursor(0, 1);       
    lcd.print("válido");       
    break;   
    }      
    delay(1000); // Esperar 1 segundo antes de actualizar el display LCD}
  }
