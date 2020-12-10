#include <HT1632.h>
#include <font_5x4.h>
#include <images.h>

int i = 0;
int wd;
char disp [] = "Hello, how are you?";

void setup () {
  HT1632.begin(PIN_PB3, PIN_PB4, PIN_PB5);//Change for JY-MCU-3208//
  
  wd = HT1632.getTextWidth(disp, FONT_5X4_END, FONT_5X4_HEIGHT);
}

void loop () {
  
  HT1632.renderTarget(0);//Updated for V2 library, see upgrade for details//
  HT1632.clear();
  HT1632.drawText(disp, OUT_SIZE - i, 2, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  HT1632.render();
  
  i = (i+1)%(wd + OUT_SIZE);
  
  delay(100);
}
