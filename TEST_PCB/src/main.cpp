/*
//  Código de probas para testear a placa Lil' Whale
//  Válido para Rev01
//                                            a_reyes 11/11/17
*/

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

/* TESTS*/
bool testLED = 0;
bool testSerial = 0;
bool testSD = 0;
bool testUSB = 0;

/* GPIOs
TODO: Comprobar que o número dos GPIO son correctos
TODO: Externalizar o valor dos GPIOs noutro ficheiro
*/
const int LED = 27;     // LED de debug
    // Tarxeta SD. Añado o prefixo "sd" para evitar conflictos cas variables SPI
const int sdDO = 35;
const int sdSCLK = 32;
const int sdDI = 33;
const int sdCS = 26;
  // STOTG. Añado o prefixo "u" (USB) para evitar conflictos na definición de pins co framework de arduino.
const int uDAT_VP = 21;
const int uSEO_VM = 19;
const int uRCV = 5;
const int uVP = 17;
const int uVM = 16;
const int uOE_TP_INT = 4;
const int uINT_ = 39; //TODO: Comprobar este!!
const int uRESET_ = 15;
const int uSCL = 13;
const int uSDA = 12;

int espera = 1000; //Tempo en microsegundos entre parpadeos do LED
void setup() {
    // Encender o LED no inicio
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
    delayMicroseconds(espera);
    digitalWrite(LED, LOW);
    delayMicroseconds(espera);
    delayMicroseconds(espera);

    /* TEST SD*/
    digitalWrite(LED, HIGH);
    delayMicroseconds(3000);
    digitalWrite(LED, LOW);
    delayMicroseconds(espera);
    delayMicroseconds(500);
    digitalWrite(LED, HIGH);
    delayMicroseconds(3000);
    digitalWrite(LED, LOW);
    delayMicroseconds(espera);
    delayMicroseconds(500);
    // pinMode(SS, OUTPUT); TODO: Investigar esto. Este pin parece que debe ser posto como saída aínda que non se conecte.
    if (!SD.begin(sdCS, sdDI, sdDO, sdSCLK))
    {
      // Non podo asumir que a comunicación serie funciona. Uso o LEd porque é, a priori, máis robusto.

      return;
    }
}

void loop() {
    // put your main code here, to run repeatedly:
}
