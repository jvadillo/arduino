/* ===============================================================
      Project: Aldeano 24hrs
       Author: Jon Vadillo
      Created: 08/06/2016
  Arduino IDE: 1.0.5
      Website: http://www.jonvadillo.com
  Description: .....
  ================================================================== */

/*
  Connect 5V on Arduino to VCC on Relay Module
  Connect GND on Arduino to GND on Relay Module
  Connect GND on Arduino to the Common Terminal (middle terminal) on Relay Module. */

#define RELAY1  6
#define RELAY2  7
#define LEDgreen 4 //Connect Digital Pin 4 on Arduino to Green LED (+ 330 ohm resistor) and then to "NO" terminal on relay module
#define LEDyellow 12 //Connect Digital Pin 13 on Arduino to Yellow LED (+ 330 ohm resistor) and then to "NC" terminal on relay module

int command;
int state = 0; //TODO: define states.

void setup() {
  // Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDyellow, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if(Serial.available() > 0) {

    char mode = Serial.read();
    char pin = Serial.read();  
    
    switch(mode) {
      case '1':
        digitalWrite(LEDyellow, HIGH); 
        break;
      case '0':
        digitalWrite(LEDyellow, LOW); 
        break;
    }
  }
  delay(500);
}
