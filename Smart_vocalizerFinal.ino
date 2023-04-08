#include "SD.h"
#define SD_ChipSelectpin 10
#include "TMRpcm.h"
#include "SPI.h"

int anlgin1=A0;
int anlgin2=A1;
int anlgin3=A2;
int readvalue1;
int readvalue2;
int readvalue3;
void audio1();
void audio2();
void audio3();
void audio4();
void audio5();
void audio6();
void looper();




TMRpcm tmrpcm;

void setup() 
{
 pinMode(anlgin1 , INPUT);
 pinMode(anlgin2 , INPUT);
 pinMode(anlgin3 , INPUT);
 Serial.begin(9600);
 tmrpcm.speakerPin=9;
 if (!SD.begin(SD_ChipSelectpin))
 {
 Serial.println("SD Fail");
 return;
 }
 

}

void loop() 
{
  readvalue1=analogRead(anlgin1);
  readvalue2=analogRead(anlgin2);
  readvalue3=analogRead(anlgin3);
  delay(100);
  Serial.print(readvalue1);
  Serial.print("   ");
  Serial.print(readvalue2);
  Serial.print("   ");
  Serial.print(readvalue3);
  Serial.println("  ");

  
  if((readvalue1 < 3) && (readvalue2 < 5) && (readvalue3 < 5))
  {
    audio2();
  }
   if((readvalue2 < 5)&& (readvalue3 < 5))
  {
    audio3();  
  }
   if((readvalue1 < 3) && (readvalue2 < 5))
  {
    audio6();  
  }
   if(readvalue1 < 1)
  {
    audio1();  
  }
   if(readvalue2 < 5)
  {
    audio4();  
  }
   if(readvalue3 < 5)
  {
    audio5();  
  }


}

void audio1()
{
   tmrpcm.play("1.wav");
   delay(4000);
   loop();
}
void audio2()
{
   tmrpcm.play("2.wav");
   delay(4000);
    loop();
}
void audio3()
{
   tmrpcm.play("3.wav");
   delay(4000);
    loop();
}
void audio4()
{
   tmrpcm.play("4.wav");
   delay(4000);
   loop();
}
void audio5()
{
   tmrpcm.play("5.wav");
   delay(4000);
    loop();
}
void audio6()
{
   tmrpcm.play("6.wav");
   delay(4000);
    loop();
}
 
