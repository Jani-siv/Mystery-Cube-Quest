//library for time functions for arduino
//compile this program using command g++ main.cpp aika.cpp -o testi.o
// c Jani Sivonen
//setting time for game
#include "aika.h"
#include <avr/io.h>
#include <util/delay.h>

#include <iostream>
int main()
{
	pelinTiedot peli;
	peli.alustaAika(100);
	std::cout << peli.peliAika;
	return 0;
}


