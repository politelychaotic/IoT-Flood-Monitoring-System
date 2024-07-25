#define GrnLed 8
#define RedLed 12
#define Threshold 75

int inches = 0;

int distance, cm = 0;
int i=0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); //cls trig
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  //Sets the trigger pin to HIGH state for 10 ms
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  //read echo pin, then return soundwaveroundtrip time in ms
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(GrnLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  Serial.print("Water_Level=[");
}

void loop()
{
  while(i<30){//collect only 30 points
    //measure the ping time in cm
    cm = 0.01723 * readUltrasonicDistance(7,7);
    //cm -> inches by cm/2.54
    inches = (cm/2.54);
    distance=cm;
    delay(500); //wait for 100 ms
    if (distance > Threshold){ //no flooding
      digitalWrite(GrnLed, HIGH);
      digitalWrite(RedLed, LOW);
    }
    else
    { //flooding
      digitalWrite(GrnLed, LOW); 
      digitalWrite(RedLed, HIGH);
    }
    Serial.print(distance);
    Serial.print(";");
    Serial.println();
    delay(1000);
    i++;
    if(i == 30){
      Serial.print("];");
      while(1);
    }
  } 
}
