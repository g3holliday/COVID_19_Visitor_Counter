
int piezoPin = 6; // pin for the piezo
int trigPin = 8;
int echoPin = 9;

int val = 0; // variable for reading the pin status
int counter = 0;
int currentState = 0;
int previousState = 0;     

void setup() {
pinMode(piezoPin, OUTPUT); // declare piezo as output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
Serial.begin(9600);
}

void loop(){
delay(200);// reading will be taken after 200 milliseconds
Serial.println("\n");

int duration, distance;
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn (echoPin, HIGH);
    distance = (duration/2) / 29.1;
  
    if (distance < 15) {  // Change the number for long or short distances.
      digitalWrite(piezoPin, HIGH);

    }
 else {
      digitalWrite(piezoPin, LOW);
    } 

val = digitalRead(piezoPin); // read input value
if (val ==  HIGH) { // check if the input is HIGH (led on)
currentState = 1;
}
else {
currentState = 0;
}

if(currentState != previousState){
  
if(currentState == 1){
counter = counter + 1;
Serial.print(" Arduino has been passed ");
Serial.println(counter);
Serial.print("times.");
}
}
previousState = currentState;

}
 

  
  
  


  
  
