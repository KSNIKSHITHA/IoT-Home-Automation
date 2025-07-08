const int pirPin = 2;    
const int ldrPin = A0;    
const int relayPin = 8;   
const int lightThreshold = 600;  
unsigned long lastMotionTime = 0;
const unsigned long autoOffDelay = 2 * 60 * 1000;  
void setup() 
{
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); 
  Serial.begin(9600);
}
void loop() 
  {
  int motion = digitalRead(pirPin);
  int lightLevel = analogRead(ldrPin);
  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.println(lightLevel);
    if (motion == HIGH && lightLevel < lightThreshold) 
    {
    digitalWrite(relayPin, HIGH); 
    lastMotionTime = millis();     
    }
  if (digitalRead(relayPin) == HIGH && millis() - lastMotionTime > autoOffDelay) 
    {
    digitalWrite(relayPin, LOW);
    }
 delay(500);
  }
