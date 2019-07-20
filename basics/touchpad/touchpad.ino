#include<Mouse.h>
#include <ps2.h>
#define PS2_DATA 10
#define PS2_CLK 9

byte mstat1;
byte mstat2;
byte mxy;
byte mx;                  
byte my;      
byte mz;               
int msval[2];
int repeatCnt;

PS2 moose(PS2_CLK, PS2_DATA);                

void setup() {
  Mouse.begin();
  moose.write(0xff);  
  moose.read();
  moose.read();
  moose.read(); 
  moose.write(0xf0); 
  moose.read(); 
  delayMicroseconds(100);
  moose.write(0xe8);
  moose.read(); 
  moose.write(0x03);
  moose.read(); 
  moose.write(0xe8);
  moose.read(); 
  moose.write(0x00); 
  moose.read();  
  moose.write(0xe8);
  moose.read();  
  moose.write(0x01);
  moose.read(); 
  moose.write(0xe8);
  moose.read(); 
  moose.write(0x00); 
  moose.read(); 
  moose.write(0xf3);
  moose.read(); 
  moose.write(0x14);
  moose.read(); 
  Serial.begin(9600);
}

void ms_read()
{moose.write(0xeb);
  moose.read();
  mstat1 = moose.read();
  mxy = moose.read();
  mz = moose.read();
  mstat2 = moose.read();
  mx = moose.read();
  my = moose.read();
  msval[0] = (((mstat2 & 0x10) << 8) | ((mxy & 0x0F) << 8) | mx );
  msval[1] = (((mstat2 & 0x20) << 7) | ((mxy & 0xF0) << 4) | my );
  msval[2] = int(mz);
}

void loop() {
  ms_read();
  if (msval[0] > 0 and msval[2] > 10)
  { repeatCnt++; }
  else
  { repeatCnt = 0; }
 
    if (repeatCnt > 2)
  {
    msval[0] = map(msval[0], 580, 5164, -1023, 1023);
    msval[1] = map(msval[1], 1120, 5967, 1023, -1023);
    Mouse.move(msval[0]/200,msval[1]/200);
  }


}
