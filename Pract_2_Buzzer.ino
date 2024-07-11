#include <dht11.h>
const int buzzer = 9;
#define DHT11PIN 4

dht11 DHT11;

void  setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);
  if(DHT11.temperature>20)
  {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound... 
    delay(1000); 
  }

}
