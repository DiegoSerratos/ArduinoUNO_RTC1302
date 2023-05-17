//SE AGREGA LIBRERÍAS DE LCD
#include <Wire.h>  
//SE AGREGA LIBRERÍAS PARA RTC
#include <ThreeWire.h>  
#include <RtcDS1302.h>
//SE CREA Y CONFIGURA OBJETO PARA MANEJAR RTC
ThreeWire myWire(4,5,2); //PINES IO, SCLK, CE -> DE RTC DS1302
RtcDS1302<ThreeWire> Rtc(myWire);


void setup() {
  // SE INICAR MONITOR SERIE E IMPRIME FECHA Y HORA
    Serial.begin(57600);
    Rtc.Begin();// SE INICIALIZA RTC
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);//SE CONFIGURA FECHA Y HORA ACTUAL
   // printDateTime(compiled); //SE IMPRIME FECHA Y HORA
    Serial.println();
}

void loop() {
  RtcDateTime now = rtc.now();

  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(' ');
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.println();

  delay(3000);
}
