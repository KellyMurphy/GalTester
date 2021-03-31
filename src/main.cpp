#include <Arduino.h>
#include <limits.h>


template <typename T>
void printBinary(T value)
{
  for (size_t mask = 1 << ((sizeof(value) * CHAR_BIT) - 1); mask; mask >>= 1)
  {
    Serial.print(value & mask ? "1" : "0");
  }
}
void outputResult(byte i)
{
  PORTA = i;
    if(i<16) {
      Serial.print("0");
    }
    Serial.print(i, HEX);
    Serial.print(" ");
    printBinary(i);
    Serial.print(" ");
    printBinary(PINL);
    Serial.println();
}



void setup()
{
  Serial.begin(115200);
  
  DDRA = 0xff; //Set Port A as Output
  DDRL = 0x00; //Set Port L as Input

  for (byte i = 0; i < 0xff; i++)
  {
    outputResult(i);
  }
  outputResult(0xFF);
}

void loop()
{
  // put your main code here, to run repeatedly:
}