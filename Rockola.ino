
//Definimos el valor y sonido de
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175

#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311

#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494

#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_AS5 932

#define NOTE_E6  1319
#define NOTE_G6  1568
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_G7  3136
#define NOTE_A7  3520

#define REST 0


//Incluimos libreria de la lcd
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Definimos pines de cada componente.
int led = 13;
int buz = 1;
const int b1 = 10;
const int b2 = 9;
const int b5 = 8;
const int sig = 6;
const int play = 7;

int lista[2] = {1,2};
int costo[] = {7,5};
int cont = 0;
int sum = 0;

//Inicializamos variables para guardar estados de los botones.
int e1 = 0;  
int e2 = 0;

int c_anterior = 0;
int anterior = 0;
///////////////////////////////////////////////////////////

//Melodia de las canciones usando notas definidas. 
//------------------Cancion Supero Mario------------------//
int melodys[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempos[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  
  
};
//Underworld melody
int underworld_melodys[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempos[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

  int song = 0;



void setup()
{
  //Serial.begin(9600);
  lcd.begin(16,2); //Inicializamos la lcd para
             //poder mostrar los mensajes. 
  
  
  //Definimos las salidas y entradas
  pinMode(buz,OUTPUT);
  pinMode(b1,INPUT_PULLUP);
  pinMode(b2,INPUT_PULLUP);
  pinMode(b5,INPUT_PULLUP);
  pinMode(sig,INPUT_PULLUP);
  pinMode(play,INPUT_PULLUP);
  pinMode(led, OUTPUT);

}

void loop()
{ 
  
  if(cont == 0){
   lcd.setCursor(0,0);
   lcd.print("Main Theme");
  } 
  
  if(cont == 1){
   lcd.setCursor(0,0);
   lcd.print("Underworld");
  }
  
  lcd.setCursor(0,1);
  lcd.print("Costo: "+String(costo[cont]) +", $: "+ String(sum));
  
  if (digitalRead(b1) == HIGH){
    sum++;
   delay(500);
  }
  
  if (digitalRead(b2) == HIGH){
    sum+=2;
   delay(500);
  }
  
  if (digitalRead(b5) == HIGH){
    sum+=5;
   delay(500);
  }
  
  if (digitalRead(sig) == HIGH){
    
    if(cont == 1){
      cont=0;
    }else{
      cont++;
    }
    lcd.clear();
  }
  if (digitalRead(play) == HIGH) {
    if (sum < costo[cont]){
     lcd.setCursor(0,0);
     lcd.clear();
     lcd.print("Dinero insuficiente");
     delay(1000);
     lcd.scrollDisplayLeft();
     delay(1000);
     lcd.scrollDisplayLeft();
     delay(1000);
     lcd.scrollDisplayLeft();
     delay(3000);
     lcd.clear();
    }else{
      if(cont == 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Reproduciendo:");
        lcd.setCursor(0,1);
        lcd.print("Main Theme");
     	sing(1);
        sum=sum-costo[cont];
        lcd.clear();
     	
      }
      if(cont == 1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Reproduciendo:");
        lcd.setCursor(0,1);
        lcd.print("Underworld");
		sing(2);
        sum=sum-costo[cont];
        lcd.clear();
      }
    }
  
  }
  
}
//Codigo para la canción de mario. 
void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melodys) / sizeof(int);
    for (int thisNotes = 0; thisNotes < size; thisNotes++) {
 
    // calcula la duracion de la nota
      int noteDurations = 1000 / underworld_tempos[thisNotes];
 
      tone(buz, underworld_melodys[thisNotes], noteDurations);
 
      // Se define la duracion dependiendo la nota que suena 
      int pauseBetweenNotess = noteDurations * 1.30;
      delay(pauseBetweenNotess);
 
      // Determina el final de la nota o melodia 
      tone(buz, 0, noteDurations);
 
    }
 
  } else {
 
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melodys) / sizeof(int);
    for (int thisNotes = 0; thisNotes < size; thisNotes++) {
 
      // calcula la duracion de la nota
      int noteDurations = 1000 / tempos[thisNotes];
 
      tone(buz, melodys[thisNotes], noteDurations);
 
      // Se define la duracion dependiendo la nota que suena 
      int pauseBetweenNotess = noteDurations * 1.30;
      delay(pauseBetweenNotess);
 
      // Determina el final de la nota o melodia 
      //tone(buz, 0, noteDurations);
 
    }
  }
}

