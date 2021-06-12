#include <Arduino.h>
#include "..\.pio\libdeps\nanoatmega328\Low-Power\LowPower.h"

void ISR_P2(void);
const byte interruptPin = 2;
const byte wisher_pin = 3;
volatile byte state = false;

//const int wakeUpPin = 3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP  );
  pinMode(wisher_pin, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_P2, CHANGE);
}

void ISR_P2() {
  state = HIGH;
}

void loop() {
  //  static int x = 0;
    static int y = 0;

  attachInterrupt(0, ISR_P2, CHANGE);
 LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);  


/* delay(500);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.println("");
  Serial.print("Normal ");
  Serial.print(x);
  x = x + 1 ;
 */


  if ( state ) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Serial.println("");
    Serial.println("Wechsel ");
    Serial.print(y);
    y = y + 1 ;

    digitalWrite(wisher_pin, HIGH);
    delay(300);
    digitalWrite(wisher_pin, LOW);
    state = LOW;
  }

}
