#ifndef Keyboard_h
#define Keyboard_h

#define KEYBOARDLIBVERSION "1.0.0"

#include <inttypes.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#define KEY_LEFT_CTRL	0x01
#define KEY_LEFT_SHIFT	0x02
#define KEY_LEFT_ALT    0x04
#define KEY_LEFT_GUI    0x08
#define KEY_RIGHT_CTRL	0x10
#define KEY_RIGHT_SHIFT	0x20
#define KEY_RIGHT_ALT   0x40
#define KEY_RIGHT_GUI   0x80
#define KEY_RIGHT_ARROW 0x4F
#define KEY_LEFT_ARROW  0x50
#define KEY_DOWN_ARROW  0x51
#define KEY_UP_ARROW    0x52
#define KEY_ESC         0x29T
#define KEY_F1          0x3A
#define KEY_F2          0x3B
#define KEY_F3          0x3C
#define KEY_F4          0x3D
#define KEY_F5          0x3E
#define KEY_F6          0x3F
#define KEY_F7          0x40
#define KEY_F8          0x41
#define KEY_F9          0x42
#define KEY_F10         0x43
#define KEY_F11         0x44
#define KEY_F12         0x45
#define KEY_PRTSCR      0x46
#define KEY_SCRLK       0x47
#define KEY_PAUSE       0x48
#define KEY_DEL         0x4C
#define KEY_INS         0x49
#define KEY_END         0x4D
#define KEY_HOME        0x4A
#define KEY_PGDN        0x4E
#define KEY_PGUP        0x4B
#define KEY_BACKSPC     0x2A
#define KEY_TAB         0x2B
#define KEY_ENTER       0x28
#define KEY_SPC         0x2C
#define KEY_MUTE        0x7F
#define KEY_VOL_UP      0x80
#define KEY_VOL_DOWN    0x81
#define KEY_NONE        0x37


class Keyboard
{
   private:
      uint8_t buf[8];	/* Keyboard report buffer */

   public:
      Keyboard(void);
      void  PRESS(void);
      void  DELAY(unsigned t);

      void  ALT(char *c);
      void  ALT_SPACE(void);
      void  ALT_F2(void);
      void  ALT_F4(void);

      void  CTRL_ALT(char *c);
      void  CTRL_ALT_DEL(void);
      void  CTRL_ALT_ARROW(char *c);

      void  WINDOWS(char *c);

      void  ENTER(void);
      void  TAB(void);
      void  PRINT(void);
      void  BACKSPACE(void);

      void  STRING(char *txt);
};

#endif
