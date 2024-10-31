int IR_remote = 0;

void setup(){
  pinMode(13, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  IR_remote =digitalRead(5);
  if(IR_remote==LOW){
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }
  else{
    digitalWrite(13,LOW);
  }
}