
/* 
 * Clase para activar ou desactivar un motor de corrente continua ou 
 * unha bomba de auga. A velocidade de xiro/bombeo pódese regular 
 * indicando un valor de 0 a 255 e configurando un dos pines PWM.
 * 
 * Sara Aguado Couselo - s.aguado.dev@gmail.com
 */

class MotorDC {
 private:
 
  byte pin = 0;        // pin do sensor
  byte velocidade = 0; // velocidade de xiro

 public:
  MotorDC(byte pin, byte velocidade) {
    pinMode(pin, OUTPUT);
    this->pin = pin;
    this->velocidade = velocidade;
  }

  float activar() {
    digitalWrite(pin, HIGH);
    analogWrite(pin, velocidade);
  }

  float desactivar() {
    digitalWrite(pin, LOW);
  }
};
