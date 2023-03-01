#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h> 
#include <Arduino.h>
#include <Arduino_JSON.h>
#include "time.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define BOTtoken "5967903288:AAFtl9LXEiuOHNe8goJzHhdf3kqYX3aUbLY"  
#define CHAT_ID "1716025024"
#define WIFI_User "-2.4G"
#define WIFI_PW "z^C9Mjn7@vRNqR3dH2#t"

#define BUZZER 16

void handleNewMessages(int numNewMessages);
void conectaWifi();
void verificaMensagem();