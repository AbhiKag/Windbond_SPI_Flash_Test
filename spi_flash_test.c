
#include <SPI.h>

byte a,b,c;



void setup()
{
  
  
 
  //SPI and Serial Comm Setup
  Serial.begin(9600);
  pinMode(9,OUTPUT);  //pseudo SS
  digitalWrite(9, HIGH);
  SPI.begin();
  
  
   delay(3000);
   
   //Write Enable
    digitalWrite(9,LOW);
    SPI.transfer(0x06);
    digitalWrite(9,HIGH);

  // Sector Erase
  digitalWrite(9,LOW);
    //Instruction
    SPI.transfer(0x20); 
    
    //Address (24 bit)
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    SPI.transfer(0x00);
     digitalWrite(9,HIGH);
  
  
  delay(100);
  
  //Write Enable
    digitalWrite(9,LOW);
    SPI.transfer(0x06);
    digitalWrite(9,HIGH);
    
    
    
    
    
    //Page Program (Write Data)
    digitalWrite(9,LOW);
    //Instruction
    SPI.transfer(0x02); 
    
    //Address (24 bit)
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    
    // Dummy Data
    SPI.transfer(0x01);
    SPI.transfer(0x02);
    SPI.transfer(0x03);
    SPI.transfer(0x04);
    SPI.transfer(0x05);
    SPI.transfer(0x06);
    SPI.transfer(0x07);
    SPI.transfer(0x08);
    SPI.transfer(0x09);
    SPI.transfer(0x0A);
    SPI.transfer(0x0B);
    SPI.transfer(0x0C);
    SPI.transfer(0x0D);
    SPI.transfer(0x0E);
    SPI.transfer(0x0F);
    SPI.transfer(0xFA);
    SPI.transfer(0xFB);
    digitalWrite(9,HIGH);
    

    
    
    
delay(1000);
    
 
    
    
    //Read Data
    digitalWrite(9,LOW);
    //Instruction
    SPI.transfer(0x03); 
    
    //Address (24 bit)   
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    
    for(int i=1;i<17;i++)
    a = Serial.println(SPI.transfer(0x00),HEX);
     digitalWrite(9,HIGH);
 

  
}



void loop()
{
  delay(100);
}

