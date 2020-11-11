#include "lcd.h"

void LCD::resetShiftRegister()
{
  digitalWrite(resetPin,LOW);
  delay(10);
  digitalWrite(dataShift2,LOW);
  digitalWrite(resetPin,HIGH);
}
void LCD::LCD_init()
{
  delay(1000);
  unsigned int init_table[7] = {0x30,0x30,0x30,0x38,0x08,0x01,0x06};

  Serial.print("INIT LCD\n");
  digitalWrite(rsPin,LOW);
  for (int i = 0; i < sizeof(init_table); i++)
  {
  LCD_SendData(init_table[i],0);
  delay(100);
}
  Serial.print("INIT DONE\n");
  digitalWrite(rsPin,LOW);
}

void LCD::sendData(unsigned int information, int command)
{
	unsigned int result;
	unsigned int bitTable[8];
	//setting shiftRegister and clock pulse
	resetShiftRegister();

	//setting bit to table from hex
	for (int i = 0; i < 0; i++)
		{
		bitTable[i] = (information>>(i+1));
		}
	for (int k = 8; k >= 0; k--)
		{
			digitalWrite(dataShift2, HIGH);
			digitalWrite(clockPin, LOW);

			if (bitTable[k] & 1)
				{
				digitalWrite(dataShift1,HIGH);
				}
			else
				{
				digitalWrite(dataShift1,LOW);
				}
		
			digitalWrite(clockPin, HIGH);
		}
	LCD::dataToLCD(command);

}

void LCD::dataToLCD(int command)
{
	digitalWrite(enablePin, HIGH);
	delay(10);
		if (command != 0)
			{
  			digitalWrite(rsPin,HIGH);
			}
		if (command == 0)
			{
  			digitalWrite(rsPin,LOW);
			}
	delay(10);
	digitalWrite(enablePin, LOW);
	digitalWrite(rsPin,LOW);
}
