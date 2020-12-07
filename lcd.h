#ifndef LCD_H
#define LCD_H
#include "debug.h"
class LCD 
{
        //define pin
        //reset first entry
        public:
        int reset1       	=       0;
        int reset2       	=       0;
        int EnableLCD	 	=	1;
	void lcd_init();                              //init lcd display
        void printInScreen(int screen);                                   //print to lcd what inside screen table
        void sendData(unsigned int information, int command, int screen);   //sending command to LCD 1 to display 0 is command
        void updateTime(int kymmin, int minuutit, int kymsek,int sekunnit); //update table screen && printInScreen
        void selectScreen(int screen);				//set EnableLCD to pointing right pin        
        const int clockPin      =       2;                      //WHITE SRCLK && RCLK
        const int SRCLR         =       3;                      //ORANGE NEAR WHITE LOW state reset shift register
        const int RCLK          =       4;			//BLUE 
        const int SER           =       5;                      //BROWN serial data           
        const int OE            =       6;                      //ORANGE Enable 8-BIT data bus to LCD
        const int enablePin     =       7;                      //YELLOW LCD read bus pin      
        const int rsPin         =       8;                      //GREEN command pin, commands register LOW, to screen HIGH
	const int enablePin2 	=	9;			//GREY Second display enable pin
        unsigned int screenTable[2][16] = {{0x4D,0x43,0x51,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0},
                                     {0x4C,0x4F,0x43,0x4B,0x53,0x3A,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0}}; // First display (main) 2 rows 8 character first start 00 address second row 40 address        
         unsigned int screenTable2[2][16] = {{0x4D,0x79,0x73,0x74,0x65,0x72,0x79,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0},
                                     {0x43,0x75,0x62,0x65,0x2D,0x51,0x75,0x65,0x73,0x74,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0}}; // Second dispalay 2 rows 8 character first start 00 address second row 40 address  
        debug var;
        debug *variable = &var;  
        private:                                                                                                        
        void resetShiftRegister();                              //reset shift register                                  
        void dataToLCD(int command, int screen);                            //send data and set pin     
        
                                                                                                                        
};                                                                                                                     
#endif
