const int PIN_LED = 13;

const int LED_ON_TIME = 1000;
const int LED_OFF_TIME = 1000;

int ledState = LOW;
unsigned long tsLastStateChange = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  unsigned long delta = millis() - tsLastStateChange;
  switch(ledState) {
  case LOW:
    if (delta > LED_OFF_TIME) {
      ledState = HIGH;
      tsLastStateChange = millis();
    }
    break;
  case HIGH:
    if (delta > LED_ON_TIME) {
      ledState = LOW;
      tsLastStateChange = millis();
    }
    break;
  }
  digitalWrite(PIN_LED, ledState);
}
