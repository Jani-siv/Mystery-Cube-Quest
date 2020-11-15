#ifndef LCD_H
#define LCD_H
class LCD
{
	//define pin
	//reset first entry
	public:
	int reset 	=	0;
	void lcd_init();					//init lcd display
	void sendData(unsigned int information, int command);	//sending command to LCD 1 to display 0 is command
	//pin setup for shift register and LCD screen
	const int clockPin 	= 	2;           		//WHITE		SRCLK
	const int SRCLR 	= 	3;     			//ORANGE	LOW state reset shift register
	const int RCLK		=	4;			//BLUE		save data to register
	const int SER	 	= 	5;			//BROWN		serial data
	const int OE		=	6;			//ORANGE	LOW Enable 8-BIT data bus to LCD HIGH disable
	const int enablePin 	= 	7;			//YELLOW	LCD read bus pin
	const int rsPin 	= 	8;			//GREEN 	command pin, commands register LOW, to screen HIGH 
	private:
	void resetShiftRegister();				//reset shift register
	void dataToLCD(int command);				//send data and set pin

};
#endif



