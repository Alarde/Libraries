

#include "ACDAuth.h"

#pragma region -= Constructor/Destructor =-
RS  Enable  D4  D5  D6  D7
ACDAuth::ACDAuth(int lcdRS, int lcdEnable, int lcdD4, int lcdD5, int lcdD6, int lcdD7)
    : _lcd(lcdRS, lcdEnable, lcdD4, lcdD5, lcdD6, lcdD7)
{
        
}

#pragma endregion


void correctPIN() // do this if correct PIN entered
{
  //Serial.print("* Correct PIN *");
  //delay(1000);
  //Serial.print("  Enter PIN...");
  //Serial.println();
  fps.Open();
  fps.SetLED(true);
  checkFinger();
}

void checkFinger(){
  int tries=0;
  boolean success=false;
  //Serial.println("Please press finger");
  LiquidCrystal _lcd(21, 20, 19, 18, 17, 16);
  _lcd.clear();
  _lcd.setCursor(0,0);
  _lcd.print("Ponga el dedo en");
  _lcd.setCursor(0,1);
  _lcd.print("el lector");
  do{
  // Identify fingerprint test
	if (fps.IsPressFinger())
	{
		fps.CaptureFinger(false);
		int id = fps.Identify1_N();
		if (id<200)
		{
			
			//Serial.print("Verified ID:");
      switch(id){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
          welcomeHome(1);
          break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
          welcomeHome(2);
          break;
        default:
          _lcd.setCursor(5,1);
          _lcd.clear();
          _lcd.setCursor(0,0);
          _lcd.print("Identificador ");
          _lcd.setCursor(0,1);
          Serial.print(id);
          _lcd.print("inconsistente");
        break;
     }
     
			//Serial.println(id);
     delay(3500);
      success=true;
		}
		else
		{
      _lcd.clear();
      _lcd.setCursor(0,0);
		  _lcd.print("Huella no");
      _lcd.setCursor(0,1);
      _lcd.print("encontrada...");
      delay(2500);
      tries++;
      if(tries==5){
        //Serial.println("Please press finger");
        break;
      }else{
        _lcd.clear();
        _lcd.setCursor(0,0);
        _lcd.print("Ponga el dedo en");
        _lcd.setCursor(0,1);
        _lcd.print("el lector");
      }
		}
	}
	delay(100);
  }while (success!=true);
  fps.Close();
  fps.SetLED(false);
  Resetea();
}

void welcomeHome (int id){
  // definicion del nuevo caracter
      byte love[8] = {
          B00000,
          B00000,
          B11011,
          B11111,
          B11111,
          B01110,
          B00100,
          B00000
      };
      _lcd.createChar(0, love);
  switch(id){
    case 1:
      _lcd.clear();
      _lcd.setCursor(0,0);
      _lcd.print("Bienvenido a");
      _lcd.setCursor(0,1);
      Serial.print(id);
      _lcd.print("casa Alejandro");
      //Abriremos la puerta mediante 
      break;
    case 2:
      _lcd.clear();
      _lcd.setCursor(0,0);
      _lcd.print("Bienvenida a");
      _lcd.setCursor(0,1);
      Serial.print(id);
      _lcd.print("casa reina mia ");
      _lcd.write(byte(0));
      break;
    default:
      _lcd.clear();
      _lcd.setCursor(0,0);
      _lcd.print("Unespected error.");
      break;
  }
  
}