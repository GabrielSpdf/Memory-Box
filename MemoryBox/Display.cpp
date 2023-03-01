#include "Display.hpp"
#include <string.h>

//http://api.openweathermap.org/data/2.5/weather?q=Curitiba,BR&APPID=f841d71951d42d2132c65fadf6cd203b

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 23, /* CS=*/ 5, /* reset=*/ 22); // ESP32

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//U8GLIB_ST7920_128X64_1X u8g(5, 4, 3 ,6);

const char DEGREE_SYMBOL[] = { 0xB0, '\0' };

const char* dayName[7] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
const char* monName[12] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

int botao1 = 27; //FUNCIONA
int botao2 = 33; //FUNCIONA
int botao3 = 25; //FUNCIONA 
int botao4 = 32; //FUNCIONA
int botao5 = 26; //FUNCIONA

int valor1 = 1; 
int valor2 = 1; 
int valor3 = 1;
int valor4 = 1;
int valor5 = 1;

int menu_atual = 0;
int verifica_menu = 0;
int flag = 0;

double tempo_passado = 0.0;
int tempo_aux = 0;

String horario;
String dia_semana;
String mes_atual;

int dia, mes, ano;


String city = "Curitiba";
String stateCode = "PR";
String countryCode = "BR";
String openWeatherMapApiKey = "f841d71951d42d2132c65fadf6cd203b";

//https://api.openweathermap.org/data/2.5/weather?q=Curitiba,PR,BR&appid=f841d71951d42d2132c65fadf6cd203b

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=";
const String key = "f841d71951d42d2132c65fadf6cd203b";

//https://api.openweathermap.org/data/2.5/weather?lat=-25.504&lon=-49.2908&appid=f841d71951d42d2132c65fadf6cd203b&units=metric

String jsonBuffer;
String pathAux;

JSONVar temperatura;

String temp;

int isDigit( const char * str )
{
    if(!str) return 0;     /* Se string for NULL, retorna 0 */
    if(!(*str)) return 0;  /* Se string for VAZIA, retorna 0 */

    while( *str )
        if( !isdigit( *str++ ) )
            return 0;     

    return 1;
}

void inicializa_clima()
{
    HTTPClient http;

    pathAux = endpoint + city + "," + stateCode + "," + countryCode + "&appid=" + key + "&units=metric";

    http.begin(pathAux);
    int httpCode = http.GET();

    if(httpCode > 0)
    {
        //String payload = http.getString();
        //Serial.println(jsonBuffer);
        //Serial.println(httpCode);
        //Serial.println(payload);
        jsonBuffer = httpGETRequest(pathAux.c_str());
        JSONVar myObject = JSON.parse(jsonBuffer);
        Serial.println(myObject["main"]["temp"]);
        temperatura = myObject["main"]["temp"]; 
        temp = ((JSON.stringify(temperatura)).substring(2,0));
        if((JSON.stringify(temperatura)) == "false" || (isDigit(((JSON.stringify(temperatura)).substring(2,0)).c_str())) == 0)
        {
            Serial.println("Erro atualiza clima");
            atualiza_clima();    
        }
    }

    else 
    {
        Serial.println("Erro na requisicao HTTP");
    }

    http.end();
}

void atualiza_clima()
{
    jsonBuffer = httpGETRequest(pathAux.c_str());
    JSONVar myObject = JSON.parse(jsonBuffer);
    Serial.println(myObject["main"]["temp"]);
    temperatura = myObject["main"]["temp"];
    temp = ((JSON.stringify(temperatura)).substring(2,0));

    if((JSON.stringify(temperatura)) == "false" || (isDigit(((JSON.stringify(temperatura)).substring(2,0)).c_str())) == 0)
    {
      Serial.println("Erro atualzia clima");
      atualiza_clima();    
    }
}

void verifica_clima()
{
    if((JSON.stringify(temperatura)) == "false" || (isDigit(((JSON.stringify(temperatura)).substring(2,0)).c_str())) == 0)
    {
      Serial.println("Erro atualzia clima AQUIII");
      atualiza_clima();    
    }  
}

