#ifndef LCD_H
#define LCD_H
class LCD
{
        //define pin
        //reset first entry
        public:
        int reset       =       0;
        void lcd_init();                                        //init lcd display
        void printInScreen();                                   //print to lcd what inside screen table
        void sendData(unsigned int information, int command);   //sending command to LCD 1 to display 0 is command
        void updateTime(int kymmin, int minuutit, int kymsek,int sekunnit); //update table screen && printInScreen
        //pin setup for shift register and LCD screen
        const int clockPin      =       2;                      //SRCLK && RCLK
        const int SRCLR         =       3;                      //LOW state reset shift register
        const int RCLK          =       4;
        const int SER           =       5;                      //serial data           
        const int OE            =       6;                      //Enable 8-BIT data bus to LCD
        const int enablePin     =       7;                      //LCD read bus pin      
        const int rsPin         =       8;                      //command pin, commands register LOW, to screen HIGH 
        unsigned int screen[2][16] = {{0x4D,0x43,0x51,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0x31,0x30,0x3A,0x30,0x30},
                                     {0x4C,0x4F,0x43,0x4B,0x53,0x3A,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0}};
	private:                                                                                                        
        void resetShiftRegister();                              //reset shift register                                  
        void dataToLCD(int command);                            //send data and set pin                                 

                                                                                                                        
};                                                                                                                     
#endif           
