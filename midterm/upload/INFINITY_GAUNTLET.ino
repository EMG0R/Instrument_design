#include "I2Cdev.h"
#include "MIDIcontroller.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

byte MIDIchannel = 5;
const int switchPin = 10; //any digital pin
const int ledPin = 13;
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t butt;
#define OUTPUT_READABLE_ACCELGYRO
#define LED_PIN 13
bool blinkState = false;
MIDIswitch myInput(switchPin, 21);
void setup() {
    pinMode(ledPin, OUTPUT);

    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    Serial.begin(38400);
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    pinMode(LED_PIN, OUTPUT);
    pinMode(8, INPUT);
}

void loop() {
   if (digitalRead(8) == HIGH) {
    butt = 1;
  } 
 if (digitalRead(8) == LOW) {
    butt = 0;
  }

    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    #ifdef OUTPUT_READABLE_ACCELGYRO
        Serial.print(ax); Serial.print(" ");
        Serial.print(ay); Serial.print(" ");
        Serial.print(az); Serial.print(" ");
        Serial.print(gx); Serial.print(" ");
        Serial.print(gy); Serial.print(" ");
        Serial.println(gz); Serial.print(" ");
    #endif
    
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
    myInput.send();
    digitalWrite(ledPin, myInput.state);
    while(usbMIDI.read()){}
}