int sensorOutPin = 5; //Color sensor OUT to Arduino pin 5
int S2 = 2; //Color sensor S2 to Arduino pin 2
int S3 = 3;  //Color sensor S3 to Arduino pin 3

const int S0 = 13;
const int S1 = 12;

int data;

int rColorStrength;
int gColorStrength;
int bColorStrength;

void setup() {
  // put your setup code here, to run once:
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT); //Write to set wich color channel to read
  pinMode(S3, OUTPUT);  //Write to set wich color channel to read

  pinMode(sensorOutPin, INPUT); //Read from that pin to get color from one channel

  //Initiate Serial communication.
  Serial.begin(9600); //passes 9600 bits of information per seconds

  //Frequency Scale of 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1,LOW);

}

void loop() {

  //the sensors return a pulse's length proportional to the color's strength
  //the longer the pulse, the weaker the value of that channel
  //Store value of the measurement in an unsigned int
  // max value of int = +/- 32,728 and the pulse length measured can vary from 0 up to 102,400
  //scale it down to a number between 0 and 255
  // => rColorStrength = (pusleWidth/400-1);
  //in pulseWidth bigger means weaker so rColorStrength = 255 - (pulseWidth/400-1)

  //READ RED VALUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
   rColorStrength = pulseIn(sensorOutPin, LOW); 
  Serial.print("R = ");
  Serial.println(rColorStrength);
  delay(100);
  
  
  //READ GREEN VALUE
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  gColorStrength =  pulseIn(sensorOutPin, LOW); 
   Serial.print(" G = ");
  Serial.println(gColorStrength);
  delay(100);

  //READ BLUE VALUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  gColorStrength =  pulseIn(sensorOutPin, LOW); 
  Serial.print(" B = ");
  Serial.println(bColorStrength);
  delay(100);

  if(rColorStrength > gColorStrength && rColorStrength > bColorStrength ) {
    Serial.print("It's Red !!");
    Serial.print(" ");
  } else if(gColorStrength > rColorStrength && gColorStrength >bColorStrength) {
    Serial.print("It's Green !!");
    Serial.print(" ");
  } else if(bColorStrength > rColorStrength && bColorStrength >gColorStrength) {
     Serial.print("It's Blue !!");
     Serial.print(" ");
  } else {
    Serial.print("It's Undefined");
    Serial.print(" ");
  }
  

  

}
