#include "Box.hpp"
#include "Song.hpp"
#include "Display.hpp"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checa por mensagens a cada 1 segundo
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
int tempo_reset=0;

void conectaWifi()
{
  //Conecta ao WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_User, WIFI_PW);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); //Add root certificate for api.telegram.org
  #endif
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Conectando ao WiFi..");
    tempo_reset++;

    if(tempo_reset>5)
    {
      Serial.println("Reiniciando ESP32");
      delay(3000);
      ESP.restart();
    }
  }
  //Imprime o endereco de IP Local da ESP32
  Serial.println(WiFi.localIP());
}

void verificaMensagem()
{
  if (millis() > lastTimeBotRan + botRequestDelay)  
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) 
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}

//Verifica novas mensagens
void handleNewMessages(int numNewMessages) 
{
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) 
  {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID)
    {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    //Imprime a mensagem 
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;


    /*Comandos para o usuario do Telegram*/

    if (text == "/iniciar") 
    {
      String welcome = "Bem-vindo, " + from_name + ".\n";
      welcome += "Use os seguintes comandos para controlar seu sistema.\n\n";
      welcome += "/starwars para tocar The Imperial March (Darth Vader's Theme) - Star Wars \n";
      welcome += "/felizaniversario para tocar Happy Birthday To You - Eddy Arnold \n";
      welcome += "/nevergonnagiveyouup para tocar Never Gonna Give You Up - Rick Astley \n";
      welcome += "/shingeki para tocar Attack on Titan Season 2 OP - Shinzou wo Sasageyo! \n";
      welcome += "/starwars2 para tocar Cantina Band - Star Wars \n";
      welcome += "/zelda para tocar Zelda’s Lullaby - The Legend of Zelda Ocarina of time \n";
      welcome += "/tetris para tocar Tetris theme - (Korobeiniki) \n";
      welcome += "/harrypotter para tocar Hedwig's theme - Harry Potter \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/starwars")
    {
      SWTheImperialMarch();
    }

    if(text == "/felizaniversario")
    {
      HappyBirthday();
    }

    if(text == "/nevergonnagiveyouup")
    {
      NGGYU();
    } 

    if(text == "/shingeki")
    {
      AOTS2OP();
    }

    if(text == "/starwars2")
    {
      StarWars2();
    }

    if(text == "/zelda")
    {
      ZeldasLullaby();
    }

    if(text == "/tetris")
    {
      Tetris();
    }

    if(text == "/harrypotter")
    {
      HarryPotter();
    }
  }
}