String httpGETRequest(const char* serverName) 
{
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) 
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }

  else 
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println("Tentando novamente requisicao");
    httpGETRequest(serverName);
  }
  // Free resources
  http.end();

  return payload;
}

void inicializa_tempo() 
{
  timeClient.begin();
  timeClient.setTimeOffset(-10800);
}

void inicia_cronometro()
{
  tempo_passado = millis();
}

void atualiza_horario() 
{
  timeClient.update();
  horario = timeClient.getFormattedTime();
  dia_semana = dayName[timeClient.getDay()];
  dia = timeClient.getDate();
  mes = timeClient.getMonth();
  ano = timeClient.getYear();
  mes_atual = monName[timeClient.getMonth()];
}

void u8g2_prepare()
{
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.setFontRefHeightExtendedText();
    u8g2.setDrawColor(1);
    u8g2.setFontPosTop();
    u8g2.setFontDirection(0);  
    //u8g2.setDisplayRotation(U8G2_R2);
}

void menu_principal()
{
    //Serial.println(timeClient.getFormattedTime());
    //Serial.println(dayName[timeClient.getDay()]);
    u8g2.drawStr(42,5, horario.c_str()); 
    u8g2.drawStr(32,23, dia_semana.c_str());
    //u8g2.drawUTF8(48,23, "|");
    u8g2.setCursor(77, 23);
    u8g2.print(temp);
    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawUTF8(90, 18, DEGREE_SYMBOL);
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawUTF8(97,23, "C");
    u8g2.setCursor(33, 45);
    u8g2.print((String)dia + " " + mes_atual + " " + (String)ano);
}

void menu_musica1()
{
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 0, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15,5, "Star Wars");
    u8g2.drawStr(0,20, "Never Gonna Give You Up");
    u8g2.drawStr(0,35, "Feliz Aniversario"); 
    u8g2.drawStr(0, 50, "Shinzo wo Sasageyo!");
}

void menu_musica2()
{
    u8g2.drawStr(0,0, "Star Wars");
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 10, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15,15, "Never Gonna Give You Up");
    u8g2.drawStr(0,30, "Feliz Aniversario"); 
    u8g2.drawStr(0, 45, "Shinzo wo Sasageyo!");
}

void menu_musica3()
{
    u8g2.drawStr(0,0, "Star Wars");
    u8g2.drawStr(0,15, "Never Gonna Give You Up");
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 25, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15,30, "Feliz Aniversario");   
    u8g2.drawStr(0, 45, "Shinzo wo Sasageyo!");
}

void menu_musica4()
{
    u8g2.drawStr(0,0, "Star Wars");
    u8g2.drawStr(0,15, "Never Gonna Give You Up");
    u8g2.drawStr(0,30, "Feliz Aniversario");  
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 40, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15, 45, "Shinzo wo Sasageyo!");
}

void menu_musica5()
{
    u8g2.drawStr(0,0, "Never Gonna Give You Up");
    u8g2.drawStr(0,15, "Feliz Aniversario");
    u8g2.drawStr(0,30, "Shinzo wo Sasageyo!");  
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 40, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15, 45, "Star Wars 2");
}

void menu_musica6()
{
    u8g2.drawStr(0,0, "Feliz Aniversario");
    u8g2.drawStr(0,15, "Shinzo wo Sasageyo!");
    u8g2.drawStr(0,30, "Star Wars 2");  
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 40, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15, 45, "Zelda's Lullaby");
}

void menu_musica7()
{
    u8g2.drawStr(0,0, "Shinzo wo Sasageyo!");
    u8g2.drawStr(0,15, "Star Wars 2");
    u8g2.drawStr(0,30, "Zelda's Lullaby");  
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 40, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15, 45, "Tetris");
}

void menu_musica8()
{
    u8g2.drawStr(0,0, "Star Wars 2");
    u8g2.drawStr(0,15, "Zelda's Lullaby");
    u8g2.drawStr(0,30, "Tetris");  
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawUTF8(0, 40, "♫");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(15, 45, "Harry Potter");
}

