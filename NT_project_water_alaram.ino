
//made by AZM999
//version 1.0

// take distance from sensor
//height of tank to be somethn and take that distance to be 100%
//calculate percentage by distance and show that to lcd with percentage.
//


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 3;
const int echoPin = 4;
const int buzzerPin = 9;
const int tank_height = 150 ;
float perc = 0;

// defines variables
long duration;
int distance;

//setup loop
void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);     // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);      // Sets the echoPin as an Inpu
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);           // Starts the serial communication
}

//repeat loop
void loop() 
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  perc = (distance * (0.6666666666666667));
  
 
  Serial.print("Distance from the object = ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(perc,1);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance=");
  lcd.setCursor(9,0);
  lcd.print(distance);
  lcd.setCursor(0,1);
  lcd.print(perc);
  lcd.setCursor(4,1);
  lcd.print(" % filled");
  

delay(500);
}


//end of program
