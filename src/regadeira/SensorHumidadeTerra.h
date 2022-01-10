
/* 
 * Clase para ler o grao de humidade a través dun 
 * sensor analóxico de humidade en terra (FC-28).
 * 
 *  O valores obtidos van desde 0 sumerxido en auga a 1023 no aire.
 * 
 * Sara Aguado Couselo - s.aguado.dev@gmail.com
 */

class SensorHumidadeTerra {
 private:
 
  byte pin = 0;                            // pin do sensor
  byte index = 0;                          // índice do buffer
  unsigned int promedios[5] = {0,0,0,0,0}; // buffer de lecturas

 public:
  SensorHumidadeTerra(byte pin) {
    pinMode(pin, INPUT);
    this->pin = pin;
  }

  float lerHumidade() {
    unsigned int sum = 0;
    for (int i = 0; i < 40; i++) {
      sum += analogRead(pin);         // Calculamos a media de 40 mostras
      delay(5);                       // Separadas por 5 ms
    }
    promedios[index] = sum/40;        // Gardamos o resultado no buffer
    
    sum = 0;
    for (int i=0; i<5; i++) {         // E calculamos a media do buffer
      sum += promedios[i];
    }
    sum /= 5;

    if (++index == 5) index = 0;     
    return map(sum, 0, 1023, 100, 0); // Convertímola a porcentaxe e devolvémola
  }
};
