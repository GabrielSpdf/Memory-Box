#include "Song.hpp"

/*Star Wars - The Imperial March*/

int contador = 0;

void tom(int frequencia, int duracao)
{
  //EXECUTA O TOM CONFORME OS PARÂMETROS PASSADOS
  tone(BUZZER, frequencia, duracao); 
   
  if(contador % 2 == 0) //SE contador FOR UM NÚMERO PAR, FAZ
  { 
    delay(duracao); //INTERVALO DE ACORDO COM O VALOR DA VARIÁVEL
  }
  else //SENÃO, FAZ
  {
    delay(duracao); //INTERVALO DE ACORDO COM O VALOR DA VARIÁVEL
  }

  noTone(BUZZER); //BUZZER PERMANECE DESLIGADO
  delay(50); //INTEVALO DE 50 MILISSEGUNDOS
  contador++; //INCREMENTADOR O CONTADOR
}
  
//FUNÇÃO DA PRIMEIRA SEÇÃO
void primeraSecao()
{
  tom(NOTE_a, 500);
  tom(NOTE_a, 500);    
  tom(NOTE_a, 500);
  tom(NOTE_f, 350);
  tom(NOTE_cH, 150);  
  tom(NOTE_a, 500);
  tom(NOTE_f, 350);
  tom(NOTE_cH, 150);
  tom(NOTE_a, 650);
  
  delay(500); //INTEVALO DE 500 MILISSEGUNDOS
  
  tom(NOTE_eH, 500);
  tom(NOTE_eH, 500);
  tom(NOTE_eH, 500);  
  tom(NOTE_fH, 350);
  tom(NOTE_cH, 150);
  tom(NOTE_gS, 500);
  tom(NOTE_f, 350);
  tom(NOTE_cH, 150);
  tom(NOTE_a, 650);
  
  delay(500); //INTEVALO DE 500 MILISSEGUNDOS
}
  
//FUNÇÃO DA SEGUNDA SEÇÃO  
void segundaSecao()
{
  tom(NOTE_aH, 500);
  tom(NOTE_a, 300);
  tom(NOTE_a, 150);
  tom(NOTE_aH, 500);
  tom(NOTE_gSH, 325);
  tom(NOTE_gH, 175);
  tom(NOTE_fSH, 125);
  tom(NOTE_fH, 125);    
  tom(NOTE_fSH, 250);
  
  delay(325); //INTEVALO DE 325 MILISSEGUNDOS
  
  tom(NOTE_a, 250);
  tom(NOTE_dSH, 500);
  tom(NOTE_dH, 325);  
  tom(NOTE_cSH, 175);  
  tom(NOTE_cH, 125);  
  tom(NOTE_b, 125);  
  tom(NOTE_cH, 250);  
  
  delay(350); //INTEVALO DE 350 MILISSEGUNDOS
}

void SWTheImperialMarch()
{
    primeraSecao(); //CHAMADA DE SONS DA PRIMEIRA SEÇÃO
    segundaSecao(); //CHAMADA DE SONS DA SEGUNDA SEÇÃO

    //VARIANTE 1
    tom(NOTE_f, 250);  
    tom(NOTE_gS, 500);  
    tom(NOTE_f, 350);  
    tom(NOTE_a, 125);
    tom(NOTE_cH, 500);
    tom(NOTE_a, 375);  
    tom(NOTE_cH, 125);
    tom(NOTE_eH, 650);

    delay(500); //INTEVALO DE 500 MILISSEGUNDOS

    segundaSecao(); //CHAMADA DE TONS DA SEGUNDA SEÇÃO

    //VARIANTE 2
    tom(NOTE_f, 250);  
    tom(NOTE_gS, 500);  
    tom(NOTE_f, 375);  
    tom(NOTE_cH, 125);
    tom(NOTE_a, 500);  
    tom(NOTE_f, 375);  
    tom(NOTE_cH, 125);
    tom(NOTE_a, 650);  

    delay(650); //INTEVALO DE 650 MILISSEGUNDOS
}

