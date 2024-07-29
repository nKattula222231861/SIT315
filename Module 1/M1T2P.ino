/*
*   M1T2P
*   Code fulfilling requirements for first two tasks, using a sensor to light up an LED and using interrupts to do it.
*   Will be submitted for M1T1P and M1T2P
*
*/

//Constants for Pins used in code.
const int INPUT_PIN = 2;
const int LED_PIN = 12;

void setup() 
{
  Serial.begin(9600);

  //Sets Digital Pins 2 and 12 to act as inputs and outputs respectively, lighting up an attached LED when triggered
  pinMode(INPUT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  //Interrupt for when input pin changes state
  attachInterrupt(digitalPinToInterrupt(INPUT_PIN), react, CHANGE);

  //Interrupt for when input pin is low
}

void loop() 
{
}

//Function which occurs if a change in motion signal is detected.
void react()
{ 
  //Checks if digital pin is high, i.e motion detected
  if (digitalRead(INPUT_PIN))
  {
    //Writes high to serial monitor and turns LED on
    Serial.println("HIGH");
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED On");
  }

  //Checks if pin is low, i.e no motion detected
  else
  {
    //Writes high to serial monitor and turns LED on
    Serial.println("LOW");
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED Off");
  }
}
