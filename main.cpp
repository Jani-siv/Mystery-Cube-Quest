#include "aika.h"		//include aika library

class pelinTiedot
{
	public:
		int peliAika;
		int lukot;
		int gameOver = 0;
	private:
		void alustaAika(int maara);
		void vahennaAika(int maara);
		void paivitaAika();
		int tarkistaAika();
