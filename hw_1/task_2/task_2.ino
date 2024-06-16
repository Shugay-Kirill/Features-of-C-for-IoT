int ledGreen = 3;
int ledYellow = 4;
int ledRed = 5;
int button = 6;


void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(button, INPUT);
}

void fickerDiod(int led)
{
	for(int i = 0; i < 4; i++)
    {
    	delay(500);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
    }
}


void loop()
{
   
   digitalWrite(ledRed, HIGH);
   
   if (digitalRead(button) == HIGH) 
   {  delay(3000);
      fickerDiod(ledRed);
      digitalWrite(ledYellow, HIGH);
      delay(3000);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, HIGH);
      delay(5000);
      fickerDiod(ledGreen);
   } 
 
}