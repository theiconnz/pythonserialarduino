#include <IRremote.h>  //including infrared remote header file 

const int RECV_PIN = 10;

float brightness = 0.99;    // how bright the LED is
float trunonat = 255;
float turnoffat = 0;

int greeno = 6;
int blueo = 11;
int redo = 9;
int turnon = 11;
int count = 0;
String lastvalue = String(13);

boolean redon = false;
boolean blueon = false;
boolean greenon = false;

IRrecv irrecv(RECV_PIN);     
decode_results results;


void setup()     
{     
  Serial.begin(9600);     
  irrecv.enableIRIn();
  pinMode(redo, OUTPUT);
  pinMode(blueo, OUTPUT);
  pinMode(greeno, OUTPUT);
  pinMode(turnon, OUTPUT);
  alloff();
}

void loop()     
{     
  if (irrecv.decode(&results))
  {
        Serial.println(results.value);
        lastvalue = results.value;

        if(results.value==16711935){
          switchedon();
        } 
        if(results.value==16724175){
          red();
        } 
        
        if(results.value==16756815){
          green();
        } 

        if(results.value==16740495){
          blue();
        } 

        if(results.value==16718055){
          yellow();
        } 

        if(results.value==16734375){
          pink();
        } 

        if(results.value==16732335){
          white();
        } 

        if(results.value==16744575){
          alloff();
        }
        
        irrecv.resume(); // get the next signal
  }

}


void switchedon(){
    white();
}

//set all pins to 0V
//turn on green
void green() {
  alloff();
  digitalWrite(greeno, trunonat);
}


//set all pins to 0V
//turn on blue
void blue() {
  alloff();
  digitalWrite(blueo, trunonat);
}


//set all pins to 0V
//turn on red
void red() {
  alloff();
  digitalWrite(redo, trunonat);
}


//set all pins to 0V
//turn on all off
void alloff() {
  digitalWrite(redo, turnoffat);
  digitalWrite(blueo, turnoffat);
  digitalWrite(greeno, turnoffat);
}


//set all pins to 0V
//turn on all off
void white() {
  alloff();
  digitalWrite(redo, trunonat);
  digitalWrite(blueo, trunonat);
  digitalWrite(greeno, trunonat);
}


//set all pins to 0V
//turn on all off
void yellow() {
  digitalWrite(redo, trunonat);
  digitalWrite(blueo, turnoffat);
  digitalWrite(greeno, trunonat);
}



//set all pins to 0V
//turn on all off
void pink() {
  digitalWrite(redo, trunonat);
  digitalWrite(blueo, trunonat);
  digitalWrite(greeno, turnoffat);
}
