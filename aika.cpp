#include "aika.h"
void pelinTiedot::alustaAika(int maara)                        //time set in seconds
{
        peliAika= maara;
}
 
int pelinTiedot::vahennaAika(int maara)
{
        if (maara > peliAika)
        {
                peliAika = peliAika - maara;
                return 1;                       //return succesfull 
        }
        else
        {
                gameOver = 1;
                peliAika = 0;
                return 0;                       //time out
        }
}

int pelinTiedot::tarkistaAika()
{
                return peliAika;
}

void pelinTiedot::paivitaAika(int maara)
{
        int aika = peliAika;
        aika = aika - maara;
        peliAika = aika;
}

