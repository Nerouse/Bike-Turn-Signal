/*
AUTHOR: Nelson Lim


 */
#include <Wire.h>
#include <toneAC.h>
#include "pitches.h"
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731_Wing ledmatrix = Adafruit_IS31FL3731_Wing();

//Pins For Joystick
int VRx = A0;
int VRy = A1;
int SW = 2;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

//Pin for HeadLight LED
int mainLED = 11;

//LED MATRIX sweeping pattern
uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

//"Take Me On" Melody
int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};
int durations[] = {
8, 8, 8, 4, 4, 4,
4, 8, 8, 8, 8, 8,
8, 8, 8, 4, 4, 4,
4, 8, 8, 8, 8, 8
};
int songLength = sizeof(melody)/sizeof(melody[0]);


void setup() {
  Serial.begin(9600);

  Serial.println("ISSI swirl test");

  if (! ledmatrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 found!");

  pinMode(mainLED,OUTPUT);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

}

//PLAY TAKE ON ME
void buzz(){
  for (int thisNote = 0; thisNote < songLength; thisNote++){
    int duration = 1000/ durations[thisNote];
    toneAC( melody[thisNote], duration);
    int pause = duration * 1.3;
    delay(pause);
    noToneAC();
  }
}

void loop() {
  //READ AND MAP ANALOG STICK
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  int counter = 0;

  //Joystick netural
  if (mapX <= 0 && mapY <= 0) {
    for (uint8_t incr = 0; incr < 24; incr++)
      for (uint8_t x = 0; x < 16; x++)
        for (uint8_t y = 0; y < 9; y++)
          ledmatrix.drawPixel(x, y, sweep[(x+y+incr)%24]);
    delay(20);  
  }

  //Forward on analog stick
 if(mapX <= 0 && mapY == 512){
    buzz();
  }
 //Select button on analog stick
 if(SW_state == 0){
    int state = digitalRead(mainLED);
    if(state == HIGH){
      digitalWrite(mainLED,LOW);
      }
    else{
      digitalWrite(mainLED,HIGH);
      }
    
  }
  //Joystick Right
  if (mapX == 512 && mapY < 0) {
    counter = 6;
    while (counter > 0) {
      for (int x = 0; x <= 15; x ++) {
        ledmatrix.drawPixel(x, 0, 255);
        ledmatrix.drawPixel(x, 1, 255);
        ledmatrix.drawPixel(x, 2, 255);
        ledmatrix.drawPixel(x, 3, 255);
        ledmatrix.drawPixel(x, 4, 255);
        ledmatrix.drawPixel(x, 5, 255);
        ledmatrix.drawPixel(x, 6, 255);
        delay(20);
      }
      for (int x = 0; x <= 15; x ++) {
        ledmatrix.drawPixel(x, 0, 0);
        ledmatrix.drawPixel(x, 1, 0);
        ledmatrix.drawPixel(x, 2, 0);
        ledmatrix.drawPixel(x, 3, 0);
        ledmatrix.drawPixel(x, 4, 0);
        ledmatrix.drawPixel(x, 5, 0);
        ledmatrix.drawPixel(x, 6, 0);
        delay(10);
      }
      counter--;
    }
  }
  //Joystick Left
  if (mapX == -512 && mapY < 0) {
    counter = 6;
    while (counter > 0) {
      for (int x = 15; x >= 0; x --) {
        ledmatrix.drawPixel(x, 0, 255);
        ledmatrix.drawPixel(x, 1, 255);
        ledmatrix.drawPixel(x, 2, 255);
        ledmatrix.drawPixel(x, 3, 255);
        ledmatrix.drawPixel(x, 4, 255);
        ledmatrix.drawPixel(x, 5, 255);
        ledmatrix.drawPixel(x, 6, 255);
        delay(20);
      }
      for (int x = 15; x >= 0; x --) {
        ledmatrix.drawPixel(x, 0, 0);
        ledmatrix.drawPixel(x, 1, 0);
        ledmatrix.drawPixel(x, 2, 0);
        ledmatrix.drawPixel(x, 3, 0);
        ledmatrix.drawPixel(x, 4, 0);
        ledmatrix.drawPixel(x, 5, 0);
        ledmatrix.drawPixel(x, 6, 0);
        delay(10);
      }
      counter--;
    }
  }
  //Joystick down
  if (mapX < 0 && mapY == -512) {
    counter = 15;
    while (counter > 0) {
      for (int x = 15; x >= 0; x --) {
        ledmatrix.drawPixel(x, 0, 255);
        ledmatrix.drawPixel(x, 1, 255);
        ledmatrix.drawPixel(x, 2, 255);
        ledmatrix.drawPixel(x, 3, 255);
        ledmatrix.drawPixel(x, 4, 255);
        ledmatrix.drawPixel(x, 5, 255);
        ledmatrix.drawPixel(x, 6, 255);
      }
      for (int x = 15; x >= 0; x --) {
        ledmatrix.drawPixel(x, 0, 0);
        ledmatrix.drawPixel(x, 1, 0);
        ledmatrix.drawPixel(x, 2, 0);
        ledmatrix.drawPixel(x, 3, 0);
        ledmatrix.drawPixel(x, 4, 0);
        ledmatrix.drawPixel(x, 5, 0);
        ledmatrix.drawPixel(x, 6, 0);
      }
      delay(20);
      counter--;
   }
  }
  delay(100);
}

//CREDITS:
// Take On Me  : https://create.arduino.cc/projecthub/GeneralSpud/passive-buzzer-song-take-on-me-by-a-ha-0f04a8
// Pitches.h   : https://gist.github.com/mikeputnam/2820675 
// LED Matrix  : https://learn.adafruit.com/adafruit-15x7-7x15-charlieplex-led-matrix-charliewing-featherwing/library-reference
// ToneAC  : https://playground.arduino.cc/Code/ToneAC/
