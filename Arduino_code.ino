const int led=13;
int value=0;
int SPEAKER=10;
int freq=7000;
void setup() 
   { 
      Serial.begin(9600); 
      pinMode(led, OUTPUT);
      pinMode(SPEAKER, OUTPUT);
      digitalWrite (led, LOW);
      Serial.println("Connection established...");
   }
 
void loop() 
   {
     while (Serial.available())
        {
           value = Serial.read();
        }
     
     if (value == '1'){
        digitalWrite (led, HIGH);
        freq+=100;
        if(freq>8000)
        {
           noTone(SPEAKER);
           delay(200);
           freq=50;
        }         
        tone(SPEAKER,freq);
        delay(200);
     }     
     else if (value == '0')
        digitalWrite (led, LOW);
        noTone(SPEAKER);
           freq=50;
   }