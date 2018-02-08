
//******************MIDI*************//
#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

MIDI_CREATE_DEFAULT_INSTANCE();

//buttons
#define ringLED 12
#define ringSwitch 13

//STATES
boolean octDwn = LOW;
boolean octUp = LOW;
boolean scaleSwitch = LOW;

int leftPot = A4,
    rightPot = A3,
    sidePot = A2,
    lPotVal = 0,
    lPotLastVal = 0,
    rPotVal = 0,
    rPotLastVal = 0,
    sPotVal = 0,
    sPotLastVal = 0;

//************KEYPAD******************//
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'#', '0', '*'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8}; //connect to the column pinouts of the keypad

Keypad numberPad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  //Serial.begin(9600);
  MIDI.begin(1);
  pinMode(octUp, INPUT);
  pinMode(octDwn, INPUT);
  pinMode(scaleSwitch, INPUT);
}

void loop() {


  /////////////////POT DETECTION AND TRANSMISSION///////////////
  lPotVal = analogRead(leftPot) / 8;
  rPotVal =  analogRead(rightPot) / 8;
  sPotVal = analogRead(sidePot) / 8;

  if (lPotVal != lPotLastVal) {
    potMidi(85, lPotVal);
    lPotLastVal = lPotVal;
    delay(10);
    //Serial.print("left Pot: ");
    //Serial.println(lPotVal);
  }
  if (rPotVal != rPotLastVal) {
    potMidi(86, rPotVal);
    rPotLastVal = rPotVal;
    delay(10);
    //Serial.print("Right Pot: ");
    //Serial.println(rPotVal);
  }

  if (sPotVal != sPotLastVal) {
    potMidi(85, sPotVal);
    sPotLastVal = sPotVal;
    delay(10);
    //Serial.print("Side Pot: ");
    //Serial.println(sPotVal);
  }

  ////////////////////////////KEYPAD READING AND TRANSMISSION
  char key = numberPad.getKey();

  if (scaleSwitch == HIGH) {
    switch (numberPad.getState()) {
      case PRESSED:
        switch (key) {
          case '1':
            MIDI.sendNoteOn(60, 127, 1);
            delay(500);
            MIDI.sendNoteOff(60, 0, 1);
            Serial.println("sent C");
            break;
          case '2':
            notes(61);
            //Serial.println("sent Db");
            break;
          case '3':
            notes(62);
            //Serial.println("sent D");
            break;
          case '4':
            notes(63);
            //Serial.println("sent Eb");
            break;
          case '5':
            notes(64);
            //Serial.println("sent E");
            break;
          case '6':
            notes(65);
            //Serial.println("Sent F");
            break;
          case '7':
            notes(66);
            //Serial.println("sent F#");
            break;
          case '8':
            notes(67);
            //Serial.println("sent G");
            break;
          case '9':
            notes(68);
            //Serial.print("sent Ab");
            break;
          case '*':
            notes(69);
            //Serial.print("sent A");
            break;
          case '0':
            notes(70);
            //Serial.print("sent Bb");
            break;
          case '#':
            notes(71);
            //Serial.print("sent B");
            break;
        }
    }
  }
  else {
    switch (numberPad.getState()) {
      case PRESSED:
        switch (key) {
          case '1':
            MIDI.sendNoteOn(60, 127, 1);
            delay(500);
            MIDI.sendNoteOff(60, 0, 1);
            //Serial.println("sent C");
            break;
          case '2':
            notes(62);
            //Serial.println("sent D");
            break;
          case '3':
            notes(63);
            //Serial.println("sent D#");
            break;
          case '4':
            notes(64);
            //Serial.println("sent E");
          case '5':
            notes(67);
            //Serial.println("sent G");
            break;
          case '6':
            notes(69);
            //Serial.println("Sent A");
            break;
          case '7':
            notes(72);
            //Serial.println("sent C(oct)");
            break;
          case '8':
            notes(74);
            //Serial.println("sent D(oct)");
            break;
          case '9':
            notes(75);
            //Serial.print("sent Eb(oct)");
            break;
          case '*':
            notes(76);
            //Serial.print("sent E(oct)");
            break;
          case '0':
            notes(79);
            //Serial.print("sent G(oct)");
            break;
          case '#':
            notes(81);
            //Serial.print("sent A(oct)");
            break;
        }
    }
  }
}
// if (key != NO_KEY) {
//   Serial.println(key);
// }

void notes(int pitch) {
  if (octUp == HIGH) {
    pitch = pitch + 12;
  }
  else if (octDwn == HIGH) {
    pitch = pitch - 12;
  }
  MIDI.sendNoteOn(pitch, 127, 1);
  delay(1000);
  MIDI.sendNoteOff(pitch, 127, 1);

}

void potMidi(int CC, int val) {
  MIDI.sendControlChange(CC, val, 1);
}

