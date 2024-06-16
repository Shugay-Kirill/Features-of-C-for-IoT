void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
	
  	digitalWrite(5, HIGH);
    delay(5000);
  
  	for(int i = 0; i < 4; i++)
    {  
        digitalWrite(5, HIGH);
        delay(500); 
        digitalWrite(5, LOW);
        delay(500); 
    }
  	
  	digitalWrite(4, HIGH);
    delay(3000);
  	digitalWrite(4, LOW); 
  
  	digitalWrite(3, HIGH);
    delay(5000);
  
  	for(int i = 0; i < 4; i++)
    {  
      	digitalWrite(3, HIGH);
        delay(500); 
        digitalWrite(3, LOW);
        delay(500); 
    }
  
    digitalWrite(4, HIGH);
    delay(3000);
  	digitalWrite(4, LOW);
}