/**************************************************************************
 * Mini_Moose Operates utilizing two seperate boards that will ocmmunicate simple commands
 * via Infered frequency, transmitted from Master to Slave.  
 * 
 * MiniMoose is a Quadrapodic Robot that uses 
 * 4 knee servos 
 * 4 hip servos 
 * 1 working as a neck.
 * 
 * 
 */

/*********************< SLAVE >**************************/
#include <Servo.h>



Servo L_frontKnee;
Servo R_frontKnee;
Servo L_rearKnee;
Servo R_rearKnee;
Servo L_frontHip;
Servo R_frontHip;
Servo L_rearHip;
Servo R_rearHip;
Servo Neck_motor; 

void System_test();//checks each motor individually
void Crawl_forward(); //perform slow walk forward
void Crawl_backward(); //perfom slow walk backward
void Head_left();   //turn neck motor left
void Head_right();  //turns neck motor right
void Avoid_obsticle(); //detects obsticles && corrects path to continue
void standby(); //rests motors and enters into passive standing

int eye_pin = 10; //collects data from laser sensor
int sight;   //data from eye as int

int IR_Pin = 9;   //pin to ir sensor
int IR_reading;


void setup() {
  // put your setup code here, to run once:
  
  System_test(); //check all motors
  
  digitalRead(IR_Pin, INPUT); 
  
  
}

void loop() {
  digitalRead(IR_reading, IR_Pin); // take in int from infered sensor 

  digitalRead(sight, eye_pin); //takes in values from obsticle sensor 
  
  switch(IR_reading)
    {
      case //code// : 
        {
          Crawl_forward();  //function call to walk forward
          break;
        }
      case //code// : 
        {
          Crawl_backward(); //function call to crawl backward
          break;
        }
      case //code// : 
        {
          Head_left //function call to turn head left
          break;
        }
      case //code// : 
        {
          Head_right(); //function call to turn head right
          break;
        }
      case //code// : 
        {
          Avoid_obsticle();//function call to avoid
          break;
        }
      case default : 
        {
          standby();  //function call to standby
          break;
        }
    }
  
  // put your main code here, to run repeatedly:

}
