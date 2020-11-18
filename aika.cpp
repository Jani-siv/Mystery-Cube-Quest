#include "aika.h"
void aika::yleinenAika(LCD* objekti)
{
  if (aika::sekunnit > 0)
  	{
    		aika::sekunnit--;
  	}
  else if (aika::sekunnit == 0 && aika::kymsek > 0)
  	{
    		aika::sekunnit = 9;
    		aika::kymsek--;
  	}
  else if (aika::kymsek == 0 && aika::minuutit > 0)
  	{
  		aika::kymsek = 5;
  		aika::minuutit--;  
  	}
  else if (aika::minuutit == 0 && aika::kymmin >0)
  	{
    		aika::kymmin--;
    		aika::minuutit = 9;
    		aika::kymsek = 5;
    		aika::sekunnit = 9;
  	}
  else if (aika::kymmin == 0 && aika::minuutit == 0 && aika::kymsek == 0 && aika::sekunnit == 0)
  	{
    		aika::gameOver = 1;
  	}
  objekti->updateTime(aika::kymmin, aika::minuutit, aika::kymsek, aika::sekunnit);


}

