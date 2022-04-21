#include <LiquidCrystal_I2C.h>





LiquidCrystal_I2C lcd(0x27, 16, 2);
char data;








void setup() {
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();

  Serial.begin(9600);
  lcd.print("SAV");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {

    data = Serial.read();

    if (data == '1')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SAV traiter");
      Serial.write('1');
      delay(500);



    }
  
    else if (data == '0')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("erreur  ");
      lcd.setCursor(0,1);
      lcd.print("SAV n'existe pas");
      Serial.write('0');
      delay(500);
      // Serial.print(data);
    }

  }


}
