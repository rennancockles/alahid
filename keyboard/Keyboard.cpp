#include "Keyboard.h"

#if ARDUINO >= 100
    #include "Arduino.h"
#else
extern "C" {
    #include "WConstants.h"
}
#endif

Keyboard::Keyboard(void)
{
    buf[8] = { 0 };
}

void Keyboard::PRESS(void){
    Serial.write(buf, 8);	// Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
}

void Keyboard::DELAY(unsigned t){
    delay(t);
}


// ALT + *
void Keyboard::ALT(char *c){
    buf[0] = KEY_LEFT_ALT;
    buf[2] = c[0] - 'a' + 4;
    PRESS();
}

void Keyboard::ALT_SPACE(void){
    buf[0] = KEY_LEFT_ALT;
    buf[2] = KEY_SPC;
    PRESS();
}

void Keyboard::ALT_F2(void){
    buf[0] = KEY_LEFT_ALT;
    buf[2] = KEY_F2;
    PRESS();
}

void Keyboard::ALT_F4(void){
    buf[0] = KEY_LEFT_ALT;
    buf[2] = KEY_F4;
    PRESS();
}


// CTRL + ALT + *
void Keyboard::CTRL_ALT(char *c){
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    buf[2] = c[0] - 'a' + 4;
    PRESS();
}

void Keyboard::CTRL_ALT_DEL(void){
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    buf[2] = 0x63;
    PRESS();
}

void Keyboard::CTRL_ALT_ARROW(char *c){
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    switch (c[0]) {
        case 'r':
    	    buf[2] = 0x4F;
            break;
        case 'l':
    	    buf[2] = 0x50;
            break;
        case 'd':
    	    buf[2] = 0x51;
            break;
        case 'u':
    	    buf[2] = 0x52;
            break;
        default:
    	    buf[2] = 0x37;
            break;
    }
    PRESS();
}


// WINDOWS + ""
void Keyboard::WINDOWS(char *c){
    buf[0] = KEY_LEFT_GUI;

    if(c[0] >= 'a' && c[0] <= 'z'){
        buf[2] = c[0] - 'a' + 4;
    }
    PRESS();
}


// Single Keys
void Keyboard::ENTER(void){
    buf[2] = KEY_ENTER;
    PRESS();
}

void Keyboard::TAB(void){
    buf[2] = KEY_TAB;
    PRESS();
}

void Keyboard::PRINT(void){
    buf[2] = KEY_PRTSCR;
    PRESS();
}

void Keyboard::BACKSPACE(void){
    buf[2] = KEY_BACKSPC;
    PRESS();
}

// String
void Keyboard::STRING(char *txt){
    while(*txt){
        if(*txt >= 'a' && *txt <= 'z'){
            buf[2] = *txt - 'a' + 4;
        }
        else if(*txt >= 'A' && *txt <= 'Z'){
            buf[0] = KEY_LEFT_SHIFT;

            buf[2] = *txt - 'A' + 4;
        }
        else if(*txt >= '0' && *txt <= '9'){
            if(*txt == '0'){
                buf[2] = *txt - 9;
            }
            else{
                buf[2] = *txt - 19;
            }
        }
        else if(*txt == ' '){
            buf[2] = KEY_SPC;
        }
        else if(*txt == '&'){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x24;
        }
        else if(*txt == '>'){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = KEY_NONE;
        }
        else if(*txt == '<'){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x36;
        }
        else if(*txt == '|'){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x64;
        }
        else if(*txt == '/'){
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x14;
        }
        else if(*txt == '\\'){
            buf[2] = 0x34;
        }
        else if(*txt == ';'){
            buf[2] = 0x38;
        }
        else if(*txt == '('){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x26;
        }
        else if(*txt == ')'){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = 0x27;
        }
        else if(*txt == '{'){
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x24;
        }
        else if(*txt == '}'){
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x27;
        }
        else if(*txt == '['){
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x25;
        }
        else if(*txt == ']'){
            buf[0] = KEY_RIGHT_ALT;
            buf[2] = 0x26;
        }
        else if(*txt == '#'){
            buf[0] = KEY_LEFT_SHIFT;
            buf[2] = '3' - 19;
        }
        else if(*txt == '-'){
            buf[2] = 0x2D;
        }
        else if(*txt == '='){
            buf[2] = 0x2E;
        }
        else if(*txt == '.'){
            buf[2] = 0x37;
        }
        else if(*txt == ','){
            buf[2] = 0x36;
        }
        else{
            buf[2] = KEY_NONE;
        }
        PRESS();
        txt++;
    }
}
