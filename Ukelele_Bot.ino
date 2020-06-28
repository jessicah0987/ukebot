#include <Servo.h>

//Servo s1, s2, s3, s4; // Servos for fret pads
Servo servos[4];

/*
 * NB: F servo also uses A servo.
 */

int PAD_DOWN = 150; // Servo position for pressing down
int PAD_UP = 0; // Position for letting up

//plays "Don't Stop Believing"
char song[] = "CGAFCGAFCGAFCGAFCCGAFCGCGACGAFCGAFCGAFCGACGAFCFGCGACGCGFCGCGAFCG";
int tempo = 128;

void setup() {
  Serial.begin(9600);
  
  // Initialize servos
  servos[0].attach(3);
  servos[1].attach(5);
  servos[2].attach(6);
  servos[3].attach(9);

  
  
  //controls strummer wheel motor
  bool STRUMMER = false;
  
  // Loop thru song
  for (char c : song) {
    STRUMMER = true;

    // Set appropriate frets
    switch (c) {
      case 'C': servos[0].write(PAD_DOWN);
                Serial.println("C");
                break;

      case 'G': servos[1].write(PAD_DOWN);
                Serial.println("G");
                break;

      case 'A': servos[2].write(PAD_DOWN);
                Serial.println("A");
                break;

      case 'F': servos[2].write(PAD_DOWN);
                servos[3].write(PAD_DOWN);
                Serial.println("F");
                break;

      default:  Serial.println("default");
                break;
    }

    // Strum
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
    delay((60000 / tempo) - 500);
    resetServosPos();
  }
  
}

void resetServosPos() {
  for (Servo s : servos) {
    s.write(PAD_UP);
  }
}

void loop() { 
  
}
