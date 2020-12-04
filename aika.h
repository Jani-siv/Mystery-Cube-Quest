#ifndef AIKA_H
#define AIKA_H
#include "lcd.h"
#include "debug.h"

class aika
{
                public:
                
                bool yleinenAika = false;                 //aika keskeytyksen alustus
                unsigned long int keskeytysMillis = 0;    
                void alustaAika(int maara);         
                int vahennaAika(int maara); 
                void paivitaAika(int maara);
                //void yleinenAika();                 //vähentää pääkellosta 1 sekunnin
                int tarkistaAika();
                void yleinenAikaFunktio(LCD* objekti); 
                debug var;
                debug *variable = &var;//aika keskeytys
                                                                            
                int kymmin = 10;                                //pääkellon minuutit ja sekunnit
                int minuutit = 0;                                                       
                int kymsek = 0;                                                     
                int sekunnit = 0;                                                   
                                                                                    
                
                
                int aikaMin = 10;                               //keskeytyksen aika minuuttia      
                int aikaSec = 0;                                //keskeytyksen aika sekunttia      
                
                unsigned long int millisFunktiossa = 0;
};                                                                                                 
#endif   
