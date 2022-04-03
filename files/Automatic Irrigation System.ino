/* 
2- shoulder servo
A0- moisture sensor
4- water pump
8- base servo
*/

#include <Servo.h>

Servo servo_2;
Servo servo_8;
int M_Sensor = A0;

void setup()
{
  servo_2.attach(2, 500, 2500);
  pinMode(4, OUTPUT);
  servo_8.attach(8, 500, 2500);
  Serial.begin(9600);
}

void loop()
{
  servo_8.write(145);
  delay(1000);
  servo_2.write(180);
  delay(1500);
  servo_2.write(150);
  delay(1000); // Delay a little bit to improve simulation performance
  int Read1 = analogRead(M_Sensor);
float  Moisture1 = map(Read1, 1023, 0, 0, 100);
  Serial.println(Moisture1);
  delay(1000);
  servo_2.write(180);
  if (Moisture1< 6)   // for dry soil
  { 
  digitalWrite(4, HIGH);
  delay(15000); // Wait for 15000 millisecond(s)
  digitalWrite(4, LOW);
    }
   else {
     if (Moisture1>= 6 && Moisture1<=30) //for Moist Soil
    { 
     digitalWrite(4, HIGH);
     delay(10000); // Wait for 10000 millisecond(s)
     digitalWrite(4, LOW);
    }
 
     else {  // For Soggy soil:
     Serial.println("No Water Needed");
     }
  }
  Serial.println("Plant 1 done");
  delay(2000); // Wait for 2000 millisecond(s)
  
  servo_8.write(85);
  delay(1000);
  servo_2.write(180);
  delay(1500);
  servo_2.write(150);
  delay(1000); // Delay a little bit to improve simulation performance
  int Read2 = analogRead(M_Sensor);
float  Moisture2 = map(Read2, 1023, 0, 0, 100);
  Serial.println(Moisture2);
  delay(1000);
  servo_2.write(180);
 if (Moisture2< 6)   // for dry soil
  { 
  digitalWrite(4, HIGH);
  delay(15000); // Wait for 15000 millisecond(s)
  digitalWrite(4, LOW);
    }
   else {
     if (Moisture2>= 6 && Moisture2<=30) //for Moist Soil
    { 
     digitalWrite(4, HIGH);
     delay(10000); // Wait for 10000 millisecond(s)
     digitalWrite(4, LOW);
    }
 
     else {  // For Soggy soil:
     Serial.println("No Water Needed");
     }
  }
  Serial.println("Plant 2 done");
  delay(2000); // Wait for 2000 millisecond(s)
  
  servo_8.write(30);
  delay(1000);
  servo_2.write(180);
  delay(1500);
  servo_2.write(150);
  delay(1000); // Delay a little bit to improve simulation performance
  int Read3 = analogRead(M_Sensor);
float  Moisture3 = map(Read3, 1023, 0, 0, 100);
  Serial.println(Moisture3);
  delay(1000);
  servo_2.write(180);
 if (Moisture3< 6)   // for dry soil
  { 
  digitalWrite(4, HIGH);
  delay(15000); // Wait for 15000 millisecond(s)
  digitalWrite(4, LOW);
    }
   else {
     if (Moisture3>= 6 && Moisture3<=30) //for Moist Soil
    { 
     digitalWrite(4, HIGH);
     delay(10000); // Wait for 10000 millisecond(s)
     digitalWrite(4, LOW);
    }
 
     else {  // For Soggy soil:
     Serial.println("No Water Needed");
     }
  }
  Serial.println("Plant 3 done");
  delay(2000); // Wait for 2000 millisecond(s)
  
  servo_8.write(145);

  delay(21600000); // Wait for 21600000 millisecond(s), i.e. 6 hours

}
