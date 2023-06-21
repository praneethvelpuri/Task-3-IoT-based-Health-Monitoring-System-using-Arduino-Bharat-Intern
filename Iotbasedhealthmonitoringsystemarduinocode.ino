#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// Define the pins for the sensors
const int bloodPressurePin = A0;
const int bloodSugarPin = A1;
const int heartRatePin = A2;

// Define the pins for the LCD display
const int rsPin = 12;
const int enPin = 11;
const int d4Pin = 10;
const int d5Pin = 9;
const int d6Pin = 8;
const int d7Pin = 7;

// Create a LiquidCrystal object
LiquidCrystal lcd(rsPin, enPin, d4Pin, d5Pin, d6Pin, d7Pin);

// Create a SoftwareSerial object
SoftwareSerial serial(2, 3);

// Initialize the sensors
void setup() {
  pinMode(bloodPressurePin, INPUT);
  pinMode(bloodSugarPin, INPUT);
  pinMode(heartRatePin, INPUT);

  // Initialize the LCD display
  lcd.begin(16, 2);

  // Initialize the SoftwareSerial object
  serial.begin(9600);
}

// Read the sensor values and send the data to the cloud
void loop() {
  int bloodPressure = analogRead(bloodPressurePin);
  int bloodSugar = analogRead(bloodSugarPin);
  int heartRate = analogRead(heartRatePin);

  // Send the data to the cloud
  serial.print(bloodPressure);
  serial.print(",");
  serial.print(bloodSugar);
  serial.print(",");
  serial.print(heartRate);
  serial.print("\n");

  // Update the LCD display
  lcd.setCursor(0, 0);
  lcd.print("Blood Pressure: ");
  lcd.print(bloodPressure);
  lcd.setCursor(0, 1);
  lcd.print("Blood Sugar: ");
  lcd.print(bloodSugar);
  lcd.setCursor(8, 0);
  lcd.print("Heart Rate: ");
  lcd.print(heartRate);
}
