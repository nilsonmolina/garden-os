#include <Arduino.h>

// ------------------------------------------
// global variables & function declarations
// ------------------------------------------
#define SERIAL_BAUD 921600 // Serial baud rate
#define SENSOR_PIN 13 // ESP32 pin GPIO13 that connects to AOUT pin of moisture sensor
#define RELAY_PIN 26 // ESP32 pin GPIO12 that connects to the relay
#define DRY_SOIL 1800 // Sensor output values above this indicate dry soil. Below this indicate wet soil.

void printWelcomeMessage();


// ------------------------------------------
// main code
// ------------------------------------------
void setup() {
  // setup the serial monitor baud rate so we can see the output
  Serial.begin(SERIAL_BAUD);

  // setup the GPIO pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // print a welcome message to the serial monitor
  printWelcomeMessage();
}

void loop() {
  // read the sensor value and print it to the serial monitor
  int dryness_value = analogRead(SENSOR_PIN);
  Serial.print("Moisture value: ");
  Serial.println(dryness_value);

  // a dryness value above 1800 indicates dry soil. Let's light up the LED to indicate wet soil.
  if (dryness_value > DRY_SOIL) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RELAY_PIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
  }

  // wait 1 second before reading the sensor again
  delay(1000);
}


// ------------------------------------------
// function definitions
// ------------------------------------------
void printWelcomeMessage() {
  Serial.println("\nsystem startup...");
  delay(random(500, 1000));
  Serial.println("\ndetecting hardware...");
  delay(random(50, 1000));
  Serial.println("\nchecking memory...");
  delay(random(50, 1000));
  Serial.println("\nchecking storage...");
  delay(random(50, 1000));
  Serial.println("\nchecking connected devices...");
  delay(random(50, 1000));
  Serial.println("\nsystem is ready to commence boot sequence...");
  delay(random(50, 250));
  Serial.println("\n-------------------------");
  Serial.print("loading gardenOS");
  for (int i = 0; i < random(3, 10); i++) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\ngardenOS initialized!");
  Serial.println("-------------------------");
}
