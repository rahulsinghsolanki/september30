#define trigPin 2
#define echoPin 3
//int buzzer_pin = 10; 
long duration;
int distance; 
int enab1=5;
int input1=7;
int input2=8;
int enab2=6;
int input3=9;
int input4=10;

void stop(void);

  void setup ( ) {

        Serial.begin (9600); 
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
      //  pinMode (buzzer_pin, OUTPUT);
        pinMode(enab1,OUTPUT);
        pinMode(enab2,OUTPUT);
        pinMode(input1,OUTPUT);
        pinMode(input2,OUTPUT);
        pinMode(input3,OUTPUT);
        pinMode(input4,OUTPUT);



}




  void loop ( ) {

    // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance= duration*0.034/2;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(5);

  if (distance <= 10) 

        {
             
          stop();
        //  digitalWrite (buzzer_pin, HIGH);

        }

  else {

            
         forward();
        // digitalWrite (buzzer_pin, LOW);

              

  } 

  }

  void stop()
  {
    digitalWrite(input1,LOW);
    digitalWrite(input2,LOW);
    digitalWrite(input3,LOW);
    digitalWrite(input4,HIGH);
   // analogWrite(enab1,0);
   // analogWrite(enab2,255);
    digitalWrite(enab1,LOW);
     digitalWrite(enab2,HIGH);
    Serial.println ("stop"); 
     
  }


   void forward()
  {
    digitalWrite(input1,LOW);
    digitalWrite(input2,HIGH);
    digitalWrite(input3,LOW);
    digitalWrite(input4,HIGH);
    
    //analogWrite(enab1,255);
    //analogWrite(enab2,255);
    digitalWrite(enab1,HIGH);
    digitalWrite(enab2,HIGH);
    Serial.println ("forward");
     
  }


