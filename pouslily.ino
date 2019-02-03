#include <Wire.h>  // Include Wire if you're using I2C
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "define.h"


void setup() {

  Serial.begin(9600);
  pinMode(pinValve1, OUTPUT);
  pinMode(pinValve2, OUTPUT);
  pinMode(pinPump, OUTPUT);
  pinMode(pinFan, OUTPUT);
  setup_buttons();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(2);//2 : 10 x 4 char
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  //display.println("1234567890");
  display.println(" pousLily ");
  display.println("    V1    ");
  display.display();
  delay(2000);
}

// executee en boucle

void loop() {


  check_buttons();
  show_menu();
  routine();
  
  if (justpressed[0])
  {
    select--;
    if (select < 1)
    {
      if (id_menu == ID_PRINC)
        select = size_m_princ;
      if (id_menu == ID_MANU)
        select = size_m_manu;
    }
  }
  if (justpressed[1])
  {
    select++;
    if (id_menu == ID_PRINC && select > size_m_princ)
      select = 1;
    if (id_menu == ID_MANU && select > size_m_manu)
      select = 1;
  }
  if (justpressed[2])
  {
    enter();
  }

  delay(5);
}


void update_actionneurs()
{
  if (etat_actionneurs[0]) //valve 1
  {
    digitalWrite(pinValve1, HIGH);
  } else
  {
    digitalWrite(pinValve1, LOW);
  }

  if (etat_actionneurs[1]) //valve 2
  {
    digitalWrite(pinValve2, HIGH);
  } else
  {
    digitalWrite(pinValve2, LOW);
  }

  if (etat_actionneurs[2]) //Fan
  {
    digitalWrite(pinFan, HIGH);
  } else
  {
    digitalWrite(pinFan, LOW);
  }

  if (etat_actionneurs[3]) //pump
  {
    digitalWrite(pinPump, HIGH);
  } else
  {
    digitalWrite(pinPump, LOW);
  }

}



