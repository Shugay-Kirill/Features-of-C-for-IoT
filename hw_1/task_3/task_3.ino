int ledGreen = 3;
int ledYellow = 4;
int ledRed = 5;
int incomingByte;

void setup()
{
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
}


void loop()
{
  if(Serial.available()>0)
  {
  
    incomingByte = Serial.read();
    switch(incomingByte){
      case '1': //Red on 
          digitalWrite(ledRed, HIGH);
          break;
      case '0': //Red off
          digitalWrite(ledRed, LOW);
          break;
      case '3': //Yellow on
          digitalWrite(ledYellow, HIGH);
          break;
      case '2': //Yellow off
          digitalWrite(ledYellow, LOW);
          break;
      case '5': //Green on 
          digitalWrite(ledGreen, HIGH);
          break;
      case '4': //Green off
          digitalWrite(ledGreen, LOW);
          break;
      }
   }
}