#include "lcd.h"
#include "debug.h"
#include <Arduino.h>
void LCD::resetShiftRegister()
{
        digitalWrite(LCD::SRCLR,LOW);
        digitalWrite(LCD::SRCLR,HIGH);
}

//function conver hex to bin and set bit to shift register
void LCD::sendData(unsigned int information, int command, int screen)
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
                        //by pass first round
                if ( k != 0)
                        {
                        digitalWrite(LCD::RCLK,HIGH);
                        digitalWrite(LCD::RCLK,LOW);
                        }
                digitalWrite(LCD::clockPin, LOW);

                if (bitTable[k] & 1)
                        {
                        digitalWrite(LCD::SER,HIGH);
                        }
                else
                        {
                        digitalWrite(LCD::SER,LOW);
                        }

                        digitalWrite(LCD::clockPin, HIGH);
                }
        //save bit to register
        digitalWrite(LCD::RCLK,HIGH);
        digitalWrite(LCD::RCLK,LOW);
        //open bus for LCD and enable LCD read
        LCD::dataToLCD(command, screen);

}
//lcd init command
void LCD::lcd_init()
{

  if (LCD::reset1 != 1 || LCD::reset2 != 1)
  {
  digitalWrite(LCD::enablePin, LOW);
  digitalWrite(LCD::enablePin2, LOW);
  digitalWrite(LCD::OE,HIGH);
   for (long int p = 0; p < 4000000; p++)
  {

  }
  unsigned int init_table[8] = {0x30,0x30,0x30,0x3C,0x08,0x01,0x06,0x0C};
  Serial.print("INIT LCD\n");
  digitalWrite(LCD::rsPin,LOW);
  digitalWrite(LCD::enablePin,LOW);
  digitalWrite(LCD::enablePin2,LOW);
  for (int i = 0; i < 8; i++)
  {

          LCD::sendData(init_table[i],0,1);
    LCD::variable->debugInt(init_table[i]);
   if(i == 7)
   {
    break;
   }
}
  for (int i = 0; i < 8; i++)
  {

    LCD::sendData(init_table[i],0,2);
    LCD::variable->debugInt(init_table[i]);
   if(i == 7)
   {
    break;
  }
}
  Serial.print("INIT DONE\n");
  digitalWrite(LCD::rsPin,LOW);
  //init done
  LCD::reset1 = 1;
        LCD::reset2 = 1;


  }

}

//write to bus and enable LCD read
void LCD::dataToLCD(int command, int screen)
{
        LCD::selectScreen(screen);

                if (command != 0)
                        {
                digitalWrite(LCD::rsPin,HIGH);
                        }
                if (command == 0)
                        {
                        digitalWrite(LCD::rsPin,LOW);
                        }
        digitalWrite(LCD::RCLK,HIGH);
        digitalWrite(LCD::RCLK,LOW);

        digitalWrite(LCD::EnableLCD, HIGH);

        digitalWrite(LCD::OE, LOW);

        digitalWrite(LCD::EnableLCD, LOW);
        digitalWrite(LCD::rsPin,LOW);
        digitalWrite(LCD::OE, HIGH);
        resetShiftRegister();
}

void LCD::printInScreen(int screen)
{

        for (int k = 0; k < 2; k++)
                {
                //debug
                LCD::variable->debugInt(k);

                for (int i = 0; i <16; i++)
                        {
                        //selecting screen table before send
                        if (screen == 1)
                                {
                                LCD::sendData(LCD::screenTable[k][i],1,screen);
                                //debug
                                LCD::variable->debugInt(i);
                                LCD::variable->debugInt(screenTable[k][i]);
                                }
                        if (screen == 2)
                                {
                                LCD::sendData(LCD::screenTable2[k][i],1,screen);
                               //debug
                                LCD::variable->debugInt(i);
                                LCD::variable->debugInt(screenTable2[k][i]);
                                }
                        }
                for (int j=0; j <24; j++)
                        {
                        //debug
                   //     LCD::variable->debugInt(j);
                        LCD::sendData(0x20,1,screen);           //filling invisible addresses in LCD
                  //      LCD::variable->debugInt(j);
                        }

                }

}
//main time update function
void LCD::updateTime(int kymmin, int minuutit, int kymsek,int sekunnit) //time interrupt updata screen table
{
LCD::screenTable[0][11] = 0x30 + kymmin;
LCD::screenTable[0][12] = 0x30 + minuutit;
LCD::screenTable[0][14] = 0x30 + kymsek;
LCD::screenTable[0][15] = 0x30 + sekunnit;
LCD::printInScreen(1);
}
//select screen and set enable pin correctly
void LCD::selectScreen(int screen)
{
if (screen == 1)
        {
                LCD::EnableLCD = LCD::enablePin;
        }
        if (screen == 2)
        {
                LCD::EnableLCD = LCD::enablePin2;
        }
}

void LCD::winner() 
{
 
  LCD::screenTable[0][0] = 0x57;
  LCD::screenTable[0][0] = 0x49;
  LCD::screenTable[0][0] = 0x4D;
  LCD::screenTable[0][0] = 0x4D;
  LCD::screenTable[0][0] = 0x45;
  LCD::screenTable[0][0] = 0x52;
  LCD::printInScreen(1);  
}

 
