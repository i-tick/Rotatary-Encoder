
// encoder pins

const int encAclk = 2;       

const int encAdt = 3;

const int encBclk = 4;

const int encBdt = 5;


// Globals

//volatile unsigned long enc_l = 0;

//volatile unsigned long enc_r = 0;

int p=0,q=0;

int counterA=0;
int Astate;
int Alaststate;
int lastcountA;

int counterB=0;
int Bstate;
int Blaststate;
int lastcountB;

String A="";
String B="",X="";

void setup() {
  // put your setup code here, to run once:

  // Set up pins

  pinMode(encAclk, INPUT); //CLK 
  digitalWrite(encAclk,HIGH);

  pinMode(encAdt, INPUT);  //DT
  digitalWrite(encAclk,HIGH);
  pinMode(encBclk, INPUT); //CLK 
  digitalWrite(encAclk,HIGH);
  pinMode(encBdt, INPUT); //CLK 
  digitalWrite(encAclk,HIGH);

  // Set up interrupts

  //attachInterrupt(digitalPinToInterrupt(encA), count, CHANGE);

  //attachInterrupt(digitalPinToInterrupt(enc_right), countRight, CHANGE);

  Serial.begin(9600);
  Alaststate=digitalRead(encAclk); 
  Blaststate=digitalRead(encBclk); 
  


}

void loop() {
  
  // put your main code here, to run repeatedly:

  Astate=digitalRead(encAclk);
  if(Astate!=Alaststate)
  {
    lastcountA=counterA;
    if(digitalRead(encAdt)!=Astate)
      {counterA++;
      }
    else
    {
      counterA--;  
    }

    if(lastcountA!=counterA)
    {
      p=1;
    }
    else
    {
      p=0;
    }
    
    A=counterA;
  }
  Alaststate=Astate;
  
  Bstate=digitalRead(encBclk);
  if(Bstate!=Blaststate)
  {
    lastcountB=counterB;
    if(digitalRead(encBdt)!=Bstate)
      {counterB++;
      }
    else
    {
      counterB--;  
    }
    
    if(lastcountB!=counterB)
    {
      q=1;
    }
    else
    {
      q=0;
    }
    
    B=counterB;
  }
  Blaststate=Bstate;


  if(p==1 || q==1)
  {
    X=X.concat(String("counterA"));
    X=X.concat(",");
    X=X.concat(String("counterB"));
    X=X.concat(" ");
    Serial.println(X);
  }
  
}
