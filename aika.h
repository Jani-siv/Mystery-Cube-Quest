#ifndef AIKA_H
#define AIKA_H
#include "lcd.h"

class aika
{
		public:
                int gameOver = 0;
                void alustaAika(int maara);
                int vahennaAika(int maara); 
                void paivitaAika(int maara);
                void yleinenAika(LCD* objekti);			//vähentää pääkellosta 1 sekunnin
                int tarkistaAika();
    private:
                int kymmin = 10;				//pääkellon minuutit ja sekunnit
                int minuutit = 0;
                int kymsek = 0;
                int sekunnit = 0;
};
#endif
