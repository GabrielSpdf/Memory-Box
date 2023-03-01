#include "Box.hpp"
#include "Song.hpp"
#include "Display.hpp"


void setup() 
{
  Serial.begin(115200);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  
  conectaWifi();

  inicializa_clima();
  inicializa_tempo();
  inicializa_display();
  inicia_cronometro();
}

void loop() 
{
  //verificaMensagem();
  desenha_display();
}