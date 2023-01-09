/******************************************
 * Meaxy Kusama
 * PS/2 to x68000 converter
 * MDL
 *****************************************/


#include "PS2Mouse.h"
#include "PS2Keyboard.h"

#define DATA_PIN 7
#define CLOCK_PIN 2
#define DataPin 8
#define IRQpin 3

PS2Keyboard keyboard;
PS2Mouse mouse(CLOCK_PIN, DATA_PIN);

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Mouse & Keyboard test:");
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else {
      // otherwise, just print all normal characters
      Serial.print(c);
    }
	
	
  }
  
  MouseData data = mouse.readData();
  
  Serial.print(data.status);
  Serial.print("\tPX:");
  Serial.print(data.position.x);
  Serial.print("\tPY:");
  Serial.print(data.position.y);
  Serial.println();
  delay(20);
  
}
