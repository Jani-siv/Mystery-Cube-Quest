//library for time functions for arduino
// c Jani Sivonen
//setting time for game
void alustaAika(int maara);
//decrease time if player make error
int vahennaAika(int maara);
//update time in lcd screen
void paivitaAika(int maara);
// check how much time is left in game
int tarkistaAika();

void alustaAika(int maara)			//time set in seconds
{
	peliAika = maara;
}

int vahennaAika(int maara)
{
	if (maara > peliAika)
	{
		peliAika = peliAika - maara;
		return 1;			//return succesfull 1
	}
	else
	{
		gameOver = 1;
		peliAika = 0;
		return 0;			//time out
	}
}

int tarkistaAika()
{
		return peliAika;
}

void paivitaAika(int maara)
{
	int aika = tarkistaAika();
	aika = aika - maara;
	peliAika = aika;
}





