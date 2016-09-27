// Title: Windows Hello World
// Author: Rennan Cockles

#include <Keyboard.h>

Keyboard kb;


void setup()
{  
    Serial.begin(9600);  
    delay(1000);
}


void loop()
{
    kb.WINDOWS("r");
    kb.DELAY(1000);    
    kb.STRING("notepad");  
    kb.ENTER();
    kb.DELAY(1500);   
    kb.STRING("Hello World!!");
    kb.ENTER();
    
    kb.DELAY(300000); 
}