void menu_especial()
{
    u8g2.drawStr(0,5, "Feliz Aniversario,");
    u8g2.drawStr(0,20, "amor. Aproveite");
    u8g2.drawStr(0,35, "o presente!");  
    u8g2.drawStr(0, 50, "Te amo! <3");
}

void draw()
{
    u8g2_prepare();

    verifica_botoes();
    
    if(tempo_aux == 0)
    {
      inicia_cronometro();   
      tempo_aux = 1;   
    }

    if(menu_atual == 0)
    {
        if((millis()-tempo_passado) > 300000)
        {
          Serial.println("ENTROU");
          verifica_clima();
          atualiza_clima();
          tempo_aux = 0;          
        }

        atualiza_horario();
        menu_principal();  
    }

    else if(menu_atual == 1)
        menu_musica1();

    else if(menu_atual == 2)
        menu_musica2();

    else if(menu_atual == 3)
        menu_musica3();

    else if(menu_atual == 4)
        menu_musica4();

    else if(menu_atual == 5)
        menu_musica5();

    else if(menu_atual == 6)
        menu_musica6();

    else if(menu_atual == 7)
        menu_musica7();

    else if(menu_atual == 8)
        menu_musica8();

    else if(menu_atual == 15)
        menu_especial();
}

void inicializa_display()
{ 
    pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);
    pinMode(botao3, INPUT_PULLUP);
    pinMode(botao4, INPUT_PULLUP);
    pinMode(botao5, INPUT_PULLUP);

    u8g2.begin();
}

void verifica_botoes()
{
    valor1 = digitalRead(botao1);
    valor2 = digitalRead(botao2);
    valor3 = digitalRead(botao3);
    valor4 = digitalRead(botao4);
    valor5 = digitalRead(botao5);

    /*Menu Musica*/

    if(valor2 == LOW && menu_atual<8 && menu_atual>0) //Seletor pra baixo  
    {
        menu_atual++; 
        Serial.println("Pra baixo no menu");
    }

    if(valor3 == LOW && menu_atual>1) //Seletor pra cima
    {
        menu_atual--;
        Serial.println("Pra cima no menu");      
    }

    /*Botao Seleciona de acordo com o menu*/
    if(valor4 == LOW && menu_atual == 1) //Star Wars
    {
        SWTheImperialMarch();
        Serial.println("Star Wars tocou");
    }

    if(valor4 == LOW && menu_atual == 2) //Never Gonna Give You Up
    {
        NGGYU();   
        Serial.println("Never Gonna Give You Up tocou");
    }

    if(valor4 == LOW && menu_atual == 3) //Feliz Aniversario
    {
        HappyBirthday();
        Serial.println("Feliz Aniversario tocou");
    }

    if(valor4 == LOW && menu_atual == 4) //Attack on Titan
    {
        AOTS2OP();
        Serial.println("Shinzo wo Sasageyo tocou");
    }

    if(valor4 == LOW && menu_atual == 5) //StarWars 2
    {
        StarWars2();
        Serial.println("Star Wars 2 tocou");
    }

    if(valor4 == LOW && menu_atual == 6) //Zelda's Lullaby
    {
        ZeldasLullaby();
        Serial.println("Zelda's Lullaby tocou");
    }

    if(valor4 == LOW && menu_atual == 7) //Tetris
    {
        Tetris();
        Serial.println("Tetris tocou");
    }

    if(valor4 == LOW && menu_atual == 8) //HarryPotter
    {
        HarryPotter();
        Serial.println("Harry Potter tocou");
    }

    if(valor5 == LOW) //Botao Mensagem
    {
      menu_atual = 15;      
    }
        
    /*Botao alterna menu*/
    if(valor1 == LOW && verifica_menu == 0) 
    {
        menu_atual = 0;
        verifica_menu = 1;
    }

    else if(valor1 == LOW && verifica_menu == 1)
    {
        menu_atual = 1;
        verifica_menu = 0;
    }
}

//Limpa buffer e imprime
void desenha_display()
{
    u8g2.firstPage();
    do
    {
      draw();
    } while(u8g2.nextPage());

  
  /*Outra alternativa*/
  /*
    u8g2.clearBuffer();
    draw();
    u8g2.sendBuffer();
  */
}