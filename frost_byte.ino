const int sampleWindow = 50;
unsigned int sample;
void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis= millis();
  float peaktopeak= 0;
  
  unsigned int signalMax = 1024;
  unsigned int signelMin = 0;

  while (millis() - startMillis < sampleWindow){
    sample = analogRead(0);
    if(sample < 1024)
    {
      if (sample > signalMax)
      {
        signalMin = sample; 
      }
      else if (sample < signalMin)
      {
       signalMin = sample; 
        
      }
    }
  }
  peaktopeak = signalMax - signalMin;
  float db = map(peaktopeak,20,900,49.5,90);
  print
}

