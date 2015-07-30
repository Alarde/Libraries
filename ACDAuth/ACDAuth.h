/*
|| @file ACDAuth.h
|| @version 0.1
|| @author Alejandro Arguelles
|| @contact arguelles04@gmail.com
||
|| @description
|| | This library provides the authentication from an external interface.
|| #
||
*/

#infdef ACDAUTH_H
#define ACDAUTH_H

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "Keypad.h"
#include "FPS_GT511C3.h" // Finger print library
#include "SoftwareSerial.h"; //Required to finger print library

typedef enum {OWNER, FAMILY, VISITOR, UNKNOWN} Users;


// Del id 0 al id 4 -- Alejandro
// Del id 5 al 9 -- Cristina

class ACDAuth{
    
    public:
        void checkId();
        
    private:
        LiquidCristal _lcd;
        
};
#endif