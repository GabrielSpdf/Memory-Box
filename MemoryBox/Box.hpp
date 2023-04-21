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

#define BOTtoken "TOKENBOTTELEGRAM"  
#define CHAT_ID "CHATBOTTELEGRAM"
#define WIFI_User "NOMEWIFI"
#define WIFI_PW "SENHAWIFI"

#define BUZZER 16

void handleNewMessages(int numNewMessages);
void conectaWifi();
void verificaMensagem();
