#include <U8g2lib.h>
#include <NTPClient.h>
#include <WifiUdp.h>
#include <HTTPClient.h>

#include "Box.hpp"
#include "Song.hpp"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

void u8g2_prepare();
void menu_principal();
void menu_musica1();
void menu_musica2();
void menu_musica3();
void menu_especial();
void draw();
void inicializa_display();
void desenha_display();
void verifica_botoes();
void setDisplayRotation(const u8g2_cb_t *u8g2_cb);

void inicializa_tempo();
void atualiza_horario();

String httpGETRequest(const char* serverName);
void inicializa_clima();
void atualiza_clima();
void verifica_clima();

void inicia_cronometro();

int isDigit( const char * str );

