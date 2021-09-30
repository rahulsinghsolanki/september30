/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
 
int enab1=5;
int input1=7;
int input2=8;
int enab2=6;
int input3=9;
int input4=10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
        pinMode(pushButton, INPUT);
        pinMode(enab1,OUTPUT);
        pinMode(enab2,OUTPUT);
        pinMode(input1,OUTPUT);
        pinMode(input2,OUTPUT);
        pinMode(input3,OUTPUT);
        pinMode(input4,OUTPUT);


}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
 // Serial.println(buttonState);
 if(buttonState==1)
 {
  forward();
 }
 else if(buttonState==0)
 {
  stop();
  
 }
  delay(1000);        // delay in between reads for stability
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




