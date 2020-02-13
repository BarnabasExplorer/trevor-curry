#define SPACER 0.001


float ti, tf, td;
float g;
float d=0.3603625+SPACER;
float sqtd;
void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600);
  pinMode(4,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(2,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  
  digitalWrite(8,HIGH);
  delay(3000);

  Serial.println("Waiting to drop...");
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  int button=digitalRead(4);
  while(button==1){
    // do nothing
    button=digitalRead(4);
  }
  
  //this command demagnetizes the magnet
  digitalWrite(8,LOW);
  int sensor=digitalRead(2);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH); 
  //delay to compensate for time to turn off electromagnet
  delay(10);
  ti=millis();
  
 while (digitalRead(2)==1) {
  //do nothing
 }

  while(sensor==1){
    // do nothing
    sensor=digitalRead(2);
  }
 Serial.println(); 
 Serial.println("Triggered!");
  tf=millis();
  td=tf-ti;
  Serial.println();
  delay(2000);
  Serial.print("The time of drop is: ");
  Serial.print(td);
  Serial.println(" milliseconds");
  
  Serial.println();
  sqtd=(sq(td/1000));
  g=d*2/sqtd;
  delay(2000);
  Serial.print ("We input these variables into the formula, g=2d/t^2 and we get the answer");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.print(".  ");
  delay(3000);
  Serial.print(g);
  Serial.print(" m/s^2");
  while(sensor==0){
    // do nothing
    sensor=digitalRead(2);
  
  }
  Serial.println();
  Serial.println();
  Serial.println();
  delay(500);
  Serial.println("------------------------------------------------------------------------------------");
}

