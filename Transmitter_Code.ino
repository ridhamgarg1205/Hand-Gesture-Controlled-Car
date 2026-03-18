//Transmitter Code

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

const int LED = 2;
const int BUTTON = 3;

bool TX_FLAG = false;

int count = 0;

bool buttonState = HIGH;       // debounced state
bool lastReading = HIGH;       // last raw reading
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 25;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); // External pull-up assumed

  while (!radio.begin()) {
    Serial.println("NRF24L01 Not Connected");
    delay(1000);
  }

  Serial.println("Connected to NRF24L01");
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  bool reading = digitalRead(BUTTON);

  // Check for state change
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  // If stable for debounceDelay time, accept the new state
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // On falling edge (press)
      if (buttonState == LOW) {
        TX_FLAG = !TX_FLAG;
        Serial.println(TX_FLAG ? "📡 Communication Started" : "🛑 Communication Stopped");
      }
    }
  }

  lastReading = reading;

   if (TX_FLAG) {
    digitalWrite(LED, HIGH);
    if (millis() - lastSendTime > sendInterval) {
      lastSendTime = millis();
      String text = String(count);
      radio.write(text.c_str(), text.length() + 1);
      Serial.println("Sent: " + text);
      count++;
    }
  } else {
    digitalWrite(LED, LOW);
    static unsigned long lastMsgTime = 0;
    if (millis() - lastMsgTime > 400) {
      Serial.println("Press Button to start communication");
      lastMsgTime = millis();
    }
  }
}