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
	//pin setup
	const int clockPin 	= 	2;                 
	const int resetPin 	= 	3;                 
	const int dataShift1 	= 	4;
	const int dataShift2	=	5;
	const int enablePin 	= 	6;
	const int rsPin 	= 	7;
	const int rwPin 	= 	8;
	private:
	void resetShiftRegister();				//reset shift register
	void dataToLCD(int command);				//send data and set pin

};
#endif



