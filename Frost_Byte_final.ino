/* arduino sound meter developed by Frostbyte*/
const int sampleWindow = 50;
unsigned int sample;
void setup() {
Serial.begin(9600);
}
void loop() {
unsigned long startMillis= millis();
unsigned int peaktopeak= 0;

unsigned int signalMax = 0;
unsigned int signalMin = 1024;
while (millis() - startMillis < sampleWindow){
sample = analogRead(0);
if(sample < 1024)
{
if (sample > signalMax)
{
signalMax = sample;
}
else if (sample < signalMin)
{
signalMin = sample;

}
}
}
peaktopeak = signalMax - signalMin;
double volts = ((peaktopeak * 3.3)/ 1024) * 0.707;
double firstvalue = log10(volts/0.00631)*20;
double secondvalue = firstvalue + 94 - 44 -25;
Serial.println(secondvalue);


}


