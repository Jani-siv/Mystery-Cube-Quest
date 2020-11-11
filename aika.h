//library for time functions for arduino
// c Jani Sivonen
//setting time for game
void pelinTiedot*::alustaAika(int maara);
//decrease time if player make error
int pelinTiedot::vahennaAika(int maara);
//update time in lcd screen
void pelinTiedot::paivitaAika(int maara);
// check how much time is left in game
int pelinTiedot::tarkistaAika();

void pelinTiedot*::alustaAika(int maara)			//time set in seconds
{
	peliAika = maara;
}

int pelinTiedot::vahennaAika(int maara)
{
	if (maara > peliAika)
	{
		peliAika = peliAika - maara;
		return 1;			//return succesfull 
	}
	else
	{
		gameOver = 1;
		peliAika = 0;
		return 0;			//time out
	}
}

int pelinTiedot::tarkistaAika()
{
		return peliAika;
}

void pelinTiedot::paivitaAika(int maara)
{
	int aika = tarkistaAika();
	aika = aika - maara;
	peliAika = aika;
}





