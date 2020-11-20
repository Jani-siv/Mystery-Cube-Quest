#include "debug.h"
#include "Arduino.h"
void debug::debugInt(int tulostus)
{
        if (debug::debugLCD == 1 && debug::debugAika == 0)
        {
                Serial.print("Debug LCD value: ");
                Serial.println(tulostus);

        }
        if (debug::debugAika == 1 && debug::debugLCD == 0)
        {
                Serial.print("Debug Aika message: ");
                Serial.println(tulostus);


        }
        if (debug::debugAika == 1 && debugLCD == 1)
        {
                Serial.println("only one class at time");
        }
}

