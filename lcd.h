#ifndef LCD_H
#define LCD_H
class LCD
{
	//define pin
	//reset first entry
	public:
	int reset 	=	0;
	void LCD_init();					//init lcd display
	void sendData(unsigned int information, int command);	//sending command to LCD 1 to display 0 is command
	private:
	int clockPin 	= 	2;                 
	int resetPin 	= 	3;                 
	int dataShift1 	= 	4;
	int dataShift2	=	5;
	int enablePin 	= 	8;
	int rsPin 	= 	7;
	int rwPin 	= 	6;
	void resetShiftRegister();				//reset shift register
	void dataToLCD(int command);				//send data and set pin

};
#endif



