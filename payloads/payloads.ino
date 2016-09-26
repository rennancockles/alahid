#include <Keyboard.h>

Keyboard kb;


void setup()
{  
    Serial.begin(9600);  
    delay(1000);
}


void loop()
{
    kb.CTRL_ALT_ARROW("d");
    
    kb.DELAY(300000); 
}



