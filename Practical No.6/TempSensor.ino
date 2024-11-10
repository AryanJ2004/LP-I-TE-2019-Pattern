int tempPin = A0;   
int val;             
float v;             
float cel;           
int ledPin = 7;      

void setup() {
  pinMode(ledPin, OUTPUT);  
  Serial.begin(9600);       
}

void loop() {
  val = analogRead(tempPin);  
  v = val * (5.0 / 1023.0);   
  cel = (v - 0.5) * 100;      
  Serial.print("TEMPERATURE: ");
  Serial.print(cel);
  Serial.println(" C");

  if (cel > 50) {
    digitalWrite(ledPin, HIGH);  
    delay(1000);                  
    digitalWrite(ledPin, LOW);   
    delay(1000);               
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
