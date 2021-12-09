#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (gear icon).

char auth[] = "Paste your Auth Token Here";   

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Wifi SSID"; //Enter your Wifi User Name
char pass[] = "Wifi password"; //Enter your Wifi Password


Servo waist;
Servo shoulder;
Servo elbow;

Servo wristroll;
Servo wristpitch;
Servo Gripper;


//V0,V1..are virtual pins 
BLYNK_WRITE(V0)
{
  waist.write(param.asInt());//param.asInt is a function of blynk library which returns integer parameter from the blynk app.
}

BLYNK_WRITE(V1)
{
  shoulder.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  elbow.write(param.asInt());
}

BLYNK_WRITE(V3)
{
  wristroll.write(param.asInt());
}


BLYNK_WRITE(V4)
{
  wristpitch.write(param.asInt());
}


BLYNK_WRITE(V5)
{
  Gripper.write(param.asInt());
}



void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  waist.attach(D0);
  shoulder.attach(D4);
  elbow.attach(D5);

  wristroll.attach(D6);
  wristpitch.attach(D7);
  Gripper.attach(D1);
}
 
void loop()
{
  Blynk.run();
}
