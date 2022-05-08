#include <Keypad.h>

#define numRegisters 8
#define ser 2
#define rclk 6
#define sclk 7

  
#define numberNum 10
const boolean seg[numberNum][numRegisters]={
  {1,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,1,1,0,1,0},
  {1,1,1,1,0,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,0,1,1,0},
  {1,0,1,1,1,1,1,0},
  {1,1,1,0,0,0,0,0},
  {1,1,1,1,1,1,1,0},
  {1,1,1,1,0,1,1,0}
};

const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {' ','0',' '}
};
byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {5, 4, 3};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  pinMode(ser,OUTPUT);
  pinMode(sclk,OUTPUT);
  pinMode(rclk,OUTPUT);
}

void loop()
{
  char key=keypad.getKey();
  if(key){
    writeRegisters(byte(key));
  }
}

void writeRegisters(byte whatNum){
  whatNum-=48;
  digitalWrite(rclk,LOW);
  
  for(int i=numRegisters-1;i>=0;i--){
    digitalWrite(sclk,LOW);
    boolean val=seg[whatNum][i];
    digitalWrite(ser,val);
    digitalWrite(sclk,HIGH);
    
  }
  
  digitalWrite(rclk,HIGH);
}

