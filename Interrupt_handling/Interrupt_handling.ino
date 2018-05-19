/*Variable names for pins*/
//button numbers assigned to pin number
const int trig1 = 8;
const int echo1 = 10;

const int trig2 = 8;
const int echo2 = 10;

const int InteruptPin = ; // trigger pin to interupt program 
//2 distance variables of type int
int time1;
int time2;
volatile int distPath;
volatile int distFall;

//button state will be used to run a program
//assigned to 2 buttons
int button_state = 0;
int previous_state = 0;

void setup() {
  //declaring the buttons as inputs
  pinMode(trig1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo1, INPUT); // Sets the echoPin as an Input
  pinMode(trig2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo1, INPUT); // Sets the echoPin as an Input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {

    digitalWrite(trig1, LOW);// Clears the trigPin
    digitalWrite(trig2, LOW);// Clears the trigPin
    delayMicroseconds(2);
    digitalWrite(trig1, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    time1 = pulseIn(echo1, HIGH);
    time2 = pulseIn(echo2, HIGH);
    // Calculating the distance
    distPath= time1*0.034/2;
    distFall= time2*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("DistPath: ");
     Serial.print("           DistPath: ");
     Serial.print("                      ");
    Serial.println(distPath);
    Serial.println(distFall);
      //see if any buttons have been pressed
      if(digitalRead(button1) == HIGH)
        button_state = 1;
      if(digitalRead(button2) == HIGH)
        button_state = 2;

  //see if we start a new function
  if(button_state != previous_state){
    switch(button_state) {
      case 1:
        //run program 1 (stop/idle state?
        Serial.print("button 1 pressed");
        break;
      case 2:
        //run program 2
        Serial.print("button 2 pressed");
        break;
      default:
        //default error state (idle state?)
        Serial.print("default state, should not happen :( (im so lonely)");
        button_state = 0;
    }
    //short delay
    delay(50);
  }
  //update previous_state
  previous_state = button_state;
}
