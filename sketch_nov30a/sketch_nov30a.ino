


int pwmMotorA = 11;
int pwmMotorB = 10;
int lightA=12;
int lightB=13;


//TEMPERATURE
int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
int sensorInput;    //The variable we will use to store the sensor input
double temp;  

void setup() {
 // put your setup code here, to run once:

//Setup pins
  pinMode(pwmMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(lightA,OUTPUT);
  pinMode(lightB,OUTPUT);


//TEMPERATURE
  Serial.begin(9600); //Start the Serial Port at 9600 baud (default)
  
}

void loop() {
  // put your main code here, to run repeatedly:
 // read the input on analog pin 1:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

if(sensorValue<900)
{
    Light();
}
  
  else{
          StopLight();
      
  }
//TEMPERATURE
 sensorInput = analogRead(A0); //read the analog sensor and store it
  temp = (double)sensorInput / 1024;   //find percentage of input reading
  temp = temp * 5;                     //multiply by 5V to get voltage
  temp = temp - 0.5;                   //Subtract the offset 
  temp = temp * 100;                   //Convert to degrees 

  //TEMPERATURE
   Serial.print("Current Temperature: ");
  Serial.println(temp);
  if (temp<25)
  {
    Forward();
  }
  else
  {
    StopMotor();   
  }
}

//LIGHT
void Light()
{
  digitalWrite(lightA,LOW);
  digitalWrite(lightB,HIGH);
}

//TEMPERATURE FAN CODE
void Forward() 
{
  digitalWrite(pwmMotorA, HIGH);
  digitalWrite(pwmMotorB, LOW);
}
void StopMotor()
{
  digitalWrite(pwmMotorA,LOW);
  digitalWrite(pwmMotorB,LOW);
}

void StopLight()
{
  digitalWrite(lightA,LOW);
  digitalWrite(lightB,LOW);
  
}
