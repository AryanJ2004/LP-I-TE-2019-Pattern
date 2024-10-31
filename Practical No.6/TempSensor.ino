char degree=176; 
const int sensor=A1;
void setup()
{
  pinMode(sensor, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop()
{
  int tmp = analogRead(sensor);
  float voltage = (tmp * 5.0)/1024;
  float milliVolt = voltage * 1000;
  
  float tmpCel =  (milliVolt-500)/10 ;
  Serial.print("Celsius: ");
  Serial.print(tmpCel);
  Serial.println(degree);
  delay(1000);
  if(tmpCel<40)
  {
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7,LOW);
    delay(1000);
  }
  else if(tmpCel>40 && tmpCel<200)
  {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }
  else if(tmpCel>200)
  {
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
  }
  else{
    digitalWrite(13,LOW);
  }
}