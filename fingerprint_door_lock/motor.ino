int m1 = 11;
int m2 = 10;
int enA = 9;
int d1 , d2 ;
//////////////// MOTOR SETUP ///////////////////////

void motor_setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(enA, OUTPUT);
}

////////////////// MOTOR SETUP ENDS ////////////////////

/*
 * This function is used to stop the motor completely
 */
void motor_stop()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}

/*
 * This function is used define direction and pass PWM to the Motor.
 */
void motor_run(byte dir, int motor_speed)
{
  Serial.print("IM HERE!!");
  //d1 & d2 are the variables for clockwise or anti-clockwise rotation of the motor
  d1 = (dir == 1) ? 1 : 0;  
  d2 = (dir == 1) ? 0 : 1;
  analogWrite(enA, motor_speed);  //passing PWM to the motor
  digitalWrite(m1, d1);
  digitalWrite(m2, d2);
}