/************************************************************/
/*Happy Birthday*/

int melody_hb[] = 
{
  NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
  NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
  NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

  NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
  NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
  NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2,
};

int tempo_hb = 140;
int notes_hb = sizeof(melody_hb) / sizeof(melody_hb[0]) / 2;
int wholenote_hb = (60000 * 4) / tempo_hb;
int divider_hb = 0, noteDuration_hb = 0;

void HappyBirthday() 
{
  for (int thisNote = 0; thisNote < notes_hb * 2; thisNote = thisNote + 2) 
  {
    // calculates the duration of each note
    divider_hb = melody_hb[thisNote + 1];
    if (divider_hb > 0) 
    {
      // regular note, just proceed
      noteDuration_hb = (wholenote_hb) / divider_hb;
    }

    else if (divider_hb < 0) 
    {
      // dotted notes are represented with negative durations!!
      noteDuration_hb = (wholenote_hb) / abs(divider_hb);
      noteDuration_hb *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(BUZZER, melody_hb[thisNote], noteDuration_hb * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration_hb);

    // stop the waveform generation before the next note.
    noTone(BUZZER);
  }
}

/**************************/
/*Never Gonna Give You Up - Rick Astley*/

int tempo_nggyu = 114;

int melody_nggyu[] = {

  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //1
  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //repeat from 1
  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
  REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
  NOTE_B4,16, NOTE_A4,2, REST,4, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,4, NOTE_A4,8, //7
  NOTE_A5,8, REST,8, NOTE_A5,8, NOTE_E5,-4, REST,4, 
  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,8, REST,8,
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, REST,4,
   
  NOTE_D5,2, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8, //13
  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, NOTE_A4,4,
  REST,2, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8,
  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
  NOTE_E5,4, NOTE_D5,2, REST,4,
  REST,8, NOTE_B4,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,4, REST,8,
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
  REST,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_D5,8,
  
  REST,8, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //29
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4, REST,8,
  REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,4, NOTE_E5,-4, 
  NOTE_D5,2, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, 
  NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_A4,8, NOTE_A4,4,

  REST,-4, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //35
  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 

  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //40
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
   
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
  
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 

  NOTE_E5,4, NOTE_D5,2, REST,4
};

int notes_nggyu = sizeof(melody_nggyu) / sizeof(melody_nggyu[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote_nggyu = (60000 * 4) / tempo_nggyu;

int divider_nggyu = 0, noteDuration_nggyu = 0;

void NGGYU()
{
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes_nggyu * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider_nggyu = melody_nggyu[thisNote + 1];
    if (divider_nggyu > 0) {
      // regular note, just proceed
      noteDuration_nggyu = (wholenote_nggyu) / divider_nggyu;
    } else if (divider_nggyu < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration_nggyu = (wholenote_nggyu) / abs(divider_nggyu);
      noteDuration_nggyu *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(BUZZER, melody_nggyu[thisNote], noteDuration_nggyu * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration_nggyu);

    // stop the waveform generation before the next note.
    noTone(BUZZER);
  }
}


/*************************/
/*Attack on Titan Season 2 OP - Shinzou wo Sasageyo*/

int tempo_shingeki = 80; //Tempo musica

int melody_shingeki[] = {
//1
NOTE_A4,32, NOTE_CS5,32, NOTE_C5,32, NOTE_A4,16, NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_E5,16, NOTE_A4,16, 
NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_E5,16,

NOTE_A4,16, NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_E5,8 ,NOTE_C5,8 ,NOTE_D5,8 ,NOTE_B4,8, 
NOTE_C5,16,

//4
NOTE_FS3,16, NOTE_CS4,8, NOTE_D4,8 ,NOTE_B3,8 ,NOTE_CS4,8, NOTE_CS4,8, NOTE_D4,8
,NOTE_B3,8 ,NOTE_FS3,16,

//6
NOTE_FS3,16, NOTE_CS4,8, NOTE_D4,8 ,NOTE_B3,8 ,NOTE_CS4,8, NOTE_CS4,8, NOTE_D4,8 ,NOTE_B3,8 ,
NOTE_FS3,32, NOTE_FS3,32, 
NOTE_FS3,16, NOTE_CS4,8, NOTE_D4,-8, NOTE_B3,16, NOTE_CS4,8, NOTE_CS4,8, NOTE_CS4,8, 
NOTE_FS3,32, NOTE_GS3,32, NOTE_CS4,32, NOTE_F4,32, NOTE_GS4,32, NOTE_CS5,32,

//8
NOTE_A4,16, NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_E5,8 ,NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,
NOTE_A4,16, 
NOTE_A4,16, NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_E5,8 ,NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_A4,16, 
NOTE_A4,16, NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_E5,8 ,NOTE_E5,8 ,NOTE_F5,8 ,NOTE_D5,8 ,NOTE_A4,32, NOTE_A4,32,

//11
NOTE_A4,16, NOTE_E5,8 ,NOTE_F5,-8, NOTE_D5,16, NOTE_D5,8 ,NOTE_E5,8 ,NOTE_A6,-16, 
NOTE_A4,-16,
NOTE_CS5,16, NOTE_B4,16, NOTE_A4,16, NOTE_GS4,16, NOTE_FS4,16, NOTE_GS4,16, NOTE_A4,16,
NOTE_E5,16, NOTE_E5,-8, NOTE_B4,16, NOTE_CS5,8, NOTE_B4,8
,
//13 
NOTE_FS4,16, NOTE_GS4,16, NOTE_A4,16, NOTE_CS5,16,
NOTE_B4,16, NOTE_A4,16, NOTE_GS4,16, NOTE_E4,16,
NOTE_E5,16, NOTE_FS5,16, NOTE_E5,-16, NOTE_B4,32, 
NOTE_CS5,8, NOTE_A4,32, NOTE_B4,32, NOTE_CS5,32, NOTE_D5,32,
NOTE_E5,16, NOTE_D5,16, NOTE_CS5,16, NOTE_A4,16, NOTE_B4,16, NOTE_CS5,16,
NOTE_E5,16, NOTE_D5,16, NOTE_CS5,16, NOTE_D5,-16, NOTE_G5,32, NOTE_G5,8
,NOTE_D5,8,

//15
NOTE_E5,16, NOTE_D5,16, NOTE_C5,16, NOTE_B4,16,
NOTE_A4,16, NOTE_B4,16, NOTE_C5,16, NOTE_E5,16,
NOTE_D5,-8, NOTE_B4,16, NOTE_E5,8, NOTE_E5,8, NOTE_E5,8,
NOTE_E5,16, NOTE_D5,16, NOTE_C5,16, NOTE_B4,16, NOTE_A4,16, NOTE_C5,8, NOTE_E5,16,
NOTE_D5,16, NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, NOTE_D5,16, NOTE_G5,8,

//17
NOTE_E5,16, NOTE_D5,16, NOTE_C5,16, NOTE_B4,16,
NOTE_A4,16, NOTE_B4,16, NOTE_C5,16, NOTE_E5,16,
NOTE_G5,-8, NOTE_D5,16,
NOTE_E5,-8, NOTE_D5,32, NOTE_E5,32,
NOTE_F5,-8, NOTE_D5,32, NOTE_F5,32,
NOTE_FS5,16, NOTE_DS5,16, NOTE_FS5,16, NOTE_A5,16,
NOTE_A5,-8, NOTE_GS5,16,
NOTE_GS5,16, NOTE_E5,16, NOTE_B4,16, NOTE_GS4,16, NOTE_E4,16, NOTE_C5,16,

//19
NOTE_C5,-8, NOTE_D5,16, NOTE_D5,-8, NOTE_F5,16, NOTE_F5,-8, NOTE_E5,16, NOTE_E5,-8,
NOTE_C5,16,
NOTE_C5,-8, NOTE_C5,16, NOTE_D5,16, NOTE_C5,16, NOTE_B4,16, NOTE_A4,16, 
NOTE_A4,-8, NOTE_G4,16,
NOTE_G4,-8, NOTE_C6,16,
NOTE_C5,16, NOTE_F4,16, NOTE_A4,16, NOTE_D5,16,
NOTE_D5,16, NOTE_G4,16, NOTE_B4,16, NOTE_F5,16, 
NOTE_F5,-8, NOTE_E5,16,
NOTE_E5,8, NOTE_C5,16,

//22
NOTE_C5,-8, NOTE_C5,16,
NOTE_D5,16, NOTE_C5,16, NOTE_D5,16, NOTE_F5,16,
NOTE_A5,-8, NOTE_GS5,16,
NOTE_GS5,16, NOTE_D6,16, NOTE_B4,16, NOTE_E5,16,
NOTE_DS5,-8, NOTE_F5,16,
NOTE_F5,-8, NOTE_A5,16,
NOTE_A5,-8, NOTE_G5,16, NOTE_G5,-8, NOTE_DS5,16,

//24
NOTE_DS5,-8, NOTE_DS5,16,
NOTE_F5,16, NOTE_DS5,16, NOTE_D5,16, NOTE_C5,16,
NOTE_C5,-8, NOTE_AS5,16,
NOTE_AS5,-8, NOTE_DS5,16,
NOTE_E5,32, NOTE_G5,32, NOTE_E4,32, NOTE_E5,32, NOTE_G4,32, NOTE_E4,32,
NOTE_F5,16,
NOTE_F5,32, NOTE_B4,32, NOTE_F4,32, NOTE_F5,32, NOTE_B4,32, NOTE_F4,32, NOTE_A5,16,
NOTE_A5,32, NOTE_E5,32, NOTE_A4,32, NOTE_A5,32, NOTE_E5,32, NOTE_A4,32, NOTE_G5,16,
NOTE_G5,32, NOTE_E5,32, NOTE_G4,32, NOTE_G5,32, NOTE_E5,32, NOTE_G4,32,
NOTE_E5,16,

//26
NOTE_DS5,-8, NOTE_DS5,16,
NOTE_F5,16, NOTE_DS5,16, NOTE_D5,16, NOTE_AS5,16,
NOTE_C5,16, NOTE_G5,16, NOTE_C5,16, NOTE_A5,16,
NOTE_C5,16, NOTE_F5,16, NOTE_C5,16, NOTE_G5,16,
NOTE_C5,16, NOTE_G5,16, NOTE_C5,16, NOTE_A5,16,
NOTE_C5,16, NOTE_F5,16, NOTE_C5,16, NOTE_G5,16,
NOTE_C5,16, NOTE_G5,16, NOTE_C5,16, NOTE_A5,16,
NOTE_C5,16, NOTE_F5,16, NOTE_C5,16, NOTE_G5,16,

//28
NOTE_C5,16, NOTE_E5,16, NOTE_C5,16, NOTE_F5,16,
NOTE_D5,16, NOTE_E5,32, NOTE_F5,32, NOTE_FS5,32, NOTE_A5,32,
NOTE_B5,16, NOTE_B5,16, NOTE_E5,16, NOTE_C6,16, //BS5 PARA C6
NOTE_E5,16, NOTE_A5,16, NOTE_E5,16, NOTE_B5,16,
NOTE_E5,16, NOTE_B5,16, NOTE_E5,16, NOTE_C6,16, //BS5 PARA C6
NOTE_E5,16, NOTE_A5,16, NOTE_E5,16, NOTE_B5,16,
NOTE_E5,16, NOTE_B5,16, NOTE_E5,16, NOTE_C6,16, //BS5 PARA C6
NOTE_E5,16, NOTE_A5,16, NOTE_E5,16, NOTE_B5,16,

//30
NOTE_B5,16, NOTE_FS5,8, NOTE_A5,8, NOTE_F5,8, NOTE_FS5,16,
NOTE_DS5,2, NOTE_FS5,32, NOTE_B5,32, NOTE_E6,32,
};

int notes_shingeki = sizeof(melody_shingeki) / sizeof(melody_shingeki[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote_shingeki = (60000 * 4) / tempo_shingeki;

int divider_shingeki = 0, noteDuration_shingeki = 0;

void AOTS2OP()
{
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes_shingeki * 2; thisNote = thisNote + 2) 
  {
    // calculates the duration of each note
    divider_shingeki = melody_shingeki[thisNote + 1];
    if (divider_shingeki > 0) {
      // regular note, just proceed
      noteDuration_shingeki = (wholenote_shingeki) / divider_shingeki;
    } else if (divider_shingeki < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration_shingeki = (wholenote_shingeki) / abs(divider_shingeki);
      noteDuration_shingeki *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(BUZZER, melody_shingeki[thisNote], noteDuration_shingeki * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration_shingeki);

    // stop the waveform generation before the next note.
    noTone(BUZZER);
  }
}

/**************************/
/*Cantina Band - Star Wars*/
// Score available at https://musescore.com/user/6795541/scores/1606876

int tempo_sw2 = 140;

int melody_sw2[] = {

  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8, 
  NOTE_B4,8,  NOTE_AS4,8, NOTE_B4,8, NOTE_A4,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_G4,8,
  NOTE_G4,4,  NOTE_E4,-2, 
  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,

  NOTE_A4,-4, NOTE_A4,-4, NOTE_GS4,8, NOTE_A4,-4,
  NOTE_D5,8,  NOTE_C5,-4, NOTE_B4,-4, NOTE_A4,-4,
  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
  NOTE_D5,4, NOTE_D5,-4, NOTE_B4,8, NOTE_A4,-4,
  NOTE_G4,-4, NOTE_E4,-2,
  NOTE_E4, 2, NOTE_G4,2,
  NOTE_B4, 2, NOTE_D5,2,

  NOTE_F5, -4, NOTE_E5,-4, NOTE_AS4,8, NOTE_AS4,8, NOTE_B4,4, NOTE_G4,4, 
  
};


int notes_sw2 = sizeof(melody_sw2) / sizeof(melody_sw2[0]) / 2;

int wholenote_sw2 = (60000 * 2) / tempo_sw2;

int divider_sw2 = 0, noteDuration_sw2 = 0;

void StarWars2() 
{
  for (int thisNote_sw2 = 0; thisNote_sw2 < notes_sw2 * 2; thisNote_sw2 = thisNote_sw2 + 2) {

    divider_sw2 = melody_sw2[thisNote_sw2 + 1];
    if (divider_sw2 > 0) {
      noteDuration_sw2 = (wholenote_sw2) / divider_sw2;
    } else if (divider_sw2 < 0) {
      noteDuration_sw2 = (wholenote_sw2) / abs(divider_sw2);
      noteDuration_sw2 *= 1.5; 
    }

    tone(BUZZER, melody_sw2[thisNote_sw2], noteDuration_sw2*0.9);

    delay(noteDuration_sw2);
    
    noTone(BUZZER);
  }
}


/**************************/
/*Zelda’s Lullaby - The Legend of Zelda Ocarina of time*/
// Score available at https://musescore.com/user/12754451/scores/2762776

int tempo_zelda = 108;


int melody_zelda[] = {

  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,2, NOTE_C4,8, NOTE_D4,8, 
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,-2,
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D5,2, NOTE_C5,4,
  NOTE_G4,2, NOTE_F4,8, NOTE_E4,8, 
  NOTE_D4,-2,
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,2, NOTE_C4,8, NOTE_D4,8, 
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,-2,
  NOTE_E4,2, NOTE_G4,4,

  NOTE_D5,2, NOTE_C5,4,
  NOTE_G4,2, NOTE_F4,8, NOTE_E4,8, 
  NOTE_F4,8, NOTE_E4,8, NOTE_C4,2,
  NOTE_F4,2, NOTE_E4,8, NOTE_D4,8, 
  NOTE_E4,8, NOTE_D4,8, NOTE_A3,2,
  NOTE_G4,2, NOTE_F4,8, NOTE_E4,8, 
  NOTE_F4,8, NOTE_E4,8, NOTE_C4,4, NOTE_F4,4,
  NOTE_C5,-2, 
  
};


int notes_zelda = sizeof(melody_zelda) / sizeof(melody_zelda[0]) / 2;

int wholenote_zelda = (60000 * 4) / tempo_zelda;

int divider_zelda = 0, noteDuration_zelda = 0;

void ZeldasLullaby() {
  for (int thisNote_zelda = 0; thisNote_zelda < notes_zelda * 2; thisNote_zelda = thisNote_zelda + 2) {

    divider_zelda = melody_zelda[thisNote_zelda + 1];
    if (divider_zelda > 0) {
      noteDuration_zelda = (wholenote_zelda) / divider_zelda;
    } else if (divider_zelda < 0) {
      noteDuration_zelda = (wholenote_zelda) / abs(divider_zelda);
      noteDuration_zelda *= 1.5; 
    }

    tone(BUZZER, melody_zelda[thisNote_zelda], noteDuration_zelda*0.9);

    delay(noteDuration_zelda);
    
    noTone(BUZZER);
  }
}


/**************************/
/*Tetris theme - (Korobeiniki)*/
//Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192

int tempo_tetris=144; 


int melody_tetris[] = {

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
  
  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,

};


/**************************/
/*Tetris theme - (Korobeiniki)*/
//Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192

int notes_tetris=sizeof(melody_tetris)/2/2; 

int wholenote_tetris = (60000 * 4) / tempo_tetris;

int divider_tetris = 0, noteDuration_tetris = 0;

void Tetris() {
  for (int thisNote_tetris = 0; thisNote_tetris < notes_tetris * 2; thisNote_tetris = thisNote_tetris + 2) {

    divider_tetris = melody_tetris[thisNote_tetris + 1];
    if (divider_tetris > 0) {
      noteDuration_tetris = (wholenote_tetris) / divider_tetris;
    } else if (divider_tetris < 0) {
      noteDuration_tetris = (wholenote_tetris) / abs(divider_tetris);
      noteDuration_tetris *= 1.5; 
    }

    tone(BUZZER, melody_tetris[thisNote_tetris], noteDuration_tetris*0.9);

    delay(noteDuration_tetris);
    
    noTone(BUZZER);
  }
}



/**************************/
/*Hedwig's theme - Harry Potter*/
//Score from https://musescore.com/user/3811306/scores/4906610

int tempo_harrypotter = 144;

int melody_harrypotter[] = {

  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
  REST,4, NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1, 
  
};

int notes_harrypotter = sizeof(melody_harrypotter) / sizeof(melody_harrypotter[0]) / 2;

int wholenote_harrypotter = (60000 * 4) / tempo_harrypotter;

int divider_harrypotter = 0, noteDuration_harrypotter = 0;

void HarryPotter() {
  for (int thisNote_harrypotter = 0; thisNote_harrypotter < notes_harrypotter * 2; thisNote_harrypotter = thisNote_harrypotter + 2) {

    divider_harrypotter = melody_harrypotter[thisNote_harrypotter + 1];
    if (divider_harrypotter > 0) {
      noteDuration_harrypotter = (wholenote_harrypotter) / divider_harrypotter;
    } else if (divider_harrypotter < 0) {
      noteDuration_harrypotter = (wholenote_harrypotter) / abs(divider_harrypotter);
      noteDuration_harrypotter *= 1.5; 
    }

    tone(BUZZER, melody_harrypotter[thisNote_harrypotter], noteDuration_harrypotter*0.9);

    delay(noteDuration_harrypotter);
    
    noTone(BUZZER);
  }
}