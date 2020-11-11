//library for time functions for arduino
// c Jani Sivonen
//setting time for game
class pelinTiedot
{
	private:
		int peliAika;
		int lukot;
		int gameOver = 0;
	public:
		void alustaAika(int maara);
		int vahennaAika(int maara);
		void paivitaAika(int maara);
		int tarkistaAika();
};

int main()
{
	return 0;
}



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


