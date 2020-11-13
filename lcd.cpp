#include "lcd.h"
#include <Arduino.h>
void LCD::resetShiftRegister()
{
  digitalWrite(LCD::resetPin,LOW);
  delay(10);
  digitalWrite(LCD::dataShift2,LOW);
  digitalWrite(LCD::resetPin,HIGH);
}

void LCD::sendData(unsigned int information, int command)
{
	unsigned int result;
	unsigned int bitTable[8];
	unsigned int temp;
	//setting shiftRegister and clock pulse
	resetShiftRegister();

	//setting bit to table from hex
for (int i = 8; i >= 0; i--)
                {
                  temp =(information>>(i-1));
                  if (temp & 1)
                  {
                    bitTable[i] = 1;
                  }
                  else
                  bitTable[i] = 0;
          
                }
	for (int k = 8; k > 0; k--)
		{
			digitalWrite(LCD::dataShift2, HIGH);
			digitalWrite(LCD::clockPin, LOW);

			if (bitTable[k] & 1)
				{
				digitalWrite(LCD::dataShift1,HIGH);
				}
			else
				{
				digitalWrite(LCD::dataShift1,LOW);
				}
		
			digitalWrite(LCD::clockPin, HIGH);
		}
	LCD::dataToLCD(command);

}

void LCD::lcd_init()
{
  digitalWrite(LCD::enablePin, LOW);
  delay(1000);
  unsigned int init_table[6] = {0x30,0x30,0x30,0x38,0x0D,0x06};
  Serial.print("INIT LCD\n");
  digitalWrite(LCD::rsPin,LOW);
  for (int i = 0; i < 6; i++)
  {
	  LCD::sendData(init_table[i],0);
}

  Serial.print("INIT DONE\n");
  digitalWrite(LCD::rsPin,LOW);
  //init done
  LCD::reset = 1;
}

void LCD::dataToLCD(int command)
{

		if (command != 0)
			{
  			digitalWrite(LCD::rsPin,HIGH);
			}
		if (command == 0)
			{
  			digitalWrite(LCD::rsPin,LOW);
			}
	digitalWrite(LCD::enablePin, HIGH);
	delay(10);
	digitalWrite(LCD::enablePin, LOW);
	digitalWrite(LCD::rsPin,LOW);
	resetShiftRegister();
}
