
/* 
 * Clase para configurar e ler dun sensor dixital 
 * de temperatura e humidade:
 * 
 *  DHT11
 *  DHT22 (AM2302, AM2321)
 *  DHT21 (AM2301)
 * 
 * Sara Aguado Couselo - s.aguado.dev@gmail.com
 */

#include "DHT.h"

class SensorTemperaturaHumidade {
 private:
 
  DHT dht = DHT(2, DHT11); // obxecto de control do sensor
  float temperatura;       // último valor de temperatura lido
  float humidade;          // último valor de humidade lido

 public:
  SensorTemperaturaHumidade(byte pin, int type) {
    pinMode(pin, INPUT);
    dht = DHT(pin, type);
    dht.begin();
  }
  
  float lerTemperatura() {
    float t = dht.readTemperature();
    if (!isnan(t)) {
      temperatura = t;
    }
    return temperatura;
  }
  
  float lerHumidade() {
    float h = dht.readHumidity();
    if (!isnan(h)) {
      humidade = h;
    }
    return humidade;
  }
};
