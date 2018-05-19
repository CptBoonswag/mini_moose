/*Variable names for pins*/
//button numbers assigned to pin number
const int button1 = 8;
const int button2 = 10;

//2 distance variables of type int
int forward_sensor;
int forward_ground_sensor;

//button state will be used to run a program
//assigned to 2 buttons
int button_state = 0;
int previous_state = 0;

void setup() {
  //declaring the buttons as inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
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
