
// encoder pins

const int encA = 2;       

const int encB = 3; 

// Globals

//volatile unsigned long enc_l = 0;

//volatile unsigned long enc_r = 0;


int counter=0;
int astate;
int alaststate;

void setup() {
  // put your setup code here, to run once:

  // Set up pins

  pinMode(encA, INPUT); //CLK 
  digitalWrite(encA,HIGH);
  pinMode(encB, INPUT);  //DT
  digitalWrite(encB,HIGH);
  


  // Set up interrupts

  //attachInterrupt(digitalPinToInterrupt(encA), count, CHANGE);

  //attachInterrupt(digitalPinToInterrupt(enc_right), countRight, CHANGE);

  Serial.begin(9600);
  alaststate=digitalRead(encA);  
  


}

void loop() {
  // put your main code here, to run repeatedly:

  astate=digitalRead(encA);
  if(astate!=alaststate)
  {
    if(digitalRead(encB)!=astate)
      {counter++;
      }
    else
    {
      counter--;  
    }
    
  Serial.print("position is: ");
  Serial.println(counter);
  }
  alaststate=astate;
}
