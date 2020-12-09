int vipu1=0, vipu2=0, vipu3=0, vipu4=0, total=0, vastaus = 0;
int stopButton = 0;
int kysymys;

void setup()
{
        pinMode(2,INPUT);
        pinMode(3,INPUT);
        pinMode(4,INPUT);
        pinMode(5,INPUT);
        pinMode(6,INPUT);
        int randomSeed = analogRead(A4);
        Serial.begin(9600);
}




void loop()
{
        if (vastaus == 0)
        {
          Serial.println(kysymys);
        }
int button = digitalRead(6);
if (button == LOW && stopButton == 0)
{
        stopButton = 1;

        vipu1 = 0;
        vipu2 = 0;
        vipu3 = 0;
        vipu4 = 0;

}
if (button == HIGH && stopButton == 1)
{
        vipu1 = digitalRead(2); 
        vipu2 = digitalRead(3); 
        vipu3 = digitalRead(4); 
        vipu4 = digitalRead(5); 

        if (vipu1 == HIGH)
        {
                vipu1 = 1;
        }
        if (vipu2 == HIGH)
        {
                vipu2 = 2;
        }
        if (vipu3 == HIGH)
        {
                vipu3 = 4;
        }
        if (vipu4 == HIGH)
        {
                vipu4 = 8;
        }
        total = vipu1 + vipu2 + vipu3 + vipu4;
        stopButton = 0;
        vastaus = 1;

}
if (vastaus == 1)
{
        if (total == kysymys)
        {
                Serial.println("Oikein");
                kysymys = random(1,15);
                vastaus = 0;
        }
        else if (total != kysymys)
        {
                Serial.println("väärin, Aseta vipu kytkimet uudelleen");
                vastaus = 0;
        }
}
}
