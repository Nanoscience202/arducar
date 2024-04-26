#include <Arduino.h>
#include <SoftwareSerial.h>

const int rx = 2; // connected to TXD
const int tx = 3; // connected to RXD
const int forwardPin = 12;
const int backwardPin = 11;
const int leftPin = 13;
const int rightPin = 10;

// (main) MH10-9 address: 6C79B8B73BB9
// (receiver) HM10-5 addr: 6C79B8B73EF9

// set rec to peripherial mode (no command)
// configure main:
// AT+IMME1
// AT+ROLE1
// AT+CON6C79B8B73EF9

SoftwareSerial bt(rx, tx);

void setup() {
  pinMode(forwardPin, INPUT);
  pinMode(backwardPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);

  bt.begin(9600);

  bt.print("AT+IMME0");
  delay(400);
  bt.print("AT+ROLE1");
  delay(400);
  bt.print("AT+CON6C79B8B73EF9");
  delay(400);
}

void loop() {

  if (digitalRead(forwardPin) == HIGH) {
    bt.write('1');
  } else if (digitalRead(backwardPin) == HIGH) {
    bt.write('0');
  } else if (digitalRead(leftPin) == HIGH) {
    bt.write('3');
  } else if (digitalRead(rightPin) == HIGH) {
    bt.write('2');
  } else {
    bt.write('4');
  }
}
