#ifndef AIKA_H
#define AIKA_H
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
#endif
