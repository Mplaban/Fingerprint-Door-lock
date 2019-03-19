#include <Adafruit_Fingerprint.h> //fingerprint library
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); //Rx Tx pins declaration of fingerprint sensor
uint8_t id;
////////GLOBAL VARIABLES////////////////////////////

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);//1234puppy
const int threshold  = 80;  //Minimum Threshold confidence needed to verify the fingerprint
int bu=8; //buzzer
int count = 0;
int counter = 0; //counter to count No. of invalid attempts
int eb=7; //Enroll pushbutton

//////////////////////////////////////////////////

//////////////////////   SETUP BEGINS  ///////////////////////

void setup()  
{
  
  
  enroll_setup();  //setup function for enrollment of aa individual
  
  motor_setup();  // motor setup
  finger_setup(); //fingerprint setup
  pinMode(bu,OUTPUT);  //buzzer
  pinMode(eb,INPUT); //enroll push button
}

//////////////////// SETUP END ////////////////////////////////

//////////////////// LOOP BEGINS ////////////////////////////
void loop()                   
{
  if(digitalRead(eb)==HIGH)  //if enroll button is detected high
  {
  getFingerprintIDez(); //function to verify the fingerprint 
  delay(50);
  }
 else if(digitalRead(eb)==LOW) //if enroll button detected low :enrollment mode
  {
   getFingerprintIDez();  //function to verify the fingerprint of admins
   delay(50);
   if(finger.fingerID==1||finger.fingerID==2) //condition to check the id of admins as only admins will be able to enroll another person
   {
  Serial.println("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as..."); //unique id to store fingerprint of new enrolled person
  id = readnumber();  // function to read the id from serial monitor
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);
  
  while (!  getFingerprintEnroll() ); //WAITING FOR THE FINGERPRINT TO BE DETECTED
   }  
  }
}
/////////////////////////  LOOP ENDS /////////////////////////////////
