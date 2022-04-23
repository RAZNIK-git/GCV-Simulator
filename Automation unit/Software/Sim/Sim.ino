/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardMessage
*/

#include "Keyboard.h"

int currentState=0;

void setup() {



  pinMode(12,INPUT_PULLUP); // ON button
  pinMode(13,INPUT_PULLUP); //OFF button
  pinMode(4,OUTPUT); //relay
  pinMode(6,OUTPUT); // projectors
  pinMode(5,OUTPUT); // airconditioner
  delay(4000);
 
 


}
void loop() {
  
  if  ((digitalRead(12)==LOW) && (currentState==0)){
    ON();
    currentState=1;
  }
  if  ((digitalRead(13)==LOW) && (currentState==1)){
    OFF();
    currentState=0;}

}

void OFF(){
  Keyboard.begin();  //Sign in
  delay (300);
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.release(KEY_LEFT_GUI);
  delay(200);
  Keyboard.print("cmd");

  delay(50);
  Keyboard.press(KEY_RETURN);
  delay(30);
  Keyboard.release(KEY_RETURN);
 
  delay(1000);
  Keyboard.print("shutdown /p");
  delay(50);
  Keyboard.press(KEY_RETURN);
  delay(30);
  Keyboard.release(KEY_RETURN);
  Keyboard.end();
  delay(8000);
 
}

  


void ON(){
  delay(1000);

  digitalWrite(4, HIGH);// press pc power button
  delay(400);
  digitalWrite(4, LOW);
  delay(50000); //wait 60 seconds for pc to boot up

  Keyboard.begin();  //Sign in
  delay (300);
  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.release(KEY_RETURN);
  delay (300);
  Keyboard.println("gcv");
  delay (300);
  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.release(KEY_RETURN);
  delay (4000);
  

  





  //Start wrapper
  Keyboard.press(KEY_LEFT_GUI);
  delay(500);
  Keyboard.release(KEY_LEFT_GUI);
  delay(200);
  Keyboard.print("cmd");

  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
 
  delay(1000);
  Keyboard.println("cd Desktop");
  delay(100);
  Keyboard.println("cndwrapper.exe");
  delay(100);
  delay(2000);

  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.release(KEY_LEFT_GUI);
  delay(50);
  Keyboard.println("cmd");
  delay(100);
  Keyboard.press(KEY_RETURN);
delay(100);
  Keyboard.release(KEY_RETURN);

  
  

  delay(1000);
  Keyboard.println("cd ..");
  delay(50);
  Keyboard.println("cd ..");
  delay(50);
  Keyboard.println("cd Condor2");
  delay(50);
  Keyboard.println("Condor.exe");
  delay(50);
  delay(6000);

  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.release(KEY_LEFT_GUI);
  delay(500);  

  Keyboard.println("cmd");
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  delay(1000);

  
   Keyboard.println("cd ..");
  delay(50);
  Keyboard.println("cd ..");
  delay(50);
  Keyboard.println("cd Program Files (x86)");
  delay(50);
  Keyboard.println("cd ImmersiveDisplayPRO");
  delay(50);
  Keyboard.println("ImmersiveDisplayPRO.exe");
  delay(50);
 
Keyboard.end();
  
  

  
}
