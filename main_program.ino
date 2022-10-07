// ---------------------------------------------------------------- //
// Al Azhar Science Competition
// Code By Student SMPN 11 KOTA BEKASI: Argia M. Ahya 
// youtube: Giadev
// Instagram: @bukan_giadev
// WA: 085777849958
// Email: argiamahya1602@gmail.com
// ---------------------------------------------------------------- //
#include <Servo.h>

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// Button Pin
int button = 4;
int buttonState = 0;

// Servo Pin
Servo traficTranspo;
Servo crossWalk;

// RGB LED 1
int ledRed1 = 10;
int ledGreen1 = 11;

// RGB LED 2
int ledRed2 = 7;
int ledGreen2 = 6;

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

float distanceSensor(){
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(button, INPUT); // Sets the button pin as an INPUT
  
  // LED RGB 1
  pinMode(ledRed1, OUTPUT);
  pinMode(ledGreen1, OUTPUT);

  // LED RGB 2
  pinMode(ledRed2, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
  
  // Servo
  traficTranspo.attach(8);
  crossWalk.attach(9);
  
  // digitalWrite(red1, HIGH);
  // digitalWrite(green1, LOW);
  // delay(1000);
  // digitalWrite(red1, LOW);
  // digitalWrite(green1, HIGH);
  // delay(1000);
  // digitalWrite(red1, HIGH);
  // digitalWrite(green1, LOW);



  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

  
}

void loop() {
  // distanceSensor();

  buttonState = 0;

  buttonState = digitalRead(button);

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.0343 / 2; // Speed of sound wave divided by 2 (go and back)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println( "cm");
  
  // Serial.println(buttonState);
  Serial.println(buttonState || distance <= 8 && distance >= 4);
  if(buttonState == HIGH || distance <= 8 && distance > 3) {

    // digitalWrite(ledRed1, HIGH);

    analogWrite(ledGreen1, 255);
    analogWrite(ledRed1, 255);
    delay(500);
    analogWrite(ledGreen1, 0);
    delay(500);
    analogWrite(ledGreen1, 255);
    delay(500);
    analogWrite(ledGreen1, 0);
    delay(500);
    analogWrite(ledGreen1, 255);
    delay(500);
    analogWrite(ledGreen1, 0);
    delay(500);
    analogWrite(ledGreen1, 255);

    traficTranspo.write(0);
    crossWalk.write(90);

    analogWrite(ledRed1, 0);
    analogWrite(ledGreen2, 0);
    analogWrite(ledRed2, 255);
    analogWrite(ledGreen1, 255);

    delay(5000);
  } else {

    crossWalk.write(0);
    traficTranspo.write(85);


    analogWrite(ledRed2, 0);
    analogWrite(ledGreen1, 0);
    analogWrite(ledRed1, 255);
    analogWrite(ledGreen2, 255);

  	

  }

  
}